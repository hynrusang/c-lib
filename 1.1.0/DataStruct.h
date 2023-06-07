/*
this source code is a source code that implements data structures such as Stack, Queue, Deque, and Tree in C language.
When you use it,

#define (STACK || QUEUE || DEQUE || TREE) (int || char || double || ...)
#include "DataStruct.h href"

You can create at the top of the C source file.
For example, DataStructure.h is located in the same path as the C source file,
will use Stack data structure, and if the data type is int,

#define STACK int
#include "DataStruct.h"

You can write at the top of the C source.
Author: Hynrusang
*/
#ifndef DATASTRUCTHEADER
#define DATASTRUCTHEADER
#define new(_class_type) _##_class_type##$init();
#define __dynamic_error 1
#define __data_struct_is_empty 2
#include <stdio.h>
#include <stdlib.h>
/*
throw Error with reason
*/
void _throw(int code) {
	switch (code) {
	case __dynamic_error:
		printf("\nDynamic memory allocation failed (may be due to low memory)\n");
		exit(code);
	case __data_struct_is_empty:
		printf("\nThis DataStructure is already blank.\n");
		exit(code);
	}
}

#ifdef STACK // using Stack

// definition of Stack

/*
Stack Element(linked)
*/
typedef struct StackElement StackElement;
struct StackElement {
	STACK data;
	StackElement* before;
	StackElement* next;
};
/*
controller(Stack Element)
*/
typedef struct Stack Stack;
struct Stack {
	StackElement* first;
	StackElement* last;
	void (*push)(Stack* this, STACK data);
	STACK (*pop)(Stack* this);
	STACK (*top)(Stack* this);
	int (*is_empty)(Stack* this);
	void (*help)();
};

// Stack util

/*
push data(type is STACK) to Stack(param)
*/
void _STACK$PUSH(Stack* stack, STACK data) {
	stack->last->next = malloc(sizeof(StackElement));
	if (stack->last->next == NULL) _throw(__dynamic_error);
	else {
		stack->last->data = data;
		stack->last->next->before = stack->last;
	}
	stack->last = stack->last->next;
}
/*
get Stack(param)'s last data and remove Stack(param)'s last data
*/
STACK _STACK$POP(Stack* stack) {
	if (stack->first == stack->last) _throw(__data_struct_is_empty);
	stack->last = stack->last->before;
	free(stack->last->next);
	return stack->last->data;
}
/*
get Stack(param)'s last data
*/
STACK _STACK$TOP(Stack* stack) {
	if (stack->first == stack->last) _throw(__data_struct_is_empty);
	return stack->last->before->data;
}
/*
get boolean Stack(param) is black
*/
int _STACK$IS_EMPTY(Stack* stack) {
	return (stack->first == stack->last);
}
/*
printf all available functions
*/
void _STACK$HELP() {
	for (int i = 0; i < 30; i++) printf("*");
	printf("\nall available struct list:\n");
	printf("StackElement: struct stackElement\n");
	printf("Stack: struct stack\n");

	printf("\nall available functions list:\n");

	printf("\nabout initialization:\n");
	printf("new (Stack): Stack*\n");

	printf("\nabout push:\n");
	printf("stack->push(Stack*, STACK): void\n");

	printf("\nabout pop:\n");
	printf("stack->pop(Stack*): STACK\n");

	printf("\nabout peek:\n");
	printf("stack->top(Stack*): STACK\n");

	printf("\nabout blank check:\n");
	printf("stack->is_empty(Stack*): int\n");
	for (int i = 0; i < 30; i++) printf("*");
	printf("\n");
}
/*
return init controller(Stack Element)
*/
Stack* _Stack$init() {
	Stack* this = malloc(sizeof(Stack)); if (this == NULL) _throw(__dynamic_error);
	this->first = malloc(sizeof(StackElement));
	this->last = this->first;
	this->push = _STACK$PUSH;
	this->pop = _STACK$POP;
	this->top = _STACK$TOP;
	this->is_empty = _STACK$IS_EMPTY;
	this->help = _STACK$HELP;
	return this;
}

#endif

#ifdef QUEUE // using Queue

// definition of Queue

/*
Queue Element(linked)
*/
typedef struct QueueElement QueueElement;
struct QueueElement {
	QUEUE data;
	QueueElement* before;
	QueueElement* next;
};
/*
controller(Queue Element)
*/
typedef struct Queue Queue;
struct Queue {
	QueueElement* first;
	QueueElement* last;
	void (*enqueue)(Queue* this, QUEUE data);
	QUEUE (*dequeue)(Queue* this);
	QUEUE (*bottom)(Queue* this);
	int (*is_empty)(Queue* this);
	void (*help)();
};

// Queue util

/*
push data(type is QUEUE) to Queue(param)
*/
void _QUEUE$ENQUEUE(Queue* queue, QUEUE data) {
	queue->last->next = malloc(sizeof(QueueElement));
	if (queue->last->next == NULL) _throw(__dynamic_error);
	else {
		queue->last->data = data;
		queue->last->next->before = queue->last;
	}
	queue->last = queue->last->next;
}
/*
get Queue(param)'s first data and remove Queue(param)'s first data
*/
QUEUE _QUEUE$DEQUEUE(Queue* queue) {
	if (queue->first == queue->last) _throw(__data_struct_is_empty);
	QUEUE temp = queue->first->data;
	queue->first = queue->first->next;
	free(queue->first->before);
	return temp;
}
/*
get Queue(param)'s last data
*/
QUEUE _QUEUE$BOTTOM(Queue* queue) {
	if (queue->first == queue->last) _throw(__data_struct_is_empty);
	return queue->first->data;
}
/*
get boolean Queue(param) is black
*/
int _QUEUE$IS_EMPTY(Queue* queue) {
	return (queue->first == queue->last);
}
/*
printf all available functions
*/
void _QUEUE$HELP() {
	for (int i = 0; i < 30; i++) printf("*");
	printf("\nall available struct list:\n");
	printf("QueueElement: struct queueElement\n");
	printf("Queue: struct queue\n");

	printf("\nall available functions list:\n");

	printf("\nabout initialization:\n");
	printf("new (Queue): Queue*\n");

	printf("\nabout push:\n");
	printf("queue->enqueue(Queue*, QUEUE): void\n");

	printf("\nabout pop:\n");
	printf("queue->dequeue(Queue*): QUEUE\n");

	printf("\nabout peek:\n");
	printf("queue->bottom(Queue*): QUEUE\n");

	printf("\nabout blank check:\n");
	printf("queue->is_empty(Queue*): int\n");
	for (int i = 0; i < 30; i++) printf("*");
	printf("\n");
}
/*
return init controller(Queue Element)
*/
Queue* _Queue$init() {
	Queue* temp = malloc(sizeof(Queue));
	if (temp == NULL) _throw(__dynamic_error);
	temp->first = malloc(sizeof(QueueElement));
	temp->last = temp->first;
	temp->enqueue = _QUEUE$ENQUEUE;
	temp->dequeue = _QUEUE$DEQUEUE;
	temp->bottom = _QUEUE$BOTTOM;
	temp->is_empty = _QUEUE$IS_EMPTY;
	temp->help = _QUEUE$HELP;
	return temp;
}

#endif

#ifdef DEQUE // using Deque

// definition of Deque

/*
Deque Element(linked)
*/
typedef struct DequeElement DequeElement;
struct DequeElement {
	DEQUE data;
	DequeElement* before;
	DequeElement* next;
};
/*
controller(Deque Element)
*/
typedef struct Deque Deque;
struct Deque {
	DequeElement* first;
	DequeElement* last;
	void (*push_front)(Deque* this, DEQUE data);
	void (*push_back)(Deque* this, DEQUE data);
	DEQUE (*pop_front)(Deque* this);
	DEQUE (*pop_back)(Deque* this);
	DEQUE (*top)(Deque* this);
	DEQUE (*bottom)(Deque* this);
	/*
	get boolean Deque(param) is black
	*/	
	int (*is_empty)(Deque* this);
	/*
	printf all available functions
	*/
	void (*help)();
};

// Deque util

/*
push data(type is Deque) to Deque(param)'s first
*/
void _DEQUE$PUSH_FRONT(Deque* deque, DEQUE data) {
	deque->first->before = malloc(sizeof(DequeElement));
	if (deque->first->before == NULL) _throw(__dynamic_error);
	else {
		deque->first->before->next = deque->first;
		deque->first = deque->first->before;
		deque->first->data = data;
	}
}
/*
push data(type is Deque) to Deque(param)'s last
*/
void _DEQUE$PUSH_BACK(Deque* deque, DEQUE data) {
	deque->last->next = malloc(sizeof(DequeElement));
	if (deque->last->next == NULL) _throw(__dynamic_error);
	else {
		deque->last->data = data;
		deque->last->next->before = deque->last;
	}
	deque->last = deque->last->next;
}
/*
get Deque(param)'s first data and remove Deque(param)'s first data
*/
DEQUE _DEQUE$POP_FRONT(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	DEQUE temp = deque->first->data;
	deque->first = deque->first->next;
	free(deque->first->before);
	return temp;
}
/*
get Deque(param)'s first data and remove Deque(param)'s last data
*/
DEQUE _DEQUE$POP_BACK(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	deque->last = deque->last->before;
	free(deque->last->next);
	return deque->last->data;
}
/*
get Deque(param)'s first data
*/
DEQUE _DEQUE$TOP(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	return deque->last->before->data;
}
/*
get Deque(param)'s last data
*/
DEQUE _DEQUE$BOTTOM(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	return deque->first->data;
}
int _DEQUE$IS_EMPTY(Deque* deque) {
	return (deque->first == deque->last);
}
void _DEQUE$HELP() {
	for (int i = 0; i < 30; i++) printf("*");
	printf("\nall available struct list:\n");
	printf("DequeElement: struct dequeElement\n");
	printf("Deque: struct deque\n");

	printf("\nall available functions list:\n");

	printf("\nabout initialization:\n");
	printf("init(): Deque*\n");

	printf("\nabout push:\n");
	printf("push_front(Deque*, DEQUE): void\n");
	printf("push_back(Deque*, DEQUE): void\n");

	printf("\nabout pop:\n");
	printf("pop_front(Deque*): DEQUE\n");
	printf("pop_back(Deque*): DEQUE\n");

	printf("\nabout peek:\n");
	printf("top(Deque*): DEQUE\n");
	printf("bottom(Deque*): DEQUE\n");

	printf("\nabout blank check:\n");
	printf("is_empty(Deque*): int\n");
	for (int i = 0; i < 30; i++) printf("*");
	printf("\n");
}
/*
return init controller(Deque Element)
*/
Deque* _Deque$init() {
	Deque* temp = malloc(sizeof(Deque));
	if (temp == NULL) _throw(__dynamic_error);
	temp->first = malloc(sizeof(DequeElement));
	temp->last = temp->first;
	temp->push_front = _DEQUE$PUSH_FRONT;
	temp->push_back = _DEQUE$PUSH_BACK;
	temp->top = _DEQUE$TOP;
	temp->bottom = _DEQUE$BOTTOM;
	temp->pop_front = _DEQUE$POP_FRONT;
	temp->pop_back = _DEQUE$POP_BACK;
	temp->is_empty = _DEQUE$IS_EMPTY;
	temp->help = _DEQUE$HELP;
	return temp;
}

#endif

#endif