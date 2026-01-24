#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <stdbool.h>

#define HEIGHT 32
#define WIDTH 64
#define MAX_ROM_SIZE 4096 - 512

typedef struct{
    // TODO: Write out the things that should be present in the 
    // state of the program, stuff which should be known at eve
    // ry point of execution.
} state_;

void init_chip(state_ *state);
void state_update_keypad(state_ *state, char key, bool pressed);
uint8_t map_key_to_chip8(char key);

#endif 