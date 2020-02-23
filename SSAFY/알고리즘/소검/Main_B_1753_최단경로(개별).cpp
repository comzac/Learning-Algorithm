#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
int V, E;
int start;
int dis[20001]; // 1부터 1~20000까지의 거리를 보관할 배열
vector<pair<int, int>> graph[20001];
void input();
void disInit();
void dijkstra(int startIdx);

int main()
{
	input();
	disInit(); // 모든 거리를 최대치로 설정 (최소값이 들어올 수 있도록)
	dijkstra(start);
	for (int v = 1; v <= V; v++)
	{
		if (dis[v] == INF)
			cout << "INF" << endl;
		else
			cout << dis[v] << endl;
	}
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;
	int from, to, w;

	for (int e = 0; e < E; e++) // 최소길이 간선만 저장하도록 설계
	{
		cin >> from >> to >> w;
		if(graph[from].size() == 0)
			graph[from].push_back({ to, w });
		else
		{
			bool isCollet = false;
			for (int i = 0; i < graph[from].size(); i++)
			{
				if (graph[from][i].first == to)
				{
					if (graph[from][i].second > w)
						graph[from][i].second = w;
					isCollet = true;
				}
			}
			if(!isCollet)
				graph[from].push_back({ to, w });
		}	
	}
	
}

void disInit()
{
	for (int i = 1; i <= V; i++)
	{
		dis[i] = INF;
	}
}

void dijkstra(int startIdx)
{
	int nextDis;
	int nextVer;
	dis[startIdx] = 0; // 스스로니깐 0
	priority_queue<pair<int, int>> pq; // 최소 거리 간선을 먼저 고르기 위해 pq 활용
	pq.push({ -0, startIdx }); // 0은 상관이 없지만, pq를 greater로 바꾸던지 음수값을 활용하던지해서 최소값을 상단에 위치하도록 설정

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		int weight = cur.first * -1;
		int curVertex = cur.second; // 음수를 양수화
		if (dis[curVertex] < weight)
			continue;
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			if (curVertex == graph[curVertex][i].first) // 다시 돌아오는 경우,
				continue;
			nextVer = graph[curVertex][i].first;
			nextDis = graph[curVertex][i].second + weight;

			if (dis[nextVer] > nextDis)
			{
				dis[nextVer] = nextDis;
				pq.push({ nextDis*-1 , nextVer});
			}
		}
	}
}
