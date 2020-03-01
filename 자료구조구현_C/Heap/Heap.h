#pragma once
#ifndef __HEAP__
#define __HEAP__

#define TRUE 1
#define FALSE 0

#define HEAPLEN 100
typedef char Data;
typedef int priorityFunction(Data d1, Data d2);

typedef struct _Heap
{
	int numOfData;
	Data heapArr[HEAPLEN];
	priorityFunction* comp;
}heap;

void HeapInit(heap* h, priorityFunction pc);
int HIsEmpty(heap* h);

void HeapInsert(heap* h, Data data);
Data HeapDelete(heap* h);

#endif // !__HEAP__
