#include <YSI\YSI_Coding\y_hooks>
#include "modules/player/character/ui.inc"

const MAX_CHARACTER_SKINS = 7;

static 
    enum _:CHARACTER_CREATE {
        charGender,
        charBirthdate[12],
        charReferral,
        charModel
    };

static tempInfo[MAX_PLAYERS][CHARACTER_CREATE];
static _notifyCount[MAX_PLAYERS];
static const _maleSkins[MAX_CHARACTER_SKINS] = { 2, 6, 19, 20, 22, 29, 37 };
static const _femaleSkins[MAX_CHARACTER_SKINS] = { 12, 40, 41, 55, 56, 65, 69 };

static __ShowMessage(playerid, ConstStringTag:message)
{
    task_yield(1);
    _notifyCount[playerid]++;
    new ticket = _notifyCount[playerid],
        buffer[128];
    
    str_get(message, buffer);
    PlayerTextDrawSetString(playerid, CreateCharTD[playerid][20], buffer);
    PlayerTextDrawShow(playerid, CreateCharTD[playerid][20]);

    task_detach();
    await task_ms(3000);

    if(!IsPlayerConnected(playerid) || !IsValidPlayerTextDraw(playerid, CreateCharTD[playerid][20]))
    {
        return 0;
    }

    if(ticket == _notifyCount[playerid])
    {
        PlayerTextDrawHide(playerid, CreateCharTD[playerid][20]);
    }
    return 1;
}

stock void:ShowCharacterCreate(playerid)
{
    CreateCharacterTextDraws(playerid);
    wait_ticks(20);

    _notifyCount[playerid] = 0;
    tempInfo[playerid][charGender] = 0;
    format(tempInfo[playerid][charBirthdate], _, "%s", "00/00/0000");
    tempInfo[playerid][charReferral] = 0;
    tempInfo[playerid][charModel] = 0;

    for(new i; i < 21; i++) {
        PlayerTextDrawShow(playerid, CreateCharTD[playerid][i]);
    }
}

static void:CharacterSetSkin(playerid, idx)
{
    if(idx < 0 || idx >= MAX_CHARACTER_SKINS) {
        idx = (idx < 0) ? (MAX_CHARACTER_SKINS - 1) : (0);
        tempInfo[playerid][charModel] = idx;
    }
    
    if(tempInfo[playerid][charGender] == 1) {
        PlayerInfo[playerid][pModel] = _maleSkins[idx];
        PlayerTextDrawSetPreviewModel(playerid, CreateCharTD[playerid][6], _maleSkins[idx]);
    }
    else {
        PlayerInfo[playerid][pModel] = _femaleSkins[idx];
        PlayerTextDrawSetPreviewModel(playerid, CreateCharTD[playerid][6], _femaleSkins[idx]);
    }
    PlayerTextDrawShow(playerid, CreateCharTD[playerid][6]);
}

stock PlayerFinishCharacter(playerid)
{
    Bit_Let(PlayerLogged, playerid);
    Bit_Vet(InMainMenu, playerid);
    DestroyMainMenuTD(playerid);
    DestroyCharacterTextDraws(playerid);
    CancelSelectTextDraw(playerid);

    TogglePlayerSpectating(playerid, false);
    SetPlayerPos(playerid, 1481.6862, -1725.2517, 13.5469);

    format(PlayerInfo[playerid][pBirthDate], 12, "%s", tempInfo[playerid][charBirthdate]);
    PlayerInfo[playerid][pGender] = tempInfo[playerid][charGender];
    PlayerInfo[playerid][pRegistered] = 1;
    
    wait_ticks(10);
    SetPlayerSkin(playerid, PlayerInfo[playerid][pModel]);

    SendClientMessage(playerid, COLOR<LIGHTBLUE>, "Welcome, %s!", ReturnRPName(playerid));
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(Bit_Get(InMainMenu, playerid))
    {
        if(playertextid == CreateCharTD[playerid][7]) { // Skin move left
            if(tempInfo[playerid][charGender] == 0) 
                return __ShowMessage(playerid, @("Ban chua chon gioi tinh nhan vat!"));

            CharacterSetSkin(playerid, --tempInfo[playerid][charModel]);
            return 1;
        }
        else if(playertextid == CreateCharTD[playerid][8]){ // Skin move right
            if(tempInfo[playerid][charGender] == 0) 
                return __ShowMessage(playerid, @("Ban chua chon gioi tinh nhan vat!"));

            CharacterSetSkin(playerid, ++tempInfo[playerid][charModel]);
            return 1;
        }
        else if(playertextid == CreateCharTD[playerid][11]) { // Birthdate
            new input[128];
            await_str(input) ShowAsyncStringInputDialog(playerid, ""SERVER_NAME" | BIRTHDATE", "{FFFFFF}Nhap ngay/thang/nam (1970 - 2006) sinh cua ban ben duoi:", ">>", "X");
        
            if(!isnull(input))
            {
                new day, month, year;
                if(sscanf(input, "p</>ddd", day, month, year)) 
                    return __ShowMessage(playerid, @("Dinh dang: DD/MM/YYYY !"));

                if(!IsValidDate(year, month, day)) 
                    return __ShowMessage(playerid, @("Ngay sinh ban nhap khong hop le!"));

                if(year < 1970 || year > 2006) 
                    return __ShowMessage(playerid, @("Nam sinh tu 1970 - 2006 !"));
                
                format(tempInfo[playerid][charBirthdate], 12, "%02d/%02d/%d", day, month, year);
                PlayerTextDrawSetString(playerid, CreateCharTD[playerid][11], tempInfo[playerid][charBirthdate]);
                return 1;
            }
        }
        else if(playertextid == CreateCharTD[playerid][14]) { // Gender
            new index = await ShowAsyncListitemIndexDialog(playerid, DIALOG_STYLE_LIST, ""SERVER_NAME" | GENDER", "{6CDBB4}1.{FFFFFF} NAM\n{6CDBB4}2.{FFFFFF} NU", ">>", "X");
            if(index != -1)
            {
                tempInfo[playerid][charGender] = index + 1;
                PlayerTextDrawSetString(playerid, CreateCharTD[playerid][14], (index == 0) ? "NAM" : "NU");
                CharacterSetSkin(playerid, tempInfo[playerid][charModel]);
                return 1;
            }
        }
        else if(playertextid == CreateCharTD[playerid][17]) { // Referral
            // TODO - Implement referral code
        }
        else if(playertextid == CreateCharTD[playerid][18]) { // Finish
            if(strcmp(tempInfo[playerid][charBirthdate], "00/00/0000", false) == 0)
                return __ShowMessage(playerid, @("Ban chua chon ngay sinh!"));

            if(tempInfo[playerid][charGender] == 0) 
                return __ShowMessage(playerid, @("Ban chua chon gioi tinh nhan vat!"));

            mysql_tquery_s(mainDB, str_format("UPDATE accounts SET BirthDate = '%s', Gender = %d, Model = %d WHERE id = %d LIMIT 1", tempInfo[playerid][charBirthdate], tempInfo[playerid][charGender], PlayerInfo[playerid][pModel], PlayerInfo[playerid][pSQLID]));
            PlayerFinishCharacter(playerid);
            return 1;
        }
    }
    return 1;
}