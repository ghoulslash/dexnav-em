#pragma once

//#include "../../src/config.h"

#define MAP_NONE (0x7F | (0x7F << 8))
#define MAP_UNDEFINED (0xFF | (0xFF << 8))

#define MAP_GROUP(map) (MAP_##map >> 8)
#define MAP_NUM(map) (MAP_##map & 0xFF)

#define MAP_ROUTE_1  	((3 << 8) | 19)
#define MAP_ROUTE_2  	((3 << 8) | 20)
#define MAP_ROUTE_3  	((3 << 8) | 21)
#define MAP_ROUTE_4  	((3 << 8) | 22)
#define MAP_ROUTE_5  	((3 << 8) | 23)
#define MAP_ROUTE_6  	((3 << 8) | 24)
#define MAP_ROUTE_7 	((3 << 8) | 25)
#define MAP_ROUTE_8  	((3 << 8) | 26)
#define MAP_ROUTE_9 	((3 << 8) | 27)
#define MAP_ROUTE_10	((3 << 8) | 28)
#define MAP_ROUTE_11 	((3 << 8) | 29)
#define MAP_ROUTE_12 	((3 << 8) | 30)
#define MAP_ROUTE_13 	((3 << 8) | 31)
#define MAP_ROUTE_14 	((3 << 8) | 32)
#define MAP_ROUTE_15 	((3 << 8) | 33)
#define MAP_ROUTE_16 	((3 << 8) | 34)
#define MAP_ROUTE_17 	((3 << 8) | 35)
#define MAP_ROUTE_18 	((3 << 8) | 36)
#define MAP_ROUTE_19 	((3 << 8) | 37)
#define MAP_ROUTE_20 	((3 << 8) | 38)
#define MAP_ROUTE_21_A 	((3 << 8) | 39)
#define MAP_ROUTE_21_B 	((3 << 8) | 40)
#define MAP_ROUTE_22 	((3 << 8) | 41)
#define MAP_ROUTE_23 	((3 << 8) | 42)
#define MAP_ROUTE_24 	((3 << 8) | 43)
#define MAP_ROUTE_25 	((3 << 8) | 44)

u8 __attribute__((long_call)) GetCurrentRegionMapSectionId(void);
