//#include "stack.h"
//
//void stackInit(Stack * _stack)
//{
//	_stack->topIndex = -1;
//}
//
//int stackEmpty(Stack * _stack)
//{
//	if (_stack->topIndex == -1)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//void stackPush(Stack * _stack, Data data)
//{
//	_stack->topIndex++;
//	_stack->arr[_stack->topIndex] = data;
//
//}
//
//Data stackPop(Stack * _stack)
//{
//	if (!stackEmpty(_stack))
//	{
//		Data rData = _stack->arr[_stack->topIndex--];
//		return rData;
//	}
//	
//}
//
//Data stackPeek(Stack * _stack)
//{
//	if (!stackEmpty(_stack))
//	{
//		
//		return _stack->arr[_stack->topIndex];
//	}
//
//}
