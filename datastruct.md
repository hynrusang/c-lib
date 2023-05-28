# ![C icon](https://github.com/hynrusang/c-lib/blob/main/resource/logo.png) DataStruct
- [이전으로](https://github.com/hynrusang/c-lib/tree/main)
- [소스코드](https://github.com/hynrusang/c-lib/blob/main/1.0.0/DataStruct.h)
- [예시코드](https://github.com/hynrusang/c-lib/blob/main/1.0.0/DataStruct.c)
---
- **이 문서는 developer 버전인 DataStruct 1.0.0을 다룹니다.**  
- **현재 release 버전은 DataStruct 1.0.0입니다.**  
## 정보
- 이건 하나의 **header** 파일로 융통성 있게 **Stack**, **Queue**, **Deque**등의 자료 구조를 사용할 수 있게 해주는 **header** 파일입니다.    
- (사용방법은 아래의 요소 탭을 참고하세요.)  
  
## 요소
### Stack, StackElement  
> **Stack**과 **StackElement**는 각각 **Stack** 자료구조의 **Controller**, **Node**를 담당하는 **Struct**입니다.  
> **#include "DataStruct.h"** 이전에 **#define STACK (int || double || char || ...)** 을 선언하면,  
> 자동으로 사용가능한 **Stack** 관련 **Utility**등이 정의됩니다.  
> **#define STACK (int || double || char || ...)** 을 선언하면, 사용가능하게 되는 **Stack** 관련 **Utility**는 다음과 같습니다.
---
### Queue, QueueElement  
---
### Deque, DequeElement
---
## 업데이트 내역
> 1.0.0  
> @defined STACK Type:  
> create StackElement: struct stackElement;  
> create Stack: struct stack;  
> create init(): Stack*;  
> create push(Stack*, STACK): void;  
> create pop(Stack*): STACK;  
> create top(Stack*): STACK;  
> create is_empty(Stack*): int;  
>  
> @defined QUEUE Type:  
> create QueueElement: struct queueElement;  
> create Queue: struct queue;  
> create init(): Queue*;  
> create enqueue(Queue*, QUEUE): void;  
> create dequeue(Queue*): QUEUE;  
> create bottom(Queue*): QUEUE;  
> create is_empty(Queue*): int;  
>  
> @defined DEQUE Type:  
> create DequeElement: struct dequeElement;  
> create Deque: struct deque;  
> create init(): Deque*;  
> create push_front(Deque*, DEQUE): void;  
> create push_back(Deque*, DEQUE): void;  
> create pop_front(Deque*): DEQUE;  
> create pop_back(Deque*): DEQUE;  
> create top(Deque*): DEQUE;  
> create bottom(Deque*): DEQUE;  
> create is_empty(Deque*): int;  
---
