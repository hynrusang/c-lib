#define key
#ifdef key

#define DEQUE int
#include "DataStruct.h"

main() {
#ifdef STACK

	STACK data;
	Stack* datas = init();
	StackElement* iterator;
	help();
	printf("empty? %d\n\n", is_empty(datas));

	data = 1;
	for (; data < 10; data++) {
		printf("push %d", data);
		push(datas, data);
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}
	data--;
	printf("top %d", top(datas));
	printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(datas));
	for (; 0 < data; data--) {
		printf("pop %d", pop(datas));
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}

#endif

#ifdef QUEUE

	QUEUE data;
	Queue* datas = init();
	QueueElement* iterator;
	help();
	printf("empty? %d\n\n", is_empty(datas));

	data = 1;
	for (; data < 10; data++) {
		printf("enqueue %d", data);
		enqueue(datas, data);
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}
	data--;
	printf("bottom %d", bottom(datas));
	printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(datas));
	for (; 0 < data; data--) {
		printf("dequeue %d", dequeue(datas));
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}

#endif

#ifdef DEQUE

	DEQUE data;
	Deque* datas = init();
	DequeElement* iterator;
	help();
	printf("empty? %d\n\n", is_empty(datas));

	data = 1;
	for (; data < 10; data++) {
		printf("push_back %d", data);
		push_back(datas, data);
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}
	data--;
	printf("bottom %d", bottom(datas));
	printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(datas));
	for (; 0 < data; data--) {
		printf("pop_front %d", pop_front(datas));
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}

	data = 1;
	for (; data < 10; data++) {
		printf("push_front %d", data);
		push_front(datas, data);
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}
	data--;
	printf("top %d", top(datas));
	printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", is_empty(datas));
	for (; 0 < data; data--) {
		printf("pop_back %d", pop_back(datas));
		printf("\ndatas = ( "); iterator = datas->first; for (; iterator != datas->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", is_empty(datas));
	}

#endif
}
#endif