// stack.c

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

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
    s->data = (int*)malloc(sizeof(int) * size);
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
push(S s, int data)
{
    if(stack_is_full(s))
    {
        printf("Stack is full!\n");
        return;
    }
    s->data[++s->top] = data;
}

int
pop(S s)
{
    if(stack_is_empty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top--];
}

int
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
 * stack_destroy(S) - destroys stack 'S'
 */
void
stack_destroy(S s)
{
    if(s && s->data) free(s->data);
    if(s) free(s);
}

#undef S