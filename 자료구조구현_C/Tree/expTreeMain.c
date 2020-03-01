#include <stdio.h>
#include "expTree.h"

int main()
{
	char exp[] = "12+7*";
	btn* etree = makeExpTree(exp);


	ShowPrefixTypeExp(etree);
	printf("\n");
	ShowInfixTypeExp(etree);
	printf("\n");
	ShowPostfixTypeExp(etree);
	printf("\n");
	printf("%d ", EvaluateExp(etree));


	return 0;

}