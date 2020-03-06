#pragma once

#include "global.h"

#include "constants/flags.h"
#include "constants/vars.h"

u8 __attribute__((long_call)) FlagSet(u16 id);
u8 __attribute__((long_call)) FlagClear(u16 id);
bool8 __attribute__((long_call)) FlagGet(u16 id);
u8* __attribute__((long_call)) GetFlagPointer(u16 id);
u16 __attribute__((long_call)) VarGet(u16 var);
u32 __attribute__((long_call)) VarGetAddress(u16 var);
bool8 __attribute__((long_call)) VarSet(u16 var, u16 value);
u16 __attribute__((long_call)) VarGetEventObjectGraphicsId(u8 Id);

/*
void InitEventData(void);
void ClearTempFieldEventData(void);
void ClearUpperFlags(void);
void DisableNationalPokedex(void);
void EnableNationalPokedex(void);
bool32 IsNationalPokedexEnabled(void);
void DisableMysteryEvent(void);
void EnableMysteryEvent(void);
bool32 IsMysteryEventEnabled(void);
void DisableMysteryGift(void);
void EnableMysteryGift(void);
bool32 IsMysteryGiftEnabled(void);
void sub_809D4D8(void);
void sub_809D570(void);
void DisableResetRTC(void);
void EnableResetRTC(void);
bool32 CanResetRTC(void);
u8 VarGetFieldObjectGraphicsId(u8 id);
u16 * GetVarPointer(u16 id);
bool32 sub_806E2BC(void);
void sub_806E6FC(void);
*/

#define Var8000 (*((u16*) 0x20375D8))
#define Var8001 (*((u16*) 0x20375DA))
#define Var8002 (*((u16*) 0x20375DC))
#define Var8003 (*((u16*) 0x20375DE))
#define Var8004 (*((u16*) 0x20375E0))
#define Var8005 (*((u16*) 0x20375E2))
#define Var8006 (*((u16*) 0x20375E4))
#define Var8007 (*((u16*) 0x20375E6))
#define Var8008 (*((u16*) 0x20375E8))
#define Var8009 (*((u16*) 0x20375EA))
#define Var800A (*((u16*) 0x20375EC))
#define Var800B (*((u16*) 0x20375EE))
#define Var800D (*((u16*) 0x20375F0))


#define gSpecialVar_LastResult (*((u16*) 0x20370D0)) //extern u16 gSpecialVar_Result;
#define gSpecialVar_LastTalked (*((u16*) 0x20370D2)) //extern u16 gSpecialVar_LastTalked;
#define gSpecialVar_PlayerFacing (*((u16*) 0x20370D4)) //extern u16 gSpecialVar_PlayerFacing;
#define gSpecialVar_MonBoxId (*((u16*) 0x20370D6)) //extern u16 gSpecialVar_MonBoxId;
#define gSpecialVar_MonBoxPos (*((u16*) 0x20370D8)) //extern u16 gSpecialVar_MonBoxPos;

/*
extern u16 gSpecialVar_0x8000;
extern u16 gSpecialVar_0x8001;
extern u16 gSpecialVar_0x8002;
extern u16 gSpecialVar_0x8003;
extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
extern u16 gSpecialVar_0x8006;
extern u16 gSpecialVar_0x8007;
extern u16 gSpecialVar_0x8008;
extern u16 gSpecialVar_0x8009;
extern u16 gSpecialVar_0x800A;
extern u16 gSpecialVar_0x800B;
extern u16 gSpecialVar_Facing;
extern u16 gSpecialVar_0x8014;

extern u16 gUnknown_20370D0;
extern u16 gUnknown_20370C0;
*/
