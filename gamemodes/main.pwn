#define MAX_PLAYERS     50
#define CGEN_MEMORY     20000

#define PP_SYNTAX

#define YSI_NO_HEAP_MALLOC
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

#include <open.mp>
#include <a_mysql>
#include <PawnPlus>
#include <samp_bcrypt>
#include <crashdetect>
#include <Pawn.CMD>

#include <pp-dialog>
#include <pp-mysql>
#include <pp-bcrypt>

#include <YSI\YSI_Data\y_bit>

#include "./modules/config/database"
#include "./modules/config/plugins"
#include "./modules/core/string_def"
#include "./modules/core/func_def"

#include "./modules/player/main"

public OnGameModeInit()
{
    Plugin_Config();
    gMySQL_Connect();
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
    return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
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