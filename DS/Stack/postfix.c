/**
 * @file postfix.c
 * @brief This file contains the implementation of postfix evaluation using stack.
 * 
 * This file contains the implementation of postfix evaluation using stack.
 * In postfix notation, the operator comes after the operands.
 * This program evaluates a postfix expression using stack data structure.
 * 
 * @author gaurav5-5
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Evaluates a postfix expression.
 * 
 * @param expr The postfix expression to be evaluated.
 * @return int The result of the evaluation.
 */
double
postfix_eval(char expr[])
{
    Stack *stk = stack_create(100);
    int i = 0, nat = 10;
    double dec = 1.0, a, b;
    for(int j = 0; (expr[j]) != '\0'; j++) 
    {
        char c = expr[j];
        switch (c)
        {
        case '.':
            dec = 0.1;
            nat = 1;
            break;
        case ' ':
            dec = 1;
            nat = 10;
            i = 0;
            break;

        case '+':
            dec = 1;
            nat = 10;
            i = 0;
            a = pop(stk);
            b = pop(stk);
            push(stk, (a + b));
            break;
        case '-':
            dec = 1;
            nat = 10;
            i = 0;
            a = pop(stk);
            b = pop(stk);
            push(stk, (b - a));
            break;
        case '*':
            dec = 1;
            nat = 10;
            i = 0;
            a = pop(stk);
            b = pop(stk);
            push(stk, (a * b));
            break;
        case '/':
            dec = 1;
            nat = 10;
            i = 0;
            a = pop(stk);
            b = pop(stk);
            push(stk, (b / a));
            break;
        
        default:
            if(!i) {
                push(stk, 0);
                i = 1;
            }
            a = pop(stk);
            a = (a * nat) + (((double)(c-'0'))*dec);
            push(stk, a);
            dec *= dec;
            break;
        }
    }

    double result = pop(stk);
    stack_destroy(&stk);
    return result;
}