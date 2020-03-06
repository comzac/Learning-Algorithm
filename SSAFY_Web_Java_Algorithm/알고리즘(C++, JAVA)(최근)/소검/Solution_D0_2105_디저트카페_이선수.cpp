///* 1640~1730
//	풀이 :
//	1) 열은 1~N-2까지 행은 모든 행 순회를 한다.
//	2) 순회를 할 때마다 visit처리는 다시 해준다.
//	3) 시작위치 매개변수를 가지고 출발하고 해당 위치로 돌아오면 거리를 최대값과 비교해준다.
//	4) 범위를 벗어난 경우는 skip한다.
//	5) 최대값 비교이기 때문에 가지치기가 불가능하지만,
//	DP를 고려해보자.
//	DP를 안써도 20*20 이기 때문에, 충분할 듯 하다 ..ㅎㅎ^^;
//	6) 마지막으로 방향에 대한 제한이 있어야 될 듯 하다. 반례로 하트모양?비슷한 사이클이 형성될 수도 있다.
//	7) 따라서 현재 방향이 우하면 좌하랑 우하만 허용하고,
//		우하면 우하와 좌상만 허용하는 이런 식으로 가야할 거 같다.
//		방향을 시계방향으로 강제하는것이 문제가 될까 싶기도 하지만 
//		한 방향으로 강제했을 때, 반대의 경우의 수도 다 헤아릴 수 있을 거로 생각된다.
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//};
//
//int N;
//int maxNum;
//int map[20][20];
//bool visit[20][20];
//bool numCheck[101];
//int dir[4][2] = { {1,1},{1,-1},{-1,-1},{-1,1} };
//
//int maxVal = 0;
//
//void input();
//void boolInit();
//void dfs(pos start, pos cur, int d, int dis);
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		maxVal = 0;
//		for (int i = 0; i < N-2; i++)
//		{
//			for (int j = 1; j < N - 1; j++)
//			{
//				dfs({ i,j }, { i,j }, 0, 0);
//				//boolInit();
//			}
//		}
//
//		if (maxVal == 0)
//			cout << "#" << t << " " << -1 << endl;
//		else
//			cout << "#" << t << " " << maxVal << endl;
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N;
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp > maxNum)
//				maxNum = temp;
//		}
//	}
//}
//
//void boolInit()
//{
//	//for (int i = 1; i <= maxNum; i++)
//	//	numCheck[i] = false;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//
//}
//
//void dfs(pos start, pos cur, int d, int dis)
//{
//	if (cur.y == start.y && cur.x == start.x && visit[cur.y][cur.x])
//	{
//		// 사이클 형성
//		if (maxVal < dis)
//			maxVal = dis;
//		return;
//	}
//
//	if (visit[cur.y][cur.x] || numCheck[map[cur.y][cur.x]] || cur.y < start.y)
//		return;
//
//
//	int ny, nx;
//	int curY, curX;
//	curY = cur.y;
//	curX = cur.x;
//
//	visit[curY][curX] = true;
//	numCheck[map[curY][curX]] = true;
//
//	for (int i = 0; i < 2; i++)
//	{
//		ny = curY + dir[(d + i) % 4][0];
//		nx = curX + dir[(d + i) % 4][1];
//
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
//			continue;
//		dfs(start, { ny,nx }, (d + i) % 4, dis + 1);
//	}
//
//	visit[curY][curX] = false;
//	numCheck[map[curY][curX]] = false;
//}
//
///*
//1
//4
//9 8 9 8
//4 6 9 4
//8 7 7 8
//4 5 3 5
//
//1 8 18 18 7 16 15 3 5 6 3 6 8 3 15 13 15 2 4 1 11 17 3 4 3 17 16 2 18 10 2 3 11 12 11 17 16 2 9 16 5 4 17 7 6 16 16 11 15 8 2 1 7 18 12 11 6 2 13 12 12 15 9 11 12 18 
//*/