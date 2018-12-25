#include <stdlib.h>
#include <err.h>

#include "cpu.h"
#include "mem.h"

#include "util.h"
#include "opcode_names.h"

const char* docs_prefix = "https://www.masswerk.at/6502/6502_instruction_set.html#";
#define DOCS_PREFIX_LENGTH 55

#define NMI_PC_LOCATION 0xFFFA

byte read_byte_and_inc_pc(memory* mem) {
    byte data = read_byte(mem, mem->pc);
    mem->pc++;
    return data;
}

uint16_t read_address(memory* mem, uint16_t address) {
    byte lower = read_byte(mem, address);
    byte upper = read_byte(mem, address + 1);
    return (upper << 8) | lower;
}

uint16_t read_address_and_inc_pc(memory* mem) {
    byte lower = read_byte_and_inc_pc(mem);
    byte upper = read_byte_and_inc_pc(mem);
    return (upper << 8) | lower;
}

int cpu_steps = 0;

typedef enum addressing_mode_t {
    Immediate,
    Zeropage,
    Zeropage_X,
    Absolute,
    Absolute_X,
    Absolute_Y,
    Indirect_X,
    Indirect_Y,
    Accumulator
} addressing_mode;

// TODO: handle pages crossed cases
uint16_t indirect_y_address(memory* mem, int* cycles) {
    byte b = read_byte_and_inc_pc(mem);
    uint16_t address = read_address(mem, b) + mem->y;

    return address;
}

// TODO: handle pages crossed cases
uint16_t absolute_x_address(memory* mem, int* cycles) {
    uint16_t addr = read_address_and_inc_pc(mem);
    addr += mem->x;
    return addr;
}

// TODO: handle pages crossed cases
uint16_t absolute_y_address(memory* mem, int* cycles) {
    uint16_t addr = read_address_and_inc_pc(mem);
    addr += mem->x;
    return addr;
}

// TODO: handle pages crossed cases
byte read_value(memory* mem, int* cycles, addressing_mode mode) {
    switch (mode) {
        case Immediate:
            return read_byte_and_inc_pc(mem);

        case Absolute:
            return read_byte(mem, read_address_and_inc_pc(mem));

        case Absolute_X: {
            return read_byte(mem, absolute_x_address(mem, cycles));
        }

        case Absolute_Y: {
            return read_byte(mem, absolute_y_address(mem, cycles));
        }

        default:
            errx(EXIT_FAILURE, "Addressing mode not implemented.");
    }
}

void branch_on_condition(memory* mem, int* cycles, bool condition) {
    // Read as a signed byte
    int8_t offset = read_byte_and_inc_pc(mem);
    if (condition) {
        uint16_t newaddr = mem->pc + offset;
        printf("Branch condition hit, branching! offset: %d (0x%x) newaddr: 0x%x\n", offset, offset, newaddr);
        *cycles += SAME_PAGE(mem->pc, newaddr) ? 1 : 2;
        mem->pc = newaddr;
    }
    else {
        printf("Did not hit branch condition, not branching!\n");
    }
}

void cmp(memory* mem, byte reg, byte value) {
    byte result = reg - value;
    set_p_zn_on(mem, result);
    if (result >= 0) {
        set_p_carry(mem);
    }
    else {
        clear_p_carry(mem);
    }
}

void php(memory* mem) {
}

int interrupt_nmi(memory* mem) {
    stack_push16(mem, mem->pc);
    php(mem);
    mem->pc = read_address(mem, NMI_PC_LOCATION);
    set_p_interrupt(mem);
    return 7;
}

interrupt_type interrupt = NONE;

int interrupt_cpu_step(memory* mem) {
    // Before doing the step, see if there was an interrupt triggered
    if (interrupt == nmi) {
        return interrupt_nmi(mem);
    }
    errx(EXIT_FAILURE, "Interrupt type not implemented");
}
    
int normal_cpu_step(memory* mem) {
    uint16_t old_pc = mem->pc;
    byte opcode = read_byte_and_inc_pc(mem);
    printf("%05d $%04x: Executing instruction %s\n", cpu_steps++, old_pc, opcode_to_name_full(opcode));

    int cycles = 0;

    switch (opcode) {
        case BRK:
            // Set interrupt flag on status register
            set_p_interrupt(mem);
            mem->pc++; // Skip next byte
            cycles = 7;
            break;

        case SEI:
            set_p_interrupt(mem);
            cycles = 2;
            break;

        case STA_Absolute: // STA Absolute
            write_byte(mem, read_address_and_inc_pc(mem), mem->a);
            cycles = 4;
            break;

        case STA_Absolute_Y:
            cycles = 5;
            write_byte(mem, absolute_y_address(mem, &cycles), mem->a);
            break;

        case STA_Zeropage:
            cycles = 3;
            write_byte(mem, read_byte_and_inc_pc(mem), mem->a);
            break;

        case STA_Indirect_Y: {
            cycles = 6;
            write_byte(mem, indirect_y_address(mem, &cycles), mem->a);
            break;
        }

        case STX_Zeropage:
            cycles = 3;
            write_byte(mem, read_byte_and_inc_pc(mem), mem->x);
            break;

        case TXS:
            mem->sp = mem->x;
            cycles = 2;
            break;

        case TXA: {
            cycles = 2;
            mem->a = mem->x;
            set_p_zn_on(mem, mem->a);
            break;
        }

        case LDX_Immediate:
            mem->x = read_value(mem, &cycles, Immediate);
            set_p_zn_on(mem, mem->x);
            cycles = 2;
            break;

        case LDY_Immediate:
            mem->y = read_value(mem, &cycles, Immediate);
            set_p_zn_on(mem, mem->y);
            cycles = 2;
            break;

        case LDA_Immediate:
            mem->a = read_value(mem, &cycles, Immediate);
            set_p_zn_on(mem, mem->a);
            cycles = 2;
            break;

        case LDA_Absolute:
            //mem->a = read_byte(mem, read_address_and_inc_pc(mem));
            mem->a = read_value(mem, &cycles, Absolute);
            set_p_zn_on(mem, mem->a);
            cycles = 4;
            break;

        case LDA_Absolute_X: {
            mem->a = read_value(mem, &cycles, Absolute_X);
            set_p_zn_on(mem, mem->a);
            break;
        }

        case CLD:
            clear_p_decimal(mem);
            cycles = 2;
            break;

        case BPL: {
            cycles = 2;
            branch_on_condition(mem, &cycles, get_p_negative(mem) == false);
            break;
        }

        case BCS: {
            cycles = 2;
            branch_on_condition(mem, &cycles, get_p_carry(mem) == true);
            break;
        }

        case BNE: {
            cycles = 2;
            branch_on_condition(mem, &cycles, get_p_zero(mem) == false);
            break;
        }

        case CMP_Immediate: {
            cycles = 2;
            cmp(mem, mem->a, read_value(mem, &cycles, Immediate));
            break;
        }

        case CPY_Immediate: {
            cycles = 2;
            cmp(mem, mem->y, read_value(mem, &cycles, Immediate));
            break;
        }

        case CPY_Absolute: {
            cycles = 4;
            cmp(mem, mem->y, read_value(mem, &cycles, Absolute));
            break;
        }

        case CPX_Immediate: {
            cycles = 2;
            cmp(mem, mem->x, read_value(mem, &cycles, Immediate));
            break;
        }

        case JSR: {
            cycles = 6;
            uint16_t addr = read_address_and_inc_pc(mem);
            stack_push16(mem, mem->pc); // TODO: should this be mem->pc+1?
            mem->pc = addr;
            break;
        }

        case RTS: {
            cycles = 6;
            uint16_t addr = stack_pop16(mem);
            mem->pc = addr;
            break;
        }

        case DEY: {
            cycles = 2;
            mem->y--;
            set_p_zn_on(mem, mem->y);
            break;
        }

        case DEX: {
            cycles = 2;
            mem->x--;
            set_p_zn_on(mem, mem->x);
            break;
        }

        case INY: {
            mem->y++;
            cycles = 2;
            set_p_zn_on(mem, mem->y);
            break;
        }

        case INX: {
            mem->x++;
            cycles = 2;
            set_p_zn_on(mem, mem->x);
            break;
        }

        case INC_Absolute: {
            cycles = 6;
            uint16_t addr = read_address_and_inc_pc(mem);
            byte value = read_byte(mem, addr);
            value++;
            write_byte(mem, addr, value);
            break;
        }

        case BIT_Absolute: {
            cycles = 4;
            byte operand = read_value(mem, &cycles, Absolute);
            bool new_negative = (mask_flag(P_NEGATIVE) & operand) > 0;
            bool new_overflow = (mask_flag(P_OVERFLOW) & operand) > 0;
            set_p_negative_to(mem, new_negative);
            set_p_overflow_to(mem, new_overflow);
            set_p_zero_on(mem, operand & mem->a);
            break;
        }

        case ORA_Immediate: {
            cycles = 2;
            mem->a |= read_value(mem, &cycles, Immediate);
            set_p_zn_on(mem, mem->a);
            break;
        }

        case AND_Immediate: {
            cycles = 2;
            mem->a &= read_value(mem, &cycles, Immediate);
            set_p_zn_on(mem, mem->a);
            break;
        }

        case JMP_Absolute: {
            cycles = 3;
            mem->pc = read_address_and_inc_pc(mem);
            break;
        }

        default: {
            const char* opcode_short = opcode_to_name_short(opcode);
            char docs_link[DOCS_PREFIX_LENGTH + 10];
            snprintf(docs_link, sizeof(docs_link), "%s%s", docs_prefix, opcode_short);
            errx(EXIT_FAILURE, "Opcode not implemented: %s hex 0x%x\nSee %s", opcode_to_name_full(opcode), opcode, docs_link);
        }
    }

    return cycles;
}

int cpu_step(memory* mem) {
    if (interrupt != NONE) {
        return interrupt_cpu_step(mem);
    }
    else {
        return normal_cpu_step(mem);
    }
}

