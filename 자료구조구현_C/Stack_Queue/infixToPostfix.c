//#include "infixToPostfix.h"
//#include "ListStack.h"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//int GetOpPrec(char op)
//{
//	switch (op)
//	{
//	case '*':
//	case '/':
//		return 5;
//	case '+':
//	case '-':
//		return 3;
//	case '(':
//		return 1;
//
//	default:
//		break;
//	}
//
//	return -1;
//}
//
//int WhoPrecOp(char op1, char op2)
//{
//	int prec1 = GetOpPrec(op1);
//	int prec2 = GetOpPrec(op2);
//
//	if (prec1 > prec2)
//		return 1;
//	else if (prec1 < prec2)
//		return -1;
//	else
//		return 0;
//}
//
//
//
//void ConvToRPNExp(char exp[])
//{
//	//일단 여기서 수식 전체 문자열을 받는다
//	//이후, 문자열들을 하나하나 검사해서 stack에 담을거야
//	//그럼 일단 담아야할 stack 필요하고,
//	//문자열의 인덱스를 나타낼 변수하나 필요하고,
//	//문자열의 길이 정보 필요하고
//	//결과적으로 배열형태로 받은 exp를 반환할것이기 때문에 기존에 보관장소?가 필요하고
//
//	Stack stack;
//	int expLen = strlen(exp);
//	int idx = 0;
//	int i;
//	char* convExp = (char*)malloc(expLen + 1); // +1 해주는 이유는 문자열 특성상 마지막 \n 때문인가?
//	memset(convExp, 0, (sizeof(char)) * expLen + 1); // sizeof(char)이 굳이 들어가야할까?
//	stackInit(&stack);
//
//	char tok, popOp;
//
//	for (i = 0; i < expLen; i++)
//	{
//		tok = exp[i];
//		if (isdigit(tok))
//		{
//			convExp[idx++] = tok;
//		}
//		else
//		{
//			switch (tok)
//			{
//			case '(' :
//				stackPush(&stack, tok);
//				break;
//
//			case ')':
//				while (!stackEmpty(&stack))
//				{
//					popOp = stackPop(&stack);
//					if (popOp == '(')
//						break;
//					convExp[idx++] = popOp;
//				}
//				break;
//			
//			case '+':
//			case '-':
//			case '*':
//			case '/':
//				while (!stackEmpty(&stack) && WhoPrecOp(stackPeek(&stack), tok) >= 0)
//				{
//					convExp[idx++] = stackPop(&stack);
//				}
//
//				stackPush(&stack, tok);
//				break;						   
//			}
//		}
//	}
//
//	while (!stackEmpty(&stack))
//	{
//		convExp[idx++] = stackPop(&stack);
//	}
//
//	strcpy_s(exp, expLen + 1, convExp);
//	free(convExp);
//
//}
