stock ReturnName(playerid)
{
    new szName[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, szName, sizeof(szName));
    return szName;
}

stock ReturnRPName(playerid)
{
    new szName[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, szName, sizeof(szName));
    
    for(new i = 0; i < strlen(szName); i++)
    {
        if(szName[i] == '_')
            szName[i] = ' ';
    }
    return szName;
}

stock IsPlayerLogged(playerid)
{
    return Bit_Get(PlayerLogged, playerid);
}

stock KickEx(playerid, const reason[])
{
    SendClientMessage(playerid, 0xB64747FF, "Ban da bi truc xuat ra khoi may chu | Ly do: %s", reason);
    wait_ticks(50);
    return Kick(playerid);
}

stock PlayerTeleport(playerid, Float:x, Float:y, Float:z, Float:a, worldid, interiorid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        SetVehiclePos(vehicleid, x, y, z);
        SetVehicleZAngle(vehicleid, a);
        SetVehicleVirtualWorld(vehicleid, worldid);
        LinkVehicleToInterior(vehicleid, interiorid);
        PutPlayerInVehicle(playerid, vehicleid, 0);
    }
    else
    {
        SetPlayerPos(playerid, x, y, z);
        SetPlayerFacingAngle(playerid, a);
        SetPlayerVirtualWorld(playerid, worldid);
        SetPlayerInterior(playerid, interiorid);
    }

    Streamer_UpdateEx(playerid, x, y, z, worldid, interiorid);
    return 1;
}

stock IsPlayerPressEnterKey(playerid, KEY:oldkeys, KEY:newkeys)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        return PRESSED(KEY_FIRE);
    }
    else if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        return PRESSED(KEY_WALK);
    }
    return 0;
}