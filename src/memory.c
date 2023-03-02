#include <stdlib.h>

#include "/workspaces/motion/include/memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    // Null Case Handling.
    if (result == NULL) exit(1);
    return result;
}