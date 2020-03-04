gSaveBlock1 = 0x3005D8C;
gSaveBlock2 = 0x3005D90;
gSaveBlock3 = 0x3005D94;

gFieldMessageBoxMode = 0x20375BC;
HideFieldMessageBox = 0x8098314 | 1;
TextboxFdecodeAutoAndCreateTask = 0x80982DC | 1;

DestroyTask = 0x80A909C | 1;
CreateTask = 0x80A8FB0 | 1;
RunTasks = 0x80A910C | 1;
ResetTasks = 0x80A8F50 | 1;

FlagSet = 0x809D740 | 1;
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
SpriteCB_MonIcon = 0x80D3014 | 1;

TransferPlttBuffer = 0x80A19C0 | 1;
ResetPaletteFade = 0x80A1A74 | 1;
FillPalBufferBlack = 0x80AF020 | 1;
FreeAllSpritePalettes = 0x800870C | 1;
gReservedSpritePaletteCount = 0x300301C;
BeginNormalPaletteFade = 0x80A1AD4 | 1;
gPaletteFade = 0x2037FD4;
LoadPalette = 0x80A1938 | 1;
LoadCompressedPalette = 0x80A18F4 | 1;

SetVBlankCallback = 0x80006F0 | 1;
SetHBlankCallback = 0x80006FC | 1;
SetMainCallback1 = 0x8085E88 | 1;
SetMainCallback2 = 0x8000540 | 1;

SyncTilemaps = 0x81999D0 | 1;

RunTextPrinters = 0x8004778 | 1;

CleanupOverworldWindowsAndTilemaps = 0x8085D34 | 1;
ResetBgsAndClearDma3BusyFlags = 0x80017BC | 1;
ChangeBgX = 0x8001D04 | 1;
ChangeBgY = 0x8001E7C | 1;
ShowBg = 0x8001B30 | 1;
HideBg = 0x8001B44 | 1;
SetBgTilemapBuffer = 0x8002250 | 1;
BgIdMarkForSync = 0x81999BC | 1;
GetCurrentMapType = 0x8085BA4 | 1;
IsMapTypeOutdoors = 0x8085BD0 | 1;
IsMapTypeIndoors = 0x8085C14 | 1;
FadeScreen = 0x80ABCD0 | 1;

MallocInit = 0x8000B1C | 1;
Malloc = 0x8000B38 | 1;
malloc_ = 0x8000B38 | 1;
LZ77UnCompWram = 0x82E7090 | 1;
LZ77UnCompVram = 0x82E708C | 1;
Calloc = 0x8000B4C | 1;


SpeciesToNationalPokedexNum = 0x806D4A4 | 1;
GetSetPokedexFlag = 0x80C0664 | 1;
CreateWildMon = 0x80B4E68 | 1;
SetMonData = 0x806ACAC | 1;
CalculateMonStats = 0x8068D0C | 1;
LoadMonIconPalettes = 0x80D2F04 | 1;
CreateMonIcon = 0x80D2CC4 | 1;
GetCurrentMapWildMonHeaderId = 0x80B4CF8 | 1;
gWildMonHeaders = 0x8552D48 | 1;

CheckBagHasItem = 0x80D6724 | 1;

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

PlaySE = 0x80A37A4 | 1;

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

IsUpdateLinkStateCBActive = 0x8085D8C | 1;
InUnionRoom = 0x8018004 | 1;
InBattlePike = 0x81A80A8 | 1;
InBattlePyramid = 0x81A9E40 | 1;
InMultiPartnerRoom = 0x813994C | 1;

Memset = 0x82E9434 | 1;
memset = 0x82E9434 | 1;
memset_ = 0x82E9434 | 1;
Free = 0x8000B60 | 1;
free_ = 0x8000B60 | 1;
memcpy_ = 0x82E93D4 | 1;
memcpy = 0x82E93D4 | 1;

CB1_Overworld = 0x8085E04 | 1;
CB2_ReturnToFieldWithOpenMenu = 0x8086194 | 1;
StringCopy = 0x8008BA0 | 1;
GetCurrentRegionMapSectionId = 0x8085C58 | 1;
GetMapName = 0x812456C | 1;
CpuFastSet = 0x82E7080 | 1;

__divsi3 = 0x82E7540 | 1;
__modsi3 = 0x82E7650 | 1;
__udivsi3 = 0x82E7B68 | 1;
udivsi = 0x82E7B68 | 1;
__umodsi3 = 0x82E7B68 | 1;
umodsi = 0x82E7B68 | 1;

gDummySpriteAnimTable = 0x82EC69C;
SpriteCallbackDummy = 0x8007428;
gDummySpriteAffineAnimTable = 0x82EC6A8;

GetSafariZoneFlag = 0x80FC0A0 | 1;
GetNationalPokedexCount = 0x80C07F4 | 1;

