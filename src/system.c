#include "system.h"
#include "cpu.h"
#include "ppu.h"
#include "apu.h"

int system_step(memory* mem) {
    int cpu_steps = cpu_step(mem);
    int ppu_steps = cpu_steps * 3; // 3 PPU steps for every CPU step
    for (int i = 0; i < ppu_steps; i++) {
        ppu_step(&mem->ppu_mem);
    }

    for (int i = 0; i < cpu_steps; i++) {
        apu_step(&mem->apu_mem);
    }

    return cpu_steps;
}
