#ifndef DATASTRUCTHEADER
#define DATASTRUCTHEADER
#include <stdio.h>
#include <stdlib.h>
#define useType(Type) typedef Type element

#ifdef STACK
typedef struct stack {
	STACK data;
	struct stack* before;
	struct stack* next;
}Stack;
Stack* init() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL) {
		printf("Dynamic memory allocation failed (probably due to low memory)");
		exit(1);
	} else {
		temp->before = NULL;
		temp->data = NULL;
		temp->next = NULL;
	}
	return temp;
};
Stack* push(Stack* stack, STACK data) {
	Stack* __iterator = stack;
	for (; __iterator->next != NULL; __iterator = __iterator->next);
	__iterator->data = data;
	__iterator->next = init();
	__iterator->next->before = __iterator;
}
STACK pop(Stack* stack) {
	Stack* __iterator = stack;
	for (; __iterator->next != NULL; __iterator = __iterator->next);
	if (__iterator->before == NULL) {
		printf("This stack is already empty.");
		return 0;
	} else {
		STACK __MEMORY = __iterator->before->data;
		__iterator->before->next = NULL;
		free(__iterator);
		return __MEMORY;
	}
}
STACK top(Stack* stack) {
	Stack* __iterator = stack;
	for (; __iterator->next != NULL; __iterator = __iterator->next);
	if (__iterator->before == NULL) {
		printf("This stack is already empty.");
		return 0;
	} else return __iterator->before->data;
}
int isEmpty(Stack* stack) {
	return (stack->next == NULL);
}
size_t size(Stack* stack) {
	Stack* iterator = stack; size_t __size = 0;
	for (; iterator->next != NULL; iterator = iterator->next) __size++;
	return __size;
}
#endif

#ifdef QUEUE
typedef struct queue {
	QUEUE data;
	Queue* before;
	Queue* next;
}Queue;
#endif

#endif