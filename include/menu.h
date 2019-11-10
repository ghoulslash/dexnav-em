#pragma once

#include "global.h"

#include "text.h"
#include "window.h"

struct MenuAction
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } func;
};

struct MoveMenuInfoIcon
{
    u8 width;
    u8 height;
    u16 offset;
};

void __attribute__((long_call)) clear_scheduled_bg_copies_to_vram(void);
void __attribute__((long_call)) reset_temp_tile_data_buffers(void);
int __attribute__((long_call)) decompress_and_copy_tile_data_to_vram(u8 bg_id, const void *src, int size, u16 offset, u8 mode);
bool8 __attribute__((long_call)) free_temp_tile_data_buffers_if_possible(void);

/*
void __attribute__((long_call)) schedule_bg_copy_tilemap_to_vram(u8 bgNum); //Use BgIdMarkForSync
void box_print(u8, u8, u8, u8, const void *, s8, const u8 *);
void sub_8198070(u8 windowId, bool8 copyToVram);
void SetWindowTemplateFields(struct WindowTemplate* template, u8 priority, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 palNum, u16 baseBlock);
void SetWindowBorderStyle(u8 windowId, bool8 copyToVram, u16 tileStart, u8 palette);
void PrintMenuTable(u8 idx, u8 nstrs, const struct MenuAction *strs);
void InitMenuInUpperLeftCornerPlaySoundWhenAPressed(u8 idx, u8 nstrs,u8);
u8 GetMenuCursorPos(void);
s8 ProcessMenuInput(void);
s8 ProcessMenuInputNoWrapAround(void);
void blit_move_info_icon(u8 winId, u8 a2, u16 x, u16 y);
u64 sub_8198A50(struct WindowTemplate*, u8, u8, u8, u8, u8, u8, u16); // returns something but it isn't used, fix when menu.s is decomp'd
void CreateYesNoMenu(const struct WindowTemplate *windowTemplate, u16 borderFirstTileNum, u8 borderPalette, u8 initialCursorPos);
s8 ProcessMenuInputNoWrap_(void);
void do_scheduled_bg_tilemap_copies_to_vram(void);
void AddTextPrinterParametrized2(u8 windowId, u8 fontId, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, const struct TextColor *color, s8 speed, const u8 *str);
void sub_8197B1C(u8 windowId, bool8 copyToVram, u16 a2, u16 a3);
void sub_810F4D8(u8 windowId, bool32 someBool);
*/
