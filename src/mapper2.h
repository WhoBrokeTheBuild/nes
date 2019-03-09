#pragma once
#include <stdint.h>
#include "util.h"
#include "mem.h"
byte mapper2_prg_read(memory* mem, uint16_t address);
void mapper2_prg_write(memory* mem, uint16_t address, byte value);
byte mapper2_chr_read(ppu_memory* ppu_mem, uint16_t address);
void mapper2_chr_write(ppu_memory* ppu_mem, uint16_t address, byte value);