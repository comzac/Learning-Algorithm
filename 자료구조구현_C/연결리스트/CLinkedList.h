#pragma once
#ifndef __C_LINKED_LIST__
#define __C_LINKED_LIST__
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _Node
{
	int data;
	struct _Node* next;

}Node;

typedef struct _LinkedList
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;

}CLinkedList;

typedef CLinkedList List;

void ListInit(List* _list);
void ListInsert(List* _list, LData data);
void ListInsertFront(List* _list, LData data);


int ListFirst(List* _list, LData* data);
int ListNext(List* _list, LData* data);
LData ListRemove(List* _list);
int ListCount(List* _list);

#endif // !__C_LINKED_LIST__

