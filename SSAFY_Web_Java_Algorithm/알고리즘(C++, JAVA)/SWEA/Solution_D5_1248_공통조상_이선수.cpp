///* 1330~1440
//
//	풀이:
//	트리를 만들어서
//	같은 depth에 같은 노드값을 같는것을 찾으면 될 듯하다.
//	따라서 트리를 구성할 때, depth변수를 추가해주고,
//	서로 다른 depth라면 깊은 depth의 노드가 같아질때까지 이동을 한 뒤,
//	동시에 부모노드로 접근을 하면 될 듯하다.
//	정점이 최대 10000개 인데, 주어진 두 정점이 부모자식 관계를 갖지 않는다고 했으니
//	왼쪽한개 루트 한개 오른쪽 10000-2개 인 경우가 최대인데,
//	그래봐야 10000번 연산이다.
//	충분할 듯 하다. (물론 트리를 만드는 과정도 있지만, 전반적인 시간복잡도는 충분할 듯 하다.)
//
//	중요단서, 전체 트리에서 루트가 되는 정점은 항상 1번으로 표기된다.
//
//	그런데, 간선을 부모 - 자식순으로 준다는 단서는 있지만,
//	연결된 순서대로 준다는 말은 없다.
//	따라서, 일단 연결 관계값을 가지고
//	깊이를 동반한 트리를 형성해줘야 한다.
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct node {
//	int left;
//	int right;
//	int depth;
//	int parent;
//	node(int l = -1, int r = -1, int d = -1, int p = -1) :left(l), right(r), depth(d), parent(p) {}
//};
//
//int N, E, V1, V2;
//vector<int> connect[10001];
//node tree[10001];
//void input(); // 입력 및 그래프 형성, (이 그래프는 연결관계를 담고 있다.)
//void make_tree(int num, int depth);
//int findSameParent(int n1, int n2);
//int bfsSubTreeSize(int rn);
//void reset();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//
//		make_tree(1, 1); // 루트노드는 1이니깐, 깊이 1부터 시작
//
//		int rootNode = findSameParent(V1, V2);
//		int subTreeSize = bfsSubTreeSize(rootNode);
//
//		cout << "#" << t << " " << rootNode << " " << subTreeSize << endl;
//
//		reset();
//	}
//
//}
//
//void input()
//{
//	cin >> N >> E >> V1 >> V2;
//
//	int parent;
//	int child;
//	for (int i = 0; i < E; i++)
//	{
//		cin >> parent >> child;
//		connect[parent].push_back(child);
//	}
//
//}
//
//void make_tree(int num, int depth)
//{
//	tree[num].depth = depth;
//
//	for (int j = 0; j < connect[num].size(); j++) // i와 인접한 애들,
//	{
//		if (tree[num].left == -1)
//		{
//			tree[num].left = connect[num][j];
//			tree[tree[num].left].parent = num;
//			make_tree(tree[num].left, depth + 1);
//		}
//		else if (tree[num].right == -1)
//		{
//			tree[num].right = connect[num][j];
//			tree[tree[num].right].parent = num;
//			make_tree(tree[num].right, depth + 1);
//		}
//	}
//}
//
//int findSameParent(int n1, int n2)
//{
//	if (tree[n1].depth == tree[n2].depth)
//	{	
//		if (n1 == n2)
//			return n1;
//		else
//		{
//			return findSameParent(tree[n1].parent, tree[n2].parent);
//		}	
//	}
//	else if (tree[n1].depth > tree[n2].depth)
//	{
//		return findSameParent(tree[n1].parent, n2);
//	}
//	else
//	{
//		return findSameParent(n1, tree[n2].parent);
//	}
//
//	return 0;
//}
//
//int bfsSubTreeSize(int rn)
//{
//	int answer = 0;
//	queue<int> que;
//	que.push(rn);
//
//	while (!que.empty())
//	{
//		int cur = que.front();
//		que.pop();
//		answer++;
//
//		if (tree[cur].left != -1)
//			que.push(tree[cur].left);
//
//		if (tree[cur].right != -1)
//			que.push(tree[cur].right);
//	}
//
//	return answer;
//}
//
//void reset()
//{
//	for (int i = 0; i <= N; i++)
//	{
//		connect[i].clear();
//		tree[i].left = -1;
//		tree[i].right = -1;
//		tree[i].parent = -1;
//		tree[i].depth = -1;
//	}
//}
