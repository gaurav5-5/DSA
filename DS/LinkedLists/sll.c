#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * ===============
 * BASIC STRUCTURE
 * ===============
 *  L  +---+  L  +---+  L
 * --> | S | --> | S | -->
 *     +---+     +---+
 * S => Struct
 * L => Link
 */
#define S sll_node 
#define L sll_node* 

/*
 * ===========
 * UTIL MACROS
 * ===========
 * _NULL_CHECK(_sll_head,_ret_val)
 * 
 */
#define _NULL_CHECK(_SLL_HEAD, _RET_VAL) do       \
    if(!(_SLL_HEAD)) {                            \
        printf("\nLinked List Error: NULL HEAD"); \
        return (_RET_VAL);                        \
    } while(0)                                    \



/*
 * =========
 * GET UTILS
 * =========
 * sll_get_prev(L, int)     => node previous to first occurence of int
 * sll_get_last(L)          => end node
 * sll_get_first_of(L, int) => first occurence of int (get_prev->next)
 */
L
sll_get_prev(L head, int key)
{
    // check head
    _NULL_CHECK(head, NULL);
    // get node with value equal to key
    if(!(head->data == key)) 
        while(head && head->next && head->next->data != key) 
            head = head->next;
    return head;
}

L
sll_get_last(L head)
{
    // check head
    _NULL_CHECK(head, NULL);
    // iterate to last node
    while(head && head->next) head = head->next;
    return head;
}

L
sll_get_first_of(L head, int key)
{
    // get previous node using get_prev then return its next node
    return (sll_get_prev(head, key))->next;
}

/*
 * =============
 * DISPLAY UTILS
 * =============
 * sll_display(L)     => display start to end
 * sll_display_rev(L) => display end   to start
 */
// formats as :
// START --> data1 --> data2 --> ... -> END
void
sll_display(L head)
{
    printf("\nSTART --> ");
    while(head)
    {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("END\n");
}

// END <-- dataK <-- dataK-1 <-- ... <-- data1
void
sll_display_rev(L head)
{
    if(!head)
        printf("\nEND");
    else {
        sll_display_rev(head->next);
        printf(" <-- %d",head->data);
    }
}