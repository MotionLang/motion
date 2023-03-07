#ifndef clox_vm_h
#define clox_vm_h

#include "/workspaces/motionLang/include/chunk.h"
#include "/workspaces/motionLang/include/table.h"
#include "/workspaces/motionLang/include/value.h"

#define STACK_MAX 256

// stackTop became stackCount, an int
typedef struct {
    Chunk *chunk;
    uint8_t *ip;
    Value *stack[STACK_MAX];
    Value *stackTop;
    Table strings;
    Obj *objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

#endif