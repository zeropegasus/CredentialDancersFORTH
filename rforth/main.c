#include "int_stack.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for the execute_command function
void execute_command(const char* command, int_stack_t *stack);

int main() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int_stack_t stack;
    int_stack_init(&stack, 15);  // Initialize the stack with a capacity of 15

    printf("Enter your R-FORTH code (CTRL+D to end):\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        char* token_text;
        const char* delim = " \t\n"; // Token delimiters: space, tab, newline
        token_text = strtok(line, delim);  // This retrieves the first token in the input line.

        while (token_text != NULL) {
            token_t* token = classify_and_create_token(token_text);
            print_token(token);  // This will show the token type and text

            if (token->type == COMMAND && (strcmp(token->text, "set") != 0 && strcmp(token->text, "get") != 0)) {
                // Handle general commands using the execute_command function
                execute_command(token->text, &stack);
            } else {
                switch (token->type) {
                    case NUMBER: {
                        int number = atoi(token->text);
                        int_stack_push(&stack, number);
                        break;
                    }
                    case BOOLEAN:
                    case OPERATOR:
                        process_token(token, &stack);
                        break;
                    case COMMAND:
                        if (strcmp(token->text, "set") == 0) {
                            char* varName = strtok(NULL, delim);
                            char* varValue = strtok(NULL, delim);
                            if (varName && varValue) {
                                int value = atoi(varValue);
                                int_stack_set_var(varName, value, 0);
                                printf("Variable %s set to %d\n", varName, value);
                            } else {
                                printf("Error: Missing arguments for 'set'\n");
                            }
                        } else if (strcmp(token->text, "get") == 0) {
                            char* varName = strtok(NULL, delim);
                            if (varName) {
                                int value;
                                if (int_stack_get_var(varName, &value)) {
                                    int_stack_push(&stack, value);  // Push the retrieved value onto the stack
                                    printf("%s retrieved and pushed to stack: %d\n", varName, value);
                                } else {
                                    printf("Error: Variable '%s' not found\n", varName);
                                }
                            } else {
                                printf("Error: Missing variable name for 'get'\n");
                            }
                        }
                        break;

                    default:
                        printf("Unhandled token type: %s\n", token->text);
                        break;
                }
            }
            token_text = strtok(NULL, delim);  // Move to the next token.
        }
        int_stack_print(&stack, stdout); // Print the current state of the stack
    }

    free(line);
    return 0;
}

void execute_command(const char* command, int_stack_t *stack) {
    if (strcmp(command, "push") == 0) {
        char* numStr = strtok(NULL, " \t\n");
        if (numStr) {
            int num = atoi(numStr);
            int_stack_push(stack, num);
        }
    } else if (strcmp(command, "pop") == 0) {
        int value;
        if (int_stack_pop(stack, &value)) {
            printf("Popped: %d\n", value);
        }
    } else if (strcmp(command, "dup") == 0) {
        int_stack_dup(stack);
    } else if (strcmp(command, "swap") == 0) {
        int_stack_swap(stack);
    } else if (strcmp(command, "over") == 0) {
        int_stack_over(stack);
    } else if (strcmp(command, "rot") == 0) {
        int_stack_rot(stack);
    } else if (strcmp(command, "drop") == 0) {
        int_stack_drop(stack);
    } else if (strcmp(command, "2swap") == 0) {
        int_stack_2swap(stack);
    } else if (strcmp(command, "2dup") == 0) {
        int_stack_2dup(stack);
    } else if (strcmp(command, "2over") == 0) {
        int_stack_2over(stack);
    } else if (strcmp(command, "2drop") == 0) {
        int_stack_2drop(stack);
    } else if (strcmp(command, "+") == 0) {
        int_stack_add(stack);
    } else if (strcmp(command, "-") == 0) {
        int_stack_sub(stack);
    } else if (strcmp(command, "*") == 0) {
        int_stack_mul(stack);
    } else if (strcmp(command, "/") == 0) {
        int_stack_div(stack);
    } else if (strcmp(command, "%") == 0) {
        int_stack_mod(stack);
    } else if (strcmp(command, "divmod") == 0) {
        int_stack_divmod(stack);
    } else if (strcmp(command, ">") == 0) {
        int_stack_greater_than(stack);
    } else if (strcmp(command, "<") == 0) {
        int_stack_less_than(stack);
    } else if (strcmp(command, "=") == 0) {
        int_stack_equals(stack);
    } else if (strcmp(command, "&") == 0) {
        int_stack_logical_and(stack);
    } else if (strcmp(command, "|") == 0) {
        int_stack_logical_or(stack);
    } else if (strcmp(command, "!") == 0) {
        int_stack_logical_not(stack);
    } else {
        printf("Error: Command '%s' not recognized\n", command);
    }
}

