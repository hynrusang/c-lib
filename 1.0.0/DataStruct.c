#define DEQUE int
#include "DataStruct.h"
main() {
	Deque* datas = init();
	DequeElement* iterator;
	printf("empty? %d\n\n", is_empty(datas));

	int data = 1;
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
}