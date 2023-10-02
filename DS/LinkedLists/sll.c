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
        printf("\nLinked List Error: NULL NODE"); \
        return (_RET_VAL);                        \
    } while(0)                                    \


/*
 * ==============
 * NODE ADD UTILS
 * ==============
 * sll_create(int, L)               => creates new node
 * sll_append(L, int)            => insert at tail
 * sll_prepend(L, int)           => insert at head
 * sll_insert_after(L, int, int) => insert after key
 */
L
sll_create(int data, L next)
{
    L _n = (L)malloc(sizeof(S));
    _n->data = data;
    _n->next = next;
    return _n;
}

L
sll_append(L head, int data)
{
    L _h = head;
    if(!_h) _h = sll_create(data, NULL);
    else {
        _h = sll_get_last(_h);
        _h->next = sll_create(data, NULL);
    }
    return head;
}

L
sll_prepend(L head, int data)
{
    return sll_create(data, head);
}

L
sll_insert_after(L head, int data, int key)
{
    _NULL_CHECK(head, head);
    L _t = sll_get_prev(head, key);
    _NULL_CHECK(_t, head);
    L _n = sll_create(data, _t->next->next);
    _t->next->next = _n;
    return head;
}


/*
 * ============
 * DELETE UTILS
 * ============
 * sll_del_head(L)      => first node
 * sll_del_end(L)       => end node
 * sll_del_key(L, int)  => first occurence of int
 */
L
sll_del_head(L head)
{
    // check head
    _NULL_CHECK(head, head);
    // move head forward
    L _t = head;
    head = head->next;
    // free memory
    if(_t) free(_t);
    return head;
}

L
sll_del_end(L head)
{
    // check head
    _NULL_CHECK(head, head);
    // get end node
    L _t = sll_get_last(head);
    L _prev = sll_get_prev(head, _t->data);
    // free memory
    if(_t) free(_t);
    _prev->next = NULL;

    return head;
}

L
sll_del_key(L head, int key)
{
    // check head
    _NULL_CHECK(head, head);
    // get key
    L _t = sll_get_prev(head, key);
    _NULL_CHECK(_t, head);
    L _rm = _t->next;
    _t->next = _rm->next;
    if(_rm) free(_rm);
}

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

/*
 * ==========
 * OPERATIONS
 * ==========
 * sll_reverse(L)  => reverse linked list
 */
L
sll_reverse(L head)
{
    _NULL_CHECK(head, head);

    L prev;
    L next;

    next = prev = NULL;

    while(head) 
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return head;
}

/*
 * =======
 * DESTROY
 * =======
 * sll_destroy(L)  => frees up memory allocated to LL
 */
L
sll_destroy(L head)
{
    _NULL_CHECK(head, NULL);
    L _p = head;
    head = head->next;
    while(head)
    {
        if(_p) free(_p);
        _p = head;
        head = head->next;
    }

    return head;
}