//#include <iostream>
//#include <string>
////시간초과
//
//
//using namespace std;
//
//int w, h;
//int map[501][501];
//bool visit[501][501];
//int route;
//int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
//void dfs(int sy, int sx)
//{
//	if (visit[sy][sx])
//		return;
//	visit[sy][sx] = true;
//	if (sx == w && sy == h)
//	{
//		route++;
//		return;
//	}
//
//
//	for (int k = 0; k < 4; k++)
//	{
//		if (sy - dir[k][0] > 0 && sx - dir[k][1] > 0 && sy - dir[k][0] <= h && sx - dir[k][1] <= w
//			&& map[sy][sx] > map[sy - dir[k][0]][sx - dir[k][1]])
//		{
//			dfs(sy - dir[k][0], sx - dir[k][1]);
//			visit[sy - dir[k][0]][sx - dir[k][1]] = false;
//		}
//	}
//}
//int main()
//{
//	cin >> h >> w;
//
//	int temp;
//
//	for (int i = 1; i <= h; i++)
//	{
//		for (int j = 1; j <= w; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//		}
//	}
//
//	dfs(1,1);
//
//	cout <<route;
//
//	return 0;
//}
