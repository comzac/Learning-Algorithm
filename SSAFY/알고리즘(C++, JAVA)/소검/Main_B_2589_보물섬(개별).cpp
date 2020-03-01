///* 1545~1605 20M
//	1. 1초 128MB
//	2. 보물은 서로 간에 최단 거리로 이동하는데 있어 
//	가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다
//	3. 가로, 세로의 크기는 각각 50이하
//	4. 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 
//	같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다.
//	풀이 :
//	육지 일 때만 bfs로 접근하여 que가 동날때까지 거리를 계산하면 될 듯하다.
//	모든 육지를 검사하고 최대값을 출력하면 될듯하고
//	bfs를 검사할때마다 visit을 초기화 시켜준다.
//	뭔가 방법이 별게 없어서 변수가 있을수도 있겠지만, 딱히 떠오르지 않으니 일단 진행 ㄱ
//
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
//};
//
//bool visit[50][50];
//char map[50][50];
//int maxVal;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//int N, M;
//
//void input();
//void bfs(int y, int x);
//void visitInit();
//
//int main()
//{
//	input();
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (map[i][j] == 'W')
//				continue;
//			bfs(i, j);
//			visitInit();
//		}
//	}
//	cout << maxVal;
//
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
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//void bfs(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	visit[y][x] = true;
//
//	pos cur;
//	int curY, curX;
//	int ny, nx;
//	int size, dis;
//	dis = 0;
//	while (!que.empty())
//	{
//		size = que.size();
//		while (size-- > 0)
//		{
//			cur = que.front();
//			que.pop();
//			curY = cur.y;
//			curX = cur.x;
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 'W')
//					continue;
//
//				que.push({ ny,nx });
//				visit[ny][nx] = true;
//			}
//		}
//		dis++;
//	}
//	if (maxVal < dis - 1)
//		maxVal = dis - 1;
//
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
