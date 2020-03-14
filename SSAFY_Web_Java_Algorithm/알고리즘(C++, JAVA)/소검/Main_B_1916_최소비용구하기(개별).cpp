///* 2020~2035
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//#define INF 999999999
//
//int city; // 1~
//int bus; // 1~
//vector<pair<int, int>> graph[1001];
//int str, des;
//int dis[1001]; // str 기준 1~1000의 거리
//
//void input();
//void dijkstra(int base);
//void disInit();
//int main()
//{
//	input();
//	disInit();
//	dijkstra(str);
//	cout << dis[des];
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> city >> bus;
//
//	int from, to, weight;
//	for (int b = 0; b < bus; b++)
//	{
//		cin >> from >> to >> weight;
//		//if (graph[from].size() == 0)
//		graph[from].push_back({ to, weight });
//	}
//	cin >> str >> des;
//}
//
//void dijkstra(int base)
//{
//	priority_queue<pair<int, int>> pq;
//	dis[base] = 0;
//	pq.push({ 0, base });
//
//	while (!pq.empty())
//	{
//		pair<int, int> cur = pq.top();
//		pq.pop();
//		int curCity = cur.second;
//		int curDis = cur.first*-1;
//
//		if (dis[curCity] < curDis)
//			continue;
//
//		for (int i = 0; i < graph[curCity].size(); i++)
//		{
//			int next = graph[curCity][i].first;
//			int nextDis = graph[curCity][i].second + curDis;
//
//			if (dis[next] > nextDis)
//			{
//				dis[next] = nextDis;
//				pq.push({ -nextDis, next });
//			}
//		}
//
//	}
//
//}
//
//void disInit()
//{
//	for (int i = 1; i <= city; i++)
//		dis[i] = INF;
//}
