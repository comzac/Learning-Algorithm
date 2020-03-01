//#pragma once
//#include <stdio.h>
//#include "Tree.h"
//
//void actionFunc(BTData data)
//{
//	printf("%d \n", data);
//}
//
//int main()
//{
//	btn* bnode1 = MakeBTreeNode();
//	btn* bnode2 = MakeBTreeNode();
//	btn* bnode3 = MakeBTreeNode();
//	btn* bnode4 = MakeBTreeNode();
//	btn* bnode5 = MakeBTreeNode();
//	btn* bnode6 = MakeBTreeNode();
//
//
//	SetData(bnode1, 1);
//	SetData(bnode2, 2);
//	SetData(bnode3, 3);
//	SetData(bnode4, 4);
//	SetData(bnode5, 5);
//	SetData(bnode6, 6);
//
//
//	MakeLeftSubTree(bnode1, bnode2);
//	MakeRightSubTree(bnode1, bnode3);
//	MakeLeftSubTree(bnode2, bnode4);
//	MakeRightSubTree(bnode2, bnode5);
//	MakeRightSubTree(bnode3, bnode6);
//
//
//	printf("%d \n", GetData(GetLeftSubTree(bnode1)));
//
//	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bnode1))));
//
//	printf("\n\n\n");
//
//	PreOrderTraverse(bnode1, actionFunc);
//	printf("\n\n\n");
//
//	InOrderTraverse(bnode1, actionFunc);
//	printf("\n\n\n");
//
//	PostOrderTraverse(bnode1, actionFunc);
//	printf("\n\n\n");
//
//
//
//
//	return 0;
//
//}
