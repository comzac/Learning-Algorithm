///* 0928~0932
//	그래프 기본 문제,
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<int> graph[101];
//bool visit[101];
//int N;
//int M;
//
//int bfs(int num);
//int main()
//{
//	cin >> N >> M;
//
//	int from, to;
//
//	for (int i = 0; i < M; i++)
//	{
//		cin >> from >> to;
//
//		graph[from].push_back(to);
//		graph[to].push_back(from);
//	}
//
//	cout << bfs(1)-1 << endl;
//
//}
//
//int bfs(int num)
//{
//	queue<int> que;
//	que.push(num);
//	visit[num] = true;
//	int cnt = 0;
//	int cur;
//	while (!que.empty())
//	{
//		cur = que.front();
//		que.pop();
//		cnt++;
//		for (int i = 0; i < graph[cur].size(); i++)
//		{
//			if (visit[graph[cur][i]])
//				continue;
//			visit[graph[cur][i]] = true;
//			que.push(graph[cur][i]);
//		}
//	}
//	return cnt;
//}
