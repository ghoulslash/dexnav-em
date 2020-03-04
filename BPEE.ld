// SAVE
gSaveBlock1 = 0x3005D8C;
gSaveBlock2 = 0x3005D90;
gSaveBlock3 = 0x3005D94;

// FIELD MESSAGE
gFieldMessageBoxMode = 0x20375BC
HideFieldMessageBox = 0x8098314 | 1;
TextboxFdecodeAutoAndCreateTask = 0x80982DC | 1;

// TASK
DestroyTask = 0x80A909C | 1;
CreateTask = 0x80A8FB0 | 1;
RunTasks = 0x80A910C | 1;
ResetTasks = 0x80A8F50 | 1;

// SCRIPTING
FlagGet = 0x809D790 | 1;
FlagClear = 0x809D768 | 1;
ScriptContext2_IsEnabled = 0x8098E6C | 1;
ScriptContext2_Disable = 0x8098E60 | 1;
ScriptContext2_Enable = 0x8098E54 | 1;
Var8000 = 0x20375D8;
Var8001 = 0x20375DA;
Var8002 = 0x20375DC;
Var8003 = 0x20375DE;
Var8004 = 0x20375E0;
Var8005 = 0x20375E2;
Var8006 = 0x20375E4;
Var8007 = 0x20375E6;
Var8008 = 0x20375E8;
VarSet = 0x809D6B0 | 1;
VarGet = 0x809D694 | 1;
Menu_MoveCursor = 0x81984D8 | 1;

// SPRITES
BuildOamBuffer = 0x8006A0C | 1;
AnimateSprites = 0x80069C0 | 1;
UpdatePaletteFade = 0x80A1A1C | 1;
LoadOam = 0x8007188 | 1;
ProcessSpriteCopyRequests = 0x800742C | 1;
ResetSpriteData = 0x8006974 | 1;
FreeSpriteTileRanges = 0x80085E0 | 1;
LoadCompressedSpriteSheetUsingHeap = 0x8034988 | 1;
CreateSprite = 0x8006DF4 | 1;
LoadSpriteSheet = 0x80084F8 | 1;
LoadSpritePalette = 0x8008744 | 1;

// PALETTES
TransferPlttBuffer = 0x80A19C0 | 1;
ResetPaletteFade = 0x80A1A74 | 1;
FillPalBufferBlack = 0x80AF020 | 1;
FreeAllSpritePalettes = 0x800870C | 1;
gReservedSpritePaletteCount = 0x300301C;
BeginNormalPaletteFade = 0x80A1AD4 | 1;


// CALLBACKS
SetVBlankCallback = 0x80006F0 | 1;
SetHBlankCallback = 0x80006FC | 1;
SetMainCallback1 = 0x8085E88 | 1;
SetMainCallback2 = 0x8000540 | 1;

// VRAM
SyncTilemaps = 0x81999D0 | 1;

// STRINGS
RunTextPrinters = 0x8004778 | 1;

// OVERWORLD
CleanupOverworldWindowsAndTilemaps = 0x8085D34 | 1;
ResetBgsAndClearDma3BusyFlags = 0x80017BC | 1;
ChangeBgX = 0x8001D04 | 1;
ChangeBgY = 0x8001E7C | 1;
ShowBg = 0x8001B30 | 1;
SetBgTilemapBuffer = 0x8002250 | 1;
BgIdMarkForSync = 0x81999BC | 1;
GetCurrentMapType = 0x8085BA4 | 1;
IsMapTypeOutdoors = 0x8085BD0 | 1;
FadeScreen = 0x80ABCD0 | 1;

// MALLOC
MallocInit = 0x8000B1C | 1;
Malloc = 0x8000B38 | 1;
LZ77UnCompWram = 0x82E7090 | 1;
LZ77UnCompVram = 0x82E708C | 1;

// POKEMON
SpeciesToNationalPokedexNum = 0x806D4A4 | 1;
GetSetPokedexFlag = 0x80C0664 | 1;
CreateWildMon = 0x80B4E68 | 1;
SetMonData = 0x806ACAC | 1;
CalculateMonStats = 0x8068D0C | 1;
LoadMonIconPalettes = 0x80D2F04 | 1;
CreateMonIcon = 0x80D2CC4 | 1;
GetCurrentMapWildMonHeaderId = 0x80B4CF8 | 1;
gWildMonHeaders = 0x8552D48 | 1;

// ITEMS
CheckBagHasItem = 0x80D6724 | 1;

// WINDOWS
FreeAllWindowBuffers = 0x8003604 | 1;
InitBgsFromTemplates = 0x80017E8 | 1;
InitWindows = 0x80031C0 | 1;
AddWindow = 0x8003380 | 1;
FillWindowPixelBuffer = 0x8003C48 | 1;
DrawStdFrameWithCustomTileAndPalette = 0x8197E80 | 1;
AddTextPrinterParameterized3 = 0x8199E64 | 1;
Menu_InitCursor = 0x81983AC | 1;
CopyWindowToVram = 0x8003658 | 1;
PutWindowTilemap = 0x800378C | 1;
Menu_ProcessInputNoWrapAround_other = 0x81986C4 | 1;
ClearStdWindowAndFrameToTransparent = 0x8198070 | 1;
RemoveWindow = 0x8003574 | 1;

// SOUNDS
PlaySE = 0x80A37A4 | 1;

// MENU
sStartMenuCursorPos = 0x203760E;
sNumStartMenuActions = 0x203760F;
sCurrentStartMenuActions = 0x2037610;
gMenuCallback = 0x3005DF4;
//BuildNormalStartMenu = 0x809F4CC | 1;
BuildSafariZoneStartMenu = 0x809F538 | 1;
BuildMultiPartnerRoomStartMenu = 0x809F634 | 1;
BuildBattlePyramidStartMenu = 0x809F604 | 1;
BuildBattlePikeStartMenu = 0x809F5E0 | 1;
BuildUnionRoomStartMenu = 0x809F5A4 | 1;
BuildLinkModeStartMenu = 0x809F568 | 1;
StartMenuPokedexCallback = 0x809FBB4 | 1;
StartMenuPokemonCallback = 0x809FBF0 | 1;
StartMenuBagCallback = 0x809FC24 | 1;
StartMenuPokeNavCallback = 0x809FC58 | 1;
StartMenuPlayerNameCallback = 0x809FC8C | 1;
StartMenuSaveCallback = 0x809FCFC | 1;
StartMenuOptionCallback = 0x809FD20 | 1;
StartMenuExitCallback = 0x809FD64 | 1;
StartMenuSafariZoneRetireCallback = 0x809FD74 | 1;
StartMenuLinkModePlayerNameCallback = 0x809FD88 | 1;
StartMenuBattlePyramidRetireCallback = 0x809FDC0 | 1;
StartMenuBattlePyramidBagCallback = 0x809FDF4 | 1;
BattlePyramidRetireStartCallback = 0x809FE9C | 1;
BattlePyramidRetireReturnCallback = 0x809FEB8 | 1;
BattlePyramidRetireCallback = 0x809FED4 | 1;
RemoveExtraStartMenuWindows = 0x809F774 | 1;
HideStartMenu = 0x80A0934 | 1;
ShowStartMenu = 0x809FA9C | 1;
AddStartMenuAction = 0x809F4B0 | 1;

// LINK
IsUpdateLinkStateCBActive = 0x8085D8C | 1;
InUnionRoom = 0x8018004 | 1;
InBattlePike = 0x81A80A8 | 1;
InBattlePyramid = 0x81A9E40 | 1;
InMultiPartnerRoom = 0x813994C | 1;













