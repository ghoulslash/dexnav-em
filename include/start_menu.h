#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

#include "global.h"

extern const u8 gText_MenuPokedex[];
extern const u8 gText_MenuPokemon[];
extern const u8 gText_MenuPlayer[];
extern const u8 gText_MenuSave[];
extern const u8 gText_MenuOption[];
extern const u8 gText_MenuExit[];
extern const u8 gText_MenuRetire[];
extern const u8 gText_PokeTools[];
extern const u8 gText_DexNav[];
extern const u8 gText_MenuBag[];
extern const u8 gText_MenuPokenav[];
extern const u8 gText_MenuRest[];

//typedef u8 (*MainCallback)(void);

//0x203760E
struct StartMenu
{
	u8 cursorPos;
    u8 actionCount;
    u8 actions[9];
};

#define gStartMenu ((struct StartMenu*) 0x203760E)

//#define sStartMenuCursorPos *((u8*) 0x203760E)
//#define sNumStartMenuActions *((u8*) 0x203760F)
//#define sCurrentStartMenuActions *((u8*) 0x2037610)

#define gMenuCallback (*((u32*) 0x3005DF4))

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
    MENU_ACTION_POKETOOLS,
    MENU_ACTION_DEXNAV,
};

void AppendToList(u8* list, u8* pos, u8 newEntry);

bool8 __attribute__((long_call)) IsUpdateLinkStateCBActive(void);
void __attribute__((long_call)) BuildSafariZoneStartMenu(void);
void __attribute__((long_call)) BuildLinkModeStartMenu(void);
void __attribute__((long_call)) BuildUnionRoomStartMenu(void);
void __attribute__((long_call)) AddStartMenuAction(u8 action);
void __attribute__((long_call)) BuildBattlePikeStartMenu(void);
void __attribute__((long_call)) BuildBattlePyramidStartMenu(void);
void __attribute__((long_call)) BuildMultiPartnerRoomStartMenu(void);

bool8 __attribute__((long_call)) StartMenuPokedexCallback(void);
bool8 __attribute__((long_call)) StartMenuPokemonCallback(void);
bool8 __attribute__((long_call)) StartMenuBagCallback(void);
bool8 __attribute__((long_call)) StartMenuPlayerNameCallback(void);
bool8 __attribute__((long_call)) StartMenuSaveCallback(void);
bool8 __attribute__((long_call)) StartMenuOptionCallback(void);
bool8 __attribute__((long_call)) StartMenuExitCallback(void);
bool8 __attribute__((long_call)) StartMenuPokeNavCallback(void);
bool8 __attribute__((long_call)) StartMenuBattlePyramidBagCallback(void);
bool8 __attribute__((long_call)) StartMenuBattlePyramidRetireCallback(void);
bool8 __attribute__((long_call)) StartMenuSafariZoneRetireCallback(void);
bool8 __attribute__((long_call)) StartMenuLinkModePlayerNameCallback(void);
void __attribute__((long_call)) TaskStartMenu(u8 taskId);
void __attribute__((long_call)) ShowStartMenu(void);

bool32 __attribute__((long_call)) InUnionRoom(void);
bool8 __attribute__((long_call)) InBattlePike(void);
u8 __attribute__((long_call)) InBattlePyramid(void);
bool8 __attribute__((long_call)) InMultiPartnerRoom(void);

void __attribute__((long_call)) RemoveExtraStartMenuWindows(void);
void __attribute__((long_call)) HideStartMenu(void);

u16 __attribute__((long_call)) GetNationalPokedexCount(u8);


#endif // GUARD_START_MENU_H
