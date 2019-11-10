#pragma once

#include "global.h"

// should they be included here or included individually by every file?
#include "constants/battle.h"
#include "battle_util.h"
#include "battle_util2.h"
#include "battle_script_commands.h"
#include "battle_2.h"
#include "battle_ai_switch_items.h"
#include "battle_gfx_sfx_util.h"

/*
    Banks are a name given to what could be called a 'battlerId' or 'monControllerId'.
    Each bank has a value consisting of two bits.
    0x1 bit is responsible for the side, 0 = player's side, 1 = opponent's side.
    0x2 bit is responsible for the id of sent out pokemon. 0 means it's the first sent out pokemon, 1 it's the second one. (Triple battle didn't exist at the time yet.)
*/

#define BATTLE_BANKS_COUNT  4

#define IDENTITY_PLAYER_MON1        0
#define IDENTITY_OPPONENT_MON1      1
#define IDENTITY_PLAYER_MON2        2
#define IDENTITY_OPPONENT_MON2      3

#define SIDE_PLAYER     0x0
#define SIDE_OPPONENT   0x1

#define GET_BANK_IDENTITY(bank)((gBanksByIdentity[bank]))
#define GET_BANK_SIDE(bank)((GetBattlerPosition(bank) & BIT_SIDE))
#define GET_BANK_SIDE2(bank)((GET_BANK_IDENTITY(bank) & BIT_SIDE))


#define TRAINER_OPPONENT_3FE        0x3FE
//#define TRAINER_OPPONENT_C00        0xC00
#define TRAINER_OPPONENT_800        0x800
#define STEVEN_PARTNER_ID           0xC03
#define SECRET_BASE_OPPONENT        0x400

#define BATTLE_WON                  0x1
#define BATTLE_LOST                 0x2
#define BATTLE_DREW                 0x3
#define BATTLE_RAN                  0x4
#define BATTLE_PLAYER_TELEPORTED    0x5
#define BATTLE_POKE_FLED            0x6
#define BATTLE_CAUGHT               0x7
#define BATTLE_SAFARI_OUT_OF_BALLS  0x8
#define BATTLE_FORFEITED            0x9
#define BATTLE_OPPONENT_TELEPORTED  0xA

#define OUTCOME_LINK_BATTLE_RUN      0x80

#define STATUS_NONE             0x0
#define STATUS_SLEEP            0x7
#define STATUS_POISON           0x8
#define STATUS_BURN             0x10
#define STATUS_FREEZE           0x20
#define STATUS_PARALYSIS        0x40
#define STATUS_TOXIC_POISON     0x80
#define STATUS_TOXIC_COUNTER    0xF00

#define STATUS_PSN_ANY          ((STATUS_POISON | STATUS_TOXIC_POISON))
#define STATUS_ANY              ((STATUS_SLEEP | STATUS_POISON | STATUS_BURN | STATUS_FREEZE | STATUS_PARALYSIS | STATUS_TOXIC_POISON))

#define SIDE_STATUS_REFLECT          (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN      (1 << 1)
#define SIDE_STATUS_X4               (1 << 2)
#define SIDE_STATUS_SPIKES           (1 << 4)
#define SIDE_STATUS_SAFEGUARD        (1 << 5)
#define SIDE_STATUS_FUTUREATTACK     (1 << 6)
#define SIDE_STATUS_MIST             (1 << 8)
#define SIDE_STATUS_SPIKES_DAMAGED   (1 << 9)

#define ACTION_USE_MOVE             0
#define ACTION_USE_ITEM             1
#define ACTION_SWITCH               2
#define ACTION_RUN                  3
#define ACTION_WATCHES_CAREFULLY    4
#define ACTION_SAFARI_ZONE_BALL     5
#define ACTION_POKEBLOCK_CASE       6
#define ACTION_GO_NEAR              7
#define ACTION_SAFARI_ZONE_RUN      8
#define ACTION_9                    9
#define ACTION_RUN_BATTLESCRIPT     10 // when executing an action
#define ACTION_TRY_FINISH			11
#define ACTION_CANCEL_PARTNER       12 // when choosing an action
#define ACTION_FINISHED             12 // when executing an action
#define ACTION_NOTHING_FAINTED      13 // when choosing an action
#define ACTION_INIT_VALUE           0xFF

#define MOVESTATUS_MISSED             (1 << 0)
#define MOVESTATUS_SUPEREFFECTIVE     (1 << 1)
#define MOVESTATUS_NOTVERYEFFECTIVE   (1 << 2)
#define MOVESTATUS_NOTAFFECTED        (1 << 3)
#define MOVESTATUS_ONEHITKO           (1 << 4)
#define MOVESTATUS_FAILED             (1 << 5)
#define MOVESTATUS_ENDURED            (1 << 6)
#define MOVESTATUS_HUNGON             (1 << 7)

#define MOVESTATUS_NOEFFECT ((MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED | MOVESTATUS_FAILED))

#define MAX_TRAINER_ITEMS 4
//#define MAX_MON_MOVES 4

#define BATTLE_TERRAIN_GRASS        	0
#define BATTLE_TERRAIN_LONG_GRASS   	1
#define BATTLE_TERRAIN_SAND         	2
#define BATTLE_TERRAIN_UNDERWATER   	3
#define BATTLE_TERRAIN_WATER        	4
#define BATTLE_TERRAIN_POND         	5
#define BATTLE_TERRAIN_MOUNTAIN     	6
#define BATTLE_TERRAIN_CAVE         	7
#define BATTLE_TERRAIN_INSIDE       	8
#define BATTLE_TERRAIN_PLAIN        	9
#define BATTLE_TERRAIN_INSIDE_2       	0xA
#define BATTLE_TERRAIN_INSIDE_3       	0xB
#define BATTLE_TERRAIN_INSIDE_4       	0xC
#define BATTLE_TERRAIN_INSIDE_5       	0xD
#define BATTLE_TERRAIN_INSIDE_6       	0xE
#define BATTLE_TERRAIN_LORLEI       	0xF
#define BATTLE_TERRAIN_BRUNO 			0x10
#define BATTLE_TERRAIN_AGATHA       	0x11
#define BATTLE_TERRAIN_LANCE 			0x12
#define BATTLE_TERRAIN_CHAMPION       	0x13

//For Unbound
#ifdef UNBOUND

#define BATTLE_TERRAIN_BATTLE_TOWER			0xA
#define BATTLE_TERRAIN_BATTLE_CIRCUS		0xB
#define BATTLE_TERRAIN_SNOW_FIELD			0x14
#define BATTLE_TERRAIN_VOLCANO				0x15
#define BATTLE_TERRAIN_DARK_CAVE_WATER		0x16
#define BATTLE_TERRAIN_DARK_CAVE			0x17
#define BATTLE_TERRAIN_SNOW_CAVE			0x18
#define BATTLE_TERRAIN_FOREST				0x19
#define BATTLE_TERRAIN_ICE_IN_CAVE			0x1A
#define BATTLE_TERRAIN_RUINS_OF_VOID		0x1B
#define BATTLE_TERRAIN_DISTORTION_WORLD		0x1C
#define BATTLE_TERRAIN_GRASS_GYM			0x1D
#define BATTLE_TERRAIN_DESERT				0x1E
#define BATTLE_TERRAIN_WATER_IN_CAVE		0x1F
#define BATTLE_TERRAIN_WATER_IN_SNOW_CAVE	0x20
#define BATTLE_TERRAIN_LAVA_IN_VOLCANO		0x21
#define BATTLE_TERRAIN_WATER_IN_FOREST		0x22
#define BATTLE_TERRAIN_AUTUMN_GRASS			0x23
#define BATTLE_TERRAIN_AUTUMN_PLAIN			0x24
#define BATTLE_TERRAIN_SNOW_GRASS			0x25

#define BATTLE_TERRAIN_RANDOM				0xFF
#endif

enum
{
	NO_TERRAIN,
	ELECTRIC_TERRAIN,
	GRASSY_TERRAIN,
	MISTY_TERRAIN,
	PSYCHIC_TERRAIN
};

// array entries for battle communication
#define MULTIUSE_STATE          0x0
#define CURSOR_POSITION         0x1
#define TASK_ID                 0x1 // task Id and cursor position share the same field
#define SPRITES_INIT_STATE1     0x1 // shares the Id as well
#define SPRITES_INIT_STATE2     0x2
#define MOVE_EFFECT_BYTE        0x3
#define ACTIONS_CONFIRMED_COUNT 0x4
#define MULTISTRING_CHOOSER     0x5
#define MSG_DISPLAY             0x7
#define BATTLE_COMMUNICATION_ENTRIES_COUNT  0x8

#define MOVE_TARGET_SELECTED        0x0
#define MOVE_TARGET_DEPENDS         0x1
#define MOVE_TARGET_USER_OR_PARTNER    0x2
#define MOVE_TARGET_RANDOM          0x4
#define MOVE_TARGET_BOTH            0x8
#define MOVE_TARGET_USER            0x10
#define MOVE_TARGET_FOES_AND_ALLY   0x20
#define MOVE_TARGET_ALL   			0x20
#define MOVE_TARGET_OPPONENTS_FIELD 0x40

// defines for the u8 array gTypeEffectiveness
#define TYPE_EFFECT_ATK_TYPE(i)((gTypeEffectiveness[i + 0]))
#define TYPE_EFFECT_DEF_TYPE(i)((gTypeEffectiveness[i + 1]))
#define TYPE_EFFECT_MULTIPLIER(i)((gTypeEffectiveness[i + 2]))

// defines for the gTypeEffectiveness multipliers
#define TYPE_MUL_NO_EFFECT          0
#define TYPE_MUL_NOT_EFFECTIVE      5
#define TYPE_MUL_NORMAL             10
#define TYPE_MUL_SUPER_EFFECTIVE    20

// special type table Ids
#define TYPE_FORESIGHT  0xFE
#define TYPE_ENDTABLE   0xFF

#define BS_GET_TARGET                   0
#define BS_GET_ATTACKER                 1
#define BS_GET_EFFECT_BANK              2
#define BS_GET_gBank1   3
#define BS_GET_BANK_0   7
#define BS_ATTACKER_WITH_PARTNER        4 // for atk98_status_icon_update
#define BS_GET_ATTACKER_SIDE            8 // for atk1E_jumpifability
#define BS_GET_NOT_ATTACKER_SIDE        9 // for atk1E_jumpifability
#define BS_GET_SCRIPTING_BANK           10
#define BS_GET_OPPONENT1                12
#define BS_GET_PLAYER2                  13
#define BS_GET_OPPONENT2                14

// for battle script commands
#define CMP_EQUAL               0x0
#define CMP_NOT_EQUAL           0x1
#define CMP_GREATER_THAN        0x2
#define CMP_LESS_THAN           0x3
#define CMP_COMMON_BITS         0x4
#define CMP_NO_COMMON_BITS      0x5

struct TrainerMoney {
    u8 trainerClass;
    u8 money;
    u16 field2;
};

struct TrainerMonNoItemDefaultMoves
{
    u16 iv;
    u16 lvl;
    u16 species;
	u16 _;
};

struct TrainerMonItemDefaultMoves
{
    u16 iv;
    u16 lvl;
    u16 species;
    u16 heldItem;
};

struct TrainerMonNoItemCustomMoves
{
    u16 iv;
    u16 lvl;
    u16 species;
    u16 moves[4];
	u16 _; // 0x0000
};

struct TrainerMonItemCustomMoves
{
    u16 iv;
    u16 lvl;
    u16 species;
    u16 heldItem;
    u16 moves[4];
};

union TrainerMonPtr
{
    struct TrainerMonNoItemDefaultMoves* NoItemDefaultMoves;
    struct TrainerMonNoItemCustomMoves* NoItemCustomMoves;
    struct TrainerMonItemDefaultMoves* ItemDefaultMoves;
    struct TrainerMonItemCustomMoves* ItemCustomMoves;
};

struct Trainer
{
    /*0x00*/ u8 partyFlags;
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u8 encounterMusic : 7; // last bit is gender
			 u8 gender : 1;
    /*0x03*/ u8 trainerPic;
    /*0x04*/ u8 trainerName[12];
    /*0x10*/ u16 items[4];
    /*0x18*/ bool8 doubleBattle;
    /*0x1C*/ u32 aiFlags;
    /*0x20*/ u8 partySize;
    /*0x24*/ union TrainerMonPtr party;
};

#define PARTY_FLAG_CUSTOM_MOVES     0x1
#define PARTY_FLAG_HAS_ITEM         0x2

/*
extern const struct Trainer gTrainers[];
*/
#define TRAINER_ENCOUNTER_MUSIC(trainer)((gTrainers[trainer].encounterMusic_gender & 0x7F))

struct UnknownFlags
{
    u32 flags[4];
};

#define RESOURCE_FLAG_FLASH_FIRE 1
/*
struct BattleMove
{
    u8 effect;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 secondaryEffectChance;
    u8 target;
    s8 priority;
    u8 flags;
	u8 z_move_power;
	u8 split;
	u8 z_move_effect;
};
*/
extern const struct BattleMove gBattleMoves[];

#define FLAG_MAKES_CONTACT          0x1
#define FLAG_PROTECT_AFFECTED       0x2
#define FLAG_MAGIC_COAT_AFFECTED     0x4
#define FLAG_SNATCH_AFFECTED        0x8
#define FLAG_MIRROR_MOVE_AFFECTED   0x10
#define FLAG_KINGS_ROCK_AFFECTED    0x20
#define FLAG_TRIAGE_AFFECTED     	0x40

#define SPLIT_PHYSICAL 0
#define SPLIT_SPECIAL 1
#define SPLIT_STATUS 2

struct DisableStruct
{
    /*0x00*/ u32 transformedMonPersonality;
    /*0x04*/ u16 disabledMove;
    /*0x06*/ u16 encoredMove;
    /*0x08*/ u8 protectUses;
    /*0x09*/ u8 stockpileCounter;
    /*0x0A*/ u8 substituteHP;
    /*0x0B*/ u8 disableTimer1 : 4;
    /*0x0B*/ u8 disableTimer2 : 4;
    /*0x0C*/ u8 encoredMovePos;
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 encoreTimer:4;
    /*0x0E*/ u8 encoreTimerStartValue:4;
    /*0x0F*/ u8 perishSongTimer:4;
    /*0x0F*/ u8 perishSongTimerStartValue:4;
    /*0x10*/ u8 furyCutterCounter;
    /*0x11*/ u8 rolloutTimer:4;
    /*0x11*/ u8 rolloutTimerStartValue:4;
    /*0x12*/ u8 chargeTimer:4;
    /*0x12*/ u8 chargeTimerStartValue:4;
    /*0x13*/ u8 tauntTimer:4;
    /*0x13*/ u8 tauntTimer2:4;
    /*0x14*/ u8 bankPreventingEscape;
    /*0x15*/ u8 bankWithSureHit;
    /*0x16*/ u8 isFirstTurn;
    /*0x17*/ u8 unk17;
    /*0x18*/ u8 truantCounter : 1;
    /*0x18*/ u8 truantSwitchInHack:1;
    /*0x18*/ u8 unk18_a_2 : 2;
    /*0x18*/ u8 mimickedMoves : 4;
    /*0x19*/ u8 rechargeTimer;
    /*0x1A*/ u8 unk1A[2];
};

extern struct DisableStruct gDisableStructs[BATTLE_BANKS_COUNT];

struct ProtectStruct
{
    /* field_0 */
    u32 protected:1;
    u32 endured:1;
    u32 onlyStruggle:1;
    u32 helpingHand:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 flag0Unknown:1;
    u32 prlzImmobility:1;
    /* field_1 */
    u32 confusionSelfDmg:1;
    u32 targetNotAffected:1;
    u32 chargingTurn:1;
    u32 fleeFlag:2; // for RunAway and Smoke Ball
    u32 usedImprisionedMove:1;
    u32 loveImmobility:1;
    u32 usedDisabledMove:1;
    /* field_2 */
    u32 usedTauntedMove:1;      	// 0x1
    u32 flag2Unknown:1;         	// 0x2
    u32 flinchImmobility:1;     	// 0x4
    u32 notFirstStrike:1;       	// 0x8
    u32 palaceUnableToUseMove : 1;	// 0x10 //May be implemented...
    u32 flag_x20 : 1;           	// 0x20
    u32 flag_x40 : 1;           	// 0x40
    u32 flag_x80 : 1;           	// 0x80
    /* field_3 */
    u32 KingsShield : 1;
    u32 SpikyShield : 1;
	u32 BanefulBunker : 1;
    u32 kingsshield_damage : 1;
    u32 spikyshield_damage : 1;
    u32 banefulbunker_damage : 1;
    u32 enduredSturdy : 1;
    u32 Field3 : 1;

    /* field_4 */ u32 physicalDmg;
    /* field_8 */ u32 specialDmg;
    /* field_C */ u8 physicalBank;
    /* field_D */ u8 specialBank;
    /* field_E */ u16 fieldE;
};

extern struct ProtectStruct gProtectStructs[BATTLE_BANKS_COUNT];

struct SpecialStatus
{
    u8 statLowered : 1;             // 0x1
    u8 lightningRodRedirected : 1;  // 0x2
    u8 restoredBankSprite: 1;       // 0x4
    u8 intimidatedPoke : 1;         // 0x8
    u8 traced : 1;                  // 0x10
    u8 ppNotAffectedByPressure : 1;
    u8 flag40 : 1;
    u8 focusBanded : 1;				// 0x80
    u8 field1[3];
    s32 moveturnLostHP;
    s32 moveturnLostHP_physical;
    s32 moveturnLostHP_special;
    u8 moveturnPhysicalBank;
    u8 moveturnSpecialBank;
    u8 field12 : 1;
    u8 field13;
};

extern struct SpecialStatus gSpecialStatuses[BATTLE_BANKS_COUNT];

struct SideTimer
{
    /*0x00*/ u8 reflectTimer;
    /*0x01*/ u8 reflectBank;
    /*0x02*/ u8 lightscreenTimer;
    /*0x03*/ u8 lightscreenBank;
    /*0x04*/ u8 mistTimer;
    /*0x05*/ u8 mistBank;
    /*0x06*/ u8 safeguardTimer;
    /*0x07*/ u8 safeguardBank;
    /*0x08*/ u8 followmeTimer;
    /*0x09*/ u8 followmeTarget;
    /*0x0A*/ u8 spikesAmount : 2;
			 u8 tspikesAmount : 2;
			 u8 srAmount : 1;
			 u8 stickyWeb : 1;
    /*0x0B*/ u8 fieldB;
};

extern struct SideTimer gSideTimers[];

struct WishFutureKnock
{
    u8 futureSightCounter[BATTLE_BANKS_COUNT];
    u8 futureSightAttacker[BATTLE_BANKS_COUNT];
    u32 futureSightPartyIndex[BATTLE_BANKS_COUNT]; //was s32 futureSightDmg[BATTLE_BANKS_COUNT];
    u16 futureSightMove[BATTLE_BANKS_COUNT];
    u8 wishCounter[BATTLE_BANKS_COUNT];
    u8 wishUserID[BATTLE_BANKS_COUNT];
    u8 weatherDuration;
    u8 knockedOffPokes[2];
};

extern struct WishFutureKnock gWishFutureKnock;

struct AI_ThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s8 score[4];
    u32 funcResult;
    u32 aiFlags;
    u8 aiAction;
    u8 aiLogicId;
    u8 filler12[6];
    u8 simulatedRNG[4];
};

extern u8 gActiveBattler;
extern u8 gBattlerTarget;
extern u8 gAbsentBattlerFlags;

// script's table id to bit
#define AI_SCRIPT_CHECK_BAD_MOVE (1 << 0)
#define AI_SCRIPT_CHECK_GOOD_MOVE (1 << 1)
#define AI_SCRIPT_CHECK_VIABILITY (1 << 2)
#define AI_SCRIPT_SETUP_FIRST_TURN (1 << 3)
#define AI_SCRIPT_RISKY (1 << 4)
#define AI_SCRIPT_PREFER_STRONGEST_MOVE (1 << 5)
#define AI_SCRIPT_PREFER_BATON_PASS (1 << 6)
#define AI_SCRIPT_DOUBLE_BATTLE (1 << 7)
#define AI_SCRIPT_HP_AWARE (1 << 8)
#define AI_SCRIPT_UNKNOWN (1 << 9)
// 10 - 28 are not used
#define AI_SCRIPT_ROAMING (1 << 29)
#define AI_SCRIPT_SAFARI (1 << 30)
#define AI_SCRIPT_FIRST_BATTLE (1 << 31)

extern struct BattlePokemon gBattleMons[MAX_BATTLERS_COUNT];

struct BattleHistory //0x20003D0
{
    /*0x00*/ u16 usedMoves[2][8]; // 0xFFFF means move not used (confuse self hit, etc)
    /*0x20*/ u8 abilities[MAX_BATTLERS_COUNT / 2];
    /*0x22*/ u8 itemEffects[MAX_BATTLERS_COUNT / 2];
    /*0x24*/ u16 trainerItems[MAX_BATTLERS_COUNT];
    /*0x2C*/ u8 itemsNo;
};

struct BattleScriptsStack
{
    const u8 *ptr[8];
    u8 size;
};

struct BattleCallbacksStack
{
    void (*function[8])(void);
    u8 size;
};

struct StatsArray
{
    u16 hp;
    u16 atk;
    u16 def;
    u16 spd;
    u16 spAtk;
    u16 spDef;
};

struct StatFractions
{
    u8 dividend;
    u8 divisor;
	u16 _;
};

struct BattleResources
{
    struct SecretBaseRecord* secretBase;
    struct UnknownFlags* flags;
    struct BattleScriptsStack* battleScriptsStack;
    struct BattleCallbacksStack* battleCallbackStack;
    struct StatsArray* statsBeforeLvlUp;
    struct AI_ThinkingStruct *ai;
    struct BattleHistory *battleHistory;
    struct BattleScriptsStack *AI_ScriptsStack;
};

extern struct BattleResources* gBattleResources;

#define BATTLESCRIPTS_STACK     (gBattleResources->battleScriptsStack)
#define BATTLE_CALLBACKS_STACK  (gBattleResources->battleCallbackStack)
#define BATTLE_LVLUP_STATS      (gBattleResources->statsBeforeLvlUp)

struct BattleResults
{
    u8 playerFaintCounter;    // 0x0
    u8 opponentFaintCounter;  // 0x1
    u8 playerSwitchesCounter; // 0x2
    u8 unk3;                  // 0x3
    u8 unk4;                  // 0x4
    u8 unk5_0:1;              // 0x5
    u8 usedMasterBall:1;      // 0x5
    u8 caughtMonBall:4;       // 0x5
    u8 unk5_6:1;              // 0x5
    u8 unk5_7:1;              // 0x5
    u16 playerMon1Species;    // 0x6
    u8 playerMon1Name[11];    // 0x8
    u8 battleTurnCounter;     // 0x13
    u8 playerMon2Name[11];    // 0x14
    u8 field_1F;              // 0x1F
    u16 lastOpponentSpecies;  // 0x20
    u16 lastUsedMovePlayer;   // 0x22
    u16 lastUsedMoveOpponent; // 0x24
    u16 playerMon2Species;    // 0x26
    u16 caughtMonSpecies;     // 0x28
    u8 caughtMonNick[10];     // 0x2A
    u8 filler34[2];
    u8 usedBalls[11];     // 0x36
};

extern struct BattleResults gBattleResults;

struct BattleStruct
{
    u8 turnEffectsTracker;
    u8 turnEffectsBank;
    u8 filler2;
    u8 turncountersTracker;
    u16 wrappedMove[4];
    u8 moveTarget[4];
    u8 expGetterId;
    u8 field_11;
    u8 wildVictorySong;
    u8 dynamicMoveType;
    u8 wrappedBy[4];
    u16 assistPossibleMoves[5 * 4]; // 5 mons, each of them knowing 4 moves
    u8 field_40;
    u8 field_41;
    u8 field_42;
    u8 field_43;
    u8 field_44;
    u8 field_45;
    u8 field_46;
    u8 field_47;
    u8 focusPunchBank;
    u8 battlerPreventingSwitchout;
    u8 moneyMultiplier;
    u8 savedTurnActionNumber;
    u8 switchInAbilitiesCounter;
    u8 faintedActionsState;
    u8 faintedActionsBank;
    u8 field_4F;
    u16 expValue;
    u8 field_52;
    u8 sentInPokes;
    bool8 selectionScriptFinished[BATTLE_BANKS_COUNT];
    u8 switchoutPartyIndex[BATTLE_BANKS_COUNT];
    u8 monToSwitchIntoId[BATTLE_BANKS_COUNT];
    u8 field_60[4][3];
    u8 runTries;
    u8 caughtMonNick[11];
    u8 field_78;
    u8 safariGoNearCounter;
    u8 safariPkblThrowCounter;
    u8 safariEscapeFactor;
    u8 safariCatchFactor;
    u8 field_7D;
    u8 field_7E;
    u8 castformToChangeInto;
    u8 chosenMovePositions[BATTLE_BANKS_COUNT];
    u8 stateIdAfterSelScript[BATTLE_BANKS_COUNT];
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u8 stringMoveType;
    u8 expGetterBank;
    u8 field_90;
    u8 field_91;
    u8 switchoutIndex[2];
    u8 wallyBattleState;
    u8 wallyMovesState;
    u8 wallyWaitFrames;
    u8 wallyMoveFrames;
    u16 lastTakenMove[MAX_BATTLERS_COUNT]; //Used by mirror move
    u8 field_A0;
    u8 field_A1;
    u8 field_A2;
    u8 field_A3;
    u8 field_A4;
    u8 field_A5;
    u8 field_A6;
    u8 field_A7;
    u16 hpOnSwitchout[2];
	u8 abilityPreventingSwitchout;
    u8 hpScale;
    u8 field_AE;
	u8 field_AF;
	u8 field_B0;
	u8 field_B1;
	u8 field_B2;
	u8 field_B3;
    u8 synchronizeMoveEffect;
    u8 field_B5;
    u8 field_B6;
    u8 atkCancellerTracker;
    // void (*savedCallback)(void);
    u16 usedHeldItems[MAX_BATTLERS_COUNT];
    u8 chosenItem[MAX_BATTLERS_COUNT]; //Why is this a u8?
    u8 AI_itemType[2];
    u8 AI_itemFlags[2];
    u16 choicedMove[MAX_BATTLERS_COUNT];
    u16 changedItems[MAX_BATTLERS_COUNT];
    u8 intimidateBank;
    u8 switchInItemsCounter;
    u8 field_DA;
    u8 turnSideTracker;
    u8 fillerDC[0xDF-0xDC];
    u8 givenExpMons; //The party indices in the opponent's party that have fainted and been given exp for
    u16 lastTakenMoveFrom[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; // 4 sub-arrays containing the moves that bank was hit by, by each bank //used by Mirror Move
    u16 castformPalette[MAX_BATTLERS_COUNT][16];
    u8 field_180;
    u8 field_181;
    u8 field_182;
    u8 field_183;
    struct BattleEnigmaBerry battleEnigmaBerry;
    u8 wishPerishSongState;
    u8 wishPerishSongBank;
    bool8 overworldWeatherDone;
/*    u8 atkCancellerTracker;
    u8 field_1A4[96];
    u8 field_204[104];
    u8 field_26C[40];
    u8 AI_monToSwitchIntoId[MAX_BATTLERS_COUNT];
    u8 field_298[8];
    u8 field_2A0;
    u8 field_2A1;
    u8 field_2A2;*/
};

extern struct BattleStruct* gBattleStruct;

struct NewBattleStruct
{
	//Field Counters
	u8 MudSportTimer;
	u8 WaterSportTimer;
	u8 GravityTimer;
	u8 TrickRoomTimer;
	u8 MagicRoomTimer;
	u8 WonderRoomTimer;
	u8 FairyLockTimer;
	u8 IonDelugeTimer;
	u8 TerrainType;
	u8 TerrainTimer;

	//Team Counters
	u8 SeaOfFireTimers[NUM_BATTLE_SIDES];
	u8 SwampTimers[NUM_BATTLE_SIDES];
	u8 RainbowTimers[NUM_BATTLE_SIDES];
	u8 RetaliateCounters[NUM_BATTLE_SIDES];
	u8 LuckyChantTimers[NUM_BATTLE_SIDES];
	u8 TailwindTimers[NUM_BATTLE_SIDES];
	u8 AuroraVeilTimers[NUM_BATTLE_SIDES];

	//Personal Counters
	u8 TelekinesisTimers[MAX_BATTLERS_COUNT];
	u8 MagnetRiseTimers[MAX_BATTLERS_COUNT];
	u8 HealBlockTimers[MAX_BATTLERS_COUNT]; 			//0x20175D4
	u8 LaserFocusTimers[MAX_BATTLERS_COUNT];
	u8 ThroatChopTimers[MAX_BATTLERS_COUNT];
	u8 EmbargoTimers[MAX_BATTLERS_COUNT];
	u8 ElectrifyTimers[MAX_BATTLERS_COUNT];
	u8 SlowStartTimers[MAX_BATTLERS_COUNT];				//0x20175E8
	u8 StakeoutCounters[MAX_BATTLERS_COUNT];
	u8 StompingTantrumTimers[MAX_BATTLERS_COUNT];
	u8 NimbleCounters[MAX_BATTLERS_COUNT];
	u8 DestinyBondCounters[MAX_BATTLERS_COUNT];
	u8 MetronomeCounter[MAX_BATTLERS_COUNT];
	u8 IncinerateCounters[MAX_BATTLERS_COUNT];
	u8 LastUsedTypes[MAX_BATTLERS_COUNT];
	u8 lastTargeted[MAX_BATTLERS_COUNT];
	u8 usedMoveIndices[MAX_BATTLERS_COUNT];
	u8 DisabledMoldBreakerAbilities[MAX_BATTLERS_COUNT];
	u8 SuppressedAbilities[MAX_BATTLERS_COUNT];
	u8 skyDropAttackersTarget[MAX_BATTLERS_COUNT]; //skyDropAttackersTarget[gBankAttacker] = gBankTarget
	u8 skyDropTargetsAttacker[MAX_BATTLERS_COUNT]; //skyDropTargetsAttacker[gBankTarget] = gBankAttacker
	u8 pickupStack[MAX_BATTLERS_COUNT]; //0x2017620
	u8 synchronizeTarget[MAX_BATTLERS_COUNT]; //Bank + 1 that statused given bank
	u8 leftoverHealingDone[MAX_BATTLERS_COUNT]; //Leftovers already restored health this turn or Sticky Barb did damage
	u8 statFellThisTurn[MAX_BATTLERS_COUNT];
	u8 recalculatedBestDoublesKillingScores[MAX_BATTLERS_COUNT];

	//Bit Fields for Banks
	u8 MicleBerryBits;
	u8 UnburdenBoosts;
	u8 BeakBlastByte;
	u8 playedFocusPunchMessage;
	u8 playedShellTrapMessage;
	u8 RoostCounter;
	u8 CustapQuickClawIndicator; //0x2017632
	u8 HealingWishLoc;
	u8 PowderByte;
	u8 AbsentBattlerHelper;
	u8 activeAbilityPopUps;
	u8 NoMoreMovingThisTurn;
	u8 handleSetSwitchIns;
	u8 brokeFreeMessage;
	u8 doSwitchInEffects;
	u8 devolveForgotMove;

	//Bit Fields for Party
	u8 BelchCounters;
	u8 IllusionBroken;

	//Other Helpers
	u8 SwitchInEffectsTracker;
	u8 SentInBackup;
	u8 OriginalAttackerTargetCount;
	u8 MoveBounceTargetCount;
	u8 EchoedVoiceCounter;
	u8 EchoedVoiceDamageScale;
	u8 EnduranceHelper;
	u8 DancerBankCount;
	u8 CurrentTurnAttacker : 4;
	u8 CurrentTurnTarget : 4;
	u8 targetsToBringDown;
	u8 backupMoveEffect;
	u8 FaintEffectsTracker;
	u8 blockTracker;
	u8 preFaintEffectsTracker;
	u8 savedObjId;
	u8 lastFainted;
	u8 intimidateActive;
	u8 backupAbility;
	u8 switchOutBankLooper;
	u8 originalAttackerBackup : 2;
	u8 originalTargetBackup : 2;

	//Booleans
	bool8 MoveBounceInProgress : 2;
	bool8 moveWasBouncedThisTurn : 1;
	bool8 AttackerDidDamageAtLeastOnce : 1;
	bool8 PledgeHelper : 3;
	bool8 ParentalBondOn : 2;
	bool8 MeFirstByte : 1;
	bool8 ReceiverActivated : 1;
	bool8 GemHelper : 1;
	bool8 fusionFlareUsedPrior : 1;
	bool8 fusionBoltUsedPrior : 1;
	bool8 endTurnDone : 1;
	bool8 HappyHourByte : 1;
	bool8 attackAnimationPlayed : 1;
	bool8 DancerInProgress : 1;
	bool8 DancerByte : 1;
	bool8 InstructInProgress : 1;
	bool8 NoSymbiosisByte : 1;
	bool8 SpectralThiefActive : 1;
	bool8 MultiHitOn : 1;
	bool8 secondaryEffectApplied : 1;
	bool8 bypassSubstitute : 1;
	bool8 criticalCapture : 1;
	bool8 trainerSlideLowHpMsgDone : 1;
	bool8 TeleportBit : 1;
	bool8 restartEndTurnSwitching : 1;
	bool8 skipCertainSwitchInAbilities : 1;
	bool8 roundUsed : 1; //0x2017653
	bool8 activatedCustapQuickClaw : 1;
	bool8 calculatedAIPredictions : 1;
	bool8 batonPassing : 1;

	//Other
	u16 LastUsedMove;
	u16 NewWishHealthSave;
	u32 totalDamageGiven;
	u8 DancerTurnOrder[MAX_BATTLERS_COUNT];
	u8 PayDayByPartyIndices[PARTY_SIZE];
	u16 aiZMoveHelper;
	item_t SavedConsumedItems[PARTY_SIZE];
	s32 DamageTaken[MAX_BATTLERS_COUNT]; //0x2017668
	u8 ResultFlags[MAX_BATTLERS_COUNT];
	u8 expHelper[MAX_BATTLERS_COUNT];
	u8 megaIndicatorObjIds[MAX_BATTLERS_COUNT];
	u8 abilityPopUpIds[MAX_BATTLERS_COUNT][2];
	u8 backupSynchronizeBanks[2];
	u16 movePredictions[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //movePredictions[bankAtk][bankDef] //0x201769A
	u16 strongestMove[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //strongestMove[bankAtk][bankDef]
	u16 bestDoublesKillingMoves[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //bestDoublesKillingMoves[bankAtk][bankDef]
	s8 bestDoublesKillingScores[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //bestDoublesKillingScores[bankAtk][bankDef][bankDef / bankDefPartner / bankAtkPartner]
	bool8 canKnockOut[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //canKnockOut[bankAtk][bankDef]
	bool8 can2HKO[MAX_BATTLERS_COUNT][MAX_BATTLERS_COUNT]; //can2HKO[bankAtk][bankDef]
	u8 bestMonIdToSwitchInto[MAX_BATTLERS_COUNT][2]; //bestMonIdToSwitchInto[bankAtk][first or second choice] //0x2017762
	s8 bestMonIdToSwitchIntoScores[MAX_BATTLERS_COUNT][2];//bestMonIdToSwitchIntoScores[bankAtk][first or second choice]
	u8 calculatedAISwitchings[MAX_BATTLERS_COUNT];
	const void* aiMegaPotential[MAX_BATTLERS_COUNT]; //aiMegaPotential[bankAtk] - stores evolution data of attacker

	struct MegaData* MegaData;
	struct UltraData* UltraData;
	struct ZMoveData* ZMoveData;
};

#define gNewBS (ExtensionState.newBattleStruct)

struct TrainerSpotted {
    /* NPC state id */
    u8 id;

    /* Distance from trainer to player */
    u8 distance;

    /* The script the on the trainer NPC. */
    u8* script;
};

struct BattleExtensionState //Clear After Battle
{
    struct {
        u8 count;
		u8 approachingId;
		u8 firstTrainerNPCId; //Used in trainerbattle 0xB
		u8 secondTrainerNPCId;
        struct TrainerSpotted trainers[2];
    } spotted;

    void* partyBackup;
	pokemon_t* skyBattlePartyBackup;
	u16* itemBackup;
	u8* trainerBIntroSpeech;
	u8* trainerBDefeatSpeech;
	u8* trainerBVictorySpeech;
	u8* trainerBCantBattleSpeech;
	u8* trainerBRetAddress;
	struct NewBattleStruct* newBattleStruct;

	u16   partnerTrainerId;
	u16   partnerBackSpriteId;
	u16   trainerBTrainerId;
	u8	  multiTaskStateHelper;
};

extern struct BattleExtensionState ExtensionState;

struct NaturalGiftStruct
{
	u16 berry;
	u8 type;
	u8 power;
};

struct FlingStruct
{
	u8 power;
	u8 effect;
};

#define GET_MOVE_TYPE(move, typeArg)                        \
{                                                           \
    typeArg = gBattleStruct->dynamicMoveType & 0x3F;    	\
}

#define IS_TYPE_PHYSICAL(moveType)(moveType < TYPE_MYSTERY)
#define IS_TYPE_SPECIAL(moveType)(moveType > TYPE_MYSTERY)

/*
#define MOVE_EFFECT_SLEEP               0x1
#define MOVE_EFFECT_POISON              0x2
#define MOVE_EFFECT_BURN                0x3
#define MOVE_EFFECT_FREEZE              0x4
#define MOVE_EFFECT_PARALYSIS           0x5
#define MOVE_EFFECT_TOXIC               0x6
#define MOVE_EFFECT_CONFUSION           0x7
#define MOVE_EFFECT_FLINCH              0x8
#define MOVE_EFFECT_TRI_ATTACK          0x9
#define MOVE_EFFECT_UPROAR              0xA
#define MOVE_EFFECT_PAYDAY              0xB
#define MOVE_EFFECT_CHARGING            0xC
#define MOVE_EFFECT_WRAP                0xD
#define MOVE_EFFECT_RECOIL_25           0xE
#define MOVE_EFFECT_ATK_PLUS_1          0xF
#define MOVE_EFFECT_DEF_PLUS_1          0x10
#define MOVE_EFFECT_SPD_PLUS_1          0x11
#define MOVE_EFFECT_SP_ATK_PLUS_1       0x12
#define MOVE_EFFECT_SP_DEF_PLUS_1       0x13
#define MOVE_EFFECT_ACC_PLUS_1          0x14
#define MOVE_EFFECT_EVS_PLUS_1          0x15
#define MOVE_EFFECT_ATK_MINUS_1         0x16
#define MOVE_EFFECT_DEF_MINUS_1         0x17
#define MOVE_EFFECT_SPD_MINUS_1         0x18
#define MOVE_EFFECT_SP_ATK_MINUS_1      0x19
#define MOVE_EFFECT_SP_DEF_MINUS_1      0x1A
#define MOVE_EFFECT_ACC_MINUS_1         0x1B
#define MOVE_EFFECT_EVS_MINUS_1         0x1C
#define MOVE_EFFECT_RECHARGE            0x1D
#define MOVE_EFFECT_RAGE                0x1E
#define MOVE_EFFECT_STEAL_ITEM          0x1F
#define MOVE_EFFECT_PREVENT_ESCAPE      0x20
#define MOVE_EFFECT_NIGHTMARE           0x21
#define MOVE_EFFECT_ALL_STATS_UP        0x22
#define MOVE_EFFECT_RAPIDSPIN           0x23
#define MOVE_EFFECT_REMOVE_PARALYSIS    0x24
#define MOVE_EFFECT_ATK_DEF_DOWN        0x25
#define MOVE_EFFECT_RECOIL_33_PARALYSIS 0x26
#define MOVE_EFFECT_ATK_PLUS_2          0x27
#define MOVE_EFFECT_DEF_PLUS_2          0x28
#define MOVE_EFFECT_SPD_PLUS_2          0x29
#define MOVE_EFFECT_SP_ATK_PLUS_2       0x2A
#define MOVE_EFFECT_SP_DEF_PLUS_2       0x2B
#define MOVE_EFFECT_ACC_PLUS_2          0x2C
#define MOVE_EFFECT_EVS_PLUS_2          0x2D
#define MOVE_EFFECT_ATK_MINUS_2         0x2E
#define MOVE_EFFECT_DEF_MINUS_2         0x2F
#define MOVE_EFFECT_SPD_MINUS_2         0x30
#define MOVE_EFFECT_SP_ATK_MINUS_2      0x31
#define MOVE_EFFECT_SP_DEF_MINUS_2      0x32
#define MOVE_EFFECT_ACC_MINUS_2         0x33
#define MOVE_EFFECT_EVS_MINUS_2         0x34
#define MOVE_EFFECT_THRASH              0x35
#define MOVE_EFFECT_KNOCK_OFF           0x36
#define MOVE_EFFECT_NOTHING_37          0x37
#define MOVE_EFFECT_NOTHING_38          0x38
#define MOVE_EFFECT_NOTHING_39          0x39
#define MOVE_EFFECT_NOTHING_3A          0x3A
#define MOVE_EFFECT_SP_ATK_TWO_DOWN     0x3B
#define MOVE_EFFECT_NOTHING_3C          0x3C
#define MOVE_EFFECT_NOTHING_3D          0x3D
#define MOVE_EFFECT_NOTHING_3E          0x3E
#define MOVE_EFFECT_NOTHING_3F          0x3F
#define MOVE_EFFECT_AFFECTS_USER        0x40
#define MOVE_EFFECT_CERTAIN             0x80
*/
// table ids for general animations
#define B_ANIM_CASTFORM_CHANGE          0x0
#define B_ANIM_STATS_CHANGE             0x1
#define B_ANIM_SUBSTITUTE_FADE          0x2
#define B_ANIM_SUBSTITUTE_APPEAR        0x3
#define B_ANIM_x4                       0x4
#define B_ANIM_ITEM_KNOCKOFF            0x5
#define B_ANIM_TURN_TRAP                0x6
#define B_ANIM_ITEM_EFFECT              0x7
#define B_ANIM_SMOKEBALL_ESCAPE         0x8
#define B_ANIM_HANGED_ON                0x9
#define B_ANIM_RAIN_CONTINUES           0xA
#define B_ANIM_SUN_CONTINUES            0xB
#define B_ANIM_SANDSTORM_CONTINUES      0xC
#define B_ANIM_HAIL_CONTINUES           0xD
#define B_ANIM_LEECH_SEED_DRAIN         0xE
#define B_ANIM_MON_HIT                  0xF
#define B_ANIM_ITEM_STEAL               0x10
#define B_ANIM_SNATCH_MOVE              0x11
#define B_ANIM_FUTURE_SIGHT_HIT         0x12
#define B_ANIM_DOOM_DESIRE_HIT          0x13
#define B_ANIM_x14                      0x14
#define B_ANIM_INGRAIN_HEAL             0x15
#define B_ANIM_WISH_HEAL                0x16

#define B_ANIM_ASTONISH_DROPS 0x17
#define B_ANIM_SCARY_FACE_ASTONISH 0x18
#define B_ANIM_TRANSFORM_FRONT 0x19
#define B_ANIM_TURN_INTO_ROCK 0x1A
#define B_ANIM_WAITING_WAGGLE 0x1B
#define B_ANIM_LEVEL_UP_SHINE 0x1C
#define B_ANIM_CALL_BACK_POKEMON 0x1D
#define B_ANIM_CALL_BACK_POKEMON_2 0x1E
#define B_ANIM_CAPTURE_POKEMON 0x1F
#define B_ANIM_TURN_INTO_POKEBALL 0x20
#define B_ANIM_SWITCH 0x21
#define B_ANIM_CREATE_SUBSTITUTE_2 0x22
#define B_ANIM_TRANSFORM 0x23
#define B_ANIM_WISHIWASHI_FISH 0x24
#define B_ANIM_ZYGARDE_CELL_SWIRL 0x25
#define B_ANIM_STRONG_WINDS_CONTINUE 0x26
#define B_ANIM_ELECTRIC_SURGE 0x27
#define B_ANIM_GRASSY_SURGE 0x28
#define B_ANIM_MISTY_SURGE 0x29
#define B_ANIM_PSYCHIC_SURGE 0x2A
#define B_ANIM_SEA_OF_FIRE 0x2B
#define B_ANIM_HEALING_SPARKLES 0x2C
#define B_ANIM_LUNAR_DANCE_HEAL 0x2D
#define B_ANIM_HEALING_WISH_HEAL 0x2E
#define B_ANIM_RED_PRIMAL_REVERSION 0x2F
#define B_ANIM_BLUE_PRIMAL_REVERSION 0x30
#define B_ANIM_GRASSY_TERRAIN_HEAL 0x31
#define B_ANIM_POWDER_EXPLOSION 0x32
#define B_ANIM_BEAK_BLAST_WARM_UP 0x33
#define B_ANIM_SHELL_TRAP_SET 0x34
#define B_ANIM_BERRY_EAT 0x35
#define B_ANIM_FOG_CONTINUES 0x36
#define B_ANIM_AQUA_RING_HEAL 0x37
#define B_ELECTRIC_TERRAIN_ACTIVE_ANIM 0x38
#define B_GRASSY_TERRAIN_ACTIVE_ANIM 0x39
#define B_MISTY_TERRAIN_ACTIVE_ANIM 0x3A
#define B_PSYCHIC_TERRAIN_ACTIVE_ANIM 0x3B
#define B_BATON_PASS_ANIM 0x3C
#define B_DRAGON_TAIL_BLOW_AWAY_ANIM 0x3D
#define B_ANIM_ZMOVE_ACTIVATE 0x3E
#define B_ANIM_MEGA_EVOLUTION 0x3F
#define B_ANIM_ULTRA_BURST 0x40
#define B_ANIM_LOAD_DEFAULT_BG 0x41
#define B_ANIM_LOAD_ABILITY_POP_UP 0x42
#define B_ANIM_DESTROY_ABILITY_POP_UP 0x43
#define B_ANIM_TOTEM_BOOST 0x44

#define B_ANIM_TRANSFORM_MOVE 0xFF

// special animations table
#define B_ANIM_LVL_UP                   0x0
#define B_ANIM_SWITCH_OUT_PLAYER_MON    0x1
#define B_ANIM_SWITCH_OUT_OPPONENT_MON  0x2
#define B_ANIM_BALL_THROW               0x3
#define B_ANIM_SAFARI_BALL_THROW        0x4
#define B_ANIM_SUBSTITUTE_TO_MON        0x5
#define B_ANIM_MON_TO_SUBSTITUTE        0x6

// status animation table
#define B_ANIM_STATUS_PSN               0x0
#define B_ANIM_STATUS_CONFUSION         0x1
#define B_ANIM_STATUS_BRN               0x2
#define B_ANIM_STATUS_INFATUATION       0x3
#define B_ANIM_STATUS_SLP               0x4
#define B_ANIM_STATUS_PRZ               0x5
#define B_ANIM_STATUS_FRZ               0x6
#define B_ANIM_STATUS_CURSED            0x7
#define B_ANIM_STATUS_NIGHTMARE         0x8
#define B_ANIM_STATUS_WRAPPED           0x9

#define GET_STAT_BUFF_ID(n)((n & 7))              // first three bits 0x1, 0x2, 0x4
#define GET_STAT_BUFF_VALUE_WITH_SIGN(n)((n & 0xF8))
#define GET_STAT_BUFF_VALUE(n)(((n >> 4) & 7))      // 0x8, 0x10, 0x20, 0x40
#define STAT_BUFF_NEGATIVE 0x80                     // 0x80, the sign bit

#define SET_STAT_BUFF_VALUE(n)(((s8)(((s8)(n) << 4)) & 0xF0))

#define SET_STATCHANGER(statId, stage, goesDown) (gBattleScripting->statChanger = (statId) + (stage << 4) + (goesDown << 7))

// used in many battle files, it seems as though Hisashi Sogabe wrote
// some sort of macro to replace the use of actually calling memset.
// Perhaps it was thought calling memset was much slower?

// The compiler wont allow us to locally declare ptr in this macro; some
// functions that invoke this macro will not match without this egregeous
// assumption about the variable names, so in order to avoid this assumption,
// we opt to pass the variables themselves, even though it is likely that
// Sogabe assumed the variables were named src and dest. Trust me: I tried to
// avoid assuming variable names, but the ROM just will not match without the
// assumptions. Therefore, these macros are bad practice, but I'm putting them
// here anyway.
#define MEMSET_ALT(data, c, size, var, dest)    \
{    \
    dest = (u8 *)data;    \
    for(var = 0; var < (u32)size; var++)    \
        dest[var] = c;    \
}    \

#define MEMCPY_ALT(data, dest, size, var, src)    \
{    \
    src = (u8 *)data;    \
    for(var = 0; var < (u32)size; var++)    \
        dest[var] = src[var];    \
}    \

// defines for the 'DoBounceEffect' function
#define BOUNCE_MON          0x0
#define BOUNCE_HEALTHBOX    0x1

struct BattleScripting
{
    s32 painSplitHp;
    s32 bideDmg;
    u8 multihitString[6];
    u8 dmgMultiplier;
    u8 twoTurnsMoveStringId;
    u8 animArg1;
    u8 animArg2;
    u16 tripleKickPower;
    u8 atk49_state;
    u8 bankWithAbility;
    u8 multihitMoveEffect;
    u8 bank;
    u8 animTurn;
    u8 animTargetsHit;
    u8 statChanger;
    u8 statAnimPlayed;		//0x1B
    u8 expStateTracker;
    u8 battleStyle;
    u8 atk6C_state;
    u8 learnMoveState;
    u8 field_20;
    u8 reshowMainState;
    u8 reshowHelperState;
    u8 field_23;
    u8 field_24;
    u8 multiplayerId;
};

extern struct BattleScripting gBattleScripting;

// functions

// battle_1
void LoadBattleTextboxAndBackground(void);
void LoadBattleEntryBackground(void);
void ApplyPlayerChosenFrameToBattleMenu(void);
bool8 LoadChosenBattleElement(u8 caseId);
void DrawMainBattleBackground(void);
void task00_0800F6FC(u8 taskId);

enum BackSprites
{
    BACK_PIC_RED,
    BACK_PIC_LEAF,
    BACK_PIC_BRENDAN,
    BACK_PIC_MAY,
    BACK_PIC_PRIMO,
    BACK_PIC_OLD_MAN,
};

// rom_80A5C6C
u8 GetBattlerSide(u8 bank);
u8 GetBattlerPosition(u8 bank);
u8 GetBattlerAtPosition(u8 bank);

struct BattleSpriteInfo
{
    u16 invisible : 1; // 0x1
    u16 lowHpSong : 1; // 0x2
    u16 behindSubstitute : 1; // 0x4
    u16 substituteOffScreen : 1; // 0x8
    u16 hpNumbersNoBars : 1; // 0x10
    u16 transformSpecies;
};

struct BattleAnimationInfo
{
    u16 animArg; // to fill up later
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 ballThrowCaseId;
    u8 field_9_x1 : 1;
    u8 field_9_x2 : 1;
    u8 field_9_x1C : 3;
    u8 field_9_x20 : 1;
    u8 field_9_x40 : 1;
    u8 field_9_x80 : 1;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
};

struct BattleHealthboxInfo
{
    u8 partyStatusSummaryShown:1;
    u8 healthboxIsBouncing:1;
    u8 battlerIsBouncing:1;
    u8 ballAnimActive:1; // 0x8
    u8 statusAnimActive:1; // x10
    u8 animFromTableActive:1; // x20
    u8 specialAnimActive:1; // x40
    u8 flag_x80:1;
    u8 field_1_x1:1;
    u8 field_1_x1E:4;
    u8 field_1_x20:1;
    u8 field_1_x40:1;
    u8 field_1_x80:1;
    u8 healthboxBounceSpriteId;
    u8 battlerBounceSpriteId;
    u8 animationState;
    u8 field_5;
    u8 matrixNum;
    u8 shadowSpriteId;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
};

struct BattleBarInfo
{
    u8 healthboxSpriteId;
    s32 maxValue;
    s32 oldValue;
    s32 receivedValue;
    s32 currValue;
};

struct BattleSpriteData
{
    struct BattleSpriteInfo* bankData;
    struct BattleHealthboxInfo* healthBoxesData;
    struct BattleAnimationInfo* animationData;
    struct BattleBarInfo* battleBars;
};

#define gBattleSpritesDataPtr ((struct BattleSpriteData*) *((u32*) 0x2024018)) //extern struct BattleSpriteData* gBattleSpritesDataPtr;

#define BATTLE_BUFFER_LINK_SIZE 0x1000

extern u8 *gLinkBattleSendBuffer;
extern u8 *gLinkBattleRecvBuffer;

extern u8 *gUnknown_0202305C;
extern u8 *gUnknown_02023060;

// Move this somewhere else

#include "sprite.h"

struct MonSpritesGfx
{
    void* firstDecompressed; // ptr to the decompressed sprite of the first pokemon
    void* sprites[4];
    struct SpriteTemplate templates[4];
    struct SpriteFrameImage field_74[4][4];
    u8 field_F4[0x80];
    u8 *barFontGfx;
    void *field_178;
    void *field_17C;
};

enum EnduranceListings {ENUDRE_REG, ENDURE_STURDY, ENDURE_FOCUS_SASH};

struct MegaData
{
  u8 chosen[4];
  u8 done[4];
  u8 state;
  u8 activeBank;
  const u8* script;
  bool8 megaEvoInProgress : 1; //Used to tell the game whether or not the turn order should be recalculated
};

struct UltraData
{
  u8 chosen[4];
  u8 done[4];
};

struct ZMoveData
{
	u8 toBeUsed[4];
	u8 used[4];
	u8 partyIndex[2]; //Index of party member who used Z-Move
	u8 effect;
	u8 state;
	u8* backupTilemap;
	bool8 active : 1;
	bool8 effectApplied : 1; //Used so moves like Sleep Talk don't give 2 z-effects, clear in CMD49
	bool8 healReplacement : 1;
	bool8 viewing : 1;
	bool8 runningZEffect : 1;
	bool8 viewingDetails : 1; //Not actually related to Z-Moves, I just felt like putting it here
};

extern struct BattleSpritesGfx* gMonSpritesGfx;
extern u8 gBattleOutcome;
extern u16 gLastUsedItem;
extern u32 gBattleTypeFlags;
extern struct MonSpritesGfx* gMonSpritesGfxPtr;
extern u16 gTrainerBattleOpponent_A;
extern u16 gMoveToLearn;
extern u16 gBattleMovePower;
extern struct BattleEnigmaBerry gEnigmaBerries[MAX_BATTLERS_COUNT];
extern u16 gCurrentMove;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;
extern u8 gLastUsedAbility;
extern u8 gBattlerInMenuId;
extern u8 gPotentialItemEffectBattler;
extern u8 gBattlersCount;
extern u16 gBattlerPartyIndexes[MAX_BATTLERS_COUNT];
extern s32 gBattleMoveDamage;

extern u8 gUnknown_2023E8A;

#define BATTLE_HISTORY ((struct BattleHistory*) (gBattleResources->battleHistory))
