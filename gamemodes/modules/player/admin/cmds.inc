CMD:acode(playerid, params[])
{
    if(PlayerInfo[playerid][pAdmin] == 0) {
        return SendNonAuth(playerid);
    }

    if(isnull(PlayerInfo[playerid][pAdminCode])) 
    {
        if(isnull(params)) {
            SendSyntaxMessage(playerid, "/acode [mat khau]");
            SendClientMessage(playerid, COLOR<INDIANRED>, "* Mat khau do dai 6 den 12 ki tu.");
            SendClientMessage(playerid, COLOR<INDIANRED>, "* Dam bao mat khau du bao mat.");
            return 1;
        }

        if(strlen(params) < 6 || strlen(params) > 12) 
            return SendClientMessage(playerid, COLOR<GREY>, "Mat khau phai co do dai 6 den 12 ki tu!");
        
        if(SetAdminCode(playerid, params)) {
            SendClientMessage(playerid, COLOR<GREENYELLOW>, "* Tao mat khau quan tri vien thanh cong.");
            SendClientMessage(playerid, COLOR<GREENYELLOW>, "* Su dung /aduty de bat dau lam viec.");
        }
        else {
            SendClientMessage(playerid, COLOR<GREY>, "Co loi xay ra khi tao mat khau quan tri vien!");
        }
    }
    else 
    {
        extract params -> new string:oldcode[14], string:newcode[14]; else
        {
            return SendSyntaxMessage(playerid, "/acode [mat khau cu] [mat khau moi]");
        }

        if(strlen(oldcode) < 6 || strlen(oldcode) > 12) 
            return SendClientMessage(playerid, COLOR<GREY>, "Mat khau cu phai co do dai 6 den 12 ki tu!");

        if(strlen(newcode) < 6 || strlen(newcode) > 12) 
            return SendClientMessage(playerid, COLOR<GREY>, "Mat khau moi phai co do dai 6 den 12 ki tu!");

        if(!VerifyAdminCode(playerid, oldcode)) 
            return SendClientMessage(playerid, COLOR<GREY>, "Mat khau cu khong chinh xac!");

        if(SetAdminCode(playerid, newcode)) {
            SendClientMessage(playerid, COLOR<GREENYELLOW>, "* Doi mat khau quan tri vien thanh cong.");
            SendClientMessage(playerid, COLOR<GREENYELLOW>, "* Su dung /aduty de bat dau lam viec.");
        }
        else {
            SendClientMessage(playerid, COLOR<GREY>, "Co loi xay ra khi doi mat khau quan tri vien!");
        }
    }
    return 1;
}