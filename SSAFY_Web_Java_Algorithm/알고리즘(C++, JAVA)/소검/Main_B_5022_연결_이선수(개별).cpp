///* 2135~ 2300
//	1. 1초 128MB
//
//	풀이:
//	일단 둘 중 하나를 최단거리로 연결한 뒤, 나머지 하나를 bfs를 돌려봐야할 듯 하다.
//	그렇게 양쪽 다 진행해보고 최소거리를 출력하는 방향으로 진행해보자
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y = -1, int X = -1) :y(Y), x(X) {}
//};
//int N, M;
//int visit[101][101];
//pos parent[101][101];
//int minA, minB;
//int minVal = 999999999;
//pos p[4];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//void input();
//void visitInit();
//void routeCheck(pos e);
//int minDis(pos s, pos e, pos xs, pos xe);
//int bfs(pos s, pos e);
//int main()
//{
//	input();
//	//A를 최단거리로 하는 경우,
//	minA = minDis(p[0], p[1], p[2], p[3]);
//	if (minA != -1)
//	{
//		routeCheck(p[1]);
//	}
//	minB = bfs(p[2], p[3]);
//	if (minB != -1)
//	{
//		if (minVal > minA + minB)
//			minVal = minA + minB;
//	}
//	visitInit();
//	//B를 최단거리로 하는 경우,
//	minB = minDis(p[2], p[3], p[0], p[1]);
//	if (minB != -1)
//	{
//		routeCheck(p[3]);
//	}
//	minA = bfs(p[0], p[1]);
//	if (minA != -1)
//	{
//		if (minVal > minA + minB)
//			minVal = minA + minB;
//	}
//	if (minVal == 999999999)
//		cout << "IMPOSSIBLE";
//	else
//		cout << minVal;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	int y, x;
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> y >> x;
//		p[i].y = y;
//		p[i].x = x;
//	}
//}
//
//void visitInit()
//{
//	for (int i = 0; i <= N; i++)
//	{
//		for (int j = 0; j <= M; j++)
//		{
//			visit[i][j] = false;
//			parent[i][j] = { -1,-1 };
//		}
//	}
//}
//
//void routeCheck(pos e)
//{
//	pos cur = e;
//	int y, x;
//	y = cur.y;
//	x = cur.x;
//	while (!(y == 1000 && x == 1000))
//	{
//		visit[cur.y][cur.x] = true;
//		y = parent[cur.y][cur.x].y;
//		x = parent[cur.y][cur.x].x;
//		cur.y = y;
//		cur.x = x;
//	}
//}
//
//int minDis(pos s, pos e, pos xs, pos xe)
//{
//	int dis = 0;
//
//	queue<pos> que;
//	que.push({ s.y, s.x });
//	parent[s.y][s.x] = { 1000,1000 };
//
//	int curY, curX, ny, nx;
//
//	while (!que.empty())
//	{
//		int size = que.size();
//
//		while (size-- > 0)
//		{
//			curY = que.front().y;
//			curX = que.front().x;
//			que.pop();
//			if (curY == e.y && curX == e.x)
//			{
//				return dis;
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny > N || nx > M || parent[ny][nx].y != -1 || (ny == xs.y && nx == xs.x) || (ny == xe.y && nx == xe.x))
//					continue;
//				parent[ny][nx] = { curY,curX };
//				que.push({ ny,nx });
//			}
//		}
//		dis++;
//	}
//
//	return dis;
//}
//
//int bfs(pos s, pos e)
//{
//	queue<pos> que;
//	que.push({ s.y, s.x });
//	if (visit[s.y][s.x])
//		return -1;
//	else
//		visit[s.y][s.x] = true;
//
//	int curY, curX, ny, nx;
//	int dis = 0;
//
//	while (!que.empty())
//	{
//		int size = que.size();
//
//		while (size-- > 0)
//		{
//			curY = que.front().y;
//			curX = que.front().x;
//			que.pop();
//			if (curY == e.y && curX == e.x)
//			{
//				return dis;
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny > N || nx > M || visit[ny][nx])
//					continue;
//				visit[ny][nx] = true;
//				que.push({ ny,nx });
//			}
//		}
//		dis++;
//	}
//
//	return -1;
//}
