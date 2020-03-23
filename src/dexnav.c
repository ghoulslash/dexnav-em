#include "config.h"
#include "defines.h"

#define ROW_LAND 0
#define ROW_WATER 1

#define LAND_ROW_LENGTH (6 * 2)
#define LAND_FIRST_ROW_LAST_INDEX (5 * 2)
#define LAND_SECOND_ROW_LAST_INDEX (LAND_FIRST_ROW_LAST_INDEX + LAND_ROW_LENGTH)
#define LAND_SECOND_ROW_FIRST_INDEX (6 * 2)
#define WATER_ROW_LAST_INDEX (4 * 2)
#define ROW_MON_LENGTH 2

// DATA
// IMAGES
extern const u8 gInterfaceGfx_dexnavGuiTiles[];
extern const u8 gInterfaceGfx_dexnavGuiMap[];
extern const u8 gInterfaceGfx_dexnavGuiPal[];
extern const u8 gInterfaceGfx_selectionCursorTiles[];
extern const u8 gInterfaceGfx_selectionCursorPal[];

// STRINGS
extern const u8 gText_DexNavText[];
extern const u8 gText_DexNavWater[];
extern const u8 gText_DexNavLand[];
extern const u8 gText_PinkFlowers[];
extern const u8 gText_YellowFlowers[];
extern const u8 gText_RedFlowers[];
extern const u8 gText_BlueFlowers[];
extern const u8 gText_PinkAndPurpleFlowers[];
extern const u8 gText_BlueAndYellowFlowers[];
extern const u8 gText_Magma[];
extern const u8 gText_PokeTools[];
extern const u8 gText_GotAway[];
extern const u8 gText_LostSignal[];
extern const u8 gText_GotAwayShouldSneak[];
extern const u8 gText_CannotBeFound[];
extern const u8 gText_NotFoundNearby[];
extern const u8 gText_DexNavBack[];
extern const u8 gText_DexNav_NoInfo[];
extern const u8 gText_DexNav_CaptureToSee[];
extern const u8 gText_DexNav_ChooseMon[];
extern const u8 gText_DexNav_Invalid[];
extern const u8 gText_DexNav_NoDataForSlot[];
extern const u8 gText_DexNav_Locked[];

// TYPEDEFS
typedef void (*SuperCallback)(void);
typedef void (*SpriteCallback)(struct Sprite* s);

// DEFINES
#define TILE_SIZE 32
#define priv0 gTasks[taskId].data[0]

#define CPUFSCPY 0
#define CPUFSSET 1
#define CPUModeFS(size, mode) ((size >> 2) | (mode << 24))

#define SCANSTART_X 0
#define SCANSTART_Y 0
#define SCANSIZE_X 12
#define SCANSIZE_Y 12
//extern void CpuFastSet(void* src, void* dst, u32 mode);

#define ICON_PAL_TAG 0xDAC0
#define ICON_GFX_TAG 0xD75A
#define SELECTION_CURSOR_TAG 0x200

#define NUM_LAND_MONS 12
#define NUM_WATER_MONS 5

// STRUCTS
//static const struct TextColor MenuTextBlack = {0, 2, 3};
//static const struct WindowTemplate Tbox = {0, 2, 2, 10, TOOL_COUNT << 1, 0xF, 0x130};
static const struct TextColor DexNav_BlackText = {0, 3, 4};
static const struct TextColor DexNav_WhiteText = {0, 1, 2};
//static const struct TextColor DexNav_RedText = {0, 7, 8};
//static const struct TextColor DexNav_GreenText = {0, 5, 6};

// 203CF80
struct DexnavHudData
{
    /*
	u16 species;
    u16 moveId[MAX_MON_MOVES];
    u16 heldItem;
    u8 ability;
    u8 potential;
    u8 searchLevel;
    u8 pokemonLevel;
    u8 moveNameLength;
    u8 proximity;
    u8 environment;
	u8 unownLetter;
    s16 tileX; // position of shaking grass
    s16 tileY;
    u8 objIdSpecies;
    u8 objIdBlackBar[4];
    u8 objIdSight;
    u8 objIdAbility;
    u8 objIdMove;
    u8 objIdItem;
    u8 objIdShakingGrass;
    u8 objIdPotential[3];
    u8 movementTimes;
	*/
    // GUI data
    u8 selectedIndex;
    u8 selectedArr;
    u16 grassSpecies[NUM_LAND_MONS];
    u16 waterSpecies[NUM_WATER_MONS];
	//u16 hiddenSpecies[NUM_LAND_MONS + 1];
	//u8 unownForms[NUM_LAND_MONS];
	//u8 unownFormsByDNavIndices[NUM_LAND_MONS];
	u8 numGrassMons;
	u8 numWaterMons;
	//u8 numHiddenLandMons;
	//u8 numHiddenWaterMons;
    u8 cursorId;
    //u8 objids[17];
    void* backBuffer;
};

/*
struct OieState2
{
    const struct SpritePalette* p;
    SuperCallback s;
};
*/

static const struct BgTemplate BgConfigDexNavGUI[4] =
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
    },
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

enum
{
	WINDOW_SPECIES,
	WINDOW_ABILITY_1,
	WINDOW_ABILITY_2,
	WINDOW_ITEM_1,
	WINDOW_ITEM_2,
	WINDOW_HOENN,
	WINDOW_WATER,
	WINDOW_LAND,
	WINDOW_MAP_NAME,
	WINDOW_COUNT,
};


//extern const struct WindowTemplate sDexNavWindows[];
static const struct WindowTemplate sDexNavWindows[] =
{
	[WINDOW_SPECIES] =
	{
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
	},

	[WINDOW_ABILITY_1] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 5,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 19,
    },

	[WINDOW_ABILITY_2] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 8,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 64,
    },

	[WINDOW_ITEM_1] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 11,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 91,
    },
	
	[WINDOW_ITEM_2] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 14,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 120,
    },

	[WINDOW_HOENN] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 17,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 150,
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

	[WINDOW_COUNT] =
    {
        .bg = 0xFF, // marks the end of the tb array
    },

};

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

static void ResetGPU(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BG3CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0CNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG2VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG1VOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0HOFS, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG0VOFS, DISPCNT_MODE_0);
}

static void ClearHandlers(void)
{
    SetVBlankCallback(NULL);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetGPU();
}

void DexNavGUICallback2(void)
{
    BuildOamBuffer();
    AnimateSprites();
    UpdatePaletteFade();
    RunTasks();
    do_scheduled_bg_tilemap_copies_to_vram();
    // merge textbox and text tile maps
    //RunTextPrinters();
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
	ClearHandlers();	// callbacks
	ResetBgSettings();	// BGs
	ResetPalSettings();	// pals
	ResetSpriteData();	// objs
	FreeSpriteTileRanges();
	u32 set = 0;
	CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET)); 	// VRAM clear
	// gTasks
	InitHeap((void*) 0x2000000, 0x1C000);
	ResetTasks();
}

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

void UpdateCursorPosition(void)
{
    struct Sprite *sprite = &gSprites[sDNavState->cursorId];
	
	// update cursor position
    if (sDNavState->selectedArr != ROW_LAND)
    {
        // water
        sprite->pos1.x = CursorPositions2[sDNavState->selectedIndex];
        sprite->pos1.y = CursorPositions2[sDNavState->selectedIndex + 1];
    }
    else
    {
        // grass
        sprite->pos1.x = CursorPositions1[sDNavState->selectedIndex];
        sprite->pos1.y = CursorPositions1[sDNavState->selectedIndex + 1];
    }
	
	/*
	switch (gSprites[sDNavState->cursorId].data[0])
	{
	case 0:
		sprite->pos1.x = 30 + (24 * gSprites[sDNavState->cursorId].data[1]);
		sprite->pos1.y = 48;
		break;
	case 1:
		sprite->pos1.x = 20 + (12 * gSprites[sDNavState->cursorId].data[1]);
		sprite->pos1.y = 92;
		break;
	case 2:
		sprite->pos1.x = 20 + (12 * gSprites[sDNavState->cursorId].data[1]);
		sprite->pos1.y = 92 + 28;
		break;
	} 
	
	//sprite->pos1.x = sCursorXPositions[gSprites[sDNavState->cursorId].data[0]][gSprites[sDNavState->cursorId].data[1]];
	//sprite->pos1.y = sCursorRowYPositions[gSprites[sDNavState->cursorId].data[0]];
	*/
}

//extern const struct SpriteTemplate gSpriteTemplate_857BA68[];
//extern const struct SpriteTemplate gSpriteTemplate_857BA50[];
/*
static const struct SpriteTemplate gSpriteTemplate_857BA68 =
{
    .tileTag = TAG_TILE_1,
    .paletteTag = TAG_PAL_WAVEFORM,
    .oam = &sOamData_857BA14,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
*/

//extern const u32 gHandCursorTiles[];
//extern const u32 gHandCursorShadowTiles[];
//extern const u32 gHandCursorPalette[];

static const struct SpriteSheet CursorGFX = {(void*) gInterfaceGfx_selectionCursorTiles, 32 * 32, SELECTION_CURSOR_TAG};
static const struct SpritePalette CursorPal = {(void*) gInterfaceGfx_selectionCursorPal, SELECTION_CURSOR_TAG};
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
void CursorDummy(unusedArg struct Sprite *sprite)
{
}
static const struct SpriteTemplate CursorTemp =
{
	.tileTag = SELECTION_CURSOR_TAG,
	.paletteTag = SELECTION_CURSOR_TAG,
	.oam = (struct OamData*) &CursorOAM,
	.anims = (const union AnimCmd* const*) gDummySpriteAnimTable,
	.images = (const struct SpriteFrameImage *) &CursorGFX,
	.affineAnims = (const union AffineAnimCmd* const*) gDummySpriteAffineAnimTable,
	.callback = CursorDummy,
};

void SpawnPointerArrow(void)
{

    
    //// uncompressed
    LoadSpriteSheet(&CursorGFX);
    LoadSpritePalette(&CursorPal);
    sDNavState->cursorId = CreateSprite(&CursorTemp, 30, 48, 0);
    UpdateCursorPosition();
}

void DexNavGuiExitNoSearch(void)
{
    switch (gMain.state)
    {
        case 0:
            BeginNormalPaletteFade(~0, 0, 0x0, 0x10, 0);
            gMain.state += 1;
            break;
        case 1:
            if (!(gPaletteFade->active))
            {
                Free(sDNavState->backBuffer);
                Free(sDNavState);
                gMain.state += 1;
            }
            break;
        case 2:
            //m4aMPlayVolumeControl(gMPlayInfo_BGM, 0xFFFF, 256); // to do: this breaks the dexnav somehow..??
            SetMainCallback1(CB1_Overworld);
            FlagSet(FLAG_POKETOOLS_MENU);
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
            break;
    }
}

//extern struct OamData* sMonIconOamData;

void DexNavLoadPokeIcons(void)
{
	s16 x, y;
	u32 pid = 0xFFFFFFFF;
	//u8 hiddenLandMons = sDNavState->numHiddenLandMons;
	//u8 hiddenWaterMons = sDNavState->numHiddenWaterMons;

	LoadMonIconPalettes();

	for (u8 i = 0; i < NUM_LAND_MONS; ++i)
	{
		u16 species = sDNavState->grassSpecies[i];
		if (i > 5)
		{
			y = 92 + 28;
			x = 20 + 24 * (i - 6);
		}
		else
		{
			y = 92;
			x = 20 + 24 * i;
		}
		//x = 20 + (24 * (i % 6));
		//y = 92 + (i > 5 ? 28 : 0);
		
		/*
		if (species == SPECIES_NONE)
		{
			if (hiddenLandMons == 0)
			{
				CreateNoDataIcon(x, y);
				continue;
			}
			else
				hiddenLandMons--;
		}
		*/
		if (species != SPECIES_NONE)
		{
			if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
				CreateMonIcon(SPECIES_TREECKO - 1, SpriteCB_MonIcon, x, y, 1, pid, 0);		
			else
				CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
		}
	}

	for (u8 i = 0; i < NUM_WATER_MONS; ++i)
	{
		u16 species = sDNavState->waterSpecies[i];
		x = 30 + 24 * i;
		y = 48;

		/*
		if (species == SPECIES_NONE)
		{
			if (hiddenWaterMons == 0)
			{
				CreateNoDataIcon(x, y);
				continue;
			}
			else
				hiddenWaterMons--;
		}
		*/
	
		if (species != SPECIES_NONE)
		{
			if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_SEEN))
				CreateMonIcon(SPECIES_TREECKO - 1, SpriteCB_MonIcon, x, y, 1, pid, 0);		
			else
				CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, pid, 0);
		}
		//CreateMonIcon(3, SpriteCB_MonIcon, x, y, 0, pid, 0);
	}
}

bool8 SpeciesInArray(u16 species, u8 indexCount)
{
    u16 dexNum = SpeciesToNationalPokedexNum(species);
	//Disallow species not seen
	/*
	if (!GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
	{
		for (int i = 0; i < NUM_LAND_MONS; ++i)
		{
			if (sDNavState->hiddenSpecies[i] == SPECIES_TABLES_TERMIN)
			{
				sDNavState->hiddenSpecies[i] = dexNum;
				sDNavState->hiddenSpecies[i + 1] = SPECIES_TABLES_TERMIN;
				break;
			}
			else if (sDNavState->hiddenSpecies[i] == dexNum) //Already in array
			{
                return TRUE;
            }
		}

		if (indexCount == NUM_LAND_MONS)
			sDNavState->numHiddenLandMons++; //Increase how many question marks to print
		else
			sDNavState->numHiddenWaterMons++;

		return TRUE;
	}
	*/
	
	// seen species -> only add if unique
	for (u8 i = 0; i < indexCount; ++i)
	{
		if (indexCount == NUM_LAND_MONS)
		{
			if (SpeciesToNationalPokedexNum(sDNavState->grassSpecies[i]) == dexNum)
				return TRUE;
		}
		else
		{
			if (SpeciesToNationalPokedexNum(sDNavState->waterSpecies[i]) == dexNum)
				return TRUE;
		}
	}

	return FALSE;
}

void DexNavPopulateEncounterList(void)
{
	// nop struct data
	Memset(sDNavState->grassSpecies, 0, sizeof(sDNavState->grassSpecies)
									  + sizeof(sDNavState->waterSpecies));
									  
	//sDNavState->numGrassMons = 0;
	//sDNavState->numWaterMons = 0;
	//sDNavState->numHiddenLandMons = 0;
	//sDNavState->numHiddenWaterMons = 0;

	// populate unique wild grass encounters
	u8 grassIndex = 0;
	u8 waterIndex = 0;
	u16 species;

	//const struct WildPokemonInfo* landMonsInfo = LoadProperMonsData(LAND_MONS_HEADER);
	//const struct WildPokemonInfo* waterMonsInfo = LoadProperMonsData(WATER_MONS_HEADER);

	u16 headerId = GetCurrentMapWildMonHeaderId();
	//if (headerId == 0xFFFF)
	//	return;
	
	const struct WildPokemonInfo* landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
	const struct WildPokemonInfo* waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;


	//sDNavState->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

	if (landMonsInfo != NULL)
	{
		for (int i = 0; i < NUM_LAND_MONS; ++i)
		{
			species = landMonsInfo->wildPokemon[i].species;
			if (species != SPECIES_NONE && !(SpeciesInArray(species, NUM_LAND_MONS)))
			//if (species != SPECIES_NONE)
			{
				sDNavState->grassSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;
				
				//sDNavState->grassSpecies[grassIndex++] = landMonsInfo->wildPokemon[i].species;
			}
		}
	}

	//sDNavState->hiddenSpecies[0] = SPECIES_TABLES_TERMIN;

	if (waterMonsInfo != NULL)
	{
		for (int i = 0; i < NUM_WATER_MONS; ++i)
		{
			species = waterMonsInfo->wildPokemon[i].species;
			if (species != SPECIES_NONE && !(SpeciesInArray(species, NUM_WATER_MONS)))
			//if (species != SPECIES_NONE)
			{
				sDNavState->waterSpecies[waterIndex++] = waterMonsInfo->wildPokemon[i].species;
			}
		}
	}

	sDNavState->numGrassMons = grassIndex;
	sDNavState->numWaterMons = waterIndex;
};

#define MAP_IS(map) (gSaveBlock1->location.mapGroup == MAP_GROUP(map) && gSaveBlock1->location.mapNum == MAP_NUM(map))
void DexNavLoadAreaNames(void)
{
	const u8* landText;
	const u8* waterText;

	landText = gText_DexNavLand;
	waterText = gText_DexNavWater;
	
	AddTextPrinterParameterized3(WINDOW_WATER, 1, 4, 6, &DexNav_WhiteText, 0, waterText);
	AddTextPrinterParameterized3(WINDOW_LAND, 1, 5, 6, &DexNav_WhiteText, 0, landText);
};

extern const u8 gText_Yes[];
extern const u8 gText_No[];
void DexNavPrintMonInfo(void)
{	
	FillWindowPixelBuffer(WINDOW_SPECIES, 0);
	FillWindowPixelBuffer(WINDOW_ABILITY_1, 0);
	FillWindowPixelBuffer(WINDOW_ABILITY_2, 0);
	FillWindowPixelBuffer(WINDOW_ITEM_1, 0);
	FillWindowPixelBuffer(WINDOW_ITEM_2, 0);
	FillWindowPixelBuffer(WINDOW_HOENN, 0);
		
	u16 species = sDNavState->selectedArr == ROW_WATER ? sDNavState->waterSpecies[sDNavState->selectedIndex >> 1] : sDNavState->grassSpecies[sDNavState->selectedIndex >> 1];
	u16 dexNum = SpeciesToNationalPokedexNum(species);
	
	if (species != SPECIES_NONE && GetSetPokedexFlag(dexNum, FLAG_GET_SEEN))
	{
		// species
		AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, &DexNav_BlackText, 0, gSpeciesNames[species]);
		
		// abilities
		AddTextPrinterParameterized3(WINDOW_ABILITY_1, 0, 0, 4, &DexNav_BlackText, 0, gAbilityNames[gBaseStats[species].ability1]);
		if (gBaseStats[species].ability2 != ABILITY_NONE)
			AddTextPrinterParameterized3(WINDOW_ABILITY_2, 0, 0, 4, &DexNav_BlackText, 0, gAbilityNames[gBaseStats[species].ability2]);
		else
			AddTextPrinterParameterized3(WINDOW_ABILITY_2, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		
		// items
		if (gBaseStats[species].item1 != ITEM_NONE)
			CopyItemName(gBaseStats[species].item1, gStringVar4);
		else
			StringCopy(gStringVar4, gText_DexNav_NoInfo);
		
		AddTextPrinterParameterized3(WINDOW_ITEM_1, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);
		if (gBaseStats[species].item2 != ITEM_NONE)
			CopyItemName(gBaseStats[species].item2, gStringVar4);
		else
			StringCopy(gStringVar4, gText_DexNav_NoInfo);
		
		AddTextPrinterParameterized3(WINDOW_ITEM_2, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);
		
		// captured
		if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT))
			StringCopy(gStringVar4, gText_Yes);
		else
			StringCopy(gStringVar4, gText_No);
		
		AddTextPrinterParameterized3(WINDOW_HOENN, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);
	}
	else
	{
		AddTextPrinterParameterized3(WINDOW_SPECIES, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		AddTextPrinterParameterized3(WINDOW_ABILITY_1, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		AddTextPrinterParameterized3(WINDOW_ABILITY_2, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		AddTextPrinterParameterized3(WINDOW_ITEM_1, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		AddTextPrinterParameterized3(WINDOW_ITEM_2, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
		AddTextPrinterParameterized3(WINDOW_HOENN, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
	}
	
	CopyWindowToVram(WINDOW_SPECIES, 3);
	PutWindowTilemap(WINDOW_SPECIES);
	
	CopyWindowToVram(WINDOW_ABILITY_1, 3);
	PutWindowTilemap(WINDOW_ABILITY_1);
	
	CopyWindowToVram(WINDOW_ABILITY_2, 3);
	PutWindowTilemap(WINDOW_ABILITY_2);
	
	CopyWindowToVram(WINDOW_ITEM_1, 3);
	PutWindowTilemap(WINDOW_ITEM_1);
	
	CopyWindowToVram(WINDOW_ITEM_2, 3);
	PutWindowTilemap(WINDOW_ITEM_2);
	
	CopyWindowToVram(WINDOW_HOENN, 3);
	PutWindowTilemap(WINDOW_HOENN);
	
}

void DexNavLoadNames(void)
{
	//u16 species;
	// clean boxes
	for (int i = 0; i < WINDOW_COUNT; ++i)
	{
		FillWindowPixelBuffer(i, 0);
	}

	DexNavPrintMonInfo();

	/*
	//Print search level
	ConvertIntToDecimalStringN(gStringVar4, sSearchLevels[dexNum], 0, 4);

	if (species == SPECIES_NONE)
		AddTextPrinterParameterized3(WINDOW_ABILITY_1, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
	else
		AddTextPrinterParameterized3(WINDOW_ABILITY_1, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);

	//Print level bonus
	u8 searchLevelBonus = 0;
	if ((sSearchLevels[dexNum] >> 2) > 20)
		searchLevelBonus = 20;
	else
		searchLevelBonus = (sSearchLevels[dexNum] >> 2);

	ConvertIntToDecimalStringN(gStringVar4, searchLevelBonus, 0, 4);

	if (species == SPECIES_NONE)
		AddTextPrinterParameterized3(WINDOW_ITEM_1, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
	else
		AddTextPrinterParameterized3(WINDOW_ITEM_1, 0, 0, 4, &DexNav_BlackText, 0, gStringVar4);

	//Print hidden ability name
	if (GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT) || species == SPECIES_NONE)
	{
		if (gBaseStats[species].hiddenAbility != ABILITY_NONE) //Only display hidden ability is Pokemon has been caught
			AddTextPrinterParameterized3(WINDOW_HOENN, 0, 0, 4, &DexNav_BlackText, 0, GetAbilityName(gBaseStats[species].hiddenAbility));
		else
			AddTextPrinterParameterized3(WINDOW_HOENN, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_NoInfo);
	}
	else
		AddTextPrinterParameterized3(WINDOW_HOENN, 0, 0, 4, &DexNav_BlackText, 0, gText_DexNav_CaptureToSee);

	*/
	
	//Print status message bar
	/*
	switch(status)
	{
		case 0:
			AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, gText_DexNav_Invalid);
			break;
		case 1:
			AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, gText_DexNav_ChooseMon);
			break;
		case 2:
			AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, gText_DexNav_Locked);
			break;
		case 3:
			AddTextPrinterParameterized3(WINDOW_REPLY_TEXT, 1, 2, 8, &DexNav_WhiteText, 0, gText_DexNav_NoDataForSlot);
			break;
	}
	*/

	//Load area names
	DexNavLoadAreaNames();

	//Load map name
	GetMapName(gStringVar4, GetCurrentRegionMapSectionId(), 0);
	AddTextPrinterParameterized3(WINDOW_MAP_NAME, 1, 2, 0, &DexNav_WhiteText, 0, gStringVar4);

	// display committed gfx
	for (u8 i = 0; i < WINDOW_COUNT; ++i)
	{
		CopyWindowToVram(i, 3);
		PutWindowTilemap(i);
	}
}

/*
void HandleKeyPresses(u8 taskId)
{
	//struct Sprite *sprite = &gSprites[sDNavState->cursorId];
	
	if (!gPaletteFade->active)
	{
		switch (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT))
		{
			case A_BUTTON:
			case B_BUTTON:
				// exit to start menu
				//DestroyTask(taskId);
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
				DexNavPrintMonInfo();
				//PlaySE(SE_BAG1);
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
				DexNavPrintMonInfo();
				//PlaySE(SE_BAG1);
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
				DexNavPrintMonInfo();
				//PlaySE(SE_BAG1);
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
				DexNavPrintMonInfo();
				//PlaySE(SE_BAG1);
				break;
			default:
				return;
		}
		UpdateCursorPosition();
	} // pal fade
}
*/


void DexNavGuiSetup(void)
{
	Setup();
	FreeAllWindowBuffers();
	ChangeBgX(0, 0, 0);
	ChangeBgY(0, 0, 0);
	ChangeBgX(1, 0, 0);
	ChangeBgY(1, 0, 0);
	ResetBgsAndClearDma3BusyFlags(0);
	InitBgsFromTemplates(0, (struct BgTemplate *)&BgConfigDexNavGUI, 4);
	u32 set = 0;
	CpuFastSet((void*)&set, (void*)VRAM, CPUModeFS(0x10000, CPUFSSET));
	HideBg(1);
	HideBg(0);
	SetMainCallback2(DexNavGUICallback2);
	SetVBlankCallback(VblackCallbackSeq);
};

static void DexNavGuiHandler(void)
{
	switch(gMain.state)
	{
		case 0:
			if (!gPaletteFade->active)
			{
				DexNavGuiSetup();
				SetMainCallback1(DexNavGuiHandler);
				// allocate dexnav struct
				sDNavState = Calloc(sizeof(struct DexnavHudData));
				gMain.state += 1;
			}
			break;
		case 1: ;
			//Load BG assets
			void* DexNav_gbackBuffer = Malloc(0x800);
			sDNavState->backBuffer = DexNav_gbackBuffer;
			LoadPalette(&DexNavTextPal, 15 * 16, 32);
			const u8* palette = gInterfaceGfx_dexnavGuiPal;
			LoadCompressedPalette(palette, 0, 32);
			LZ77UnCompWram(gInterfaceGfx_dexnavGuiMap, DexNav_gbackBuffer);
			LZ77UnCompVram(gInterfaceGfx_dexnavGuiTiles, (void*) 0x06000000);
			SetBgTilemapBuffer(1, DexNav_gbackBuffer);
			BgIdMarkForSync(1);
			BgIdMarkForSync(0);
			gMain.state += 1;
			break;

		case 2:
			InitWindows(sDexNavWindows);
			DexNavPopulateEncounterList();
			DexNavLoadNames();
			gMain.state += 1;
			break;
		case 3:
		   // REG_DISPCNT = 0x7F60;
			//REG_WININ = WININ_BUILD(WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ, WIN_BG0 |
			 //			   WIN_BG1 | WIN_BG2 | WIN_BG3 | WIN_OBJ);
			//WRITE_REG_BLDCNT(0x401E);
			//REG_BLDCNT = BLDALPHA_BUILD(BLDCNT_BG1_SRC | BLDCNT_BG2_SRC | BLDCNT_BG3_SRC | BLDCNT_SPRITES_SRC, 0);

			BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0x0000);
			ShowBg(0);
			ShowBg(1);
			DexNavLoadPokeIcons();
			SpawnPointerArrow();
			//DexNavLoadCapturedAllSymbol();
			sDNavState->selectedArr = 0;
			sDNavState->selectedIndex = 0;
			gMain.state += 1;
			break;

		case 4:
			//CreateTask(HandleKeyPresses, 0);
			if (!gPaletteFade->active)
			{
				switch (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_DOWN | DPAD_UP | DPAD_LEFT | DPAD_RIGHT))
				{
					case A_BUTTON:
					case B_BUTTON:
						// exit to start menu
						//DestroyTask(taskId);
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
						DexNavPrintMonInfo();
						PlaySE(SE_BAG1);
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
						DexNavPrintMonInfo();
						PlaySE(SE_BAG1);
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
						DexNavPrintMonInfo();
						PlaySE(SE_BAG1);
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
						DexNavPrintMonInfo();
						PlaySE(SE_BAG1);
						break;
					default:
						return;
				}
				UpdateCursorPosition();
			};
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


