#include "int_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include for isdigit function

#define DICTIONARY_SIZE 100

// Function prototypes
void execute_command(const char* command, int_stack_t *stack);
void add_word_to_dictionary(const char* word, const char* command);
const char* get_command_from_dictionary(const char* word);

// Global variables for the dictionary
char* dictionary_words[DICTIONARY_SIZE];
char* dictionary_commands[DICTIONARY_SIZE];
int dictionary_count = 0;

int main() {
    char line[256]; // Buffer to store user input
    int_stack_t stack;
    int_stack_init(&stack, 15);  // Initialize the stack with a capacity of 15

    printf("Enter your R-FORTH code ('end' to stop):\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "end", 3) == 0) {
            break;
        }

        char* token = strtok(line, " \n");
        if (strcmp(token, "define") == 0) {
            char* wordName = strtok(NULL, " \n");
            char* command = strtok(NULL, "\n");  // Capture the rest of the line as the command
            if (wordName && command) {
                add_word_to_dictionary(wordName, command);
                printf("Word '%s' added to dictionary with command: %s\n", wordName, command);
            } else {
                printf("Error: Syntax error in define statement.\n");
            }
        } else {
            while (token != NULL) {
                execute_command(token, &stack);
                token = strtok(NULL, " \n");
            }
            int_stack_print(&stack, stdout); // Print the current state of the stack
        }
    }

    return 0;
}

void execute_command(const char* command, int_stack_t *stack) {
    if (isdigit((unsigned char)command[0])) {
        int number = atoi(command);
        int_stack_push(stack, number);
    } else {
        const char* dictionary_command = get_command_from_dictionary(command);
        if (dictionary_command != NULL) {
            // Execute the defined word
            char* token = strtok((char*)dictionary_command, " ");
            while (token != NULL) {
                execute_command(token, stack);
                token = strtok(NULL, " ");
            }
        } else {
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
              else if (strcmp(command, "clear") == 0) {
                int_stack_clear(stack);
            } else {
                printf("Error: Command '%s' not recognized\n", command);
            }
        }
    }
}

void add_word_to_dictionary(const char* word, const char* command) {
    if (dictionary_count < DICTIONARY_SIZE) {
        dictionary_words[dictionary_count] = strdup(word);
        dictionary_commands[dictionary_count] = strdup(command);
        dictionary_count++;
    } else {
        printf("Dictionary is full.\n");
    }
}

const char* get_command_from_dictionary(const char* word) {
    for (int i = 0; i < dictionary_count; i++) {
        if (strcmp(dictionary_words[i], word) == 0) {
            return dictionary_commands[i];
        }
    }
    return NULL;
}
