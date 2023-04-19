#ifndef clox_compiler_h
#define clox_compiler_h

#include "/workspaces/motion/src/include/common.h"
#include "/workspaces/motion/src/include/errors.h"
#include "/workspaces/motion/src/include/object.h"
#include "/workspaces/motion/src/include/vm.h"

ObjFunction* compile(const char* source);
void markCompilerRoots();

#endif