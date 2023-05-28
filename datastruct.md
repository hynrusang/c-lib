# ![datastruct.h](https://github.com/hynrusang/c-lib/blob/main/datastruct.md) DataStruct
- [이전으로](https://github.com/hynrusang/c-lib/tree/main)
- [소스코드](https://github.com/hynrusang/c-lib/blob/main/1.0.0/DataStruct.h)
---
- **이 문서는 developer 버전인 DataStruct 1.0.0을 다룹니다.**  
- **현재 release 버전은 DataStruct 1.0.0입니다.**  
## 정보
- 이건 하나의 **header** 파일로 융통성 있게 **Stack**, **Queue**, **Deque**등의 자료 구조를 사용할 수 있게 해주는 **header** 파일입니다.    
- (사용방법은 아래의 요소 탭을 참고하세요.)  
  
## 요소
### Stack, StackElement  
### Queue, QueueElement  
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
> create is_empty(Queue*): QUEUE;  
---
