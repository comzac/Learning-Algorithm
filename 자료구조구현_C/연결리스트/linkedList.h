#pragma once
#ifndef __LINKED_LIST__
#define __LINKED_LIST__
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

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
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int(*comp)(LData, LData);

}LinkedList;

typedef LinkedList List;

void ListInit(List* _list);
void ListInsert(List* _list, LData data);
void FInsert(List* _list, LData data);
void SInsert(List* _list, LData data);


int ListFirst(List* _list, LData* data);
int ListNext(List* _list, LData* data);
LData ListRemove(List* _list);
int ListCount(List* _list);
void setSortRule(List* _list, int(*comp)(LData, LData));

#endif // !__LINKED_LIST__

