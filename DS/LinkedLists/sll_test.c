#include "sll.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define L sll_node*

void test_sll_create() {
    L node = sll_create(10, NULL);
    assert(node->data == 10);
    assert(node->next == NULL);
    printf("Create Test passed!\n");
}

void test_sll_append() {
    L head = sll_create(10, NULL);
    head = sll_append(head, 20);
    head = sll_append(head, 30);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("Append Test passed!\n");
}

void test_sll_prepend() {
    L head = sll_create(10, NULL);
    head = sll_prepend(head, 20);
    head = sll_prepend(head, 30);
    assert(head->data == 30);
    assert(head->next->data == 20);
    assert(head->next->next->data == 10);
    assert(head->next->next->next == NULL);
    printf("Prepend Test passed!\n");
}

void test_sll_insert_after() {
    L head = sll_create(10, NULL);
    head = sll_append(head, 20);
    head = sll_append(head, 30);
    head = sll_insert_after(head, 25, 20);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next->data == 25);
    assert(head->next->next->next->data == 30);
    assert(head->next->next->next->next == NULL);
    printf("Insert After Test passed!\n");
}

void test_sll_del_head() {
    L head = sll_create(10, NULL);
    head = sll_append(head, 20);
    head = sll_append(head, 30);
    head = sll_del_head(head);
    assert(head->data == 20);
    assert(head->next->data == 30);
    assert(head->next->next == NULL);
    printf("Delete Head Test passed!\n");
}

void test_sll_del_end() {
    L head = sll_create(10, NULL);
    head = sll_append(head, 20);
    head = sll_append(head, 30);
    head = sll_del_end(head);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    printf("Delete End Test passed!\n");
}

void test_sll_del_key() {
    L head = sll_create(10, NULL);
    head = sll_append(head, 20);
    head = sll_append(head, 30);
    head = sll_insert_after(head, 25, 20);
    head = sll_del_key(head, 20);
    assert(head->data == 10);
    assert(head->next->data == 25);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("Delete Key Test passed!\n");
}

int main() {
    test_sll_create();
    test_sll_append();
    test_sll_prepend();
    test_sll_insert_after();
    test_sll_del_head();
    test_sll_del_end();
    test_sll_del_key();
    printf("All tests passed!\n");
    return 0;
}