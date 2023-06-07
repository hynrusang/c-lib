#define key
#ifdef key

#define STACK int
#define QUEUE int
#define DEQUE int
#include "DataStruct.h"

main() {
#ifdef STACK
#define _data stack_data
#define iterator stack_iterator
	STACK _data;
	Stack* stack = new (Stack);
	StackElement* iterator;
	stack->help();
	printf("empty? %d\n\n", stack->is_empty(stack));

	_data = 1;
	for (; _data < 10; _data++) {
		printf("push %d", _data);
		stack->push(stack, _data);
		printf("\ndatas = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", stack->is_empty(stack));
	}
	_data--;
	printf("top %d", stack->top(stack));
	printf("\ndatas = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", stack->is_empty(stack));
	for (; 0 < _data; _data--) {
		printf("pop %d", stack->pop(stack));
		printf("\ndatas = ( "); iterator = stack->first; for (; iterator != stack->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", stack->is_empty(stack));
	}

#endif

#ifdef QUEUE
#define _data queue_data
#define iterator queue_iterator
	QUEUE _data;
	Queue* queue = new (Queue);
	QueueElement* iterator;
	queue->help();
	printf("empty? %d\n\n", queue->is_empty(queue));

	_data = 1;
	for (; _data < 10; _data++) {
		printf("enqueue %d", _data);
		queue->enqueue(queue, _data);
		printf("\ndatas = ( "); iterator = queue->first; for (; iterator != queue->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", queue->is_empty(queue));
	}
	_data--;
	printf("bottom %d", queue->bottom(queue));
	printf("\ndatas = ( "); iterator = queue->first; for (; iterator != queue->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", queue->is_empty(queue));
	for (; 0 < _data; _data--) {
		printf("dequeue %d", queue->dequeue(queue));
		printf("\ndatas = ( "); iterator = queue->first; for (; iterator != queue->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", queue->is_empty(queue));
	}

#endif

#ifdef DEQUE
#define _data deque_data
#define iterator deque_iterator
	DEQUE _data;
	Deque* deque = new (Deque);
	DequeElement* iterator;
	deque->help();
	printf("empty? %d\n\n", deque->is_empty(deque));

	_data = 1;
	for (; _data < 10; _data++) {
		printf("push_back %d", _data);
		deque->push_back(deque, _data);
		printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", deque->is_empty(deque));
	}
	_data--;
	printf("bottom %d", deque->bottom(deque));
	printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", deque->is_empty(deque));
	for (; 0 < _data; _data--) {
		printf("pop_front %d", deque->pop_front(deque));
		printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", deque->is_empty(deque));
	}

	_data = 1;
	for (; _data < 10; _data++) {
		printf("push_front %d", _data);
		deque->push_front(deque, _data);
		printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", deque->is_empty(deque));
	}
	_data--;
	printf("top %d", deque->top(deque));
	printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
	printf(")\n");
	printf("empty? %d\n\n", deque->is_empty(deque));
	for (; 0 < _data; _data--) {
		printf("pop_back %d", deque->pop_back(deque));
		printf("\ndatas = ( "); iterator = deque->first; for (; iterator != deque->last; iterator = iterator->next) printf("%d ", iterator->data);
		printf(")\n");
		printf("empty? %d\n\n", deque->is_empty(deque));
	}

#endif
}
#endif