///* 1800~1820
//	1. 2√  128MB
//
//*/
//#include <iostream>
//#include <string>
//#include <set>
//using namespace std;
//
//int map[5][5];
//bool visit[5][5];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//set<string> s;
//
//void dfs(int y, int x, int cnt, string str);
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			visit[i][j] = true;
//			dfs(i, j, 1, to_string(map[i][j]));
//			visit[i][j] = false;
//		}
//	}
//
//	cout << s.size();
//
//	return 0;
//}
//
//void dfs(int y, int x, int cnt, string str)
//{
//	if (cnt == 6)
//	{
//		s.insert(str);
//		return;
//	}
//
//	int ny, nx;
//	for (int i = 0; i < 4; i++)
//	{
//		ny = y + dir[i][0];
//		nx = x + dir[i][1];
//		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || visit[ny][nx])
//			continue;
//		visit[ny][nx] = true;
//		dfs(ny, nx, cnt + 1, str + to_string(map[ny][nx]));
//		visit[ny][nx] = false;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		ny = y + dir[i][0];
//		nx = x + dir[i][1];
//		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
//			continue;
//		//visit[ny][nx] = true;
//		dfs(ny, nx, cnt + 1, str + to_string(map[ny][nx]));
//		//visit[ny][nx] = false;
//	}
//}
