#include "stack.h"

void stackInit(Stack * _stack)
{
	_stack->head = NULL;
}

int stackEmpty(Stack * _stack)
{
	if (_stack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void stackPush(Stack * _stack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = _stack->head;
	_stack->head = newNode;


}

Data stackPop(Stack * _stack)
{
	if (!stackEmpty(_stack))
	{
		Node* rPos = _stack->head;
		Data rData = rPos->data;

		_stack->head = _stack->head->next;
		free(rPos);

		return rData;
	}

}

Data stackPeek(Stack * _stack)
{
	if (!stackEmpty(_stack))
	{

		return _stack->head->data;
	}
}
