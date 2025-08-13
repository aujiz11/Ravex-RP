new MySQL:mainDB;

stock gMySQL_Connect()
{
    mysql_log(ERROR | WARNING);
    mainDB = mysql_connect_file();

    if(mysql_errno(mainDB) != 0) {
        printf("[MySQL] Could not connect to Database (Error Number: %d)", mysql_errno(mainDB));
        SendRconCommand("exit");
    }
    else 
    {
        print("[MySQL] Connect to Database successfully.");
    }
    return 1;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    print("__________________________________________________");
    printf("[MySQL] Query Error (ID: %d): %s", errorid, error);
    printf("[MySQL] Query: %s", query);
    printf("[MySQL] Callback: %s", callback);
    print("__________________________________________________");
}