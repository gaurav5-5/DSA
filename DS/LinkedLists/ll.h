#ifndef _LL_H
#define _LL_H 1

// Define Singly Linked List node if using sll.h
#   ifdef _SLL_H
typedef
struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
}
sll_node;
#   endif // _SLL_H

// Define Singly Linked List node if using cll.h
#   ifdef _CLL_H
typedef
struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode *next;
}
cll_node;
#   endif // _CLL_H

// Define Doubly Linked List node if using dll.h
#   ifdef _DLL_H
typedef
struct DoublyLinkedListNode
{
    int data;
    struct DoublyLinkedListNode *prev;
    struct DoublyLinkedListNode *next;
}
dll_node;
#endif // _DLL_H

// Define Doubly Linked List node if using dcll.h
#   ifdef _DCLL_H
typedef
struct DoublyLinkedListNode
{
    int data;
    struct DoublyLinkedListNode *prev;
    struct DoublyLinkedListNode *next;
}
dcll_node;
#   endif // _DCLL_H



#endif // !_LL_H