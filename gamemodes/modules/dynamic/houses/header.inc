const MAX_HOUSES = 100;

enum _:E_HOUSE_INFO
{
    houseId,
    houseOwner,
    houseOwnerName[MAX_PLAYER_NAME + 1],
    housePrice,
    houseEntInt,
    houseEntWorld,
    houseExitInt,
    houseExitWorld,
    Float:houseEntX,
    Float:houseEntY,
    Float:houseEntZ,
    Float:houseEntA,
    Float:houseExitX,
    Float:houseExitY,
    Float:houseExitZ,
    Float:houseExitA,
    Text3D:houseLabel,
    housePickupExt,
    housePickupInt
};

new Pool:HousePool;