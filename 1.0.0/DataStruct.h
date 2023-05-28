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

#define StackElement struct stackElement
#define Stack struct stack
/*
Stack Element(linked)
*/
StackElement {
	STACK data;
	StackElement* before;
	StackElement* next;
};
/*
controller(Stack Element)
*/
Stack {
	StackElement* first;
	StackElement* last;
};

// Stack util

/*
return init controller(Stack Element)
*/
Stack* init() {
	Stack* temp = malloc(sizeof(Stack));
	if (temp == NULL) _throw(__dynamic_error);
	temp->first = malloc(sizeof(StackElement));
	temp->last = temp->first;
	return temp;
}
/*
push data(type is STACK) to Stack(param)
*/
void push(Stack* stack, STACK data) {
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
STACK pop(Stack* stack) {
	if (stack->first == stack->last) _throw(__data_struct_is_empty);
	stack->last = stack->last->before;
	free(stack->last->next);
	return stack->last->data;
}
/*
get Stack(param)'s last data
*/
STACK top(Stack* stack) {
	if (stack->first == stack->last) _throw(__data_struct_is_empty);
	return stack->last->before->data;
}
/*
get boolean Stack(param) is black
*/
int is_empty(Stack* stack) {
	return (stack->first == stack->last);
}

#endif

#ifdef QUEUE // using Queue

// definition of Queue

#define QueueElement struct queueElement
#define Queue struct queue
/*
Queue Element(linked)
*/
QueueElement {
	QUEUE data;
	QueueElement* before;
	QueueElement* next;
};
/*
controller(Queue Element)
*/
Queue {
	QueueElement* first;
	QueueElement* last;
};

// Queue util

/*
return init controller(Queue Element)
*/
Queue* init() {
	Queue* temp = malloc(sizeof(Queue));
	if (temp == NULL) _throw(__dynamic_error);
	temp->first = malloc(sizeof(QueueElement));
	temp->last = temp->first;
	return temp;
}
/*
push data(type is QUEUE) to Queue(param)
*/
void enqueue(Queue* queue, QUEUE data) {
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
QUEUE dequeue(Queue* queue) {
	if (queue->first == queue->last) _throw(__data_struct_is_empty);
	QUEUE temp = queue->first->data;
	queue->first = queue->first->next;
	free(queue->first->before);
	return temp;
}
/*
get Queue(param)'s last data
*/
QUEUE bottom(Queue* queue) {
	if (queue->first == queue->last) _throw(__data_struct_is_empty);
	return queue->first->data;
}
/*
get boolean Queue(param) is black
*/
int is_empty(Queue* queue) {
	return (queue->first == queue->last);
}

#endif

#ifdef DEQUE // using Deque

// definition of Deque

#define DequeElement struct dequeElement
#define Deque struct deque
/*
Deque Element(linked)
*/
DequeElement {
	DEQUE data;
	DequeElement* before;
	DequeElement* next;
};
/*
controller(Deque Element)
*/
Deque {
	DequeElement* first;
	DequeElement* last;
};

// Deque util

/*
return init controller(Deque Element)
*/
Deque* init() {
	Deque* temp = malloc(sizeof(Deque));
	if (temp == NULL) _throw(__dynamic_error);
	temp->first = malloc(sizeof(DequeElement));
	temp->last = temp->first;
	return temp;
}
/*
push data(type is Deque) to Deque(param)'s first
*/
void push_front(Deque* deque, DEQUE data) {
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
void push_back(Deque* deque, DEQUE data) {
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
DEQUE pop_front(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	DEQUE temp = deque->first->data;
	deque->first = deque->first->next;
	free(deque->first->before);
	return temp;
}
/*
get Deque(param)'s first data and remove Deque(param)'s last data
*/
DEQUE pop_back(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	deque->last = deque->last->before;
	free(deque->last->next);
	return deque->last->data;
}
/*
get Deque(param)'s first data
*/
DEQUE top(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	return deque->last->before->data;
}
/*
get Deque(param)'s last data
*/
DEQUE bottom(Deque* deque) {
	if (deque->first == deque->last) _throw(__data_struct_is_empty);
	return deque->first->data;
}
/*
get boolean Deque(param) is black
*/
int is_empty(Deque* deque) {
	return (deque->first == deque->last);
}

#endif

#endif