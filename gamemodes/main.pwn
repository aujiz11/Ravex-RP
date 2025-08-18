#define MAX_PLAYERS     50
#define CGEN_MEMORY     20000
#define BCRYPT_COST     6 // test run (845ms > 484ms)

#define PP_SYNTAX_AWAIT
#define PP_SYNTAX_FOR_POOL
#define PP_SYNTAX_FOR_MAP
#define PP_SYNTAX_@
#define PP_SYNTAX_STRING_OP
        
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

#include <open.mp>
#include <a_mysql>
#include <PawnPlus>
#include <samp_bcrypt>
#include <crashdetect>
#include <Pawn.CMD>
#include <streamer>
#include <sscanf2>

#include <YSI\YSI_Coding\y_malloc>
#include <YSI\YSI_Coding\y_timers>
#include <YSI\YSI_Data\y_bit>

#include <tdialogs>
#include <pp-mysql>
#include <pp-bcrypt>
#include <timeutils>

#include "modules/config/build_info.inc"
#include "modules/config/database.inc"
#include "modules/config/plugins.inc"

#include "modules/core/main.inc"
#include "modules/dynamic/main.inc"
#include "modules/player/main.inc"

public OnGameModeInit()
{
    Build_Info();
    Plugin_Config();
    gMySQL_Connect();

    LoadHouses();
    return 1;
}

public OnGameModeExit()
{
    mysql_close(mainDB);
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    return 1;
}

public OnPlayerConnect(playerid)
{
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    SaveAccount(playerid);
    Bit_Vet(PlayerLogged, playerid);
    return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
    if(!Bit_Get(PlayerLogged, playerid))
    {
        return 0;
    }
    printf("[Pawn.CMD] %s: /%s %s", ReturnName(playerid), cmd, params);
    return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if (result == -1)
    {
        SendClientMessage(playerid, 0xFFFFFFFF, "SERVER: Unknown command.");

        return 0;
    }
    return 1;
}