#include "int_stack.h"


NamedValue vars[MAX_VARS];
int varCount = 0;
void int_stack_init(int_stack_t *stk, int capacity) {
    SLIST_INIT(&stk->head);
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value) {
    if (stk->size >= stk->capacity) {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    int_entry_t *newEntry = malloc(sizeof(int_entry_t));
    if (newEntry) {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head, newEntry, entries);
        stk->size++;
        return 1; //success
    }
    return 0; // fail
}
void int_stack_clear(int_stack_t *stk) {
    int_entry_t *entry;
    while ((entry = SLIST_FIRST(&stk->head)) != NULL) {
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
    }
    stk->size = 0;  // Reset the size of the stack to 0
}


int int_stack_pop(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        int value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
        stk->size--;
        *top_value = value;
        return 1; // success
    }
    return 0; // fail
}

int int_stack_top(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        *top_value = entry->value;
        return 1; // success
    }
    return 0; // fail
}

/* Functions for FORTH langauge stack operators */

int int_stack_dup(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_swap(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

/* New stack operations */
int int_stack_over(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (!entry || !(entry->entries.sle_next))
        return 0; // Fail if there's no second item.
    
    int second_value = entry->entries.sle_next->value;
    return int_stack_push(stk, second_value);
}


int int_stack_rot(int_stack_t *stk) {
    int value1, value2, value3;

    // Check if the stack has at least three elements
    if (stk->size < 3) {
        return 0; // Fail, not enough elements to perform rot
    }

    // Pop the top three elements
    if (!int_stack_pop(stk, &value1) || !int_stack_pop(stk, &value2) || !int_stack_pop(stk, &value3)) {
        return 0; // Fail, error during pop
    }

    // Push them back in the rotated order
    int_stack_push(stk, value2); // Now the second element becomes the top
    int_stack_push(stk, value1); // Then, what was the top element
    int_stack_push(stk, value3); // Finally, the third element becomes the bottom of these three

    return 1; // Success
}




int int_stack_drop(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    return int_stack_pop(stk, &top_value);
}

int int_stack_2swap(int_stack_t *stk) {
    if (stk->size < 4)
        return 0;
    int d1, d2, d3, d4;
    int_stack_pop(stk, &d1);
    int_stack_pop(stk, &d2);
    int_stack_pop(stk, &d3);
    int_stack_pop(stk, &d4);
    int_stack_push(stk, d2);
    int_stack_push(stk, d1);
    int_stack_push(stk, d4);
    return int_stack_push(stk, d3);
}

int int_stack_2dup(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    
    int top_value, second_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    
    // Push them back in reverse order to maintain the original stack order
    int_stack_push(stk, second_value);
    int_stack_push(stk, top_value);
    int_stack_push(stk, second_value);
    int_stack_push(stk, top_value);
    
    return 1;
}



int int_stack_2over(int_stack_t *stk) {
    if (stk->size < 4) {
        // Not enough elements for 2OVER operation
        return 0; // Indicate failure
    }

    int_entry_t *current = SLIST_FIRST(&stk->head);
    int values[2];
    int i = 0;

    // Navigate to the third element from the top
    for (i = 0; i < 2; i++) {
        current = SLIST_NEXT(current, entries);
    }

    // Assuming the list has at least four elements based on the size check
    values[0] = SLIST_NEXT(current, entries)->value; // Fourth value
    values[1] = current->value; // Third value

    // Push the third and fourth values back onto the stack
    for (i = 1; i >= 0; i--) {
        if (!int_stack_push(stk, values[i])) {
            // Push failed, handle error if needed
            return 0; // Indicate failure
        }
    }

    return 1; // Indicate success
}



int int_stack_2drop(int_stack_t *stk) {
    if (stk->size < 2) {
        // Check if the stack has at least two elements to drop
        return 0; // Return 0 if there are not enough elements to drop two
    }

    int top_value;
    int_stack_pop(stk, &top_value); // Drop the first top value
    int_stack_pop(stk, &top_value); // Drop the second top value

    return 1; // Return 1 to indicate success
}




int int_stack_add(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

/*void int_stack_print(int_stack_t *stk, FILE *file) {
    int_entry_t *entry;
    int pos = 0;
    if (stk->size == 0) {
        fprintf(file, "Stack is empty\n");
    } else {
        SLIST_FOREACH(entry, &stk->head, entries) {
            if (pos == 0) {  // Check if the current entry is the top of the stack
                fprintf(file, "%d: %d <--Top\n", pos, entry->value);
            } else {
                fprintf(file, "%d: %d\n", pos, entry->value);
            }
            pos++;
        }
    }
    fprintf(file, "\n"); // Print a newline for better formatting after the stack print
} */
void int_stack_print(int_stack_t *stk, FILE *file) {
    int_entry_t *entry;
    int pos = 0;  // Index to keep track of current position in the list

    // Determine the total entries to correctly label positions from the bottom (0)
    int totalEntries = stk->size;
    int stackIndex = 0;  // This will start from the top and count upwards

    if (stk->size == 0) {
        fprintf(file, "+---------+---------+\n");
        fprintf(file, "|  Stack  |  Empty  |\n");
        fprintf(file, "+---------+---------+\n");
    } else {
        fprintf(file, "+---------+---------+\n");
        fprintf(file, "|   Pos   |  Value  |\n");
        fprintf(file, "+---------+---------+\n");
        SLIST_FOREACH(entry, &stk->head, entries) {
            pos = totalEntries - stackIndex - 1; // Correctly calculate position from the bottom
            if (stackIndex == 0) { // Correctly check if the current entry is the top of the stack
                fprintf(file, "|  %3d:   | %7d |<--Top \n", pos, entry->value);
            } else {
                fprintf(file, "|  %3d:   | %7d |\n", pos, entry->value);
            }
            stackIndex++; // Increment to move to the next element in the list
        }
        fprintf(file, "+---------+---------+\n"); // Closing border after the stack print
    }
    fprintf(file, "\n"); // Print a newline for better formatting after the stack print
}
void int_stack_man(void) {
    printf("Commands:\n");
    printf("pop      - Pop top value of stack and return its value\n");
    printf("dup      - Duplicate top value of stack\n");
    printf("swap     - Swap top two elements of the stack\n");
    printf("over     - Duplicate second to top element in stack to the top of the stack\n");
    printf("rot      - Rotates values in the stack\n");
    printf("drop     - Drop top value of stack\n");
    printf("2swap    - Swap the top two pairs of elements\n");
    printf("2dup     - Duplicate the top two elements of the stack\n");
    printf("2over    - Duplicate the second pair of elements to the top of the stack\n");
    printf("2drop    - Drop the top two elements of the stack\n");
    printf("clear    - Clear the entire stack\n");
    printf("set      - Initializes variable and sets its value\n");
    printf("get      - Gets variable value and adds it to top of stack. Example usage: get x\n");
    printf("# + command - Append number to command to run it that many times. Example: 5drop\n");
    printf("define   - Defines a user command. Example: define add2 2 +\n\n");

    printf("Operators:\n");
    printf("+        - Adds top two values of stack\n");
    printf("-        - Subtracts top two values of stack\n");
    printf("*        - Multiplies top two values of stack\n");
    printf("/        - Divides top two values of stack\n");
    printf("%        - Finds remainder of top two values of stack (modulus operator)\n");
    printf("divmod   - Takes two numbers as arguments and returns their quotient and remainder\n\n");

    printf("Boolean:\n");
    printf(">        - Greater than. Example: 5 10 >\n");
    printf("<        - Less than. Example: 5 10 <\n");
    printf("=        - Equal to. Example: 10 10 =\n");
    printf("&        - And operator. Example: 1 1 &\n");
    printf("|        - Or operator. Example: 1 0 |\n");
    printf("!        - Negates a statement. Example: ! (1 > 0) returns 0\n\n");
}

// Add this function to your int_stack.c and call it from your main program
// or wherever appropriate when you need to display the help text.






int int_stack_size(int_stack_t* stk) {
    return stk->size;
}

int int_stack_capacity(int_stack_t* stk) {
    return stk->capacity;
}
int int_stack_sub(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value - top_value);
}

int int_stack_mul(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value * next_to_top_value);
}

int int_stack_div(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    if (top_value == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return int_stack_push(stk, next_to_top_value / top_value);
}

int int_stack_divmod(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int divisor, dividend;
    int_stack_pop(stk, &divisor);
    int_stack_pop(stk, &dividend);
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    int_stack_push(stk, remainder);
    return int_stack_push(stk, quotient);
}

int int_stack_mod(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int divisor, dividend;
    int_stack_pop(stk, &divisor);
    int_stack_pop(stk, &dividend);
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return int_stack_push(stk, dividend % divisor);
}
//new boolean operations
void int_stack_greater_than(int_stack_t *stk) {
    if (stk->size < 2) {
        printf("Error: not enough elements for 'greater than' operation.\n");
        return;
    }
    int top_value, second_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    int_stack_push(stk, second_value > top_value);
}

void int_stack_less_than(int_stack_t *stk) {
    if (stk->size < 2) {
        printf("Error: not enough elements for 'less than' operation.\n");
        return;
    }
    int top_value, second_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    int_stack_push(stk, second_value < top_value);
}

void int_stack_equals(int_stack_t *stk) {
    if (stk->size < 2) {
        printf("Error: not enough elements for 'equals' operation.\n");
        return;
    }
    int top_value, second_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    int_stack_push(stk, second_value == top_value);
}

void int_stack_logical_and(int_stack_t *stk) {
    if (stk->size < 2) {
        printf("Error: not enough elements for 'logical and' operation.\n");
        return;
    }
    int top_value, second_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    int_stack_push(stk, second_value && top_value);
}

void int_stack_logical_not(int_stack_t *stk) {
    if (stk->size < 1) {
        printf("Error: not enough elements for 'logical not' operation.\n");
        return;
    }
    int top_value;
    int_stack_pop(stk, &top_value);
    int_stack_push(stk, !top_value);
}
void int_stack_logical_or(int_stack_t *stk) {
    if (stk->size < 2) {
        printf("Error: not enough elements for 'logical or' operation.\n");
        return;
    }
    int top_value, second_value;
    // Pop the top two values from the stack
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &second_value);
    // Perform the logical OR operation and push the result back onto the stack
    int_stack_push(stk, second_value || top_value);
}


int int_stack_set_var(const char* name, int value, int isConstant) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            if (vars[i].isConstant) {
                printf("Error: %s is a constant and cannot be changed.\n", name);
                return 0;
            }
            vars[i].value = value;
            return 1;
        }
    }
    if (varCount >= MAX_VARS) {
        printf("Error: Variable storage full.\n");
        return 0;
    }
    strcpy(vars[varCount].name, name);
    vars[varCount].value = value;
    vars[varCount].isConstant = isConstant;
    varCount++;
    return 1;
}

int int_stack_get_var(const char* name, int* value) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            *value = vars[i].value;
            return 1;
        }
    }
    printf("Error: Variable %s not found.\n", name);
    return 0;


}

