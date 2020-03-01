//#include "LQueue.h"
//
//
//void QueInit(Queue * que)
//{
//	que->front = NULL;
//	que->rear = NULL;
//
//}
//
//int QIsEmpty(Queue * que)
//{
//	if (que->front == NULL)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//void EnQueue(Queue * que, Data data)
//{
//	if (que->rear->next == que->front)
//	{
//		printf("초과했습니다");
//		exit(-1);
//	}
//
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//
//	if (QIsEmpty(que))
//	{
//		que->front = newNode;
//		que->rear = newNode;
//	}
//	else
//	{
//		que->rear->next = newNode;
//		que->rear = newNode;
//	}
//
//
//}
//
//Data DeQueue(Queue * que)
//{
//	Node* delNode = (Node*)malloc(sizeof(Node));
//	Data rData;
//
//	if (QIsEmpty(que))
//	{
//		return -1;
//	}
//	else
//	{
//		delNode = que->front;
//		rData = delNode->data;
//		que->front = que->front->next;
//		free(delNode);
//		return rData;
//	}
//}
//
//Data QuePeek(Queue * que)
//{
//	if (QIsEmpty(que))
//	{
//		return -1;
//	}
//	else
//	{
//		
//		return que->front->data;
//	}
//}
