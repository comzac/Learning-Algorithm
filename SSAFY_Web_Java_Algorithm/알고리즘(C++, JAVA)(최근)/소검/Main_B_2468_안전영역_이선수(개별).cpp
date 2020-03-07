///* 2240~2310
//	1. 1초 128MB
//	2. N <= 100
//	3. 높이 최대 100
//
//	풀이 : 
//	인접구역 개수를 세는 문제이다.
//	완탐을 고려해보자면
//	높이 1~100까지 검사하며,
//	검사 회 당, visit초기화, 구역 체크 (100*100)
//	100*(100*100 + 100*100) = 2,000,000 될 듯 하다?
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0):y(Y),x(X){}
//};
//int N;
//int largeNum;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//bool visit[100][100];
//int map[100][100];
//int maxVal;
//
//void input();
//void bfs(pos cur, int height);
//void visitinit();
//int main()
//{
//	input();
//
//	for (int n = 0; n < largeNum; n++)
//	{
//		int num = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (visit[i][j] || map[i][j] <= n)
//					continue;
//				bfs({ i,j }, n);
//				num++;
//			}
//		}
//		if (num > maxVal)
//			maxVal = num;
//		
//		visitinit();
//	}
//
//	cout << maxVal;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//			if (map[i][j] > largeNum)
//				largeNum = map[i][j];
//		}
//	}
//}
//
//void bfs(pos cur, int height)
//{
//	queue<pos> que;
//	que.push({ cur.y, cur.x });
//	visit[cur.y][cur.x] = true;
//	int curY, curX, ny, nx;
//	while (!que.empty())
//	{
//		curY = que.front().y;
//		curX = que.front().x;
//		que.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || map[ny][nx] <= height)
//				continue;
//			que.push({ ny,nx });
//			visit[ny][nx] = true;
//		}
//
//	}
//}
//
//void visitinit()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//}
