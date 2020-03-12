///* 1540~
//	풀이 :
//	'*'가 아닌 곳에 들어가서, 8방향 확인하고,
//	0인 애들은 한번 더 재귀 타고 아닌 애들은 변경만해주고 ㄱ
//
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int N;
//char map[300][300];
//bool visit[300][300];
//int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
//
//
//void input();
//void dfs(int y, int x);
//int calcu(int y, int x);
//void visitInit();
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		int cnt1 = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (map[i][j] != '*' && !visit[i][j] && calcu(i,j) == 0)
//				{
//					visit[i][j] = true;
//					dfs(i, j);
//					cnt1++;
//				}
//			}
//		}
//
//		int cnt2 = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (map[i][j] != '*' && !visit[i][j])
//				{
//					cnt2++;
//				}
//			}
//		}
//
//
//		cout <<"#" << t << " " <<  cnt1 + cnt2 << endl;
//		visitInit();
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N;
//
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//void dfs(int y, int x)
//{
//
//	if (calcu(y, x) != 0)
//		return;
//
//	int ny, nx;
//	for (int i = 0; i < 8; i++)
//	{
//		ny = y + dir[i][0];
//		nx = x + dir[i][1];
//
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '*' || visit[ny][nx])
//			continue;
//
//		if (calcu(ny, nx) == 0)
//		{
//			visit[ny][nx] = true;
//			dfs(ny, nx);
//		}
//		else
//		{
//			visit[ny][nx] = true;
//		}
//	}
//
//}
//
//int calcu(int y, int x)
//{
//	int cnt = 0;
//	int ny, nx;
//	for (int i = 0; i < 8; i++)
//	{
//		ny = y + dir[i][0];
//		nx = x + dir[i][1];
//
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
//			continue;
//		if (map[ny][nx] == '*')
//			cnt++;
//	}
//	return cnt;
//}
//
//void visitInit()
//{
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			visit[i][j] = false;
//}
//
///*
//
//02*20
//13*31
//2*21*
//3*311
//2*200
//
//
//
//*/