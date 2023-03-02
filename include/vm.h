#ifndef clox_vm_h
#define clox_vm_h

#include "/workspaces/motion/include/chunk.h"
#include "/workspaces/motion/include/value.h"

#define STACK_MAX 256


//stackTop becomes stackCount, an int
typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    Value* stack;
    int stackCount;
    int stackCapacity;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();


#endif