#include "opcode_names.h"

#include "cpu.h"

const char* opcode_to_name_full(byte opcode) {
    switch (opcode) {
        case ADC_Immediate:
            return "ADC_Immediate";
        case ADC_Zeropage:
            return "ADC_Zeropage";
        case ADC_Zeropage_X:
            return "ADC_Zeropage_X";
        case ADC_Absolute:
            return "ADC_Absolute";
        case ADC_Absolute_X:
            return "ADC_Absolute_X";
        case ADC_Absolute_Y:
            return "ADC_Absolute_Y";
        case ADC_Indirect_X:
            return "ADC_Indirect_X";
        case ADC_Indirect_Y:
            return "ADC_Indirect_Y";

        case AND_Immediate:
            return "AND_Immediate";
        case AND_Zeropage:
            return "AND_Zeropage";
        case AND_Zeropage_X:
            return "AND_Zeropage_X";
        case AND_Absolute:
            return "AND_Absolute";
        case AND_Absolute_X:
            return "AND_Absolute_X";
        case AND_Absolute_Y:
            return "AND_Absolute_Y";
        case AND_Indirect_X:
            return "AND_Indirect_X";
        case AND_Indirect_Y:
            return "AND_Indirect_Y";

        case ASL_Accumulator:
            return "ASL_Accumulator";
        case ASL_Zeropage:
            return "ASL_Zeropage";
        case ASL_Zeropage_X:
            return "ASL_Zeropage_X";
        case ASL_Absolute:
            return "ASL_Absolute";
        case ASL_Absolute_X:
            return "ASL_Absolute_X";

        case BCC:
            return "BCC";
        case BCS:
            return "BCS";
        case BEQ:
            return "BEQ";

        case BIT_Zeropage:
            return "BIT_Zeropage";
        case BIT_Absolute:
            return "BIT_Absolute";

        case BMI:
            return "BMI";
        case BNE:
            return "BNE";
        case BPL:
            return "BPL";

        case BRK:
            return "BRK";

        case BVC:
            return "BVC";
        case BVS:
            return "BVS";

        case CLC:
            return "CLC";
        case CLD:
            return "CLD";
        case CLI:
            return "CLI";
        case CLV:
            return "CLV";

        case CMP_Immediate:
            return "CMP_Immediate";
        case CMP_Zeropage:
            return "CMP_Zeropage";
        case CMP_Zeropage_X:
            return "CMP_Zeropage_X";
        case CMP_Absolute:
            return "CMP_Absolute";
        case CMP_Absolute_X:
            return "CMP_Absolute_X";
        case CMP_Absolute_Y:
            return "CMP_Absolute_Y";
        case CMP_Indirect_X:
            return "CMP_Indirect_X";
        case CMP_Indirect_Y:
            return "CMP_Indirect_Y";

        case CPX_Immediate:
            return "CPX_Immediate";
        case CPX_Zeropage:
            return "CPX_Zeropage";
        case CPX_Absolute:
            return "CPX_Absolute";

        case CPY_Immediate:
            return "CPY_Immediate";
        case CPY_Zeropage:
            return "CPY_Zeropage";
        case CPY_Absolute:
            return "CPY_Absolute";

        case DEC_Zeropage:
            return "DEC_Zeropage";
        case DEC_Zeropage_X:
            return "DEC_Zeropage_X";
        case DEC_Absolute:
            return "DEC_Absolute";
        case DEC_Absolute_X:
            return "DEC_Absolute_X";

        case DEX:
            return "DEX";
        case DEY:
            return "DEY";

        case EOR_Immediate:
            return "EOR_Immediate";
        case EOR_Zeropage:
            return "EOR_Zeropage";
        case EOR_Zeropage_X:
            return "EOR_Zeropage_X";
        case EOR_Absolute:
            return "EOR_Absolute";
        case EOR_Absolute_X:
            return "EOR_Absolute_X";
        case EOR_Absolute_Y:
            return "EOR_Absolute_Y";
        case EOR_Indirect_X:
            return "EOR_Indirect_X";
        case EOR_Indirect_Y:
            return "EOR_Indirect_Y";

        case INC_Zeropage:
            return "INC_Zeropage";
        case INC_Zeropage_X:
            return "INC_Zeropage_X";
        case INC_Absolute:
            return "INC_Absolute";
        case INC_Absolute_X:
            return "INC_Absolute_X";

        case INX:
            return "INX";
        case INY:
            return "INY";

        case JMP_Absolute:
            return "JMP_Absolute";
        case JMP_Indirect:
            return "JMP_Indirect";

        case JSR:
            return "JSR";

        case LDA_Immediate:
            return "LDA_Immediate";
        case LDA_Zeropage:
            return "LDA_Zeropage";
        case LDA_Zeropage_X:
            return "LDA_Zeropage_X";
        case LDA_Absolute:
            return "LDA_Absolute";
        case LDA_Absolute_X:
            return "LDA_Absolute_X";
        case LDA_Absolute_Y:
            return "LDA_Absolute_Y";
        case LDA_Indirect_X:
            return "LDA_Indirect_X";
        case LDA_Indirect_Y:
            return "LDA_Indirect_Y";

        case LDX_Immediate:
            return "LDX_Immediate";
        case LDX_Zeropage:
            return "LDX_Zeropage";
        case LDX_Zeropage_Y:
            return "LDX_Zeropage_Y";
        case LDX_Absolute:
            return "LDX_Absolute";
        case LDX_Absolute_Y:
            return "LDX_Absolute_Y";

        case LDY_Immediate:
            return "LDY_Immediate";
        case LDY_Zeropage:
            return "LDY_Zeropage";
        case LDY_Zeropage_X:
            return "LDY_Zeropage_X";
        case LDY_Absolute:
            return "LDY_Absolute";
        case LDY_Absolute_X:
            return "LDY_Absolute_X";

        case LSR_Accumulator:
            return "LSR_Accumulator";
        case LSR_Zeropage:
            return "LSR_Zeropage";
        case LSR_Zeropage_X:
            return "LSR_Zeropage_X";
        case LSR_Absolute:
            return "LSR_Absolute";
        case LSR_Absolute_X:
            return "LSR_Absolute_X";

        case NOP:
            return "NOP";

        case ORA_Immediate:
            return "ORA_Immediate";
        case ORA_Zeropage:
            return "ORA_Zeropage";
        case ORA_Zeropage_X:
            return "ORA_Zeropage_X";
        case ORA_Absolute:
            return "ORA_Absolute";
        case ORA_Absolute_X:
            return "ORA_Absolute_X";
        case ORA_Absolute_Y:
            return "ORA_Absolute_Y";
        case ORA_Indirect_X:
            return "ORA_Indirect_X";
        case ORA_Indirect_Y:
            return "ORA_Indirect_Y";

        case PHA:
            return "PHA";
        case PHP:
            return "PHP";

        case PLA:
            return "PLA";
        case PLP:
            return "PLP";

        case ROL_Accumulator:
            return "ROL_Accumulator";
        case ROL_Zeropage:
            return "ROL_Zeropage";
        case ROL_Zeropage_X:
            return "ROL_Zeropage_X";
        case ROL_Absolute:
            return "ROL_Absolute";
        case ROL_Absolute_X:
            return "ROL_Absolute_X";

        case ROR_Accumulator:
            return "ROR_Accumulator";
        case ROR_Zeropage:
            return "ROR_Zeropage";
        case ROR_Zeropage_X:
            return "ROR_Zeropage_X";
        case ROR_Absolute:
            return "ROR_Absolute";
        case ROR_Absolute_X:
            return "ROR_Absolute_X";

        case RTI:
            return "RTI";
        case RTS:
            return "RTS";

        case SBC_Immediate:
            return "SBC_Immediate";
        case SBC_Zeropage:
            return "SBC_Zeropage";
        case SBC_Zeropage_X:
            return "SBC_Zeropage_X";
        case SBC_Absolute:
            return "SBC_Absolute";
        case SBC_Absolute_X:
            return "SBC_Absolute_X";
        case SBC_Absolute_Y:
            return "SBC_Absolute_Y";
        case SBC_Indirect_X:
            return "SBC_Indirect_X";
        case SBC_Indirect_Y:
            return "SBC_Indirect_Y";

        case SEC:
            return "SEC";
        case SED:
            return "SED";
        case SEI:
            return "SEI";

        case STA_Zeropage:
            return "STA_Zeropage";
        case STA_Zeropage_X:
            return "STA_Zeropage_X";
        case STA_Absolute:
            return "STA_Absolute";
        case STA_Absolute_X:
            return "STA_Absolute_X";
        case STA_Absolute_Y:
            return "STA_Absolute_Y";
        case STA_Indirect_X:
            return "STA_Indirect_X";
        case STA_Indirect_Y:
            return "STA_Indirect_Y";


        case STX_Zeropage:
            return "STX_Zeropage";
        case STX_Zeropage_Y:
            return "STX_Zeropage_Y";
        case STX_Absolute:
            return "STX_Absolute";

        case STY_Zeropage:
            return "STY_Zeropage";
        case STY_Zeropage_X:
            return "STY_Zeropage_X";
        case STY_Absolute:
            return "STY_Absolute";

        case TAX:
            return "TAX";
        case TAY:
            return "TAY";

        case TSX:
            return "TSX";
        case TXA:
            return "TXA";
        case TXS:
            return "TXS";
        case TYA:
            return "TYA";

        default:
            return "INVALID";
    }
}

const char* opcode_to_name_short(byte opcode) {
    switch (opcode) {
        case ADC_Immediate:
        case ADC_Zeropage:
        case ADC_Zeropage_X:
        case ADC_Absolute:
        case ADC_Absolute_X:
        case ADC_Absolute_Y:
        case ADC_Indirect_X:
        case ADC_Indirect_Y:
            return "ADC";

        case AND_Immediate:
        case AND_Zeropage:
        case AND_Zeropage_X:
        case AND_Absolute:
        case AND_Absolute_X:
        case AND_Absolute_Y:
        case AND_Indirect_X:
        case AND_Indirect_Y:
            return "AND";

        case ASL_Accumulator:
        case ASL_Zeropage:
        case ASL_Zeropage_X:
        case ASL_Absolute:
        case ASL_Absolute_X:
            return "ASL";

        case BCC:
            return "BCC";
        case BCS:
            return "BCS";
        case BEQ:
            return "BEQ";

        case BIT_Zeropage:
        case BIT_Absolute:
            return "BIT";

        case BMI:
            return "BMI";
        case BNE:
            return "BNE";
        case BPL:
            return "BPL";

        case BRK:
            return "BRK";

        case BVC:
            return "BVC";
        case BVS:
            return "BVS";

        case CLC:
            return "CLC";
        case CLD:
            return "CLD";
        case CLI:
            return "CLI";
        case CLV:
            return "CLV";

        case CMP_Immediate:
        case CMP_Zeropage:
        case CMP_Zeropage_X:
        case CMP_Absolute:
        case CMP_Absolute_X:
        case CMP_Absolute_Y:
        case CMP_Indirect_X:
        case CMP_Indirect_Y:
            return "CMP";

        case CPX_Immediate:
        case CPX_Zeropage:
        case CPX_Absolute:
            return "CPX";

        case CPY_Immediate:
        case CPY_Zeropage:
        case CPY_Absolute:
            return "CPY";

        case DEC_Zeropage:
        case DEC_Zeropage_X:
        case DEC_Absolute:
        case DEC_Absolute_X:
            return "DEC";

        case DEX:
            return "DEX";
        case DEY:
            return "DEY";

        case EOR_Immediate:
        case EOR_Zeropage:
        case EOR_Zeropage_X:
        case EOR_Absolute:
        case EOR_Absolute_X:
        case EOR_Absolute_Y:
        case EOR_Indirect_X:
        case EOR_Indirect_Y:
            return "EOR";

        case INC_Zeropage:
        case INC_Zeropage_X:
        case INC_Absolute:
        case INC_Absolute_X:
            return "INC";

        case INX:
            return "INX";
        case INY:
            return "INY";

        case JMP_Absolute:
        case JMP_Indirect:
            return "JMP";

        case JSR:
            return "JSR";

        case LDA_Immediate:
        case LDA_Zeropage:
        case LDA_Zeropage_X:
        case LDA_Absolute:
        case LDA_Absolute_X:
        case LDA_Absolute_Y:
        case LDA_Indirect_X:
        case LDA_Indirect_Y:
            return "LDA";

        case LDX_Immediate:
        case LDX_Zeropage:
        case LDX_Zeropage_Y:
        case LDX_Absolute:
        case LDX_Absolute_Y:
            return "LDX";

        case LDY_Immediate:
        case LDY_Zeropage:
        case LDY_Zeropage_X:
        case LDY_Absolute:
        case LDY_Absolute_X:
            return "LDY";

        case LSR_Accumulator:
        case LSR_Zeropage:
        case LSR_Zeropage_X:
        case LSR_Absolute:
        case LSR_Absolute_X:
            return "LSR";

        case NOP:
            return "NOP";

        case ORA_Immediate:
        case ORA_Zeropage:
        case ORA_Zeropage_X:
        case ORA_Absolute:
        case ORA_Absolute_X:
        case ORA_Absolute_Y:
        case ORA_Indirect_X:
        case ORA_Indirect_Y:
            return "ORA";

        case PHA:
            return "PHA";
        case PHP:
            return "PHP";

        case PLA:
            return "PLA";
        case PLP:
            return "PLP";

        case ROL_Accumulator:
        case ROL_Zeropage:
        case ROL_Zeropage_X:
        case ROL_Absolute:
        case ROL_Absolute_X:
            return "ROL";

        case ROR_Accumulator:
        case ROR_Zeropage:
        case ROR_Zeropage_X:
        case ROR_Absolute:
        case ROR_Absolute_X:
            return "ROR";

        case RTI:
            return "RTI";
        case RTS:
            return "RTS";

        case SBC_Immediate:
        case SBC_Zeropage:
        case SBC_Zeropage_X:
        case SBC_Absolute:
        case SBC_Absolute_X:
        case SBC_Absolute_Y:
        case SBC_Indirect_X:
        case SBC_Indirect_Y:
            return "SBC";

        case SEC:
            return "SEC";
        case SED:
            return "SED";
        case SEI:
            return "SEI";

        case STA_Zeropage:
        case STA_Zeropage_X:
        case STA_Absolute:
        case STA_Absolute_X:
        case STA_Absolute_Y:
        case STA_Indirect_X:
        case STA_Indirect_Y:
            return "STA";


        case STX_Zeropage:
        case STX_Zeropage_Y:
        case STX_Absolute:
            return "STX";

        case STY_Zeropage:
        case STY_Zeropage_X:
        case STY_Absolute:
            return "STY";

        case TAX:
            return "TAX";
        case TAY:
            return "TAY";

        case TSX:
            return "TSX";
        case TXA:
            return "TXA";
        case TXS:
            return "TXS";
        case TYA:
            return "TYA";

        /*******************
         * Illegal opcodes *
         *******************/

        // Single NOP
        case 0x1A:
        case 0x3A:
        case 0x5A:
        case 0x7A:
        case 0xDA:
        case 0xFA: 
            return "(NOP)";

        // Double NOP
        case 0x04:
        case 0x14:
        case 0x34:
        case 0x44:
        case 0x54:
        case 0x64:
        case 0x74:
        case 0x80:
        case 0x82:
        case 0x89:
        case 0xC2:
        case 0xD4:
        case 0xE2:
        case 0xF4: 
            return "(DOP)";

        // Triple NOP
        case 0x0C:
        case 0x1C:
        case 0x3C:
        case 0x5C:
        case 0x7C:
        case 0xDC:
        case 0xFC:
            return "(TOP)";

        // LAX: load accumulator and X with memory
        case 0xA7:
        case 0xB7:
        case 0xAF:
        case 0xBF:
        case 0xA3:
        case 0xB3: 
            return "(LAX)";

        // AAX: AND X register with accumulator and store result in memory
        case 0x87:
        case 0x97:
        case 0x83:
        case 0x8F:
            return "(AAX)";

        default:
            return "INVALID";
    }
}

byte opcode_sizes[] = {
        //      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
        /* 0 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* 1 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* 2 */ 3, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* 3 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* 4 */ 1, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* 5 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* 6 */ 1, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* 7 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* 8 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 0, 1, 0, 3, 3, 3, 0,
        /* 9 */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 0, 3, 0, 0,
        /* A */ 2, 2, 2, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* B */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* C */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* D */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
        /* E */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 1, 0, 3, 3, 3, 0,
        /* F */ 2, 2, 0, 0, 2, 2, 2, 0, 1, 3, 1, 0, 3, 3, 3, 0,
};

byte opcode_cycles[] = {
        //      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
        /* 0 */ 7, 6, 2, 8, 3, 3, 5, 5, 3, 2, 2, 2, 4, 4, 6, 6,
        /* 1 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
        /* 2 */ 6, 6, 2, 8, 3, 3, 5, 5, 4, 2, 2, 2, 4, 4, 6, 6,
        /* 3 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
        /* 4 */ 6, 6, 2, 8, 3, 3, 5, 5, 3, 2, 2, 2, 3, 4, 6, 6,
        /* 5 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
        /* 6 */ 6, 6, 2, 8, 3, 3, 5, 5, 4, 2, 2, 2, 5, 4, 6, 6,
        /* 7 */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
        /* 8 */ 2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 2, 4, 4, 4, 4,
        /* 9 */ 2, 6, 2, 6, 4, 4, 4, 4, 2, 5, 2, 5, 5, 5, 5, 5,
        /* A */ 2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 2, 4, 4, 4, 4,
        /* B */ 2, 5, 2, 5, 4, 4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4,
        /* C */ 2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6,
        /* D */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
        /* E */ 2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6,
        /* F */ 2, 5, 2, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7,
};

addressing_mode opcode_addressing_modes[] = {
    Implied,   Indirect_X, Implied,   Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Accumulator, Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
    Absolute,  Indirect_X, Implied,   Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Accumulator, Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
    Implied,   Indirect_X, Implied,   Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Accumulator, Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
    Implied,   Indirect_X, Implied,   Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Accumulator, Immediate,  Indirect,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
    Immediate, Indirect_X, Immediate, Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Implied,     Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_Y, Zeropage_Y, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_Y, Absolute_Y,
    Immediate, Indirect_X, Immediate, Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Implied,     Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_Y, Zeropage_Y, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_Y, Absolute_Y,
    Immediate, Indirect_X, Immediate, Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Implied,     Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
    Immediate, Indirect_X, Immediate, Indirect_X, Zeropage,   Zeropage,   Zeropage,   Zeropage,   Implied, Immediate,  Implied,     Immediate,  Absolute,   Absolute,   Absolute,   Absolute,
    Relative,  Indirect_Y, Implied,   Indirect_Y, Zeropage_X, Zeropage_X, Zeropage_X, Zeropage_X, Implied, Absolute_Y, Implied,     Absolute_Y, Absolute_X, Absolute_X, Absolute_X, Absolute_X,
};
