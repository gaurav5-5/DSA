// SLL.h

#ifndef SLL_H
#define SLL_H

// struct
typedef
struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
}
sll_node;

// Create
void sll_init(sll_node **);

// Insert
void sll_append(sll_node*, int);
void sll_insert_after(sll_node*, int, int);
void sll_insert_at(sll_node*, int, int);
void sll_push_back(sll_node*, int);

// Delete
sll_node* sll_pop(sll_node*, int);
void sll_del_head(sll_node**);
void sll_del_end(sll_node*);
void sll_del_after(sll_node*, int);

// Get Node
sll_node* sll_get_prev(sll_node*, int);
sll_node* sll_get_end(sll_node*);
sll_node* sll_get_pos(sll_node*, int);
sll_node* sll_get_first_of(sll_node*);

// Display
void sll_display(sll_node*);
void sll_display_rev(sll_node*);

// Operations
void sll_reverse(sll_node**);
void sll_sort(sll_node**, int);

// Destroy
sll_node* sll_destroy(sll_node**);

#endif