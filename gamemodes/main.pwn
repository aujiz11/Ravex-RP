#include <open.mp>
#include <a_mysql>
#include <PawnPlus>

#include <pp-mysql>

#include "./modules/config/database.inc"

main(){}

public OnGameModeInit()
{
    gMySQL_Connect();
    return 1;
}

public OnGameModeExit()
{
    mysql_close(mainDB);
    return 1;
}