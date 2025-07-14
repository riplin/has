//Copyright 2023-Present riplin

#pragma once

#include <has/types.h>
#include <pc.h>

//Absolutely nothing should be moved above or below these calls by the compiler.
inline void SYS_ClearInterrupts() { asm volatile ("cli\n\t"::: "memory"); }
inline void SYS_RestoreInterrupts() { asm volatile ("sti\n\t"::: "memory"); }
inline void SYS_Barrier() { asm volatile (""::: "memory"); }

//This is a time sensitive loop!!!!
inline void SYS_SpinWait(uint32_t cycles){ asm volatile ("1:\n\t" "loop 1b\n\t"::"c" (cycles): "%ecx", "cc", "memory"); }

#ifdef MOCK

extern uint8_t SYS_ReadPortByte(uint16_t reg);
extern void SYS_WritePortByte(uint16_t reg, uint8_t val);
extern void SYS_WritePortBytes(uint16_t reg, uint8_t val1, uint8_t val2);
extern uint16_t SYS_ReadPortShort(uint16_t reg);
extern void SYS_WritePortShort(uint16_t reg, uint16_t val);
extern void SYS_WritePortDouble(uint16_t reg, uint32_t val);
extern uint32_t SYS_ReadPortDouble(uint16_t reg);

#else

inline uint8_t SYS_ReadPortByte(uint16_t reg) { return inportb(reg); }

inline void SYS_WritePortByte(uint16_t reg, uint8_t val) { outportb(reg, val); }

inline void SYS_WritePortBytes(uint16_t reg, uint8_t val1, uint8_t val2) { outportw(reg, (uint16_t(val2) << 8) | val1); }

inline uint16_t SYS_ReadPortShort(uint16_t reg) { return inportw(reg); }

inline void SYS_WritePortShort(uint16_t reg, uint16_t val) { outportw(reg, val); }

inline void SYS_WritePortDouble(uint16_t reg, uint32_t val) { outportl(reg, val); }

inline uint32_t SYS_ReadPortDouble(uint16_t reg) { return inportl(reg); }

#endif