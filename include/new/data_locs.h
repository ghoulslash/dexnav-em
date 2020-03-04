#pragma once

#include "../global.h"
#include "../main.h"
#include "../sprite.h"
//#include "../list_menu.h"

#define gPaletteFade ((struct PaletteFadeControl*) 0x2037FD4)

typedef u8 SpeciesNames_t[POKEMON_NAME_LENGTH + 1];
#define gSpeciesNames ((SpeciesNames_t*) *((u32*) 0x83185C8))

#define gMain (((struct Main*) 0x30022C0)[0])
#define gSprites ((struct Sprite*) 0x2020630)

#define gStringVar4 ((u8*) 0x2021FC4)
