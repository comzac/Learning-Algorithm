#include "Queue.h"

void QueInit(Queue * que)
{
	que->front = 0;
	que->rear = 0;
}

int QIsEmpty(Queue * que)
{
	if (que->front == que->rear)
		return TRUE;
	else
		return FALSE;

}

int NextPosIdx(int pos)
{
	if (pos == QUEUELEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue * que, Data data)
{
	if (NextPosIdx(que->rear) == que->front)
	{
		printf("½ÇÆÐ¶ì\n");
		
	}
	else 
	{

		que->rear = NextPosIdx(que->rear);
		que->QArr[que->rear] = data;

	}

}

Data DeQueue(Queue * que)
{
	Data data;

	if (QIsEmpty(que))
		return -1;

	que->front = NextPosIdx(que->front);
	data = que->QArr[que->front];

	return data;
}

Data QuePeek(Queue * que)
{

	return que->QArr[que->front];
}
