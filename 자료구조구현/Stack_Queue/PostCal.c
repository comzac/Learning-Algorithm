 //#include "PostCal.h"
//#include <string.h>
//#include <ctype.h>
//#include "ListStack.h"
//
//int EvalRPNExp(char exp[])
//{
//	Stack stack;
//	char tok, op1, op2;
//	int len = strlen(exp);
//	int i;
//
//	stackInit(&stack);
//
//	for (i = 0; i < len; i++)
//	{
//		tok = exp[i];
//
//		if (isdigit(tok))
//		{
//			stackPush(&stack, tok - '0');
//		}
//		else
//		{
//			op2 = stackPop(&stack);
//			op1 = stackPop(&stack);
//
//			switch (tok)
//			{
//			case '+':
//				stackPush(&stack, op1 + op2);
//				break;
//			case '*':
//				stackPush(&stack, op1 * op2);
//				break;
//			case '-':
//				stackPush(&stack, op1 - op2);
//				break;
//			case '/':
//				stackPush(&stack, op1 / op2);
//				break;
//
//			default:
//				break;
//			}
//		}
//
//	}
//	
//	return stackPop(&stack);
//}
