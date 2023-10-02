// stack.h

#ifndef _STACK_H
#define _STACK_H 1

// struct definition
typedef
struct {
    int *el;
    int top;
    int max_size;
}
Stack;

#define S Stack*

// TODO create
S stack_create(int);

// Stack size
#define STACK_SIZE(stk) ((stk)->top)+1

// TODO stack overflow checker
int stack_is_full(S);
int stack_is_empty(S);

// TODO stk->el mods
void push(S, int);
int pop(S);

// TODO destroy stack
void stack_destroy(S);

#undef S
#endif // !_STACK_H