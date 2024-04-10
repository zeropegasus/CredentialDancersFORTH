// main.c
#include "int_stack.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int_stack_t stack;
    int_stack_init(&stack, 15);

    printf("Enter your R-FORTH code (CTRL+D to end):\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        char* token_text;
        const char* delim = " \t\n"; // Token delimiters: space, tab, newline
        token_text = strtok(line, delim);

        while (token_text != NULL) {
            token_t* token = classify_and_create_token(token_text);
            print_token(token);
            // Check the type of token and act accordingly
            if (token->type == NUMBER) {
                // Convert text to integer and push onto stack
                int number = atoi(token->text);
                int_stack_push(&stack, number);
            } else if (token->type == BOOLEAN) {
                // Now the operation can assume numbers are on the stack
                process_token(token, &stack);
            } else if (token->type == OPERATOR) {
                // Now the operation can assume numbers are on the stack
                process_token(token, &stack);
            } else {
                // Handle other token types as necessary
            }
            free_token(token);
           
             // Free the token after printing

            // Move to the next token
            token_text = strtok(NULL, delim);
        }
        int_stack_print(&stack, stdout);
    }

    free(line); // Free the getline buffer
    return 0;



    //Variable manager
     varTable_init(); // Initialize the table
    var_set("x", 10); // Set variable x to 10
    var_set("y", 20); // Set variable y to 20

    int xValue, yValue;
    if (var_get("x", &xValue)) {
        printf("x = %d\n", xValue);
    }

    if (var_get("y", &yValue)) {
        printf("y = %d\n", yValue);
    }

    return 0;
}
