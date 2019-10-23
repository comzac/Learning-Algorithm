#pragma once
#ifndef __EXPTREE__
#define __EXPTREE__

#include "stack.h"
#include "Tree.h"

btn* makeExpTree(char exp[]);
int EvaluateExp(btn* bt);

void ShowPrefixTypeExp(btn* bt);
void ShowInfixTypeExp(btn* bt);
void ShowPostfixTypeExp(btn* bt);




#endif // !__EXPTREE__
