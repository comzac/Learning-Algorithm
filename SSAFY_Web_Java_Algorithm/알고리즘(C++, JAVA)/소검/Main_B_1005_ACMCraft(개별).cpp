///*2045~2230
//	1. 1초 512MB
//	2. 첫 번째 게임과 두 번째 게임이 건물을 짓는 순서가 다를 수도 있다
//
//	풀이 :
//	최종 노드에서 인접한 노드로 접근하며 최대값을 기준으로 증가를 시켜주며
//	방문처리를 해주자. 최종적으로 que에 남은 노드가 없을때가
//	첫 건물로 인지되며 끝낸다.
//	-> 보다시피 이리 쉽게 해결될 문제가 아니였다.. ㅎㅎ^^
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int T;
//int N, K, D;
//int W;
//vector<int> graph[1001];
//int delay[1001] = { -1, };
//int dp[1001] = { -1, };
//vector<long> answer;
//void input();
//void build(int w);
//void reset(); // visit, graph, time 초기화 (delay는 굳이 안해도 될 듯)
//int main()
//{
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		input();
//		build(W);
//		cout << *max_element(answer.begin(), answer.end()) << endl;
//		reset();
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> K;
//	for (int n = 1; n <= N; n++)
//		cin >> delay[n];
//	int from, to;
//	for (int k = 0; k < K; k++)
//	{
//		cin >> to >> from;
//		graph[from].push_back(to); // 1 2 일 때, 그래프[2]에 1을 넣어줬다. 이 의미는 그래프[2]에 담긴 1들이 충족돼야 건설 할 수 있다의 의미
//	}
//	cin >> W; // 목적 건물
//	for (int i = 1; i <= N; i++)
//		dp[i] = -1;
//
//}
//
//void build(int w)
//{
//	queue<pair<int, int>> que;
//	que.push({ delay[w], w });
//	int cur;
//	int t;
//	int next;
//	int nextTime;
//	while (!que.empty())
//	{
//		pair<int, int> curInfo = que.front();
//		que.pop();
//		cur = curInfo.second;
//		t = curInfo.first;
//
//		if (graph[cur].size() == 0)
//		{
//			answer.push_back(t);
//		}
//		for (int i = 0; i < graph[cur].size(); i++)
//		{
//			next = graph[cur][i];
//			nextTime = delay[next] + t;
//
//			if (dp[next] < nextTime)
//			{
//				dp[next] = nextTime;
//				que.push({ nextTime, next });
//			}
//			
//		}
//	}
//}
//
//void reset()
//{
//	for (int i = 1; i <= N; i++)
//	{
//		dp[i] = -1;
//		delay[i] = -1;
//		graph[i].clear();
//		answer.clear();
//	}
//}
//
///*
//반례 생각하기
//< 여러개가 하나의 건물을 만드는데 필요조건인 경우>
//1
//4 3
//10 10 30 20
//2 1
//3 1
//4 1
//1
//
//< 딜레이가 0인 경우 >
//1
//2 1
//0 0
//2 1
//1
//
//=> dp의 초기값을 -1로 설정해주지 않으면 0이라는 값은 que에 포함되지 않아 answer vector가 empty한 상태가 되고, max_elements 함수에서 터진다.
//
//*/