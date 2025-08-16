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