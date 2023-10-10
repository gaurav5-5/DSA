#define STACK_TEST

#include "../../colorize.h"
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
    printf(GREEN("Test 1 Passed\n"));

    // Test push operation
    push(s, 10);
    assert(s->top == 0);
    assert(s->data[0] == 10);
    printf(GREEN("Test 2 Passed\n"));

    // Test pop operation
    int popped = pop(s);
    assert(popped == 10);
    assert(s->top == -1);
    printf(GREEN("Test 3 Passed\n"));

    // Test peek operation
    push(s, 20);
    assert(peek(s) == 20);
    assert(s->top == 0);
    printf(GREEN("Test 4 Passed\n"));

    // Test stack is empty
    assert(stack_is_empty(s) == 0);
    popped = pop(s);
    assert(popped == 20);
    assert(stack_is_empty(s) == 1);
    printf(GREEN("Test 5 Passed\n"));

    // Test stack is full
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    assert(stack_is_full(s) == 1);
    push(s, 6); // Should not be pushed
    printf(GREEN("Test 6 Passed\n"));

    // Test stack destruction
    stack_destroy(&s);
    assert(s == NULL);
    printf(GREEN("Test 7 Passed\n"));

    // Postfix evaluation tests
    assert(postfix_eval("1 2 +") == 3);
    assert(postfix_eval("1 2 + 3 *") == 9);
    assert(postfix_eval("1 2 + 3 * 4 /") == 2.25);
    assert(postfix_eval("1 2 + 3 * 4 / 5 -") == -0.75);
    assert(postfix_eval("1 2 + 3 * 4 / 5 - 6 7 + *") == -5.25);
    printf(GREEN("Test 8 Passed\n"));

    printf(GREEN("All tests passed!\n"));
    return 0;
}