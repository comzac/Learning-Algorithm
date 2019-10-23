//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int vertex;
//int edge;
//int start;
//int graph[1001][1001];
//int visit[1001];
//int dfsLen;
//int bfsLen;
//
//void dfs(int idx)
//{
//	if (visit[idx])
//		return;
//	visit[idx] = true;
//	cout << idx << " ";
//	dfsLen++;
//
//
//	for (int i = 0; i < vertex+1; i++)
//	{
//		if (!visit[i] && graph[idx][i] == 1)
//		{
//			dfs(i);
//			if (dfsLen == vertex)
//				return;
//		}
//	}
//
//	return;
//}
//
//void bfs(int idx)
//{
//	queue<int> q;
//	int index;
//	visit[idx] = true;
//	q.push(idx);
//	while (!q.empty())
//	{
//		index = q.front();
//		cout << index << " ";
//		bfsLen++;
//		if (bfsLen == vertex)
//			break;
//		q.pop();
//
//		for (int i = 0; i < vertex+1; i++)
//		{
//			if (!visit[i] && graph[index][i])
//			{
//				q.push(i);
//				visit[i] = true;
//			}
//		}
//	}
//	return;
//}
//
//void solution()
//{
//	for (int i = 0; i < vertex + 1; i++)
//		visit[i] = 0;
//
//	visit[start] = true;
//	cout << start << " ";
//	dfsLen++;
//	for (int i = 0; i < vertex +1; i++)
//	{
//		if (!visit[i] && graph[start][i] == 1)
//		{		
//			dfs(i);
//			break;
//		}
//	}
//	cout << endl;
//
//	for (int i = 0; i < vertex+1; i++)
//		visit[i] = 0;
//
//	bfs(start);
//
//}
//
//
//int main()
//{
//	cin >> vertex;
//	cin >> edge;
//	cin >> start;
//	int a, b;
//
//	for (int i = 0; i < edge; i++)
//	{
//		cin >> a >> b;
//		graph[a][b] = 1;
//		graph[b][a] = 1;
//	}
//
//	solution();
//
//	return 0;
//}
//
