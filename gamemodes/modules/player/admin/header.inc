enum ADMIN_LEVEL
{
    ADMIN_NONE,
    ADMIN_TRIAL,
    ADMIN_JUNIOR,
    ADMIN_GENERAL,
    ADMIN_SENIOR,
    ADMIN_HEAD
};

enum ADMIN_POWER
{
    ADMIN_POWER_NONE,
    ADMIN_POWER_PROPERTY,
    ADMIN_POWER_GROUP,
    ADMIN_POWER_DEVELOPMENT
};

new const AdminName[ADMIN_LEVEL][64] =
{
    "none",
    "Trial Admin",
    "Junior Admin",
    "General Admin",
    "Senior Admin",
    "Head Admin"
};

new const AdminPower[ADMIN_POWER][64] =
{
    "none",
    "Property Manager",
    "Group Manager",
    "Development Admin"
};