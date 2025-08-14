#include <YSI\YSI_Coding\y_hooks>
#include "modules/player/auth/ui.inc"

const ACCOUNT_NOT_EXISTS = 0;
const ACCOUNT_EXISTS = 1;

static _notifyCount[MAX_PLAYERS];
static _inputPassword[MAX_PLAYERS][G_PASSWORD_LENGTH];

stock Task:Auth_FindAccount(playerid)
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

stock void:Auth_VerifyAccount(playerid, const password[])
{
    new buffer[128]; // store the hashed string for comparison
    await mysql_aquery_s(mainDB, str_format("SELECT Password FROM accounts WHERE Username = '%s' LIMIT 1", ReturnName(playerid)));
    cache_get_value_name(0, "Password", buffer);

    new ret = await BCrypt_AsyncVerify(password, buffer);
    if(!ret) {
        __ShowMessage(playerid, "Mat khau khong chinh xac!");
    }
    else {
        _notifyCount[playerid] = 0;
        _inputPassword[playerid] = "\0";
        PlayerSpawn(playerid); 
        // should not be used for later
    }
}

stock void:Auth_CreateAccount(playerid, const password[])
{
    new result[BCRYPT_HASH_LENGTH + 1];
    await_str(result) BCrypt_AsyncHash(password);
    mysql_tquery_s(mainDB, str_format("INSERT INTO accounts (`Username`, `Password`) VALUES ('%s', '%s')", ReturnName(playerid), result), "OnPlayerRegister", "i", playerid);
}

static __ShowMessage(playerid, const message[])
{
    yield 1;
    _notifyCount[playerid]++;
    new ticket = _notifyCount[playerid];
    
    PlayerTextDrawSetString(playerid, MainMenuTD[playerid][19], message);
    PlayerTextDrawShow(playerid, MainMenuTD[playerid][19]);

    task_detach();
    await task_ms(3000);

    if(!IsPlayerConnected(playerid) || !IsValidPlayerTextDraw(playerid, MainMenuTD[playerid][19]))
    {
        return 0;
    }

    // this condition skips the previous task (if any)
    if(ticket == _notifyCount[playerid])
    {
        PlayerTextDrawHide(playerid, MainMenuTD[playerid][19]);
    }
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
    Bit_Vet(InMainMenu, playerid);
    Bit_Let(PlayerLogged, playerid);
    DestroyMainMenuTD(playerid);
    CancelSelectTextDraw(playerid);

    TogglePlayerSpectating(playerid, false);
    SetPlayerPos(playerid, 1481.6862, -1725.2517, 13.5469);

    // TODO - code to process player data (when registering)
    return 1;
}

stock void:Auth_CheckBan(playerid)
{
    await mysql_aquery_s(mainDB, str_format("SELECT COUNT(*) FROM bans WHERE `Username` = '%s' LIMIT 1", ReturnName(playerid)));

    new count = 0;
    cache_get_value_name_int(0, "COUNT(*)", count);
    if(!count) {
        CreateMainMenuTD(playerid);
        task_ticks(10);
        for(new i; i < 20; i++) {
            PlayerTextDrawShow(playerid, MainMenuTD[playerid][i]);
        }
        SelectTextDraw(playerid, COLOR_SELECT);
    }
    else {
        KickEx(playerid);
    }
}

hook OnPlayerConnect(playerid)
{
    for(new i; i < 20; i++) {
        MainMenuTD[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
    }

    _inputPassword[playerid] = "\0";
    _notifyCount[playerid] = 0;

    Bit_Let(InMainMenu, playerid);
    Auth_CheckBan(playerid);
    return 1;
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(Bit_Get(InMainMenu, playerid))
    {
        if(playertextid == MainMenuTD[playerid][18])
        {
            new dialogResponse[e_DIALOG_RESPONSES];
            await_arr(dialogResponse) DialogAsync_ShowPlayer(playerid, DIALOG_STYLE_INPUT, ""SERVER_NAME" | NHAP MAT KHAU", "{FFFFFF}Nhap mat khau cua ban ben duoi day:", ">>", "X");
        
            if(dialogResponse[Response] && !isnull(dialogResponse[InputText]))
            {
                new buffer[32 + 2];
                for(new i = 0; i < strlen(dialogResponse[InputText]) && i < 33; i++)
                {
                    strcat(buffer, ".");
                }

                format(_inputPassword[playerid], _, "%s", dialogResponse[InputText]);
                PlayerTextDrawSetString(playerid, MainMenuTD[playerid][18], buffer);
            }
            return 1;
        }
        else if(playertextid == MainMenuTD[playerid][13])
        {
            new len = strlen(_inputPassword[playerid]);
            if(len < 4 || len > G_PASSWORD_LENGTH)
                return __ShowMessage(playerid, "Mat khau phai chua 4 den 32 ky tu!");

            new result = await Auth_FindAccount(playerid);
            if(result == ACCOUNT_EXISTS) {
                Auth_VerifyAccount(playerid, _inputPassword[playerid]);
            }
            else {
                Auth_CreateAccount(playerid, _inputPassword[playerid]);
            }
        }
    }
    return 1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == INVALID_TEXT_DRAW && Bit_Get(InMainMenu, playerid))
    {
        SelectTextDraw(playerid, COLOR_SELECT);
        return 1;
    }
    return 0;
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