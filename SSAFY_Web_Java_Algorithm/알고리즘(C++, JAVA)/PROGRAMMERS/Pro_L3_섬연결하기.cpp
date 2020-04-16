///*
//	유니온 파인드를 활용한 문제,
//	각각 노드의 루트노드를 저장할 배열을 생성하고,
//	짧은 간선(거리)부터 유니온을 시켜 같은 루트가 아닌 경우, 연결을
//	진행하면 된다.
//	섬 개수 n보다 하나 적은 n-1개의 간선이 연결되면 모든 섬이 연결된걸로 간주한다.
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int root[101];
//int N;
//
//bool cmp(vector<int> a, vector<int> b) {
//	return a[2] < b[2];
//}
//
//void make_set() {
//	for (int i = 0; i < N; i++)
//		root[i] = -1;
//}
//
//int getParent(int x) {
//	if (root[x] < 0)
//		return x;
//	return root[x] = getParent(root[x]);
//}
//
//bool unionSet(int a, int b) {
//	int rootA = getParent(a);
//	int rootB = getParent(b);
//
//	if (rootA == rootB)
//		return false;
//
//	if (root[rootA] < root[rootB])
//	{
//		root[rootA] += root[rootB];
//		root[rootB] = rootA;
//	}
//	else
//	{
//		root[rootB] += root[rootA];
//		root[rootA] = rootB;
//	}
//	return true;
//}
//
//int solution(int n, vector<vector<int>> costs) {
//	int answer = 0;
//	N = n;
//	make_set();
//	sort(costs.begin(), costs.end(), cmp);
//	int edgeCnt = 0;
//	int sum = 0;
//	for (int i = 0; i < costs.size(); i++)
//	{
//		int to = costs[i][0];
//		int from = costs[i][1];
//
//		if (unionSet(to, from)) {
//			edgeCnt++;
//			sum += costs[i][2];
//			if (edgeCnt == N - 1)
//				break;
//		}
//	}
//	answer = sum;
//	return answer;
//}
//
//int main()
//{
//	int n = 4;
//	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
//	cout << solution(n, costs);
//}
//
//
