///*0330~0410 40M
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y, int X):y(Y),x(X){}
//};
//int N, M;
//bool visit[100][100][4];
//int map[100][100];
//vector<pos> meltPos;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//bool meltCheck(int y, int x);
//void visitInit(int idx);
//void fixMap();
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> map[i][j];
//	int time = 0;
//	while (true)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (map[i][j] == 0)
//					continue;
//				if (meltCheck(i, j))
//				{
//					meltPos.push_back({ i,j });
//				}
//			}
//		}
//		if (meltPos.size() == 0)
//			break;
//		fixMap();
//		time++;
//	}
//	cout << time;
//	return 0;
//}
//
//bool meltCheck(int y, int x)
//{
//	int cnt = 0;
//	queue<pos> que[4];
//	int curY, curX, ny, nx;
//	int curNum;
//	int idx = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		ny = y + dir[i][0];
//		nx = x + dir[i][1];
//		if (map[ny][nx] == 0)
//		{
//			que[idx].push({ ny,nx});
//			visit[ny][nx][idx] = true;
//			idx++;
//		}
//	}
//
//	if (idx < 2)
//		return false;
//
//	for (int i = 0; i < idx; i++)
//	{
//		while (!que[i].empty())
//		{
//			pos cur = que[i].front();
//			que[i].pop();
//			curY = cur.y;
//			curX = cur.x;
//			if (curY == 0 || curX == 0 || curY == N - 1 || curX == M - 1)
//			{
//				cnt++;
//				if (cnt >= 2)
//				{
//					visitInit(i);
//					return true;
//				}
//				break;
//			}
//			for (int k = 0; k < 4; k++)
//			{
//				ny = curY + dir[k][0];
//				nx = curX + dir[k][1];
//
//				if (map[ny][nx] == 1 || visit[ny][nx][i])
//					continue;
//
//				que[i].push({ ny,nx });
//				visit[ny][nx][i] = true;
//			}
//		}
//		visitInit(i);
//	}
//	
//	return false;
//}
//
//void visitInit(int idx)
//{
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			visit[i][j][idx] = false;
//}
//
//void fixMap()
//{
//	for (int i = 0; i < meltPos.size(); i++)
//	{
//		map[meltPos[i].y][meltPos[i].x] = 0;
//	}
//	meltPos.clear();
//}
//
///*
//8 9
//0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0
//0 1 1 0 0 0 1 1 0
//0 1 0 1 1 1 0 1 0
//0 1 0 0 1 0 0 1 0
//0 1 0 1 1 1 0 1 0
//0 1 1 0 0 0 1 1 0
//0 0 0 0 0 0 0 0 0
//
//*/