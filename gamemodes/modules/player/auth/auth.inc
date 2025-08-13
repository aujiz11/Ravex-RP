#include <YSI\YSI_Coding\y_hooks>

const ACCOUNT_NOT_EXISTS = 0;
const ACCOUNT_EXISTS = 1;

stock Task:PlayerCheckAuth(playerid)
{
    new Task:t = task_new();
    task_detach();
    task_yield(t); 

    await mysql_aquery_s(mainDB, str_format("SELECT COUNT(*) FROM accounts WHERE Username = '%s' LIMIT 1", ReturnName(playerid)));
    
    new count = 0;
    cache_get_value_name_int(0, "COUNT(*)", count);
    task_set_result(t, count ? ACCOUNT_EXISTS : ACCOUNT_NOT_EXISTS);
    return Task:0;
}

stock ShowDialogLogin(playerid, const error[]="")
{
    task_yield(1);
    new dialogResponse[e_DIALOG_RESPONSES];
    if(isnull(error)) {
        await_arr(dialogResponse) DialogAsync_ShowPlayer(playerid, DIALOG_STYLE_INPUT, ""SERVER_NAME" | LOGIN", "{FFFFFF}Nhap mat khau cua ban ben duoi de tiep tuc:", ">>", "");
    }
    else {
        await_arr(dialogResponse) DialogAsync_ShowPlayer_s(playerid, DIALOG_STYLE_INPUT, @(""SERVER_NAME" | LOGIN"), str_format(""ERR_S" %s\n\n{FFFFFF}Nhap mat khau cua ban ben duoi de tiep tuc:", error), ">>", "");
    }

    if(!dialogResponse[Response]) 
        return ShowDialogLogin(playerid);
    
    if(isnull(dialogResponse[InputText])) 
        return ShowDialogLogin(playerid, "Ban chua nhap mat khau.");

    new password[BCRYPT_HASH_LENGTH + 1];
    await mysql_aquery_s(mainDB, str_format("SELECT Password FROM accounts WHERE Username = '%s' LIMIT 1", ReturnName(playerid)));
    cache_get_value_name(0, "Password", password);

    new ret = await BCrypt_AsyncVerify(dialogResponse[InputText], password);
    if(!ret) {
        ShowDialogLogin(playerid, "Mat khau khong chinh xac.");
    }
    else {
        PlayerSpawn(playerid); 
        // should not be used for later
    }
    return 1;
}

stock ShowDialogRegister(playerid, const error[]="")
{
    task_yield(1);

    new dialogResponse[e_DIALOG_RESPONSES];
    if(isnull(error)) {
        await_arr(dialogResponse) DialogAsync_ShowPlayer(playerid, DIALOG_STYLE_INPUT, ""SERVER_NAME" | REGISTER", "{FFFFFF}Nhap mat khau cua ban ben duoi de tiep tuc:", ">>", "");
    }
    else {
        await_arr(dialogResponse) DialogAsync_ShowPlayer_s(playerid, DIALOG_STYLE_INPUT, @(""SERVER_NAME" | REGISTER"), str_format(""ERR_S" %s\n\n{FFFFFF}Nhap mat khau cua ban ben duoi de tiep tuc:", error), ">>", "");
    }

    if(!dialogResponse[Response]) 
        return ShowDialogRegister(playerid);
    
    if(isnull(dialogResponse[InputText])) 
        return ShowDialogRegister(playerid, "Ban chua nhap mat khau.");

    if(strlen(dialogResponse[InputText]) < 4 || strlen(dialogResponse[InputText]) > 32)
        return ShowDialogRegister(playerid, "Mat khau phai tu 4 den 32 ky tu.");

    new result[BCRYPT_HASH_LENGTH + 1];
    await_str(result) BCrypt_AsyncHash(dialogResponse[InputText]);

    mysql_tquery_s(mainDB, str_format("INSERT INTO accounts (`Username`, `Password`) VALUES ('%s', '%s')", ReturnName(playerid), result), "OnPlayerRegister", "i", playerid);
    return 1;
}

// This function may be removed in the future
Function:OnPlayerRegister(playerid)
{
    PlayerInfo[playerid][pSQLID] = cache_insert_id();
    SendClientMessage(playerid, -1, "Dang ky thanh cong");
    PlayerSpawn(playerid);
    return 1;
}

stock PlayerSpawn(playerid)
{
    Bit_Let(PlayerLogged, playerid);
    TogglePlayerSpectating(playerid, false);
    SetPlayerPos(playerid, 1481.6862, -1725.2517, 13.5469);

    // TODO - code to process player data (when registering)
    return 1;
}

hook OnPlayerConnect(playerid)
{
    new result = await PlayerCheckAuth(playerid);
    if(result == ACCOUNT_EXISTS) {
        ShowDialogLogin(playerid);  
    }
    else {
        ShowDialogRegister(playerid);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Bit_Vet(PlayerLogged, playerid);
    return 1;
}

hook OnPlayerRequestClass(playerid, classid)
{
    if(IsPlayerNPC(playerid)) return 1;
	if(Bit_Get(PlayerLogged, playerid))
	{
		TogglePlayerSpectating(playerid, true);
		task_ticks(30); // wait 30 ticks from server
        TogglePlayerSpectating(playerid, false);
	}
	else
	{
		TogglePlayerSpectating(playerid, true);
	}
	return 1;
}