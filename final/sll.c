#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Singly linked list node struct
typedef 
struct node {
    int data;
    struct node *next;
}
sll_node;

#define N sll_node
#define L sll_node*

// Check if head is NULL
#define SLL_CHECK_HEAD(_sll, _ret) \
    if (_sll == NULL) { \
        printf("Error: head is NULL\n"); \
        return _ret; \
    } \

// create node
L sll_create_node(int);

// create list
L sll_create_list();

















// create node
L sll_create_node(int data) {
    L node = (L) malloc(sizeof(N));
    node->data = data;
    node->next = NULL;
    return node;
}
// create list
L sll_create_list() {
    
    L head = sll_create_node(data);
    
    char ch;
    int cur = 0, i = 0;

    char *nums = (char *) malloc(sizeof(char) * 1024);
    {
        printf("============\n INPUT RULES \n============\n");
        printf(" 1. Enter numbers separated by some character\n");
        printf(" 2. Separator must not be a number\n");
        printf(" 3. End input with 'y' to stop\n");
        
        scanf("%[^y]", nums);
    }

    ch = nums[i];
    while(ch != 'y' && ch != 'Y')
    {
        ch = nums[i];

        switch (nums[i])
        {
            case '0':
            case '9':
                cur = cur * 10 + (ch - '0');
                break;
            default:
                break;
        }

    }

}
