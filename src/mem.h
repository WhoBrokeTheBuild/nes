#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "mapper/rom.h"
#include "util.h"
#include "ppu.h"
#include "apu.h"
#include "controller.h"

typedef struct controller_t {
    button index;
    byte lastwrite;
    bool allread;
} controller;

typedef struct memory_t {
    // accumulator
    byte a;

    // x index register
    byte x;

    // y index register
    byte y;

    // stack pointer
    byte sp;

    // program counter
    uint16_t pc;

    // processor status register (bitwise flags)
    // NV-BDIZC
    byte p;

    // currently loaded nes rom
    rom* r;

    // PPU
    ppu_memory ppu_mem;

    // APU
    apu_memory apu_mem;

    // Internal RAM
    byte ram[0x800];

    controller ctrl1;
} memory;

byte read_byte(memory* mem, uint16_t address);
void write_byte(memory* mem, uint16_t address, byte value);


void set_flag(memory* mem, int index);
void clear_flag(memory* mem, int index);
int get_flag(memory* mem, int index);


memory* get_blank_memory(rom* r);

void load_rom_into_memory(memory* mem, rom* r);

#define P_NEGATIVE 7
#define P_OVERFLOW 6
#define P_BREAK 4
#define P_DECIMAL 3
#define P_INTERRUPT 2
#define P_ZERO 1
#define P_CARRY 0


#define SAME_PAGE(addr1, addr2) (addr1 & 0xFF00) == (addr2 & 0xFF00)

bool is_negative(byte value);

int get_p_negative(memory* mem);
int get_p_overflow(memory* mem);
int get_p_break(memory* mem);
int get_p_decimal(memory* mem);
int get_p_interrupt(memory* mem);
int get_p_zero(memory* mem);
int get_p_carry(memory* mem);

void set_p_negative(memory* mem);
void set_p_overflow(memory* mem);
void set_p_break(memory* mem);
void set_p_decimal(memory* mem);
void set_p_interrupt(memory* mem);
void set_p_zero(memory* mem);
void set_p_carry(memory* mem);

void set_p_negative_to(memory* mem, bool value);
void set_p_overflow_to(memory* mem, bool value);
void set_p_break_to(memory* mem, bool value);
void set_p_decimal_to(memory* mem, bool value);
void set_p_interrupt_to(memory* mem, bool value);
void set_p_zero_to(memory* mem, bool value);
void set_p_carry_to(memory* mem, bool value);

void clear_p_negative(memory* mem);
void clear_p_overflow(memory* mem);
void clear_p_break(memory* mem);
void clear_p_decimal(memory* mem);
void clear_p_interrupt(memory* mem);
void clear_p_zero(memory* mem);
void clear_p_carry(memory* mem);

void set_p_zero_on(memory* mem, byte value);
void set_p_negative_on(memory* mem, byte value);
void set_p_zn_on(memory* mem, byte value);

void stack_push(memory* mem, byte value);
void stack_push16(memory* mem, uint16_t value);

byte stack_pop(memory* mem);
uint16_t stack_pop16(memory* mem);
