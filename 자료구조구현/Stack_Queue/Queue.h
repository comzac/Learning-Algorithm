#pragma once
#ifndef __QUEUE__
#define __QUEUE__

#define TRUE 1
#define FALSE 0

#define QUEUELEN 100

typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data QArr[QUEUELEN];

}CQueue;

typedef CQueue Queue;

void QueInit(Queue* que);
int QIsEmpty(Queue* que);
int NextPosIdx(int pos);
void Enqueue(Queue* que, Data data);
Data DeQueue(Queue* que);
Data QuePeek(Queue* que);




#endif // !__QUEUE__
