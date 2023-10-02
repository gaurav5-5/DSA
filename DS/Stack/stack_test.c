#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define S Stack*

int main() {
    // Test stack creation
    S s = stack_create(5);
    assert(s != NULL);
    assert(s->max_size == 5);
    assert(s->top == -1);

    // Test push operation
    push(s, 10);
    assert(s->top == 0);
    assert(s->data[0] == 10);

    // Test pop operation
    int popped = pop(s);
    assert(popped == 10);
    assert(s->top == -1);

    // Test peek operation
    push(s, 20);
    assert(peek(s) == 20);
    assert(s->top == 0);

    // Test stack is empty
    assert(stack_is_empty(s) == 0);
    popped = pop(s);
    assert(popped == 20);
    assert(stack_is_empty(s) == 1);

    // Test stack is full
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    assert(stack_is_full(s) == 1);
    push(s, 6); // This should print "Stack is full!" and not push 6 onto the stack

    // Test stack destruction
    stack_destroy(&s);
    assert(s == NULL);

    printf("All tests passed!\n");
    return 0;
}