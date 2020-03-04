#pragma once

#define FLAG_POKETOOLS_MENU 0x4FF   // temp flag for secondary menu
#define FLAG_SYS_POKETOOLS_GET 0x264    // flag to add poketools to menu

#define sDNavState (*((struct DexnavHudData**) 0x203E038))  // dex nav data pointer in ram