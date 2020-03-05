#ifndef GUARD_MALLOC_H
#define GUARD_MALLOC_H

#include "global.h"

#define HEAP_SIZE 0x1C000
#define malloc Alloc
#define calloc(ct, sz) AllocZeroed((ct) * (sz))
#define free Free

#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    free(ptr);                          \
    ptr = NULL;                         \
}

extern u8 gHeap[];
void __attribute__((long_call)) *Alloc(u32 size);
void __attribute__((long_call)) *AllocZeroed(u32 size);
void Free(void *pointer);
void InitHeap(void *pointer, u32 size);

void* __attribute__((long_call)) Malloc(u32 size);
void* __attribute__((long_call)) Calloc(u32 size);
void __attribute__((long_call)) InitHeap(void* memStart, u32 memSize);
void __attribute__((long_call)) Free(void *pointer);

void* __attribute__((long_call)) memcpy_(void *dst, const void* src, u8 size);
void* __attribute__((long_call)) memset_(void *dst, u8 pattern, u8 size);

void* __attribute__((long_call)) Memcpy(void *dst, const void *src, u32 size);
void* __attribute__((long_call)) Memset(void *dst, u8 pattern, u32 size);

#endif // GUARD_MALLOC_H
