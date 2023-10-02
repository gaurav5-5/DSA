/**
 * @file stack.c
 * @brief This file contains the implementation of a stack data structure.
 * 
 * Stack is implemented array style
 * Functions:
 * - stack_create: creates a new stack with the specified capacity.
 * - stack_is_full: checks if the stack is full.
 * - stack_is_empty: checks if the stack is empty.
 * - push: adds an element to the top of the stack.
 * - pop: removes and returns the top element of the stack.
 * - peek: returns the top element of the stack without removing it.
 * - stack_destroy: destroys the given stack and frees all associated memory.
 * 
 * @author gaurav5-5
*/

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>


/*
 * ===============
 * BASIC STRUCTURE
 * ===============
 *           <-- TOP -->               MAX_SIZE
 *   +----+----+----+-----+-----+-----+-------+
 *   | d1 | d2 | d3 | ... | ... | ... |  ...  |
 *   +----+----+----+-----+-----+-----+-------+
 */
#define S Stack*

/*
 * ==============
 * STACK CREATION
 * ==============
 * stack_create(int) - returns a stack of size 'int'
 */
S
stack_create(int size)
{
    S s = (S)malloc(sizeof(Stack));
    s->max_size = size;
    s->top = -1;
    s->data = (STACK_TYPE*)malloc(sizeof(STACK_TYPE) * size);
    return s;
}

/*
 * ============
 * SPACE CHECKS
 * ============
 * stack_is_empty(S) - returns 1 if stack is empty, 0 otherwise
 * stack_is_full(S) - returns 1 if stack is full, 0 otherwise
 */
int
stack_is_empty(S s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

int
stack_is_full(S s)
{
    if(s->top == s->max_size - 1)
        return 1;
    return 0;
}

/**
 * ================
 * STACK OPERATIONS
 * ================
 * push(S, int) - pushes 'int' onto stack 'S'
 * pop(S) - pops top element off stack 'S'
 * peek(S) - returns top element of stack 'S'
 */
void
push(S s, STACK_TYPE data)
{
    if(stack_is_full(s))
    {
        printf("Stack is full!\n");
        return;
    }
    s->data[++(s->top)] = data;
}

STACK_TYPE
pop(S s)
{
    if(stack_is_empty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    STACK_TYPE d = s->data[(s->top)];
    s->top--;
    return d;
}

STACK_TYPE
peek(S s)
{
    if(stack_is_empty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}

/*
 * ==============
 * STACK DELETION
 * ==============
 * stack_destroy(S*) - destroys stack '*S'
 */
void
stack_destroy(S* s)
{
    free((*s)->data);
    free(*s);
    *s = NULL;
}

#undef S