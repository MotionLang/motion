#ifndef clox_debug_h
#define clox_debug_h

#include "/workspaces/motion/src/include/chunk.h"
#include "/workspaces/motion/src/include/common.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif