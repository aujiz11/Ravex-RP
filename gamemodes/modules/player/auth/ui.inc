new PlayerText:MainMenuTD[MAX_PLAYERS][20];

stock CreateMainMenuTD(playerid)
{
    MainMenuTD[playerid][0] = CreatePlayerTextDraw(playerid, -6.000, 0.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][0], 652.000, 459.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][0], 168430335);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][0], true);

    MainMenuTD[playerid][1] = CreatePlayerTextDraw(playerid, 242.000, 122.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][1], 162.000, 190.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][1], 421075455);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][1], true);

    MainMenuTD[playerid][2] = CreatePlayerTextDraw(playerid, 279.000, 127.000, "PARTICLE:bloodpool_64");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][2], 50.000, 52.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][2], -7601921);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][2], true);

    MainMenuTD[playerid][3] = CreatePlayerTextDraw(playerid, 293.000, 132.000, "R");
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][3], 0.900, 4.100);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][3], true);

    MainMenuTD[playerid][4] = CreatePlayerTextDraw(playerid, 313.000, 139.000, "avex");
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][4], 0.540, 3.100);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][4], true);

    MainMenuTD[playerid][5] = CreatePlayerTextDraw(playerid, 261.000, 198.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][5], 134.000, 19.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][5], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][5], true);

    MainMenuTD[playerid][6] = CreatePlayerTextDraw(playerid, 248.000, 208.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][6], 10.000, 9.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][6], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][6], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][6], true);

    MainMenuTD[playerid][7] = CreatePlayerTextDraw(playerid, 245.000, 203.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][7], 16.000, 15.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][7], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][7], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][7], true);

    MainMenuTD[playerid][8] = CreatePlayerTextDraw(playerid, 246.000, 195.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][8], 13.000, 12.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][8], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][8], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][8], true);

    MainMenuTD[playerid][9] = CreatePlayerTextDraw(playerid, 261.000, 224.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][9], 134.000, 19.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][9], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][9], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][9], true);

    MainMenuTD[playerid][10] = CreatePlayerTextDraw(playerid, 248.000, 231.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][10], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][10], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][10], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][10], true);

    MainMenuTD[playerid][11] = CreatePlayerTextDraw(playerid, 248.000, 221.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][11], 10.000, 23.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][11], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][11], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][11], true);

    MainMenuTD[playerid][12] = CreatePlayerTextDraw(playerid, 251.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][12], 4.000, 7.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][12], 421075455);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][12], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][12], true);

    MainMenuTD[playerid][13] = CreatePlayerTextDraw(playerid, 282.000, 255.000, "LD_SPAC:white"); // Login button
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][13], 80.000, 27.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][13], 252645375);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][13], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, MainMenuTD[playerid][13], true);

    MainMenuTD[playerid][14] = CreatePlayerTextDraw(playerid, 321.000, 263.000, "THAM GIA");
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][14], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][14], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][14], true);

    MainMenuTD[playerid][15] = CreatePlayerTextDraw(playerid, 242.000, 304.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][15], 162.000, 16.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][15], -1523963137);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][15], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][15], true);

    MainMenuTD[playerid][16] = CreatePlayerTextDraw(playerid, 323.000, 306.000, ""SERVER_NAME" - "BUILD_VERSION"");
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][16], 0.210, 1.299);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][16], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][16], true);

    MainMenuTD[playerid][17] = CreatePlayerTextDraw(playerid, 267.000, 200.000, ReturnName(playerid)); // show player name
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][17], 0.230, 1.500);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][17], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][17], true);

    MainMenuTD[playerid][18] = CreatePlayerTextDraw(playerid, 266.000, 221.000, "_"); // input password
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][18], 0.310, 2.099);
    PlayerTextDrawTextSize(playerid, MainMenuTD[playerid][18], 394.000, 15.000);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][18], true);
    PlayerTextDrawSetSelectable(playerid, MainMenuTD[playerid][18], true);

    MainMenuTD[playerid][19] = CreatePlayerTextDraw(playerid, 325.000, 180.000, "_");
    PlayerTextDrawLetterSize(playerid, MainMenuTD[playerid][19], 0.219, 1.199);
    PlayerTextDrawAlignment(playerid, MainMenuTD[playerid][19], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, MainMenuTD[playerid][19], -10270721);
    PlayerTextDrawSetShadow(playerid, MainMenuTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, MainMenuTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, MainMenuTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, MainMenuTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, MainMenuTD[playerid][19], true);
}

stock DestroyMainMenuTD(playerid)
{
    for(new i; i < 20; i++) {
        PlayerTextDrawDestroy(playerid, MainMenuTD[playerid][i]);
        MainMenuTD[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
    }
}