#include "/workspaces/motion/src/include/flags.h"

bool FLAG_STRICT = false;

int FLAG_STATE; // 0: REPL
                // 1: Run
                // 2: Compile
                // 3: Interpret