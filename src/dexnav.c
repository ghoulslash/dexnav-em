#include "config.h"
#include "defines.h"

#define IS_NEWER_UNOWN_LETTER(species) (species >= SPECIES_UNOWN_B && species <= SPECIES_UNOWN_QUESTION)

#define priv0 gTasks[taskId].data[0]

#define CPUFSCPY 0
#define CPUFSSET 1
#define CPUModeFS(size, mode) ((size >> 2) | (mode << 24))

#define ICONX 0x10
#define ICONY 0x92

#define ROW_LAND 0
#define ROW_WATER 1

#define NUM_LAND_MONS           12
#define NUM_WATER_MONS          5
struct DexnavHudData
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 moveId[MAX_MON_MOVES];
    /*0x0A*/ u16 heldItem;
    /*0x0C*/ u8 ability;
    /*0x0D*/ u8 potential;
    /*0x0E*/ u8 searchLevel;
    /*0x0F*/ u8 pokemonLevel;
    /*0x10*/ u8 moveNameLength;
    /*0x11*/ u8 proximity;
    /*0x12*/ u8 environment;
	/*0x13*/ u8 unownLetter;
    /*0x14*/ s16 tileX; // position of shaking grass
    /*0x16*/ s16 tileY;
    /*0x18*/ u8 objIdSpecies;
    /*0x19*/ u8 objIdBlackBar[4];
    /*0x1D*/ u8 objIdSight;
    /*0x1E*/ u8 objIdAbility;
    /*0x1F*/ u8 objIdMove;
    /*0x20*/ u8 objIdItem;
    /*0x21*/ u8 objIdShakingGrass;
    /*0x22*/ u8 objIdPotential[3];
    /*0x25*/ u8 movementTimes;
// GUI data
    /*0x26*/ u16 grassSpecies[NUM_LAND_MONS];
    /*0x3E*/ u16 waterSpecies[NUM_WATER_MONS];
	/*0x48*/ u16 hiddenSpecies[NUM_LAND_MONS + 1];
	/*0x62*/ u8 unownForms[NUM_LAND_MONS];
	/*0x6E*/ u8 unownFormsByDNavIndices[NUM_LAND_MONS];
	/*0x7A*/ u8 numGrassMons;
	/*0x7B*/ u8 numWaterMons;
	/*0x7C*/ u8 numHiddenLandMons;
	/*0x7D*/ u8 numHiddenWaterMons;
    /*0x7E*/ u8 cursorId;
    /*0x7F*/ u8 objids[17];
    /*0x90*/ u8 selectedIndex;
    /*0x91*/ u8 selectedArr;
    /*0x92*/ u8 abilityNum;
    /*0x93*/ u8 filler93;
    /*0x94*/ void* backBuffer;
}; /* size = 0x98 */

// Defines
enum WindowIds
{
    WINDOW_SPECIES,
    WINDOW_SEARCH_LEVEL,
    WINDOW_LEVEL_BONUS,
    WINDOW_HIDDEN_ABILITY,
    WINDOW_REPLY_TEXT,
    WINDOW_WATER,
    WINDOW_LAND,
    WINDOW_MAP_NAME,
    WINDOW_COUNT,
};

enum Statuses
{
    STATUS_INVALID_SEARCH,
    STATUS_CHOOSE_MON,
    STATUS_LOCKED,
    STATUS_NO_DATA,
    STATUS_INCORRECT_AREA,
};

enum PokeToolsMenuItems
{
    POKETOOLS_ACTION_POKEDEX,
    POKETOOLS_ACTION_DEXNAV,
};

// RAM
//EWRAM_DATA static u8 sDexNavSearchLevels[NUM_SPECIES] = {0};    // to be moved to saveblock!!!!
//EWRAM_DATA static struct DexnavHudData *sDNavState = {NULL};  //#define sDNavState (*((struct DexnavHudData**) 0x203E038))


// image data

//extern const u32 gInterfaceGfx_dexnavGuiTiles[];
//extern const u32 gInterfaceGfx_dexnavGuiMap[];
//extern const u32 gInterfaceGfx_dexnavGuiPal[];

extern const u32 sDexnavGuiTiles[];
extern const u32 sDexnavGuiTilemap[];
extern const u32 sDexnavGuiPal[];

//extern const u32 gInterfaceGfx_selectionCursorTiles[];
//extern const u16 gInterfaceGfx_selectionCursorPal[];

//static const u32 gInterfaceGfx_CapturedAllPokemonTiles[] = INCBIN_U32("graphics/dexnav/captured_all.4bpp.lz");
//static const u32 gInterfaceGfx_CapturedAllPokemonPal[] = INCBIN_U32("graphics/dexnav/captured_all.gbapal.lz");

//static const u32 sDexNavNoDataSymbolTiles[] = INCBIN_U32("graphics/dexnav/no_data.4bpp.lz");

// strings
/*
extern const u8 sText_DexNavWater[];
extern const u8 sText_DexNavLand[];
extern const u8 sText_DexNavBack[];
extern const u8 sText_DexNav_NoInfo[];
extern const u8 sText_DexNav_CaptureToSee[];
extern const u8 sText_DexNav_ChooseMon[];
extern const u8 sText_DexNav_Invalid[];
extern const u8 sText_DexNav_NoDataForSlot[];
*/

static const struct BgTemplate BgConfigDexNavGUI[] =
{
    {
        .baseTile = 0,
        .priority = 2,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 29,
        .charBaseIndex = 1,
        .bg = 0,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 28,
        .charBaseIndex = 0,
        .bg = 1,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 0,
        .mapBaseIndex = 30,
        .charBaseIndex = 2,
        .bg = 2,
    },
    {
        .baseTile = 0,
        .priority = 3,
        .paletteMode = 0,
        .screenSize = 1,
        .mapBaseIndex = 31,
        .charBaseIndex = 3,
        .bg = 3,
    }
};
/*
static const struct OamData sCapturedAllPokemonSymbolOAM =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0, //Highest
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData IconOAM =
{
    .y = 0,
    .affineMode = 1,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2, // 32x32 square
    .tileNum = 0,
    .priority = 2, //above the rest
    .paletteNum = 0,
    .affineParam = 0,
};
*/

/*
static const struct OamData CursorOAM =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2, //32x32
    .tileNum = 0,
    .priority = 0, // above BG layers
    .paletteNum = 0,
    .affineParam = 0
};
*/

/*
// cursor positions for water
static const u16 CursorPositions2[] =
{
    30 + 24 * 0, 48,
    30 + 24 * 1, 48,
    30 + 24 * 2, 48,
    30 + 24 * 3, 48,
    30 + 24 * 4, 48,
};

// positions for grass
static const u16 CursorPositions1[] =
{
    20 + 24 * 0, 92,
    20 + 24 * 1, 92,
    20 + 24 * 2, 92,
    20 + 24 * 3, 92,
    20 + 24 * 4, 92,
    20 + 24 * 5, 92,
    20 + 24 * 0, 92 + 28,
    20 + 24 * 1, 92 + 28,
    20 + 24 * 2, 92 + 28,
    20 + 24 * 3, 92 + 28,
    20 + 24 * 4, 92 + 28,
    20 + 24 * 5, 92 + 28,
};
*/

// GUI Windows
#define rgb5(r, g, b) (u16)((r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10))
static const u16 DexNavTextPal[] =
{
    rgb5(255, 0, 255), rgb5(248, 248, 248), rgb5(112, 112, 112), rgb5(96, 96, 96),
    rgb5(208, 208, 208), rgb5(76, 154, 38), rgb5(102, 194, 66), rgb5(168, 75, 76),
    rgb5(224, 114, 75), rgb5(180, 124, 41), rgb5(241, 188, 60), rgb5(255, 0, 255),
    rgb5(255, 0, 255), rgb5(255, 0, 255), rgb5(255, 133, 200), rgb5(64, 200, 248)
};

static const struct WindowTemplate sDexNavWindows[] =
{
    [WINDOW_SPECIES] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 6,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WINDOW_SEARCH_LEVEL] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 19,
    },
    [WINDOW_LEVEL_BONUS] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 12,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 64,
    },
    [WINDOW_HIDDEN_ABILITY] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 91,
    },
    [WINDOW_REPLY_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 17,
        .width = 26,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 127,
    },
    [WINDOW_WATER] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 19,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 205,
    },
    [WINDOW_LAND] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 8,
        .width = 19,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 262,
    },
    [WINDOW_MAP_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 319,
    },
    DUMMY_WIN_TEMPLATE
};


/*
//64x32 oam with highest priority
static const struct OamData FontOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x32),
    .x = ICONX,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 8x8 oam with highest priority
static const struct OamData HeldOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = ICONX,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 32x32 object with priority 1, one less than held item which overlaps it
static const struct OamData PIconOAM =
{
    .y = ICONY,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = ICONX,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate BulbTemp =
{
    .tileTag = 0x3139,
    .paletteTag = 0x3139,
    .oam = &PIconOAM,
    .anims =  gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
*/

/*
static const u8 MenuTextBlack[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};
static const u8 DexNav_BlackText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_RED};
static const u8 DexNav_WhiteText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY};
static const u8 DexNav_RedText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 DexNav_GreenText[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GREEN};
*/


/*
static const struct CompressedSpriteSheet sCapturedAllPokemonSpriteSheet = 
{
    .data = gInterfaceGfx_CapturedAllPokemonTiles,
    .size = 8 * 8 / 2,
    .tag = CAPTURED_ALL_TAG
};

static const struct SpriteTemplate sCapturedAllPokemonSymbolTemplate =
{
    .tileTag = CAPTURED_ALL_TAG,
    .paletteTag = SELECTION_CURSOR_TAG,
    .oam = &sCapturedAllPokemonSymbolOAM,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sIconTiles = 
{
    .data = sDexNavNoDataSymbolTiles,
    .size = 32 * 32,
    .tag = ICON_GFX_TAG
};
*/

/*
static const struct SpriteSheet CursorGFX = {(void*) gInterfaceGfx_selectionCursorTiles, 32 * 32, SELECTION_CURSOR_TAG};
static const struct SpritePalette CursorPal = {(void*) gInterfaceGfx_selectionCursorPal, SELECTION_CURSOR_TAG};

static const struct SpriteTemplate CursorTemp =
{
    .tileTag = SELECTION_CURSOR_TAG,
    .paletteTag = SELECTION_CURSOR_TAG,
    .oam = &CursorOAM,
    .anims =  gDummySpriteAnimTable,
    .images = (const struct SpriteFrameImage *) &CursorGFX,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sIconTemplate =
{
    .tileTag = ICON_GFX_TAG,
    .paletteTag = ICON_PAL_TAG,
    .oam = &IconOAM,
    .anims =  gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
*/

// functions
u32 MathMin(u32 num1, u32 num2)
{
	if (num1 < num2)
		return num1;

	return num2;
}

void VblackCallbackSeq(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void ClearHandlers(void)
{
    SetVBlankCallback((void*) 0);
    SetHBlankCallback((void*) 0);
    SetMainCallback1((void*) 0);
    SetMainCallback2((void*) 0);
}

void DexNavGUICallback2(void)
{
    BuildOamBuffer();
    AnimateSprites();
    UpdatePaletteFade();
    RunTasks();
    do_scheduled_bg_tilemap_copies_to_vram();
    // merge textbox and text tile maps
    RunTextPrinters();
}

void FillPalBufferBlack(void)
{
    CpuFastFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
}

void ResetPalSettings(void)
{
    ResetPaletteFade();
    FillPalBufferBlack();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 0;
}

void ResetBgSettings(void)
{
    CleanupOverworldWindowsAndTilemaps();
    ResetBgsAndClearDma3BusyFlags(0);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

void Setup(void)
{
    u32 set;
    
    ClearHandlers();    // callbacks
    ResetBgSettings();    // BGs
    ResetPalSettings();    // pals
    ResetSpriteData();    // objs
    FreeSpriteTileRanges();
    set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));     // VRAM clear
    InitHeap((void*) 0x2000000, 0x1C000);
    ResetTasks();
}

void DexNavGuiSetup(void)
{
    u32 set;
    
    Setup();
    FreeAllWindowBuffers();
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, (struct BgTemplate *)&BgConfigDexNavGUI, 4);
    set = 0;
    CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));
    HideBg(1);
    HideBg(0);
    SetMainCallback2(DexNavGUICallback2);
    SetVBlankCallback(VblackCallbackSeq);
}

#define LAND_ROW_LENGTH (6 * 2)
#define LAND_FIRST_ROW_LAST_INDEX (5 * 2)
#define LAND_SECOND_ROW_LAST_INDEX (LAND_FIRST_ROW_LAST_INDEX + LAND_ROW_LENGTH)
#define LAND_SECOND_ROW_FIRST_INDEX (6 * 2)
#define WATER_ROW_LAST_INDEX (4 * 2)
#define ROW_MON_LENGTH 2
void DexNavGuiHandler(void)
{
    //u16 species;
    void* DexNav_gbackBuffer = malloc(0x800);
    
    switch(gMain.state)
    {
        case 0:
            if (!gPaletteFade->active)
            {
                DexNavGuiSetup();
                SetMainCallback1(DexNavGuiHandler);
                // allocate dexnav struct
                sDNavState = AllocZeroed(sizeof(struct DexnavHudData));
                gMain.state++;
            }
            break;
        case 1:
            //Load BG assets
            sDNavState->backBuffer = &DexNav_gbackBuffer;
            LoadPalette(&DexNavTextPal, 15 * 16, 32);
            LoadCompressedPalette(sDexnavGuiPal, 0, 32);

            LZ77UnCompWram(sDexnavGuiTilemap, DexNav_gbackBuffer);
            LZ77UnCompVram(sDexnavGuiTiles, (void *)VRAM);
            SetBgTilemapBuffer(1, DexNav_gbackBuffer);
            BgIdMarkForSync(1);
            BgIdMarkForSync(0);
            gMain.state++;
            break;
        case 2:
            InitWindows(sDexNavWindows);
            //DexNavPopulateEncounterList();
            //DexNavLoadNames(1);
            gMain.state++;
            break;
        case 3:
           // REG_DISPCNT = 0x7F60;
            //REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
             //               WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
            //WRITE_REG_BLDCNT(0x401E);
            //REG_BLDCNT = BLDALPHA_BUILD(BLDCNT_BG1_SRC | BLDCNT_BG2_SRC | BLDCNT_BG3_SRC | BLDCNT_SPRITES_SRC, 0);

            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0x0000);
            ShowBg(0);
            ShowBg(1);
            //DexNavLoadPokeIcons();
            //SpawnPointerArrow();
            //DexNavLoadCapturedAllSymbol();
            sDNavState->selectedArr = ROW_LAND;
            sDNavState->selectedIndex = 0;
            gMain.state++;
            break;
        case 4:
            /*
            if (!gPaletteFade->active)
            {
                switch (gMain.newAndRepeatedKeys & (A_BUTTON | B_BUTTON | DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT | R_BUTTON))
                {
                    case A_BUTTON:
                    case B_BUTTON:
                        // exit to start menu
                        SetMainCallback1(DexNavGuiExitNoSearch);
                        gMain.state = 0;
                        return;
                    case DPAD_DOWN:
                        if (sDNavState->selectedArr == ROW_LAND)
                        {
                            if (sDNavState->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDNavState->selectedIndex = MathMin(sDNavState->selectedIndex - LAND_ROW_LENGTH, WATER_ROW_LAST_INDEX);
                                sDNavState->selectedArr = ROW_WATER;
                            }
                            else
                            {
                                sDNavState->selectedIndex += LAND_ROW_LENGTH; //Move to second row of land
                            }
                        }
                        else //ROW_WATER
                        {
                            sDNavState->selectedArr = ROW_LAND; //Keep index the same
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_Z_SCROLL);
                        break;

                    case DPAD_UP:
                        if (sDNavState->selectedArr == ROW_LAND)
                        {
                            if (sDNavState->selectedIndex >= LAND_SECOND_ROW_FIRST_INDEX)
                            {
                                sDNavState->selectedIndex -= LAND_ROW_LENGTH; //Move to first row of land
                            }
                            else
                            {
                                sDNavState->selectedIndex = MathMin(sDNavState->selectedIndex, WATER_ROW_LAST_INDEX);
                                sDNavState->selectedArr = ROW_WATER;
                            }
                        }
                        else //ROW_WATER
                        {
                            sDNavState->selectedArr = ROW_LAND;
                            sDNavState->selectedIndex += LAND_ROW_LENGTH; //So be on the second row
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_Z_SCROLL);
                        break;

                    case DPAD_LEFT:
                        // wrap cursor around
                        if (sDNavState->selectedArr == ROW_WATER)
                            sDNavState->selectedIndex = (sDNavState->selectedIndex == 0) ? WATER_ROW_LAST_INDEX : sDNavState->selectedIndex - ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDNavState->selectedIndex == 0 || sDNavState->selectedIndex == LAND_SECOND_ROW_FIRST_INDEX)
                                sDNavState->selectedIndex += LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDNavState->selectedIndex -= ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_Z_SCROLL);
                        break;
                    case DPAD_RIGHT:
                        if (sDNavState->selectedArr == ROW_WATER)
                            sDNavState->selectedIndex = (sDNavState->selectedIndex == WATER_ROW_LAST_INDEX) ? 0 : sDNavState->selectedIndex + ROW_MON_LENGTH;
                        else //ROW_LAND
                        {
                            if (sDNavState->selectedIndex == LAND_FIRST_ROW_LAST_INDEX || sDNavState->selectedIndex == LAND_SECOND_ROW_LAST_INDEX)
                                sDNavState->selectedIndex -= LAND_FIRST_ROW_LAST_INDEX; //Wrap around
                            else
                                sDNavState->selectedIndex += ROW_MON_LENGTH;
                        }
                        DexNavLoadNames(1);
                        PlaySE(SE_Z_SCROLL);
                        break;
                    case R_BUTTON:
                    {
                        // check selection is valid. Play sound if invalid
                        u16 species = sDNavState->selectedArr ? sDNavState->waterSpecies[sDNavState->selectedIndex / 2] : sDNavState->grassSpecies[sDNavState->selectedIndex / 2];
                        // if species is MISSINGNO then error
                        if (species != SPECIES_NONE)
                        {
                            if (species == SPECIES_UNOWN)
                            {
                                u8 letter = sDNavState->unownFormsByDNavIndices[sDNavState->selectedIndex / 2] - 1;
                                if (letter > 0)
                                    species = SPECIES_UNOWN_B + letter - 1;
                            }

                            // species was valid
                            DexNavLoadNames(2);
                            PlaySE(SE_Z_SEARCH);
                            // create value to store in a var
                            VarSet(VAR_DEXNAV, (sDNavState->selectedArr << 15) | species);
                        }
                        else
                        {
                            // beep and update
                            DexNavLoadNames(0);
                            PlaySE(SE_HAZURE);
                        }
                        break;
                    }
                    default:
                        return;
                }
                UpdateCursorPosition();
            }
            */
            break;
    }
}

u8 ExecDexNav(void)
{
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0x0000);
	SetMainCallback1(DexNavGuiHandler);
	gMain.state = 0;
	return TRUE;
};

