///* 0210~0240
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//int dir[2][2] = { {0,1},{1,0} };
//int N;
//int map[100][100];
//long long dp[100][100];
//long long DP();
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	cout << DP();
//	return 0;
//}
//
//long long DP()
//{
//	dp[0][0] = 1;
//	int ny, nx;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (dp[i][j] == 0 || (i == N-1 && j == N-1))
//				continue;
//			int dis = map[i][j];
//
//			for (int k = 0; k < 2;k++)
//			{
//				ny = i + dir[k][0]*dis;
//				nx = j + dir[k][1]*dis;
//
//				if (ny >= N || nx >= N)
//					continue;
//				dp[ny][nx] += dp[i][j];
//			}
//		}
//	}
//
//	return dp[N - 1][N - 1];
//}
