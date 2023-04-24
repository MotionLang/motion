#ifndef clox_errors_h
#define clox_errors_h

#include "/workspaces/motion/src/include/common.h"
#include "/workspaces/motion/src/include/scanner.h"

typedef enum {
    // Filler Error (Unused)
    ERR_NO_ERR,
    // Hope you never see these
    ERR_FATAL,
    ERR_OVERFLOW,
    ERR_MEMORY,
    ERR_BAD_TOKEN,
    ERR_BAD_OP,

    // Scanner Errors
    ERR_BAD_CHAR,
    ERR_BAD_STRING,

    // Compiler Errors
    ERR_SYNTAX,
    ERR_PAREN,
    ERR_BLOCK,
    ERR_BAD_LOOP,
    ERR_BAD_VAR,
    ERR_BAD_SUPER,
    ERR_BAD_THIS,
    ERR_MISSING_EXPR,
    ERR_BAD_ASSIGN,
    ERR_BAD_CLASS,
    ERR_BAD_RETURN,

    // VM Errors,
    ERR_BAD_TYPE,
    ERR_BAD_ARGC,
    ERR_BAD_CALL,
    ERR_BAD_PROPERTY,
    ERR_BAD_METHOD,
    ERR_BAD_FIELD,
    ERR_BAD_OPERANDS,
    ERR_UNDEF_VAR,
} errorCode;

char* stringWithArrows(const char* text, const int pos_start,
                       const int pos_end);

#endif