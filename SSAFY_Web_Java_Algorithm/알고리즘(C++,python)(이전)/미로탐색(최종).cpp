//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//int map[100][100];
//int visit[100][100];
//int n, m; // 세로 가로
//
//bool check(int x, int y)
//{
//	if (x >= 0 && x < n && y >= 0 && y < m)
//		return true;
//	return false;
//}
//void solution()
//{
//	//시작점
//	int x, y;
//	x = y = 0;
//
//	//bfs 큐
//	queue<pair<int, int>> q;
//
//	//시작지점 push
//	q.push({ x,y });
//
//	//현재 위치
//	pair<int, int> site;
//
//	int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
//
//	int nextX;
//	int nextY;
//
//	while (!q.empty())
//	{
//		site = q.front();
//		q.pop();
//		x = site.first;
//		y = site.second;
//		visit[x][y] = true;
//
//		for (int i = 0; i < 4; i++)
//		{
//			nextX = x + direction[i][0];
//			nextY = y + direction[i][1];
//
//			if (check(nextX, nextY) && map[nextX][nextY] == 1 && !visit[nextX][nextY])
//			{
//				q.push({ nextX, nextY });
//				map[nextX][nextY] = map[x][y] + 1;
//			}
//		}
//	}
//
//	cout << map[n - 1][m - 1];
//}
//int main()
//{
//	cin >> n >> m;
//
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < m; j++)
//		{
//			map[i][j] = temp[j] - '0';
//		}
//	}
//
//	solution();
//	return 0;
//}
//
///*
//거리를 구해야 하고 시작지점과 목표지점이 고정되어있다.
//	 -> 문제의 조건 파악
//경로가 따로 필요하지 않기때문에 부모노드에 대한 정보는 필요없으며
//	 -> 불필요한 메모리 할당
//최종적으로 마지막 지점까지 연산이 이루어지기 때문에 중간에 break를 할 필요없다.
//	 -> 문제의 조건 파악
//또한 별도의 테이블 필요없이 기존의 테이블을 수정하면서 진행하면 된다.
//	 -> 이 부분에서 메모리를 최소화시킬 수 있다.
//*/