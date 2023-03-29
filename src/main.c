#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/workspaces/motion/src/include/chunk.h"
#include "/workspaces/motion/src/include/common.h"
#include "/workspaces/motion/src/include/debug.h"
#include "/workspaces/motion/src/include/memory.h"
#include "/workspaces/motion/src/include/vm.h"

static void repl() {
    printf("Motion v0.05");
    printf("\n");
    char line[1024];
    for (;;) {
        printf("Motion $ ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

static char* readFile(const char* path) {
    FILE* file = fopen(path, "rb");

    if (file == NULL) {
        fprintf(stderr, "Err: BadFileErr | File: \"%s\".\n", path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Err: OutOfMemoryErr | File: \"%s\".\n", path);
        exit(74);
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        fprintf(stderr, "Err: FileReadErr | File: \"%s\".\n", path);
        exit(74);
    }

    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}

static void runFile(const char* path) {
    char* source = readFile(path);
    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR) exit(65);
    if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {
    initVM();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        if ((strcmp(argv[1], "--info")) || (strcmp(argv[1], "-i") == 0)) {
            printf("Motion v0.0.5\n");
            printf("\n");
        } else if ((strcmp(argv[1], "--help")) || (strcmp(argv[1], "-h") == 0)) {
            printf("Help:\n");
            printf("No Command: Launch REPL\n");
            printf("info: Information about Motion\n");
            printf("run:  Run file\n");
            printf("help: This command\n");
        } else {
            fprintf(stderr, "Invalid Command");
        }
    } else if (argc == 3) {
        if ((strcmp(argv[1], "--run")) || (strcmp(argv[1], "-r")) == 0) {
            runFile(argv[2]);
        }

    } else {
        fprintf(stderr, "Invalid Command");
    }

    freeVM();
    return 0;
}