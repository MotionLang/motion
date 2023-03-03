#include <stdio.h>
#include <stdarg.h>

#include "/workspaces/motion/include/common.h"
#include "/workspaces/motion/include/debug.h"
#include "/workspaces/motion/include/vm.h"
#include "/workspaces/motion/include/memory.h"
#include "/workspaces/motion/include/compiler.h"

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
}

static void runtimeError(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fputs("\n", stderr);

    size_t instruction = vm.ip - vm.chunk->code - 1;
    int line = vm.chunk->lines[instruction];
    fprintf(stderr, "[line %d] in script\n", line);
    resetStack();
}

void initVM() {
    vm.stack = NULL;
    vm.stackCapacity = 0;
    resetStack();
}

void freeVM() {
    
}

void push(Value value) {
    *vm.stackTop = value
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

/*This doesn't work, and I wish I hadn't 
dynamically adjusted the stack size.

The problem lies in the fact that 
stackTop is a pointer, but stackCount
is an int.

It needs to return a value from the
stack without popping. */

/*UPDATE: 
I reverted back to a stack limit. sad.
At least this works now. I think.*/
static Value peek(int distance) {
    return vm.stackTop[-1 - distance]
}

static InterpretResult run() {
    #define READ_BYTE() (*vm.ip++)
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    #define BINARY_OP(valueType, op) \
        do { \
            if(!IS_NUMBER(peek(0)) || !IS_NUMBER(peek(1))) { \
                runtimeError("Invalid Operands"); \
                return INTERPRET_RUNTIME_ERROR; \
            } \
            double b = AS_NUMBER(pop()); \
            double a = AS_NUMBER(pop()); \
            push(valueType(a op b)); \
        } while (false)


        for (;;) {
            #ifdef DEBUG_TRACE_EXECUTION
                printf("          ");
                for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
                    printf("[ ");
                    printValue(*slot);
                    printf(" ]");
                }
                printf("\n");
                disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
            #endif
            
            uint8_t instruction;
            switch (instruction = READ_BYTE()) {
                case OP_CONSTANT: {
                    Value constant = READ_CONSTANT();
                    push(constant);
                    break;
                }
                case OP_ADD:      BINARY_OP(NUMBER_VAL, +); break;
                case OP_SUBTRACT: BINARY_OP(NUMBER_VAL, -); break;
                case OP_MULTIPLY: BINARY_OP(NUMBER_VAL, *); break;
                case OP_DIVIDE:  BINARY_OP(NUMBER_VAL, /); break;
                
                case OP_NEGATE:    
                    if (!IS_NUMBER(peek(0))) {
                        runtimeError("InvalidOperatorErr");
                        return INTERPRET_RUNTIME_ERROR;
                    }
                    push(NUMBER_VAL(-AS_NUMBER(pop())));
                    break;
                case OP_RETURN: {
                    printValue(pop());
                    printf("\n");
                    return INTERPRET_OK;
                }
            }
        }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

InterpretResult interpret(const char* source) {
    Chunk chunk;
    initChunk(&chunk);

    if (!compile(source, &chunk)) {
        freeChunk(&chunk);
        return INTERPRET_COMPILE_ERROR;
    }

    vm.chunk = &chunk;
    vm.ip = vm.chunk->code;

    InterpretResult result = run();

    freeChunk(&chunk);
    return result;
}