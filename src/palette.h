#pragma once
#include "ppu.h"

color rgb_palette[] = {
    { .r = 0x66, .g=0x66, .b=0x66, .a=0xFF },
    { .r = 0x00, .g=0x2A, .b=0x88, .a=0xFF },
    { .r = 0x14, .g=0x12, .b=0xA7, .a=0xFF },
    { .r = 0x3B, .g=0x00, .b=0xA4, .a=0xFF },
    { .r = 0x5C, .g=0x00, .b=0x7E, .a=0xFF },
    { .r = 0x6E, .g=0x00, .b=0x40, .a=0xFF },
    { .r = 0x6C, .g=0x06, .b=0x00, .a=0xFF },
    { .r = 0x56, .g=0x1D, .b=0x00, .a=0xFF },
    { .r = 0x33, .g=0x35, .b=0x00, .a=0xFF },
    { .r = 0x0B, .g=0x48, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x52, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x4F, .b=0x08, .a=0xFF },
    { .r = 0x00, .g=0x40, .b=0x4D, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0xAD, .g=0xAD, .b=0xAD, .a=0xFF },
    { .r = 0x15, .g=0x5F, .b=0xD9, .a=0xFF },
    { .r = 0x42, .g=0x40, .b=0xFF, .a=0xFF },
    { .r = 0x75, .g=0x27, .b=0xFE, .a=0xFF },
    { .r = 0xA0, .g=0x1A, .b=0xCC, .a=0xFF },
    { .r = 0xB7, .g=0x1E, .b=0x7B, .a=0xFF },
    { .r = 0xB5, .g=0x31, .b=0x20, .a=0xFF },
    { .r = 0x99, .g=0x4E, .b=0x00, .a=0xFF },
    { .r = 0x6B, .g=0x6D, .b=0x00, .a=0xFF },
    { .r = 0x38, .g=0x87, .b=0x00, .a=0xFF },
    { .r = 0x0C, .g=0x93, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x8F, .b=0x32, .a=0xFF },
    { .r = 0x00, .g=0x7C, .b=0x8D, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0xFF, .g=0xFE, .b=0xFF, .a=0xFF },
    { .r = 0x64, .g=0xB0, .b=0xFF, .a=0xFF },
    { .r = 0x92, .g=0x90, .b=0xFF, .a=0xFF },
    { .r = 0xC6, .g=0x76, .b=0xFF, .a=0xFF },
    { .r = 0xF3, .g=0x6A, .b=0xFF, .a=0xFF },
    { .r = 0xFE, .g=0x6E, .b=0xCC, .a=0xFF },
    { .r = 0xFE, .g=0x81, .b=0x70, .a=0xFF },
    { .r = 0xEA, .g=0x9E, .b=0x22, .a=0xFF },
    { .r = 0xBC, .g=0xBE, .b=0x00, .a=0xFF },
    { .r = 0x88, .g=0xD8, .b=0x00, .a=0xFF },
    { .r = 0x5C, .g=0xE4, .b=0x30, .a=0xFF },
    { .r = 0x45, .g=0xE0, .b=0x82, .a=0xFF },
    { .r = 0x48, .g=0xCD, .b=0xDE, .a=0xFF },
    { .r = 0x4F, .g=0x4F, .b=0x4F, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0xFF, .g=0xFE, .b=0xFF, .a=0xFF },
    { .r = 0xC0, .g=0xDF, .b=0xFF, .a=0xFF },
    { .r = 0xD3, .g=0xD2, .b=0xFF, .a=0xFF },
    { .r = 0xE8, .g=0xC8, .b=0xFF, .a=0xFF },
    { .r = 0xFB, .g=0xC2, .b=0xFF, .a=0xFF },
    { .r = 0xFE, .g=0xC4, .b=0xEA, .a=0xFF },
    { .r = 0xFE, .g=0xCC, .b=0xC5, .a=0xFF },
    { .r = 0xF7, .g=0xD8, .b=0xA5, .a=0xFF },
    { .r = 0xE4, .g=0xE5, .b=0x94, .a=0xFF },
    { .r = 0xCF, .g=0xEF, .b=0x96, .a=0xFF },
    { .r = 0xBD, .g=0xF4, .b=0xAB, .a=0xFF },
    { .r = 0xB3, .g=0xF3, .b=0xCC, .a=0xFF },
    { .r = 0xB5, .g=0xEB, .b=0xF2, .a=0xFF },
    { .r = 0xB8, .g=0xB8, .b=0xB8, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF },
    { .r = 0x00, .g=0x00, .b=0x00, .a=0xFF }
};
