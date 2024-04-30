// token.c
#include "token.h"
#include "int_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

token_t* new_token(token_type_t type, const char* text) {
    token_t* token = (token_t*)malloc(sizeof(token_t));
    token->type = type;
    token->text = strdup(text);
    return token;
}

void print_token(const token_t* token) {
    const char* type_str = "";
    switch (token->type) {
        case NUMBER:
            type_str = "Number";
            break;
        case OPERATOR:
            type_str = "Operator";
            break;
        case SYMBOL:
            type_str = "Symbol";
            break;
        case WORD:
            type_str = "Word";
            break;
        case BOOLEAN:
            type_str = "Boolean";
            break;
        case COMMAND:
            type_str = "Command";  // Adding a label for COMMAND tokens
            break;
        case VARIABLE:
            type_str = "Variable";  // Adding a label for VARIABLE tokens
            break;
        default:
            type_str = "Unknown";  // This will handle any other unclassified types
            break;
    }
    printf("Token: Type = %s, Text = %s\n", type_str, token->text);
}


token_t* classify_and_create_token(const char* text) {
    // First check for a number that might have letters following it, indicating a command
    if (isdigit(text[0]) || (text[0] == '-' && isdigit(text[1]))) {
        int i = 1;
        // Skip all digits to see if any non-digit characters follow
        while (isdigit(text[i]) || text[i] == '.') i++;
        // If non-digit characters follow, it's a command, not a simple number
        if (text[i] != '\0') {
            return new_token(COMMAND, text);
        } else {
            return new_token(NUMBER, text);
        }
    } else if (isalpha(text[0])) {
        // Check common stack operations explicitly
        if (strcmp(text, "pop") == 0 || strcmp(text, "swap") == 0 || strcmp(text, "dup") == 0 || 
            strcmp(text, "over") == 0 || strcmp(text, "rot") == 0 || strcmp(text, "drop") == 0 || 
            strcmp(text, "2swap") == 0 || strcmp(text, "2dup") == 0 || strcmp(text, "2over") == 0 || 
            strcmp(text, "2drop") == 0 || strcmp(text, "clear") == 0 || strcmp(text, "set") == 0 || strcmp(text, "get") == 0) {
            return new_token(COMMAND, text);  
        } else {
            return new_token(VARIABLE, text);
        }
    } else if (strchr("+-*/%", text[0]) && strlen(text) == 1) {
        return new_token(OPERATOR, text);
    } else if (strchr(":;", text[0]) && strlen(text) == 1) {
        return new_token(SYMBOL, text);
    } else if (strchr(">&=!|<", text[0]) && strlen(text) == 1) {
        return new_token(BOOLEAN, text);
    } else {
        return new_token(WORD, text);
    }
}




void free_token(token_t* token) {
    if (token) {
        free(token->text); // Free the string
        free(token); // Then free the token itself
    }
}

void process_token(token_t* token, int_stack_t* stack) {
    switch (token->type) {
        case COMMAND:
            if (strcmp(token->text, "set") == 0) {
                char* varName = strtok(NULL, " \t\n"); // Get variable name
                char* varValue = strtok(NULL, " \t\n"); // Get variable value
                int value = atoi(varValue);
                int_stack_set_var(varName, value, 0); // Assuming non-constant variable for simplicity
            } else if (strcmp(token->text, "get") == 0) {
                char* varName = strtok(NULL, " \t\n");
                int value;
                if (int_stack_get_var(varName, &value)) {
                    printf("%s = %d\n", varName, value);
                }
            }
            break;
        case BOOLEAN: // Use the correct token type as per your naming convention
            if (strcmp(token->text, "&") == 0) {
                int_stack_logical_and(stack);
            } else if (strcmp(token->text, "|") == 0) {
                int_stack_logical_or(stack);
            } else if (strcmp(token->text, "=") == 0) {
                int_stack_equals(stack);
            } else if (strcmp(token->text, ">") == 0) {
                int_stack_greater_than(stack);
            } else if (strcmp(token->text, "<") == 0) {
                int_stack_less_than(stack);
            } else if (strcmp(token->text, "!") == 0) {
                int_stack_logical_not(stack);
            }
            // As these functions operate directly on the stack, no result variable is needed here
            break;
        case OPERATOR: // New case for arithmetic operators
            if (strcmp(token->text, "+") == 0) {
                int_stack_add(stack);
            } else if (strcmp(token->text, "-") == 0) {
                int_stack_sub(stack);
            } else if (strcmp(token->text, "*") == 0) {
                int_stack_mul(stack);
            } else if (strcmp(token->text, "/") == 0) {
                int_stack_div(stack);
            } else if (strcmp(token->text, "%") == 0) {
                int_stack_mod(stack);
            } else if (strcmp(token->text, "divmod") == 0) {
                int_stack_divmod(stack);
            }
            break;
        // Handle other cases as necessary
    }
}

