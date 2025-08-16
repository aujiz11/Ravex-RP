new PlayerText:CreateCharTD[MAX_PLAYERS][21];

stock CreateCharacterTextDraws(playerid)
{
    CreateCharTD[playerid][0] = CreatePlayerTextDraw(playerid, 178.000, 134.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][0], 284.000, 210.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][0], 421075455);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][0], true);

    CreateCharTD[playerid][1] = CreatePlayerTextDraw(playerid, 284.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][1], 1.000, 194.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][1], -1523963137);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][1], true);

    CreateCharTD[playerid][2] = CreatePlayerTextDraw(playerid, 195.000, 122.000, "Character");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][2], 0.589, 2.199);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][2], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][2], true);

    CreateCharTD[playerid][3] = CreatePlayerTextDraw(playerid, 346.000, 122.000, "Information");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][3], 0.589, 2.199);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][3], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][3], true);

    CreateCharTD[playerid][4] = CreatePlayerTextDraw(playerid, 278.000, 129.000, "PARTICLE:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][4], -98.000, 155.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][4], -1523963261);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][4], true);

    CreateCharTD[playerid][5] = CreatePlayerTextDraw(playerid, 278.000, 303.000, "PARTICLE:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][5], -98.000, -19.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][5], -1523963261);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][5], true);

    CreateCharTD[playerid][6] = CreatePlayerTextDraw(playerid, 159.000, 159.000, "_");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][6], 134.000, 128.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, CreateCharTD[playerid][6], 0);
    PlayerTextDrawSetPreviewRot(playerid, CreateCharTD[playerid][6], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehicleColours(playerid, CreateCharTD[playerid][6], 0, 0);

    CreateCharTD[playerid][7] = CreatePlayerTextDraw(playerid, 178.000, 298.000, "_");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][7], 42.000, 43.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, CreateCharTD[playerid][7], 19132);
    PlayerTextDrawSetPreviewRot(playerid, CreateCharTD[playerid][7], 67.000, -129.000, -71.000, 1.000);
    PlayerTextDrawSetPreviewVehicleColours(playerid, CreateCharTD[playerid][7], 0, 0);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][7], true);

    CreateCharTD[playerid][8] = CreatePlayerTextDraw(playerid, 235.000, 298.000, "_");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][8], 42.000, 43.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, CreateCharTD[playerid][8], 19132);
    PlayerTextDrawSetPreviewRot(playerid, CreateCharTD[playerid][8], 202.000, 60.000, -64.000, 1.000);
    PlayerTextDrawSetPreviewVehicleColours(playerid, CreateCharTD[playerid][8], 0, 0);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][8], true);

    CreateCharTD[playerid][9] = CreatePlayerTextDraw(playerid, 291.000, 171.000, "NGAY SINH:");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][9], 0.230, 1.600);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][9], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][9], true);

    CreateCharTD[playerid][10] = CreatePlayerTextDraw(playerid, 289.000, 188.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][10], 165.000, 21.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][10], 168430335);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][10], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][10], true);

    CreateCharTD[playerid][11] = CreatePlayerTextDraw(playerid, 293.000, 192.000, "_");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][11], 0.230, 1.600);
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][11], 451.000, 14.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][11], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][11], true);

    CreateCharTD[playerid][12] = CreatePlayerTextDraw(playerid, 291.000, 215.000, "GIOI TINH:");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][12], 0.230, 1.600);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][12], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][12], true);

    CreateCharTD[playerid][13] = CreatePlayerTextDraw(playerid, 289.000, 232.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][13], 165.000, 21.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][13], 168430335);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][13], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][13], true);

    CreateCharTD[playerid][14] = CreatePlayerTextDraw(playerid, 293.000, 236.000, "_");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][14], 0.230, 1.600);
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][14], 451.000, 14.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][14], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][14], true);

    CreateCharTD[playerid][15] = CreatePlayerTextDraw(playerid, 291.000, 259.000, "MA GIOI THIEU:");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][15], 0.240, 1.600);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][15], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][15], true);

    CreateCharTD[playerid][16] = CreatePlayerTextDraw(playerid, 289.000, 276.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][16], 165.000, 21.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][16], 168430335);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][16], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][16], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][16], true);

    CreateCharTD[playerid][17] = CreatePlayerTextDraw(playerid, 293.000, 280.000, "(neu co)");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][17], 0.230, 1.600);
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][17], 451.000, 14.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][17], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][17], true);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][17], true);

    CreateCharTD[playerid][18] = CreatePlayerTextDraw(playerid, 335.000, 305.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CreateCharTD[playerid][18], 76.000, 28.000);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][18], 579543807);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][18], 255);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][18], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][18], true);
    PlayerTextDrawSetSelectable(playerid, CreateCharTD[playerid][18], true);

    CreateCharTD[playerid][19] = CreatePlayerTextDraw(playerid, 372.000, 312.000, "KET THUC");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][19], 0.300, 1.600);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][19], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][19], true);

    CreateCharTD[playerid][20] = CreatePlayerTextDraw(playerid, 290.000, 155.000, "_");
    PlayerTextDrawLetterSize(playerid, CreateCharTD[playerid][20], 0.259, 1.299);
    PlayerTextDrawAlignment(playerid, CreateCharTD[playerid][20], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, CreateCharTD[playerid][20], -1306385665);
    PlayerTextDrawSetShadow(playerid, CreateCharTD[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, CreateCharTD[playerid][20], 0);
    PlayerTextDrawBackgroundColour(playerid, CreateCharTD[playerid][20], 150);
    PlayerTextDrawFont(playerid, CreateCharTD[playerid][20], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, CreateCharTD[playerid][20], true);
}

stock DestroyCharacterTextDraws(playerid)
{
    for (new i = 0; i < 20; i++) {
        PlayerTextDrawDestroy(playerid, CreateCharTD[playerid][i]);
        CreateCharTD[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
    }
}