#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "config.h"
#include "gba/gba.h"
#include <string.h>

#define EVENT_OBJECTS_COUNT_1 16
#define EVENT_OBJECTS_COUNT_2 14
#define EVENT_OBJECTS_COUNT 30


// Define unused parameters
#define unusedArg __attribute__((unused))

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")

#if defined (__APPLE__) || defined (__CYGWIN__)
// Get the IDE to stfu

// We define it this way to fool preproc.
#define INCBIN(x) {0}
#define INCBIN_U8  INCBIN
#define INCBIN_U16 INCBIN
#define INCBIN_U32 INCBIN
#define INCBIN_S8  INCBIN
#define INCBIN_S16 INCBIN
#define INCBIN_S32 INCBIN
#define _(x) (x)
#define __(x) (x)
#endif // __APPLE__

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

// useful math macros

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

#define POKEMON_SLOTS_NUMBER 412
#define POKEMON_NAME_LENGTH 10
#define OT_NAME_LENGTH 7

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#define abs(x) (((x) < 0) ? -(x) : (x))

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. For example, diploma.c seems to declare rodata before each use while
// other files declare out of order and must be at the beginning. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8*) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void*) T2_READ_32(ptr)

// This macro is required to prevent the compiler from optimizing
// a dpad up/down check in sub_812CAD8 (fame_checker.c).
// We suspect it was used globally.
// GameFreak never ceases to amaze.
// TODO: Propagate use of this macro
#define TEST_BUTTON(field, button) ({(field) & (button);})
#define JOY_NEW(button) TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button)  TEST_BUTTON(gMain.heldKeys, button)

#define SPECIES_TABLES_TERMIN 0xFEFE
#define MOVE_TABLES_TERMIN 0xFEFE
#define ITEM_TABLES_TERMIN 0xFEFE
#define ABILITY_TABLES_TERMIN 0xFF
#define MOVE_EFFECT_TABLES_TERMIN 0xFF

extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

enum
{
    VERSION_SAPPHIRE = 1,
    VERSION_RUBY = 2,
    VERSION_EMERALD = 3,
    VERSION_FIRE_RED = 4,
    VERSION_LEAF_GREEN = 5,
};

enum LanguageId {
    LANGUAGE_JAPANESE = 1,
    LANGUAGE_ENGLISH = 2,
    LANGUAGE_FRENCH = 3,
    LANGUAGE_ITALIAN = 4,
    LANGUAGE_GERMAN = 5,
    // 6 goes unused but the theory is it was meant to be Korean
    LANGUAGE_SPANISH = 7,
};

#define GAME_LANGUAGE (LANGUAGE_ENGLISH)

#define PC_ITEMS_COUNT      30
#define BAG_ITEMS_COUNT     42
#define BAG_KEYITEMS_COUNT  30
#define BAG_POKEBALLS_COUNT 13
#define BAG_TMHM_COUNT      58
#define BAG_BERRIES_COUNT   43

enum
{
    MALE,
    FEMALE
};

enum
{
    OPTIONS_BUTTON_MODE_NORMAL,
    OPTIONS_BUTTON_MODE_LR,
    OPTIONS_BUTTON_MODE_L_EQUALS_A
};

enum
{
    OPTIONS_TEXT_SPEED_SLOW,
    OPTIONS_TEXT_SPEED_MID,
    OPTIONS_TEXT_SPEED_FAST
};

enum
{
    OPTIONS_SOUND_MONO,
    OPTIONS_SOUND_STEREO
};

enum
{
    OPTIONS_BATTLE_STYLE_SHIFT,
    OPTIONS_BATTLE_STYLE_SET
};

enum
{
	OPTIONS_NORMAL_DIFFICULTY,
	OPTIONS_EASY_DIFFICULTY,
	OPTIONS_HARD_DIFFICULTY,
	OPTIONS_EXPERT_DIFFICULTY,
};

enum
{
    BAG_ITEMS = 1,
    BAG_POKEBALLS,
    BAG_TMsHMs,
    BAG_BERRIES,
    BAG_KEYITEMS
};

enum
{
    POCKET_ITEMS = 1,
    POCKET_KEYITEMS,
	POCKET_POKEBALLS,
    POCKET_TM_HM,
    POCKET_BERRIES
};


struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct UCoords32
{
    u32 x;
    u32 y;
};

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

#define DEX_FLAGS_NO ((POKEMON_SLOTS_NUMBER / 8) + ((POKEMON_SLOTS_NUMBER % 8) ? 1 : 0))

struct Pokedex
{
    /*0x00*/ u8 order;
    /*0x01*/ u8 unknown1;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2;
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
    /*0x10*/ u8 owned[DEX_FLAGS_NO];
    /*0x44*/ u8 seen[DEX_FLAGS_NO];
};

struct PokemonJumpResults // possibly used in the game itself?
{
    u16 jumpsInRow;
    u16 field2;
    u16 excellentsInRow;
    u16 field6;
    u16 field8;
    u16 fieldA;
    u32 bestJumpScore;
};

struct BerryPickingResults // possibly used in the game itself? Size may be wrong as well
{
    u32 bestScore;
    u16 berriesPicked;
    u16 berriesPickedInRow;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
};

struct PyramidBag
{
    u16 items_Lvl50[10];
    u16 items_OpenLvl[10];
    u8 quantity[10];
};

struct BerryCrush
{
    u16 berryCrushResults[4];
    u32 berryPowderAmount;
    u32 unk;
};

#define PLAYER_NAME_LENGTH  8

struct UnknownSaveBlock2Struct
{
    u8 field_0;
    u8 field_1;
    u8 field_2[2];
    u8 field_4[8];
    u8 field_C[16];
    u16 field_1C[6];
    u16 field_28[6];
    u8 field_34[176];
    u8 field_E4;
    u8 field_E5;
    u8 field_E6;
    u8 field_E7;
    u8 field_E8;
    u8 field_E9;
    u8 field_EA;
    u8 field_EB;
}; // sizeof = 0xEC

struct UnkSaveBlock2Substruct_55C
{
    /* 0x000:0x55C */ u8 unk_00_0:1;
    u8 unk_00_1:1;
    /* 0x001:0x55D */ u8 unk_01;
    /* 0x002:0x55E */ u8 unk_02[2];
    /* 0x004:0x560 */ u16 unk_04[2];
    /* 0x008:0x564 */ u16 unk_08[2];
    /* 0x00C:0x568 */ u16 unk_0C[2];
    /* 0x010:0x56C */ u8 unk_10;
    /* 0x011:0x56D */ u8 unk_11[3];
    /* 0x014:0x570 */ u16 unk_14;
    /* 0x016:0x572 */ u8 unk_16;
}; // size: 0x018

#define LINK_B_RECORDS_COUNT 5

struct LinkBattleRecord
{
    u8 name[PLAYER_NAME_LENGTH];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
};

struct LinkBattleRecords
{
    struct LinkBattleRecord entries[LINK_B_RECORDS_COUNT];
    u8 languages[LINK_B_RECORDS_COUNT];
};

struct SaveBlock2
{
    /*0x000*/ u8 playerName[PLAYER_NAME_LENGTH];
    /*0x008*/ u8 playerGender; // MALE, FEMALE
    /*0x009*/ u8 specialSaveWarp;
	/*0x00A*/ u8 playerTrainerId[4];
    /*0x00E*/ u16 playTimeHours;
    /*0x010*/ u8 playTimeMinutes;
    /*0x011*/ u8 playTimeSeconds;
    /*0x012*/ u8 playTimeVBlanks;
    /*0x013*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x014*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
              u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
              u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
              u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
              u16 optionsBattleSceneOff:1; // whether battle animations are disabled
              u16 regionMapZoom:1; // whether the map is zoomed in
    /*0x018*/ struct Pokedex pokedex;
    /*0x090*/ u8 filler_90[0x8];
    /*0x098*/ struct Time localTimeOffset;
    /*0x0A0*/ struct Time lastBerryTreeUpdate;
    /*0x0A8*/ u32 field_A8;
    /*0x0AC*/ u8 filler_AC[0x3F4];
    /*0x4A0*/ u32 unk_4A0[0x2F];
    /*0x55c*/ struct UnkSaveBlock2Substruct_55C unk_55C;
    /*0x574*/ u8 filler_574[0x324];
    /*0x898*/ u16 mapView[0x100];
    /*0xA98*/ struct LinkBattleRecords linkBattleRecords;
    /*0xAF0*/ struct BerryCrush berryCrush;
    /*0xB00*/ u8 filler_B00[0x420];
    /*0xF20*/ u32 encryptionKey;
};

extern struct SaveBlock2 *gSaveBlock2Ptr;

#define PARTY_SIZE 6

struct SecretBaseParty
{
    u32 personality[PARTY_SIZE];
    u16 moves[PARTY_SIZE * 4];
    u16 species[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    u8 levels[PARTY_SIZE];
    u8 EVs[PARTY_SIZE];
};

struct SecretBaseRecord
{
    /*0x1A9C*/ u8 secretBaseId;
    /*0x1A9D*/ u8 sbr_field_1_0:4;
    /*0x1A9D*/ u8 gender:1;
    /*0x1A9D*/ u8 sbr_field_1_5:1;
    /*0x1A9D*/ u8 sbr_field_1_6:2;
    /*0x1A9E*/ u8 trainerName[7]; // TODO: Change PLAYER_NAME_LENGTH to 7
    /*0x1AA5*/ u8 trainerId[4]; // byte 0 is used for determining trainer class
    /*0x1AA9*/ u8 language;
    /*0x1AAA*/ u16 sbr_field_e;
    /*0x1AAC*/ u8 sbr_field_10;
    /*0x1AAD*/ u8 sbr_field_11;
    /*0x1AAE*/ u8 decorations[16];
    /*0x1ABE*/ u8 decorationPos[16];
    /*0x1AD0*/ struct SecretBaseParty party;
};

#include "constants/game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "pokemon.h"
#include "shop.h"

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct Pokeblock
{
    u8 color;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 feel;
};

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool8 active;
    /*0x14*/ u8 filler[0x8];
};

struct RoamerOld
{
    u32 ivs; //0x00
    u32 personality; //0x04
    u16 species; //0x08
    u16 hp; //0x0A
    u8 level; //0x0A
    u8 status; //0x0D
    u8 cool; //0x0E
    u8 beauty; //0x0F
    u8 cute; //0x10
    u8 smart; //0x11
    u8 tough; //0x12
    bool8 active; //0x13
    u8 filler[0x8]; //0x14
	//SIZE = 0x1C
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

struct EasyChatPair
{
    u16 unk0_0:7;
    u16 unk0_7:7;
    u16 unk1_6:1;
    u16 unk2;
    u16 words[2];
}; /*size = 0x8*/

struct __attribute__((packed)) MailStruct
{
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
	/*0x22*/ u16 _;
};

struct MailStructDaycare
{
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct UnkMauvilleOldManStruct
{
               u8 unk_2D94;
               u8 unk_2D95;
    /*0x2D96*/ u16 mauvilleOldMan_ecArray[6];
    /*0x2DA2*/ u16 mauvilleOldMan_ecArray2[6];
    /*0x2DAE*/ u8 playerName[8];
    /*0x2DB6*/ u8 filler_2DB6[0x3];
    /*0x2DB9*/ u8 playerTrainerId[4];
               u8 unk_2DBD;
}; /*size = 0x2C*/

struct UnkMauvilleOldManStruct2
{
    u8 filler0;
    u8 unk1;
    u8 unk2;
    u16 mauvilleOldMan_ecArray[10];
    u8 mauvilleOldMan_ecArray2[12];
    u8 fillerF[0x2];
}; /*size = 0x2C*/

struct MauvilleOldManTrader
{
    u8 unk0;
    u8 unk1[4];
    u8 unk5[4][11];
    u8 unk31;
};

typedef union OldMan
{
    struct UnkMauvilleOldManStruct oldMan1;
    struct UnkMauvilleOldManStruct2 oldMan2;
    struct MauvilleOldManTrader trader;
    u8 filler[0x3C];
} OldMan;

struct RecordMixing_UnknownStructSub
{
    u32 unk0;
    u8 data[0x34];
    //u8 data[0x38];
};

struct RecordMixing_UnknownStruct
{
    struct RecordMixing_UnknownStructSub data[2];
    u32 unk70;
    u16 unk74[0x2];
};

struct RecordMixingGiftData
{
    u8 unk0;
    u8 quantity;
    u16 itemId;
    u8 filler4[8];
};

struct RecordMixingGift
{
    int checksum;
    struct RecordMixingGiftData data;
};

struct ContestWinner
{
    u32 personality;
    u32 trainerId;
    u16 species;
    u8 contestCategory;
    u8 monName[11];
    u8 trainerName[8];
    u8 contestRank;
};

struct DayCareMail
{
    struct MailStructDaycare message;
    u8 OT_name[PLAYER_NAME_LENGTH + 1];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 gameLanguage:4;
    u8 monLanguage:4;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    struct DayCareMail mail;
    u32 steps;
};

#define DAYCARE_MON_COUNT 2

struct DayCare
{
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u16 offspringPersonality; //For some reason in FR this is a 16
    u8 stepCounter;
};

struct RecordMixingDayCareMail
{
    struct DayCareMail mail[DAYCARE_MON_COUNT];
    u32 numDaycareMons;
    bool16 holdsItem[DAYCARE_MON_COUNT];
};

struct MysteryEventStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:3;
    u8 unk_0_5:3;
    u8 unk_1;
};

struct QuestLogNPCData
{
    u32 x:8;
    u32 negx:1;
    u32 y:8;
    u32 negy:1;
    u32 elevation:6;
    u32 movementType:8;
};

struct UnkStruct_203B024
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04[14];
};

union QuestLogScene
{
    u8 allocation[32];
    u16 ident;
};

typedef union QuestLogScene QuestLogScene;

// This name is a complete guess and may change.

// Declare here so that it can be recursively referenced.
union QuestLogMovement;

// Define here
union QuestLogMovement
{
    u16 ident_raw;
    struct {
    	u16 ident:12;
    	u16 flags:4;
    } ident_struct;
};

struct QuestLog
{
    /*0x0000*/ u8 unk_000;
    /*0x0001*/ s8 unk_001;
    /*0x0002*/ s8 unk_002;
    /*0x0003*/ s8 unk_003;
    /*0x0004*/ s16 unk_004;
    /*0x0006*/ s16 unk_006;
    /*0x0008*/ u8 filler_008[0x140];

    // These arrays hold the game state for
    // playing back the quest log
    /*0x0148*/ u8 flags[0x120];
    /*0x02c8*/ u16 vars[0x100];
    /*0x0468*/ struct QuestLogNPCData npcData[64];
    /*0x0568*/ u16 unk_568[128];
    /*0x0668*/ u16 end[0];
};

#include "fame_checker.h"

struct FameCheckerSaveData
{
	/*3a54*/ u16 pickState:2;
	         u16 flavorTextFlags:12;
	         u16 unk_0_E:2;
};

#define NUM_EASY_CHAT_EXTRA_PHRASES 33
#define EASY_CHAT_EXTRA_PHRASES_SIZE 8


struct MEventBuffer_3120_Sub
{
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[40];
    u8 unk_2C[10][40];
};

struct MEventBuffer_3120
{
    u32 crc;
    struct MEventBuffer_3120_Sub data;
};

struct MEventBuffer_32E0_Sub
{
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u8 unk_08_0:2;
    u8 unk_08_2:4;
    u8 unk_08_6:2;
    u8 unk_09;
    u8 unk_0A[40];
    u8 unk_32[40];
    u8 unk_5A[4][40];
    u8 unk_FA[40];
    u8 unk_122[40];
};

struct MEventBuffer_32E0
{
    u32 crc;
    struct MEventBuffer_32E0_Sub data;
};

struct MEventBuffer_3430_Sub
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08[2][7];
};

struct MEventBuffer_3430
{
    u32 crc;
    struct MEventBuffer_3430_Sub data;
};

struct MENewsJisanStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:3;
    u8 unk_0_5:3;
    u8 berry;
};

struct MEventBuffers
{
    /*0x000 0x3120*/ struct MEventBuffer_3120 buffer_000;
    /*0x1c0 0x32e0*/ struct MEventBuffer_32E0 buffer_1c0;
    /*0x310 0x3430*/ struct MEventBuffer_3430 buffer_310;
    /*0x338 0x3458*/ u16 unk_338[4];
    /*0x340 0x3460*/ struct MENewsJisanStruct unk_340;
    /*0x344 0x3464*/ u32 unk_344[2][5];
}; // 0x36C 0x348C

struct TrainerTowerLog
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA_0:1;
    u8 unkA_1:1;
    u8 unkA_2:1;
    u8 unkA_3:1;
    u8 unkA_4:1;
    u8 unkA_5:1;
    u8 unkA_6:2;
};

struct TrainerRematchState
{
    u16 stepCounter;
    u8 rematches[100];
};

#define EVENT_OBJECT_TEMPLATES_COUNT 64
#define BERRY_TREES_COUNT  128
#define FLAGS_COUNT        288 // 300
#define VARS_COUNT         256
#define MAIL_COUNT         16


struct SaveBlock1
{
    /*0x0000*/ struct Coords16 pos;
    /*0x0004*/ struct WarpData location;
    /*0x000C*/ struct WarpData warp1;
    /*0x0014*/ struct WarpData warp2;
    /*0x001C*/ struct WarpData lastHealLocation;
    /*0x0024*/ struct WarpData warp4;
    /*0x002C*/ u16 savedMusic;
    /*0x002E*/ u8 weather;
    /*0x002F*/ u8 filler_2F;
    /*0x0030*/ u8 flashLevel;
    /*0x0032*/ u16 mapDataId;
    /*0x0034*/ u8 playerPartyCount;
    /*0x0038*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x0290*/ u32 money;
    /*0x0294*/ u16 coins;
    /*0x0296*/ u16 registeredItem; // registered for use with SELECT button
    /*0x0298*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x0310*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    /*0x03b8*/ struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    /*0x0430*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    /*0x0464*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    /*0x054c*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    /*0x05F8*/ u8 seen1[DEX_FLAGS_NO];
	/*0x062C*/ u16 berryBlenderRecords[3]; // unused
	/*0x0632*/ u8 field_632[6]; // unused?
    /*0x0638*/ u8 trainerRematchStepCounter;
    /*0x063A*/ u8 ALIGNED(2) trainerRematches[100];
    /*0x06A0*/ struct EventObject eventObjects[EVENT_OBJECTS_COUNT_1];
    /*0x08E0*/ struct EventObjectTemplate eventObjectTemplates[EVENT_OBJECT_TEMPLATES_COUNT];
    /*0x0EE0*/ u8 flags[FLAGS_COUNT];
    /*0x1000*/ u16 vars[VARS_COUNT];
    /*0x1200*/ u32 gameStats[NUM_GAME_STATS];
    /*0x1300*/ struct QuestLog questLog[4];
	/*0x2CA0*/ u16 unk2CA0[6];
	/*0x2CAC*/ u16 unk2CAC[6];
	/*0x2CB8*/ u16 unk2CB8[6];
	/*0x2CC4*/ u16 unk2CC4[6];
    /*0x2CD0*/ struct MailStruct mail[MAIL_COUNT];
    /*0x2F10*/ u8 additionalPhrases[EASY_CHAT_EXTRA_PHRASES_SIZE];
    /*0x2F18*/ OldMan oldMan; // unused
    /*0x2F54*/ struct EasyChatPair easyChatPairs[5]; // unused
    /*0x2F80*/ struct DayCare daycare;
    /*0x309C*/ u8 giftRibbons[52];
    /*0x30D0*/ struct Roamer roamer;
    /*0x30EC*/ struct EnigmaBerry enigmaBerry;
    /*0x3120*/ struct MEventBuffers unk_3120;
    /*0x348C*/ u8 filler_348C[400];
    /*0x361C*/ struct RamScript ramScript;
    /*0x3A08*/ u8 filler3A08[12];
    /*0x3A14*/ u8 seen2[DEX_FLAGS_NO];
    /*0x3A48*/ u8 filler_3a48[4];
    /*0x3A4C*/ u8 rivalName[PLAYER_NAME_LENGTH];
    /*0x3A54*/ struct FameCheckerSaveData fameChecker[NUM_FAMECHECKER_PERSONS];
    /*0x3A94*/ struct EventObject eventObjects2[EVENT_OBJECTS_COUNT_2];		//u8 filler3A94[0x204];		14 * 36 = 504 bytes / 516
	/*0x3C8C*/ u8 filler[12];
    /*0x3C98*/ struct DaycareMon route5DayCareMon;
    /*0x3D24*/ u8 filler3D24[0x10];
    /*0x3D34*/ u32 unkArrayIdx;
    /*0x3D38*/ struct TrainerTowerLog unkArray[4];
};

//extern struct SaveBlock1* gSaveBlock1Ptr;

struct Bitmap           // TODO: Find a better spot for this
{
    u8* pixels;
    u32 width:16;
    u32 height:16;
};

extern u8 gReservedSpritePaletteCount;

struct BrmData {
	MainCallback exitCallback;	//0x0-0x3
	u32 unk4;			//0x4-0x7
	u8 unk8_0:4;			//0x8
    u8 mode:2;
    u8 unk8_2:2;
    s8 selectedPoke;		//0x9
    s8 unkA;
    u8 unkB;
    u16 unkC;
    s16 unkE;
    s16 unk10;
};

struct MenuChoiceStruct {
	u8 choiceX;
	u8 choiceY;
	u8 choiceCurrent;
	u8 choiceMin;
	u8 choiceMax;
	u8 choiceRboxId;
	u16 choiceFboxId;
	u16 choiceYStride;
};

struct BrmBoxes {
	/*0x00*/ u32 brmCallback;
	/*0x04*/ u16 field4;
	/*0x06*/ u16 field6;
	/*0x08*/ u16 field8;
	/*0x0A*/ u16 fieldA;
	/*0x0C*/ u8 optsBoxId;   // box that holds brm options
	/*0x0D*/ u8 actionBoxId;  // box in bottom left that tells you what to do
	/*0x0E*/ u8 fieldMoveHelpboxId;	// lists what field move does
	/*0x0F*/ u8 brmSequence[8];	// sequence of brm field Ids
	/*0x17*/ u8 numBrmOpts;		// number of brm options
};

#define gText_Cancel ((u8*) 0x84161C1)

#endif // GUARD_GLOBAL_H
