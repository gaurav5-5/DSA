/**
 * @file stack.h
 * @brief This header file contains the definition and implementation of a stack data structure.
 * 
 * The stack is implemented using an array and supports the following operations:
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

#ifndef _STACK_H
#define _STACK_H 1

#ifndef STACK_TYPE
#define STACK_TYPE double
#endif

/**
 * @brief struct representing stack
 * 
 */
typedef struct {
    STACK_TYPE *data; // Pointer to the array storing the stack elements 
    int top;          // Index of the top element in the stack 
    int max_size;     // Maximum number of elements that can be stored in the stack 
} Stack;

#define S Stack*

/**
 * @brief creates a new stack with the given max size
 * 
 * @param size maximum number of elements the stack can hold.
 * @return Stack* pointer to the newly created stack.
 */
S stack_create(int);

// Stack size
#define STACK_SIZE(stk) ((stk)->top)+1

/**
 * @brief checks if stack is full.
 * 
 * @param S stack to be checked.
 * @return int Returns 1 if the stack is full, 0 otherwise.
 */
int stack_is_full(S);

/**
 * @brief Checks if the stack is empty.
 * 
 * @param S The stack to check.
 * @return int Returns 1 if the stack is empty, 0 otherwise.
 */
int stack_is_empty(S);

/**
 * Adds an element to the top of the stack.
 *
 * @param S The stack to which the element is to be added.
 * @param data The element to be added to the stack.
 */
void push(S, STACK_TYPE);

/**
 * @brief Removes and returns the top element of the stack.
 * 
 * @param S The stack from which the element is to be removed.
 * @return STACK_TYPE The element removed from the stack.
 */
STACK_TYPE pop(S);

/**
 * Returns the top element of the stack without removing it.
 *
 * @param S stack to be peeked
 * @return top element
 */
STACK_TYPE peek(S);

// TODO destroy stack
/**
 * @brief destroys stack and frees allocated memory
 * 
 * @param S stack to destroy
 */
void stack_destroy(S*);

#undef S
#endif // !_STACK_H