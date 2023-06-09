#ifndef clox_scanner_h
#define clox_scanner_h

#include "value.h"

typedef enum {
    // Single char tokens
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_OPEN_BLOCK,
    TOKEN_CLOSE_BLOCK,
    TOKEN_AT,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_MINUS,
    TOKEN_PLUS,
    TOKEN_SEMICOLON,
    TOKEN_SLASH,
    TOKEN_STAR,
    // One or two char tokens
    TOKEN_BANG,
    TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,
    TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,
    TOKEN_GREATER_EQUAL,
    TOKEN_LESS,
    TOKEN_LESS_EQUAL,
    // Literals
    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_NUMBER,
    // Keywords
    TOKEN_AND,
    TOKEN_CLASS,
    TOKEN_ELSE,
    TOKEN_FALSE,
    TOKEN_FOR,
    TOKEN_FUNC,
    TOKEN_IF,
    TOKEN_NIL,
    TOKEN_OR,
    TOKEN_PRINT,
    TOKEN_RETURN,
    TOKEN_SUPER,
    TOKEN_THIS,
    TOKEN_TRUE,
    TOKEN_USE,
    TOKEN_VAR,
    TOKEN_WHILE,

    // Misc
    TOKEN_NEWLINE,
    TOKEN_ERROR,
    TOKEN_EOF
} TokenType;

typedef struct{
    int number;
    char* contents;
} Line;

typedef struct {
    TokenType type;
    const char* start;
    int length;
    int line;

    Value value;
} Token;

/*
typedef struct {
    const char* start;
    const char* current;
    int line;
} Scanner; */

void initScanner(const char* source);
Token scanToken();

#endif