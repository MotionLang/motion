#ifndef clox_debug_h
#define clox_debug_h

#include "/workspaces/motionLang/include/common.h"
#include "/workspaces/motionLang/include/chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif