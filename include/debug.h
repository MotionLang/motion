#ifndef clox_debug_h
#define clox_debug_h

#include "/workspaces/codespaces-blank/include/common.h"
#include "/workspaces/codespaces-blank/include/chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif