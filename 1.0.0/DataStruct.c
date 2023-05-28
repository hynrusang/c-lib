#define DEQUE int
#include "DataStruct.h"
main() {
	Deque* stack = init();
	DequeElement* iterator;
	int data = 1;
	printf("empty? %d\n\n", is_empty(stack));
	for (; data < 10; data++) {
		printf("push_back %d", data);
		push_back(stack, data);
		printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(stack));
	}
	data--;
	printf("bottom %d", bottom(stack));
	printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(stack));
	for (; 0 < data; data--) {
		printf("pop_front %d", pop_front(stack));
		printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(stack));
	}

	data = 1;
	for (; data < 10; data++) {
		printf("push_front %d", data);
		push_front(stack, data);
		printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(stack));
	}
	data--;
	printf("top %d", top(stack));
	printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(stack));
	for (; 0 < data; data--) {
		printf("pop_back %d", pop_back(stack));
		printf("\nstack = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(stack));
	}
}