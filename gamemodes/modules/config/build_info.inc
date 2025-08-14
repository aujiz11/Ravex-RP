#define BUILD_VERSION "0.0.2"
#define BUILD_AUTHOR  "Aujiz"
#define BUILD_GIT     "aujiz11"

stock Build_Info()
{
    new info[32];
    format(info, _, "Github:            "BUILD_GIT""),
    Server_PrintIntroPart(info),
    Server_PrintIntroPart(YSI_EMPTY),
    format(info, _, "Built Version:     "BUILD_VERSION""),
    Server_PrintIntroPart(info),
    format(info, _, "Built Author:      "BUILD_AUTHOR""),
    Server_PrintIntroPart(info),
    Server_PrintIntroPart(YSI_EMPTY),
    format(info, _, "Built Date:        %s", __date),
    Server_PrintIntroPart(info),
    format(info, _, "Built Time:        %s", __time),
    Server_PrintIntroPart(info),
    Server_FinishIntroPart();
}