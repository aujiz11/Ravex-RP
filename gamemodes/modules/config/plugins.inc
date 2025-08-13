stock Plugin_Config()
{
    new bool:enabled;
    enabled = GetConsoleVarAsBool("crashdetect.enabled_long_call_time");
    if(enabled) {
        new value;
        value = GetConsoleVarAsInt("crashdetect.long_call_time");
        SetCrashDetectLongCallTime(value);
        printf("[Plugin] Crashdetect - Set Long Call Time (%d)", value);
    }
    else {
        print("[Plugin] Crashdetect - Disabled Long Call Time");
        DisableCrashDetectLongCall();
    }
}