stock Account_MySQLUpdate(&String:query, sqlid)
{
    // Make sure the query length is not too large
    if(2046 - str_len(query) < 200) {
        new String:whereclause = str_new(" WHERE id = ") + str_val(sqlid);
        query = str_cat(query, whereclause);
        mysql_tquery_s(mainDB, query);
        str_clear(query);
        query = str_new("UPDATE accounts SET");
    }
    else {
        if(str_findc(query, '=') != -1) {
            query = str_cat(query, @(","));
        }
    }
}

stock Account_MySQLFinish(&String:query, sqlid)
{
    if(str_empty(query)) {
        return 0;
    }

    if(str_find(query, @("WHERE id =")) != -1) {
        mysql_tquery_s(mainDB, query);
    }
    else {
        new String:whereclause = str_new(" WHERE id = ") + str_val(sqlid);
        query = str_cat(query, whereclause);
        mysql_tquery_s(mainDB, query);
        print_s(@("Query: ") + query);
        str_delete(query); // ensure the `query` variable is no longer in use
    }
    return 1;
}

stock SavePlayerInteger(playerid, &String:query, const column[], value)
{
    Account_MySQLUpdate(query, PlayerInfo[playerid][pSQLID]);
    query = str_cat(query, str_format(" `%s` = %d", column, value));
}

stock SavePlayerString(playerid, &String:query, const column[], const value[])
{
    Account_MySQLUpdate(query, PlayerInfo[playerid][pSQLID]);
    query = str_cat(query, str_format(" `%s` = '%s'", column, value));
}

stock SavePlayerFloat(playerid, &String:query, const column[], Float:value)
{
    Account_MySQLUpdate(query, PlayerInfo[playerid][pSQLID]);
    query = str_cat(query, str_format(" `%s` = %f", column, value));
}

stock SaveAccount(playerid)
{
    if(!IsPlayerLogged(playerid)) return 0;

    new 
        String:query = @("UPDATE accounts SET"),
        Float:pos[4];

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(playerid, pos[3]);

    SavePlayerInteger(playerid, query, "Model", PlayerInfo[playerid][pModel]);
    SavePlayerInteger(playerid, query, "World", GetPlayerVirtualWorld(playerid));
    SavePlayerInteger(playerid, query, "Interior", GetPlayerInterior(playerid));

    SavePlayerFloat(playerid, query, "PlayerPosX", pos[0]);
    SavePlayerFloat(playerid, query, "PlayerPosY", pos[1]);
    SavePlayerFloat(playerid, query, "PlayerPosZ", pos[2]);
    SavePlayerFloat(playerid, query, "PlayerAngle", pos[3]);

    Account_MySQLFinish(query, PlayerInfo[playerid][pSQLID]);
    return 1;
}

stock LoadAccount(playerid)
{
    await mysql_aquery_s(mainDB, str_format("SELECT * FROM accounts WHERE Username = '%s' LIMIT 1", ReturnName(playerid)));

    if(!cache_num_rows())
    {
        KickEx(playerid, "Tai khoan khong ton tai");
        return 0;
    }

    cache_get_value_name_int(0, "id", PlayerInfo[playerid][pSQLID]);
    
    cache_get_value_name(0, "Username", PlayerInfo[playerid][pName]);
    cache_get_value_name(0, "BirthDate", PlayerInfo[playerid][pBirthDate]);
    cache_get_value_name_int(0, "Gender", PlayerInfo[playerid][pGender]);
    cache_get_value_name_int(0, "Model", PlayerInfo[playerid][pModel]);
    cache_get_value_name_int(0, "Referral", PlayerInfo[playerid][pReferral]);
    cache_get_value_name_int(0, "World", PlayerInfo[playerid][pWorld]);
    cache_get_value_name_int(0, "Interior", PlayerInfo[playerid][pInterior]);

    cache_get_value_name_float(0, "PlayerPosX", PlayerInfo[playerid][pPosX]);
    cache_get_value_name_float(0, "PlayerPosY", PlayerInfo[playerid][pPosY]);
    cache_get_value_name_float(0, "PlayerPosZ", PlayerInfo[playerid][pPosZ]);
    cache_get_value_name_float(0, "PlayerAngle", PlayerInfo[playerid][pAngle]);

    return 1;
}