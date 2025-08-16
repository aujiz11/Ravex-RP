const G_PASSWORD_LENGTH = 32;

enum E_PLAYER_INFO
{
    pSQLID,
    pName[MAX_PLAYER_NAME + 1],
    pBirthDate[12],
    pGender,
    pModel,
    pReferral
};

new PlayerInfo[MAX_PLAYERS][E_PLAYER_INFO];
new BitArray:PlayerLogged<MAX_PLAYERS>;
new BitArray:InMainMenu<MAX_PLAYERS>;