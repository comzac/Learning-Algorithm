//#include <iostream>
//#include <string>
//
///*
//3 3
//50 45 37 
//35 50 40 
//30 30 25 
//
//
//*/
//using namespace std;
//
//int w, h;
//int map[502][502];
//int route[502][502];
//int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
//
//int dfs(int sy, int sx)
//{
//	if (route[sy][sx] != -1) 
//		return route[sy][sx];
//	if (sx < 1 || sx > w || sy < 1 || sy > h) 
//		return 0;
//	if (sx == 1 && sy == 1)
//		return 1;
//
//
//	int ny, nx;
//	route[sy][sx] = 0; //# 놓침 (접근한 경우 0처리를 해줘야 하는데 -1로 두니깐 계속 변화가없었음)
//
//	for (int k = 0; k < 4; k++) {
//		ny = sy - dir[k][0];
//		nx = sx - dir[k][1];
//		if (map[ny][nx] > map[sy][sx])
//		{
//			route[sy][sx] += dfs(ny, nx);
//		}
//	}
//
//	return route[sy][sx];
//
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
//	for (int i = 0; i < 502; i++)
//	{
//		for (int j = 0; j < 502; j++)
//		{
//			route[i][j] = -1;
//		}
//	}
//	cout << dfs(h,w);
//
//	return 0;
//}
