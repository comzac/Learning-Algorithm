#pragma once
#ifndef __BTREE__
#define __BTREE__

#include <stdlib.h>


typedef int BTData;

typedef struct _BTNode
{
	BTData data;
	struct _BTNode* left;
	struct _BTNode* right;

}BTNode;

typedef BTNode btn;

btn* MakeBTreeNode();
BTData GetData(btn* bt);
void SetData(btn* bt, BTData data);

btn* GetLeftSubTree(btn* bt);
btn* GetRightSubTree(btn* bt);

void MakeLeftSubTree(btn* main, btn* sub);
void MakeRightSubTree(btn* main, btn* sub);

typedef void actionFunction(BTData data);

void InOrderTraverse(btn* bt, actionFunction action);
void PreOrderTraverse(btn* bt, actionFunction action);
void PostOrderTraverse(btn* bt, actionFunction action);

#endif // !__BNTREE__
