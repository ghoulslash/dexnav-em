#include "config.h"
#include "defines.h"

//static bool8 StartMenuPokeToolsCallback(void);

static const struct MenuAction sStartMenuItems[] =
{
    {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    {gText_MenuBag, {.u8_void = StartMenuBagCallback}},
    {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    {gText_MenuPlayer, {.u8_void = StartMenuPlayerNameCallback}},
    {gText_MenuSave, {.u8_void = StartMenuSaveCallback}},
    {gText_MenuOption, {.u8_void = StartMenuOptionCallback}},
    {gText_MenuExit, {.u8_void = StartMenuExitCallback}},
    {gText_MenuRetire, {.u8_void = StartMenuSafariZoneRetireCallback}},
    {gText_MenuPlayer, {.u8_void = StartMenuLinkModePlayerNameCallback}},
    {gText_MenuRest, {.u8_void = StartMenuSaveCallback}},
    {gText_MenuRetire, {.u8_void = StartMenuBattlePyramidRetireCallback}},
    {gText_MenuBag, {.u8_void = StartMenuBattlePyramidBagCallback}},
	{gText_PokeTools, {.u8_void = PokeToolsFunc}},
	{gText_DexNav, {.u8_void = ExecDexNav}},
};

static void BuildPokeToolsMenu(void)
{
	gStartMenu->actionCount = 0;

	AddStartMenuAction(MENU_ACTION_POKEDEX);
	AddStartMenuAction(MENU_ACTION_DEXNAV);
	AddStartMenuAction(MENU_ACTION_EXIT);

	FlagClear(FLAG_POKETOOLS_MENU);
}

static void BuildNormalStartMenu(void)
{
    if (FlagGet(FLAG_SYS_POKETOOLS_GET))
        AddStartMenuAction(MENU_ACTION_POKETOOLS);
    else if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

void BuildStartMenuActions(void)
{
    gStartMenu->actionCount = 0;

    if (IsUpdateLinkStateCBActive() == TRUE)
        BuildLinkModeStartMenu();
    else if (InUnionRoom() == TRUE)
        BuildUnionRoomStartMenu();
    else if (GetSafariZoneFlag() == TRUE)
        BuildSafariZoneStartMenu();
    else if (InBattlePike())
        BuildBattlePikeStartMenu();
    else if (InBattlePyramid())
        BuildBattlePyramidStartMenu();
    else if (InMultiPartnerRoom())
        BuildMultiPartnerRoomStartMenu();
	else if (FlagGet(FLAG_POKETOOLS_MENU))
		BuildPokeToolsMenu();
	else
		BuildNormalStartMenu();
}

static void CloseStartMenu(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
}
/*
static bool8 StartMenuPokeToolsCallback(void)
{
    CloseStartMenu();
    PlaySE(SE_WIN_OPEN);
    CreateTask(ToolSelection, 0);
    
    return TRUE;
}
*/

u8 PokeToolsFunc(void)
{
	CloseStartMenu();
	PlaySE(SE_WIN_OPEN);

    FlagSet(FLAG_POKETOOLS_MENU);
    ShowStartMenu();

	return 1;
}


bool8 HandleStartMenuInput(void)
{
    if (gMain.newKeys & DPAD_UP)
    {
        PlaySE(SE_SELECT);
        gStartMenu->cursorPos = Menu_MoveCursor(-1);
    }

    if (gMain.newKeys & DPAD_DOWN)
    {
        PlaySE(SE_SELECT);
        gStartMenu->cursorPos = Menu_MoveCursor(1);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if (sStartMenuItems[gStartMenu->actions[gStartMenu->cursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
                return FALSE;
        }
		
        gMenuCallback = (u32)sStartMenuItems[gStartMenu->actions[gStartMenu->cursorPos]].func.u8_void;

        if (gMenuCallback != (u32)StartMenuSaveCallback
            && gMenuCallback != (u32)StartMenuExitCallback
            && gMenuCallback != (u32)StartMenuSafariZoneRetireCallback
            && gMenuCallback != (u32)StartMenuBattlePyramidRetireCallback
            && gMenuCallback != (u32)PokeToolsFunc)
        {
           FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    if (gMain.newKeys & (START_BUTTON | B_BUTTON))
    {
        RemoveExtraStartMenuWindows();
        HideStartMenu();
        return TRUE;
    }

    return FALSE;
}
