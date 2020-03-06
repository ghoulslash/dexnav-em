#pragma once

#define FLAG_POKETOOLS_MENU 0x265   // temp flag for secondary menu
#define FLAG_SYS_POKETOOLS_GET 0x264    // flag to add poketools to menu

#define sDNavState (*((struct DexnavHudData**) 0x203CF80))  // dex nav data pointer in ram