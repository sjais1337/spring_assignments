#include "parser.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

uint16_t get_opcode(state_ *state){
    // TODO: write a function which combines two bytes into a single
    // chip8 instruction to be used by the Virtual CPU.
}

void inst_jump(state_ *state, uint16_t nnn){
    // TODO: Implement instruction
}

void inst_call(state_ *state, uint16_t nnn){
    // TODO: Implement instruction
}

void inst_ret(state_ *state){
    // TODO: Implement instruction
}

void inst_skip_byte_eq(state_ *state, uint8_t x, uint8_t kk){
    // TODO: Implement instruction
}

void inst_add_x_y(state_ *state, uint8_t x, uint8_t y){
    // TODO: Implement instruction
}

void inst_sub_x_y(state_ *state, uint8_t x, uint8_t y){
    // TODO: Implement instruction
}

void inst_shr_x(state_ *state, uint8_t x){
    // TODO: Implement instruction
}

void inst_shl_x(state_ *state, uint8_t x){
    // TODO: Implement instruction
}

void inst_draw(state_ *state, uint8_t x, uint8_t y, uint8_t n){
    // TODO: Implement instruction
}


void parse_opcode(uint16_t opcode, state_* state){
    // TODO: Initialize the following variables.

    uint16_t nnn;
    uint8_t n;
    uint8_t x;
    uint8_t y;
    uint8_t kk;

    // No todo here
    switch(opcode & 0xF000){
        case 0x0000: 
            switch (opcode & 0x00FF){
                case 0xEE: inst_ret(state); break;
            }
            break;
        case 0x1000: inst_jump(state, nnn); break;
        case 0x2000: inst_call(state, nnn); break;
        case 0x3000: inst_skip_byte_eq(state, x, kk); break;
        case 0x8000: 
            switch(n){
                case 0x4: inst_add_x_y(state, x, y); break;
                case 0x5: inst_sub_x_y(state, x, y); break;
                case 0x6: inst_shr_x(state, x); break;
                case 0xE: inst_shl_x(state, x); break;
            }
            break;
        case 0xD000: inst_draw(state, x, y, n); break;
        case 0xE000: 
            switch(opcode & 0x00FF){
            }
            break;
        case 0xF000:
            switch(opcode & 0x00FF){
            }
            break;
        default: break; 
    }
}