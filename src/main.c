#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/workspaces/motion/src/include/chunk.h"
#include "/workspaces/motion/src/include/common.h"
#include "/workspaces/motion/src/include/debug.h"
#include "/workspaces/motion/src/include/memory.h"
#include "/workspaces/motion/src/include/vm.h"

static void repl() {
    printf("Motion v0.05\n");
    printf("Ctrl-C to Exit\n");
    printf("\n");
    char line[1024];
    for (;;) {
        printf(ANSI_COLOR_BLACK "~> " ANSI_COLOR_RESET);

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
        fprintf(stderr,
                ANSI_COLOR_RED
                "Err: BadFileErr | File: \"%s\" could not be found\n",
                path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, ANSI_COLOR_RED "Err: OutOfMemoryErr | File: \"%s\".\n",
                path);
        exit(74);
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        fprintf(stderr, ANSI_COLOR_RED "Err: FileReadErr | File: \"%s\".\n",
                path);
        printf(ANSI_COLOR_RESET);
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
        if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--info") == 0)) {
            printf("Motion v0.0.5\n");
            printf("\n");
            printf(
                "Motion is licensed under GPLv3. See "
                "https://www.gnu.org/licenses/gpl-3.0.en.html for more "
                "information.\n");
            printf("\n");
            printf("Type -h for help.\n");
        } else if ((strcmp(argv[1], "-h") == 0) ||
                   (strcmp(argv[1], "--help") == 0)) {
            printf("Help:\n");
            printf("--help / -h: This command\n");
            printf("--info / -i: Information about Motion\n");
            printf(
                "--run / -r:  Run a file. The final argument is the path to the "
                "file you wish to execute\n");

        } else {
            fprintf(stderr, ANSI_COLOR_RED "motion: Invalid Command\n");
            printf(ANSI_COLOR_RESET);
        }
    } else if (argc == 3) {
        if ((strcmp(argv[1], "--run")) || (strcmp(argv[1], "-r")) == 0) {
            runFile(argv[2]);
        }

    } else {
        fprintf(stderr, "motion: Invalid Command");
    }

    freeVM();
    return 0;
}