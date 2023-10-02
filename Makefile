CC = gcc

BIN_DIR = bin
TEST_DIR = bin/tests
STACK_DIR = DS/Stack
LL_DIR = DS/LinkedLists

stack:
	gcc -o $(TEST_DIR)/stack_test $(STACK_DIR)/stack.c $(STACK_DIR)/stack_test.c -I$(STACK_DIR)

sll:
	gcc -o $(TEST_DIR)/sll_test $(LL_DIR)/sll.c $(LL_DIR)/sll_test.c -I$(LL_DIR)