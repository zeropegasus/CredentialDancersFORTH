#ifndef INT_STACK_H
#define INT_STACK_H


#include <stdio.h>
#include <sys/queue.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100 
#define MAX_VARS 100

typedef struct int_entry {
    int value;
    SLIST_ENTRY(int_entry) entries;
} int_entry_t;

typedef struct int_stack {
    SLIST_HEAD(stackhead, int_entry) head;
    int size;
    int capacity;
} int_stack_t;

typedef struct {
    char name[50];
    int value;
    int isConstant;
} NamedValue;

extern NamedValue vars[MAX_VARS];
extern int varCount;
extern void int_stack_clear(int_stack_t *stk);
extern void int_stack_init(int_stack_t *stk, int capacity);
extern int int_stack_push(int_stack_t *stk, int value);
extern int int_stack_pop(int_stack_t *stk, int *top_value);
extern int int_stack_top(int_stack_t *stk, int *top_value);
extern int int_stack_dup(int_stack_t *stk);
extern int int_stack_swap(int_stack_t *stk);
extern int int_stack_over(int_stack_t *stk);
extern int int_stack_rot(int_stack_t *stk);
extern int int_stack_drop(int_stack_t *stk);
extern int int_stack_2swap(int_stack_t *stk);
extern int int_stack_2dup(int_stack_t *stk);
extern int int_stack_2over(int_stack_t *stk);
extern int int_stack_2drop(int_stack_t *stk);
extern int int_stack_add(int_stack_t *stk);
extern void int_stack_print(int_stack_t *stk, FILE *file);
extern int int_stack_size(int_stack_t* stk);
extern int int_stack_capacity(int_stack_t* stk);
extern int int_stack_sub(int_stack_t *stk);
extern int int_stack_mul(int_stack_t *stk);
extern int int_stack_div(int_stack_t *stk);
extern int int_stack_divmod(int_stack_t *stk);
extern int int_stack_mod(int_stack_t *stk);
extern int int_stack_set_var(const char* name, int value, int isConstant);
extern int int_stack_get_var(const char* name, int* value);
extern void int_stack_greater_than(int_stack_t* stk);
extern void int_stack_less_than(int_stack_t* stk);
extern void int_stack_equals(int_stack_t* stk);
extern void int_stack_logical_and(int_stack_t *stk);
extern void int_stack_logical_or(int_stack_t *stk);
extern void int_stack_logical_not(int_stack_t *stk);
#endif // INT_STACK_H