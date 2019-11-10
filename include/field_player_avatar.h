#pragma once

#include "global.h"

bool8 __attribute__((long_call)) TestPlayerAvatarFlags(u8);
void __attribute__((long_call)) SetPlayerAvatarTransitionFlags(u16 a);
bool8 __attribute__((long_call)) PartyHasMonWithSurfOriginal(void);
bool8 __attribute__((long_call)) IsPlayerFacingSurfableFishableWater(void);
bool8 __attribute__((long_call)) IsPlayerSurfingNorth(void);
void __attribute__((long_call)) PlayerGetDestCoords(s16* x, s16* y);
u8 __attribute__((long_call)) TestPlayerAvatarFlags(u8 a);
u8 __attribute__((long_call)) PlayerGetZCoord(void);
void __attribute__((long_call)) SetPlayerAvatarStateMask(u8 a);
void __attribute__((long_call)) sub_8150498(u8 state);
void __attribute__((long_call)) ClearPlayerAvatarInfo(void);
void __attribute__((long_call)) GetXYCoordsOneStepInFrontOfPlayer(s16* xPtr, s16* yPtr);

//In Engine
u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u16 GetPlayerAvatarGraphicsIdByStateId(u8 state);
