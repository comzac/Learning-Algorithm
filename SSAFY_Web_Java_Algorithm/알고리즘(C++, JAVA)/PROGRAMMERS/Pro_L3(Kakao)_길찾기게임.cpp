#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct node {
	int num;
	int y, x;
	node* left;
	node* right;

};

bool cmp(node a, node b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

void addNode(node* parent, node* child)
{
	if (parent->x > child->x)
	{
		if (parent->left == NULL)
			parent->left = child;
		else
			addNode(parent->left, child);
	}
	else
	{
		if (parent->right == NULL)
			parent->right = child;
		else
			addNode(parent->right, child);
	}
}

void preorder(vector<int>& v, node* n)
{
	if (n == NULL)
		return;

	v.push_back(n->num);
	preorder(v, n->left);
	preorder(v, n->right);
}

void postorder(vector<int>& v, node* n)
{
	if (n == NULL)
		return;

	postorder(v, n->left);
	postorder(v, n->right);
	v.push_back(n->num);
	
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	
	vector<node> idxNode;

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		idxNode.push_back({ i+1, nodeinfo[i][1], nodeinfo[i][0]});
	}
	sort(idxNode.begin(), idxNode.end(), cmp);

	node* root = &idxNode[0];

	for (int i = 1; i < idxNode.size(); i++)
	{
		addNode(root, &idxNode[i]);
	}


	vector<int> pre;
	preorder(pre, root);
	vector<int> post;
	postorder(post, root);
	answer = { pre,post };

	return answer;
}
int main()
{
	vector<vector<int>> nodeinfo = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
	vector<vector<int>> result = solution(nodeinfo);

	for (auto a : result) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}