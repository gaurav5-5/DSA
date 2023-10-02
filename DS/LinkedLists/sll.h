// SLL.h

#ifndef _SLL_H
#define _SLL_H 1

// struct definitions
#include "ll.h"

#define L sll_node*

// Create
L sll_create(int, L);

// Insert
L sll_append(L, int);
L sll_insert_after(L, int, int);
L sll_prepend(L, int);

// Delete
L sll_del_head(L);
L sll_del_end(L);
L sll_del_key(L, int);

// Get Node
L sll_get_prev(L, int);
L sll_get_last(L);
L sll_get_first_of(L, int);

// Display
void sll_display(L);
void sll_display_rev(L);

// Operations
L sll_reverse(L);

// Destroy
L sll_destroy(L);

#undef L

#endif