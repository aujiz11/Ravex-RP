stock LoadHouses()
{
    // ordered should be set to TRUE to ensure always getting
    // the smallest index
    // Read more: https://github.com/IS4Code/PawnPlus/wiki/Pools#ordered-pools
    HousePool = pool_new(_, true);
    mysql_tquery_s(mainDB, @("SELECT houses.*, accounts.Username FROM houses LEFT JOIN accounts ON houses.OwnerID = accounts.id"), "OnLoadHouses", "");
}

Function:OnLoadHouses()
{
    new 
        rows = cache_num_rows(),
        houseData[E_HOUSE_INFO];

    for(new i; i < rows && i < MAX_HOUSES; i++)
    {
        cache_get_value_name_int(i, "id", houseData[houseId]);
        cache_get_value_name_int(i, "OwnerID", houseData[houseOwner]);
        cache_get_value_name(i, "Username", houseData[houseOwnerName]);
        cache_get_value_name_int(i, "Price", houseData[housePrice]);
        cache_get_value_name_int(i, "EntInterior", houseData[houseEntInt]);
        cache_get_value_name_int(i, "EntWorld", houseData[houseEntWorld]);
        cache_get_value_name_int(i, "ExitInterior", houseData[houseExitInt]);
        cache_get_value_name_int(i, "ExitWorld", houseData[houseExitWorld]);
        cache_get_value_name_float(i, "EntX", houseData[houseEntX]);
        cache_get_value_name_float(i, "EntY", houseData[houseEntY]);
        cache_get_value_name_float(i, "EntZ", houseData[houseEntZ]);
        cache_get_value_name_float(i, "EntA", houseData[houseEntA]);
        cache_get_value_name_float(i, "ExitX", houseData[houseExitX]);
        cache_get_value_name_float(i, "ExitY", houseData[houseExitY]);
        cache_get_value_name_float(i, "ExitZ", houseData[houseExitZ]);
        cache_get_value_name_float(i, "ExitA", houseData[houseExitA]);

        if(houseData[houseEntX] != 0.0) {
            new string[128];
            if(houseData[houseOwner] == 0) {
                format(string, _, "Dang ban voi gia {D3D360}$%i", houseData[housePrice]);
            }
            else {
                format(string, _, "So huu: {D3D360}%s", houseData[houseOwnerName]);
            }

            format(string, _, "{06EF31}[HOUSE #%d]\n{FFFFFF}%s", i, string);
            houseData[houseLabel] = CreateDynamic3DTextLabel(string, 0x3EAA52FF, houseData[houseEntX], houseData[houseEntY], houseData[houseEntZ]+0.7, 10.0, .testlos = 1, .worldid = houseData[houseEntWorld], .interiorid = houseData[houseEntInt]);
            houseData[housePickupExt] = CreateDynamicPickup(1273, 23, houseData[houseEntX], houseData[houseEntY], houseData[houseEntZ], houseData[houseEntWorld], houseData[houseEntInt]);
        }

        if(houseData[houseExitX] != 0.0) {
            houseData[housePickupInt] = CreateDynamicPickup(19135, 23, houseData[houseExitX], houseData[houseExitY], houseData[houseExitZ], houseData[houseExitWorld], houseData[houseExitInt]);
        }

        pool_add_arr(HousePool, houseData);
    }

    printf("[House] Da tai %d ngoi nha tu co so du lieu", rows);
}

// update house pickup and label (if house exists)
static __HousePickupAdd(idx)
{
    if(idx < 0 || idx >= MAX_HOUSES || !pool_has(HousePool, idx)) 
        return 0;

    new houseData[E_HOUSE_INFO];
    if(pool_get_arr_safe(HousePool, idx, houseData))
    {
        if(IsValidDynamic3DTextLabel(houseData[houseLabel]))
            DestroyDynamic3DTextLabel(houseData[houseLabel]);

        if(IsValidDynamicPickup(houseData[housePickupExt]))
            DestroyDynamicPickup(houseData[housePickupExt]);

        if(IsValidDynamicPickup(houseData[housePickupInt]))
            DestroyDynamicPickup(houseData[housePickupInt]);

        new string[128];
        if(houseData[houseOwner] == 0) {
            format(string, _, "Dang ban voi gia {D3D360}$%i", houseData[housePrice]);
        }
        else {
            format(string, _, "So huu: {D3D360}%s", houseData[houseOwnerName]);
        }

        format(string, _, "[HOUSE #%d]\n{FFFFFF}%s", idx, string);
        houseData[houseLabel] = CreateDynamic3DTextLabel(string, 0x3EAA52FF, houseData[houseEntX], houseData[houseEntY], houseData[houseEntZ]+0.7, 10.0, .testlos = 1, .worldid = houseData[houseEntWorld], .interiorid = houseData[houseEntInt]);
        houseData[housePickupExt] = CreateDynamicPickup(1273, 23, houseData[houseEntX], houseData[houseEntY], houseData[houseEntZ], houseData[houseEntWorld], houseData[houseEntInt]);

        if(houseData[houseExitX] != 0.0) {
            houseData[housePickupInt] = CreateDynamicPickup(19135, 23, houseData[houseExitX], houseData[houseExitY], houseData[houseExitZ], houseData[houseExitWorld], houseData[houseExitInt]);
        }
        pool_set_arr(HousePool, idx, houseData);
        return 1;
    }
    return 0;
}

stock House_Create(Float:x, Float:y, Float:z, Float:a, worldid, interiorid, price, ownerid = 0)
{
    new houseData[E_HOUSE_INFO];
    houseData[houseEntX] = x;
    houseData[houseEntY] = y;
    houseData[houseEntZ] = z;  
    houseData[houseEntA] = a;
    houseData[housePrice] = price;
    houseData[houseOwner] = ownerid;
    houseData[houseEntWorld] = worldid;
    houseData[houseEntInt] = interiorid;

    await mysql_aquery_s(mainDB, str_format("INSERT INTO houses (EntX, EntY, EntZ, EntA, EntWorld, EntInterior, Price, OwnerID) VALUES (%f, %f, %f, %f, %d, %d, %d, %d)", x, y, z, a, worldid, interiorid, price, ownerid));
    houseData[houseId] = cache_insert_id();

    new idx = pool_add_arr(HousePool, houseData);
    __HousePickupAdd(idx);
    return idx;
}

stock House_Delete(idx)
{
    if(idx < 0 || idx >= MAX_HOUSES || !pool_has(HousePool, idx)) 
        return 0;

    new houseData[E_HOUSE_INFO];
    if(pool_get_arr_safe(HousePool, idx, houseData))
    {
        if(IsValidDynamic3DTextLabel(houseData[houseLabel]))
            DestroyDynamic3DTextLabel(houseData[houseLabel]);

        if(IsValidDynamicPickup(houseData[housePickupExt]))
            DestroyDynamicPickup(houseData[housePickupExt]);

        if(IsValidDynamicPickup(houseData[housePickupInt]))
            DestroyDynamicPickup(houseData[housePickupInt]);

        mysql_tquery_s(mainDB, str_format("DELETE FROM houses WHERE `id` = %d LIMIT 1", houseData[houseId]));

        pool_remove_deep(HousePool, idx);
        return 1;
    }
    return 0;
}

CMD:ahouse(playerid, params[])
{
    // TODO - add condition for admin
    // if(PlayerInfo[playerid][pAdmin] < 4){return;}
    
    // `extract` is a macro for `unformat` similar to `sscanf`
    // Read more: https://github.com/Y-Less/sscanf?tab=readme-ov-file#extract
    extract params -> new string:option[12], string:secoption[64]=""; else
    {
        SendClientMessage(playerid, -1, "SYNTAX: /ahouse [option]");
        SendClientMessage(playerid, -1, "Options: create, delete");
        return 1;
    }

    if(!strcmp(option, "create", true))
    {
        extract secoption -> new price; else
        {
            return SendClientMessage(playerid, -1, "SYNTAX: /ahouse create [price]");
        }

        if(pool_size(HousePool) >= MAX_HOUSES)
            return SendClientMessage(playerid, -1, "Maximum house limit reached.");

        if(price <= 0)
            return SendClientMessage(playerid, -1, "Price must be greater than 0.");

        new Float:_pos[4];
        GetPlayerPos(playerid, _pos[0], _pos[1], _pos[2]);
        GetPlayerFacingAngle(playerid, _pos[3]);

        new idx = House_Create(_pos[0], _pos[1], _pos[2], _pos[3], GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), price);
        SendClientMessage(playerid, -1, "House created successfully (ID: %d).", idx);
    }
    else if(!strcmp(option, "delete", true))
    {
        extract secoption -> new houseid; else
        {
            return SendClientMessage(playerid, -1, "SYNTAX: /ahouse delete [houseId]");
        }

        if(!House_Delete(houseid))
            return SendClientMessage(playerid, -1, "Failed to delete house (ID: %d).", houseid);

        SendClientMessage(playerid, -1, "House deleted successfully (ID: %d).", houseid);
    }
    else
    {
        SendClientMessage(playerid, -1, "Invalid option.");
    }
    return 1;
}