///* 0200~0230
//
//	1. 1초 128MB
//	2. 가로세로가 최대 100이기때문에 한번 순회하는데 10000번의 연산이므로
//	시간적으로는 충분할듯하다.
//	순회하며 사방을 검사하여, 사방이 전부 1이 아니면 false
//	전부 1이면 true 한 뒤, true한만큼의 숫자를 반환한다. 
//	이후, 녹는걸 확인한 배열을 바탕으로 맵을 수정한다.
//
//	문제를 잘못파악했다.
//
//	사방의 문제가 아닌 전체를 기준으로 노출된 가장자리를 제거하는것이었다.
//	큰틀은 같지만, 녹는 방법을 다르게 해야한다.
//	bfs를 활용해서 0인 값들로만 이동이 가능하며, 가장자리에 닿을 수 있는 애들이
//	가장자리이다.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y, int X):y(Y),x(X){}
//};
//int N, M;
//int map[100][100];
//bool melt[100][100];
//bool visit[100][100];
//int oldNum;
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//
//void input();
//bool melting(int y, int x);
//void fixMap();
//void visitInit();
//int main()
//{
//	input();
//	int time = 0;
//	while (true)
//	{
//		int num = 0;
//		for (int i = 1; i < N - 1; i++)
//		{
//			for (int j = 1; j < M - 1; j++)
//			{
//				if (map[i][j] == 0)
//					continue;
//
//				if (melting(i, j))
//				{
//					melt[i][j] = true;
//					num++;
//				}
//				visitInit();
//			}
//		}
//
//		if (num == 0)
//			break;
//		fixMap();
//		oldNum = num;
//		time++;
//	}
//	cout << time << endl;
//	cout << oldNum << endl;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp == 1)
//				oldNum++;
//		}
//	}
//}
//
//bool melting(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	visit[y][x] = true;
//	int curY, curX, ny, nx;
//	while (!que.empty())
//	{
//		pos cur = que.front();
//		que.pop();
//		curY = cur.y;
//		curX = cur.x;
//		for (int k = 0; k < 4; k++)
//		{
//			ny = curY + dir[k][0];
//			nx = curX + dir[k][1];
//
//			if (map[ny][nx] == 1 || visit[ny][nx])
//				continue;
//
//			if (ny == 0 || nx == 0 || ny == N - 1 || nx == M - 1)
//				return true;
//			else
//			{
//				que.push({ ny,nx });
//				visit[ny][nx] = true;
//			}
//		}
//	}
//
//	return false;
//}
//
//void fixMap()
//{
//	for (int i = 1; i < N - 1; i++)
//	{
//		for (int j = 1; j < M - 1; j++)
//		{
//			if (melt[i][j])
//			{
//				map[i][j] = 0;
//				melt[i][j] = false;
//			}
//		}
//	}
//}
//
//void visitInit()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//}
