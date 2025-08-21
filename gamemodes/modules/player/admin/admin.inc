stock IsAnAdmin(playerid, ADMIN_LEVEL:level)
{
    return (
        PlayerInfo[playerid][pAdminDuty] &&
        PlayerInfo[playerid][pAdmin] >= _:level
    );
}

stock IsAdminPowerful(playerid, ADMIN_POWER:power)
{
    return (
        IsAnAdmin(playerid, ADMIN_HEAD) ||
        PlayerInfo[playerid][pAdminPower] == _:power
    );
}

stock GetAdminName(ADMIN_LEVEL:level)
{
    if(level <= ADMIN_NONE || level > ADMIN_HEAD)
        return "Unknown";

    return AdminName[level];
}

stock SetAdminCode(playerid, const code[])
{
    if(PlayerInfo[playerid][pAdmin] == 0 || isnull(code)) {
        return 0;
    }
    
    new string[128]; 
    await_str(string) BCrypt_AsyncHash(code, 4); // cost is 4 to reduce latency
    mysql_tquery_s(mainDB, str_format("UPDATE accounts SET AdminCode = '%s' WHERE id = %d", string, PlayerInfo[playerid][pSQLID]));
    format(PlayerInfo[playerid][pAdminCode], 128, "%s", string);
    return 1;
}

stock VerifyAdminCode(playerid, const code[])
{
    if(PlayerInfo[playerid][pAdmin] == 0 || isnull(code)) {
        return 0;
    }

    new ret = await BCrypt_AsyncVerify(code, PlayerInfo[playerid][pAdminCode]);
    return ret;
}