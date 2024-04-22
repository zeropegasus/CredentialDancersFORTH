#include "int_stack.h"
#include "int_stack.c"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char name[50];  // Name of the function/word
    char command[255];  // The command that follows the function
} DictionaryEntry;

// Global dictionary array
DictionaryEntry dictionary[MAX_WORDS];
int dictionarySize = 0;

// Function to add a word and its command to the dictionary
void add_word_to_dictionary(const char* name, const char* command) {
    if (dictionarySize >= MAX_WORDS) {
        printf("Dictionary full, cannot add more words.\n");
        return;
    }
    strcpy(dictionary[dictionarySize].name, name);
    strcpy(dictionary[dictionarySize].command, command);
    dictionarySize++;
    printf("Word '%s' with command added to dictionary.\n", name);
}

// Function to find a word in the dictionary and execute its command
void execute_dictionary_word(const char* name, int_stack_t* stack) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(dictionary[i].name, name) == 0) {
            printf("Executing command for '%s': %s\n", name, dictionary[i].command);
            execute_command(dictionary[i].command, stack);
            return;
        }
    }
    printf("Word '%s' not found in dictionary.\n", name);
}

// Implement the execute_command function based on your specific needs
void execute_command(const char* command, int_stack_t* stack) {
    // Parse and execute the command as per your environment's needs
    // This is a placeholder function
    printf("Command executed: %s\n", command);
}

int main() {
    int_stack_t stack;
    int_stack_init(&stack, 15);  // Initialize the stack with a capacity of 15
    char line[256]; // Buffer to store user input

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
            } else {
                printf("Error: Syntax error in define statement.\n");
            }
        } else {
            execute_dictionary_word(token, &stack);
        }
    }

    return 0;
}