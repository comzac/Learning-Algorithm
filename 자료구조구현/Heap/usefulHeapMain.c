#include <stdio.h>
#include "Heap.h"


int actionFunction(Data d1, Data d2)
{
	return d2 - d1;
}

int main()
{

	heap _heap;
	HeapInit(&_heap, actionFunction);

	HeapInsert(&_heap, 'A');
	HeapInsert(&_heap, 'G');
	HeapInsert(&_heap, 'C');
	//printf("%c \n", HeapDelete(&_heap));

	HeapInsert(&_heap, 'D');
	HeapInsert(&_heap, 'B');
	HeapInsert(&_heap, 'E');
	//printf("%c \n", HeapDelete(&_heap));

	while (!HIsEmpty(&_heap))
		printf("%c \n", HeapDelete(&_heap));


	return 0;
}