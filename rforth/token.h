// token.h
#ifndef TOKEN_H
#define TOKEN_H
#include "int_stack.h"
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    BOOLEAN,
    COMMAND,
    VARIABLE,
    UNKNOWN 
} token_type_t;

typedef struct {
    token_type_t type;
    char* text;
} token_t;

// Function declarations
extern token_t* new_token(token_type_t type, const char* text);
extern void print_token(const token_t* token);
extern token_t* classify_and_create_token(const char* text);
extern void free_token(token_t* token);
extern void process_token(token_t* token, int_stack_t* stack);

#endif // TOKEN_H
