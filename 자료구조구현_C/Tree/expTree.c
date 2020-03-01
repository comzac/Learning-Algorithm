#include "expTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



btn * makeExpTree(char exp[])
{
	Stack stack;
	char tok;
	int expLen = strlen(exp);
	int i;
	btn* newNode;

	stackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		newNode = MakeBTreeNode();
		if (isdigit(exp[i]))
		{
			SetData(newNode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(newNode, stackPop(&stack));
			MakeLeftSubTree(newNode, stackPop(&stack));
			SetData(newNode, exp[i]);
		}
		stackPush(&stack, newNode);
	}
	return stackPop(&stack);
}

int EvaluateExp(btn * bt)
{
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1, op2;

	op1 = EvaluateExp(GetLeftSubTree(bt));
	op2 = EvaluateExp(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;

	default:
		break;
	}


	return 0;
}

int showData(Data data)
{
	if (data >= 0 && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);


}

void ShowPrefixTypeExp(btn * bt)
{
	PreOrderTraverse(bt, showData);
}

void ShowInfixTypeExp(btn * bt)
{
	InOrderTraverse(bt, showData);
}

void ShowPostfixTypeExp(btn * bt)
{
	PostOrderTraverse(bt, showData);
}
