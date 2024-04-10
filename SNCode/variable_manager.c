#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 256 // Simple hash table size

typedef struct VarEntry {
    char *key;
    int value;
    struct VarEntry *next; // For collision resolution using chaining
} VarEntry;

VarEntry *varTable[TABLE_SIZE];

// Hash function for strings
unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // Simple hash function
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    return value % TABLE_SIZE;
}

// Initialize the variable table
void varTable_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        varTable[i] = NULL;
    }
}

// Insert or update a variable
void var_set(const char *key, int value) {
    unsigned int slot = hash(key);
    VarEntry *entry = varTable[slot];

    // Search for existing variable and update it
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    // Insert new variable
    VarEntry *newEntry = malloc(sizeof(VarEntry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = varTable[slot];
    varTable[slot] = newEntry;
}

// Get a variable's value
int var_get(const char *key, int *value) {
    unsigned int slot = hash(key);
    VarEntry *entry = varTable[slot];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            *value = entry->value;
            return 1; // Success
        }
        entry = entry->next;
    }

    return 0; // Variable not found
}