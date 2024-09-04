#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

/*STEP 1. create components*/
// MEMORY
#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];  