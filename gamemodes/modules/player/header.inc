enum E_PLAYER_INFO
{
    pSQLID,
    pName[MAX_PLAYER_NAME + 1]
};

new PlayerInfo[MAX_PLAYERS][E_PLAYER_INFO];
new BitArray:PlayerLogged<MAX_PLAYERS>;