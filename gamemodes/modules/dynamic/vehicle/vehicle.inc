#include <YSI\YSI_Coding\y_hooks>

stock Vehicle_Create(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:spawnA, color1, color2, respawnDelay, worldid=0, interiorid=0, Float:health=1000.0, const num_plate[]="", bool:addSiren=false)
{
    new vehicleid = CreateVehicle(modelid, spawnX, spawnY, spawnZ, spawnA, color1, color2, respawnDelay, addSiren);
    if(vehicleid <= 0 || vehicleid >= INVALID_VEHICLE_ID) 
    {
        return INVALID_VEHICLE_ID;
    }

    new vehicleData[E_VEHICLE_INFO];
    vehicleData[vehicleModel] = modelid;
    vehicleData[vehicleWorld] = worldid;
    vehicleData[vehicleInt] = interiorid;
    vehicleData[vehicleFuel] = 100.0;
    vehicleData[vehicleHealth] = health;
    vehicleData[vehicleX] = spawnX;
    vehicleData[vehicleY] = spawnY;
    vehicleData[vehicleZ] = spawnZ;

    SetVehicleNumberPlate(vehicleid, num_plate);
    LinkVehicleToInterior(vehicleid, interiorid);
    SetVehicleVirtualWorld(vehicleid, worldid);
    SetVehicleHealth(vehicleid, health);

    map_add_arr(VehicleMap, vehicleid, vehicleData);
    return vehicleid;
}

stock bool:Vehicle_Destroy(vehicleid)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    DestroyVehicle(vehicleid);
    if(map_has_key(VehicleMap, vehicleid))
    {
        map_remove_deep(VehicleMap, vehicleid);
    }
    return true;
}

stock bool:Vehicle_SetHealth(vehicleid, Float:health)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    SetVehicleHealth(vehicleid, health);
    if(map_has_key(VehicleMap, vehicleid))
    {
        map_set_cell(VehicleMap, vehicleid, vehicleHealth, health);
    }
    return true;
}

stock bool:Vehicle_GetHealth(vehicleid, &Float:health)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    if(map_has_key(VehicleMap, vehicleid))
    {
        new vehicleData[E_VEHICLE_INFO];
        map_get_arr(VehicleMap, vehicleid, vehicleData);
        health = vehicleData[vehicleHealth];
        return true;
    }
    return false;
}

stock bool:Vehicle_GetFuel(vehicleid, &Float:fuel)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    if(map_has_key(VehicleMap, vehicleid))
    {
        new vehicleData[E_VEHICLE_INFO];
        map_get_arr(VehicleMap, vehicleid, vehicleData);
        fuel = vehicleData[vehicleFuel];
        return true;
    }
    return false;
}

stock bool:Vehicle_SetFuel(vehicleid, Float:fuel)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    if(map_has_key(VehicleMap, vehicleid))
    {
        map_set_cell(VehicleMap, vehicleid, vehicleFuel, fuel);
        return true;
    }
    return false;
}

stock bool:Vehicle_GetEngineState(vehicleid, &VEHICLE_PARAMS:engineState)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }
    
    GetVehicleParamsEx(vehicleid, engineState);
    return true;
}

stock bool:Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS:engineState)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    SetVehicleParamsEx(vehicleid, engineState);
    return true;
}

stock bool:Vehicle_GetLightState(vehicleid, &VEHICLE_PARAMS:lightState)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }
    
    GetVehicleParamsEx(vehicleid, _, lightState);
    return true;
}

stock bool:Vehicle_SetLightState(vehicleid, VEHICLE_PARAMS:lightState)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    SetVehicleParamsEx(vehicleid, _, lightState);
    return true;
}

stock bool:Vehicle_IsBicycle(vehicleid)
{
    if(!IsValidVehicle(vehicleid))
    {
        return false;
    }

    new modelid = GetVehicleModel(vehicleid);
    if(modelid == 481 || modelid == 509 || modelid == 510)
    {
        return true;
    }
    return false;
}

stock StartVehicleEngine(playerid, vehicleid)
{
    if(!IsValidVehicle(vehicleid))
    {
        return 0;
    }

    task_detach();
    task_yield(1);

    SendClientMessage(playerid, COLOR<GREY>, "Ban dang co gang mo dong co xe...");
    wait_ms(2000);

    new Float:fuel;
    Vehicle_GetFuel(vehicleid, fuel);
    if(fuel <= 0)
    {
        SendClientMessage(playerid, COLOR<RED>, "Xe da het nhien lieu!");
        return 1;
    }

    new Float:health;
    Vehicle_GetHealth(vehicleid, health);
    if(health <= 250)
    {
        SendClientMessage(playerid, COLOR<RED>, "Xe da bi hu hong!");
        return 1;
    }

    SendClientMessage(playerid, COLOR<GREEN>, "Dong co xe da duoc mo!");
    Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_ON);
    return 1;
}

// test command vehicle create
CMD:veh(playerid, params[])
{
    if(isnull(params)) return SendSyntaxMessage(playerid, "/veh [modelid]");

    new 
        modelid = strval(params),
        Float:pos[3];

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

    Vehicle_Create(modelid, pos[0], pos[1], pos[2], 0.0, random(150), random(150), -1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), 1200.0, "KIET");
    return 1;
}

// test command vehicle destroy
CMD:vdestroy(playerid, params[])
{
    if(isnull(params)) return SendSyntaxMessage(playerid, "/vdestroy [vehicle id]");
    
    new vehicleid = strval(params);

    Vehicle_Destroy(vehicleid);
    return 1;
}

CMD:bugvhp(playerid, params[])
{
    SetVehicleHealth(GetPlayerVehicleID(playerid), 1000.0);
    SendClientMessage(playerid, -1, "Bug Vehicle Health!");
    return 1;
}

// Synchronize vehicle data every 500 ms (0.5 sec)
task _VehicleTask[500]()
{
    for_map(idx : VehicleMap)
    {
        new vehicleid = iter_get_key(idx); 
        new vehicleData[E_VEHICLE_INFO];
        if(iter_get_arr(idx, vehicleData))
        {
            new Float:vHealth, VEHICLE_PARAMS:engineState;
            GetVehicleHealth(vehicleid, vHealth);
            Vehicle_GetEngineState(vehicleid, engineState);

            if(vHealth > vehicleData[vehicleHealth]) {
                // ensure the vehicle health is always true
                SetVehicleHealth(vehicleid, vehicleData[vehicleHealth]);
            }
            else if(vHealth < 250.0) {
                SetVehicleHealth(vehicleid, 250.0);
                iter_set_cell(idx, vehicleHealth, 250.0);
                if(engineState == VEHICLE_PARAMS_ON) {
                    Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_OFF);
                }
            }
            else {
                vehicleData[vehicleHealth] = vHealth;
                iter_set_cell(idx, vehicleHealth, vHealth);
            }

            if(vehicleData[vehicleFuel] <= 0.0 && engineState == VEHICLE_PARAMS_ON) {
                Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_OFF);
            }

            if(engineState == VEHICLE_PARAMS_ON)
            {
                new Float:distance = GetVehicleDistanceFromPoint(vehicleid, vehicleData[vehicleX], vehicleData[vehicleY], vehicleData[vehicleZ]);
                if(distance >= 5.0 && distance <= 40.0)
                {
                    new Float:fuelConsumption = distance * 0.003;
                    vehicleData[vehicleFuel] -= fuelConsumption;
                    if(vehicleData[vehicleFuel] < 0.0) {
                        vehicleData[vehicleFuel] = 0.0;
                    }
                    // TODO - calculate fuel consumption for each vehicle model
                    GetVehiclePos(vehicleid, vehicleData[vehicleX], vehicleData[vehicleY], vehicleData[vehicleZ]);
                    iter_set_arr(idx, vehicleData);
                }
            }
        }
    }
}

hook OnGameModeInit()
{
    VehicleMap = map_new();
    return 1;
}

hook OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        new 
            vehicleid = GetPlayerVehicleID(playerid), 
            VEHICLE_PARAMS:engineState;

        if(IsValidVehicle(vehicleid))
        {
            Vehicle_GetEngineState(vehicleid, engineState);
            if(engineState == VEHICLE_PARAMS_UNSET || engineState == VEHICLE_PARAMS_OFF)
            {
                if(Vehicle_IsBicycle(vehicleid)) {
                    Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_ON);
                }
                else {
                    Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_OFF);
                }
            }
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, KEY:oldkeys, KEY:newkeys)
{
    if(PRESSED(KEY_NO))
    {
        if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            new vehicleid = GetPlayerVehicleID(playerid);
            if(IsValidVehicle(vehicleid) && !Vehicle_IsBicycle(vehicleid))
            {
                new VEHICLE_PARAMS:engineState;
                Vehicle_GetEngineState(vehicleid, engineState);
                if(engineState == VEHICLE_PARAMS_OFF) {
                    StartVehicleEngine(playerid, vehicleid);
                }
                else {
                    Vehicle_SetEngineState(vehicleid, VEHICLE_PARAMS_OFF); 
                    SendClientMessage(playerid, COLOR<GREY>, "Ban da tat dong co xe!");
                }
            }
        }
    }

    if(PRESSED(KEY_LOOK_BEHIND) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        new VEHICLE_PARAMS:lightState;
        Vehicle_GetLightState(vehicleid, lightState);
        if(lightState == VEHICLE_PARAMS_ON) {
            Vehicle_SetLightState(vehicleid, VEHICLE_PARAMS_OFF);
        }
        else {
            Vehicle_SetLightState(vehicleid, VEHICLE_PARAMS_ON);
        }
    }
    return 1;
}