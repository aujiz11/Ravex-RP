stock ReturnName(playerid)
{
    new szName[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, szName, sizeof(szName));
    return szName;
}

stock IsPlayerLogged(playerid)
{
    return Bit_Get(PlayerLogged, playerid);
}

stock KickEx(playerid)
{
    return Kick(playerid);
}