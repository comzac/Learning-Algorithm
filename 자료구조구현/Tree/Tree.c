#include "Tree.h"

btn * MakeBTreeNode()
{
	btn* newBtn = (btn*)malloc(sizeof(btn));
	newBtn->left = NULL;
	newBtn->right = NULL;
	
	return newBtn;
}

BTData GetData(btn * bt)
{
	return bt->data;
}

void SetData(btn * bt, BTData data)
{
	bt->data = data;
}

btn * GetLeftSubTree(btn * bt)
{

	return bt->left;
}

btn * GetRightSubTree(btn * bt)
{
	return bt->right;
}

void MakeLeftSubTree(btn * main, btn * sub)
{
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(btn * main, btn * sub)
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}

void InOrderTraverse(btn * bt, actionFunction action)
{
	if (bt == NULL)
		return;

	InOrderTraverse(bt->left, action);
	action(bt->data);
	InOrderTraverse(bt->right, action);
}

void PreOrderTraverse(btn * bt, actionFunction action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreOrderTraverse(bt->left, action);
	PreOrderTraverse(bt->right, action);
}

void PostOrderTraverse(btn * bt, actionFunction action)
{
	if (bt == NULL)
		return;

	PostOrderTraverse(bt->left, action);
	PostOrderTraverse(bt->right, action);
	action(bt->data);

}
