///* 1545~1700 + 2020~2135 = 1H15M+1H+15M = 2H30M
//
//	[점화식]
//
//	dp[s][e] = dp[s][k] + dp[k+1][e] + l[i-1]*l[k]*l[j]; (s<= k <= j)
//
//	이해를 돕기 위한 예제,
//
//	ABCD
//	A <= K <= C
//	dp[A][C] = dp[A][A] + dp[B][C] + l[A-0]*l[A]*l[C];
//						...
//						...
//						...
//
//	가장 이해하기 어려운 부분은 세번째 세 가지 값이 곱해지는 부분이다.
//	이와 같은 개념이다. 세 개의 행렬을 두고 생각하면 애매하지만, 차라리 다섯개를 지정해보자
//	ABCF
//
//	이때 최소 연산 갯수를 구할 때, 다양한 경우의 수가 있을것이다.
//
//	(AB)CF 로 시작될 수도 있고, AB(CF)가 될 수도 있다.
//
//	따라서 위에서 의미하는 바는 내가 이미 연산(횟수를 파악한)을 끝낸(dp값) 부분을 더하고,
//	예를 들어 A(BC)F 이와 같이 BC의 횟수가 파악된 상태에서 ,
//	우리는 AC와 CF간의 연산횟수를 파악하고 싶은 것이다. 
//	따라서 ACF의 곱을 더해주게 되는것이다.
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <deque>
//#include <algorithm>
//
//using namespace std;
//
//struct matrix {
//
//	int row;
//	int col;
//	matrix(int r = 0, int c = 0) : row(r), col(c) {}
//
//};
//
//int map[100][100];
//int N;
//vector<matrix> v;
//int dp[21][21];
//deque<matrix> dq;
//int m[21];
//
//void input();
//void check_matrix(int y, int x);
//void connectMatrix();
//void dpMethod();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		v.clear();
//		dq.clear();
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (map[i][j] == 0)
//					continue;
//				check_matrix(i, j);
//			}
//		}
//
//		connectMatrix();
//
//		dpMethod();
//
//
//		cout << "#" << t << " " << dp[1][v.size()] << endl;
//
//		for (int i = 0; i < 21; i++)
//		{
//			for (int j = 0; j < 21; j++)
//			{
//				dp[i][j] = 0;
//			}
//			m[i] = 0;
//		}
//	}
//}
//
//void input()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//}
//
//void check_matrix(int y, int x)
//{
//	// 가로 검사
//	int sx, ex;
//	sx = ex = x;
//	while (map[y][ex] != 0 && ex < N)
//	{
//		ex++;
//	}
//
//	// 세로 검사
//	int sy, ey;
//	sy = ey = y;
//	while (map[ey][x] != 0 && ey < N)
//	{
//		ey++;
//	}
//
//	int row, col;
//	row = ey - sy;
//	col = ex - sx;
//
//	v.push_back({ row, col });
//
//	for (int i = sy; i < ey; i++)
//	{
//		for (int j = sx; j < ex; j++)
//		{
//			map[i][j] = 0;
//		}
//	}
//}
//
//void connectMatrix()
//{
//	dq.push_back({ v[0].row, v[0].col });
//
//	while (dq.size() != v.size())
//	{
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (v[i].col == dq.front().row)
//			{
//				dq.push_front(v[i]);
//			}
//			else if (dq.back().col == v[i].row)
//			{
//				dq.push_back(v[i]);
//			}
//		}
//	}
//
//	for (int i = 0; i <= v.size(); i++)
//	{
//		if (i == v.size())
//		{
//			m[i] = dq[i - 1].col;
//		}
//		else
//		{
//			m[i] = dq[i].row;
//		}
//	}
//
//}
//
//void dpMethod()
//{
//	int limit = v.size();
//	for (int l = 0; l < limit; l++)
//	{
//		for (int i = 1; i <= limit - l; i++)
//		{
//			int kLimit = i + l;
//			if (i == kLimit)
//			{
//				dp[i][kLimit] = 0;
//				continue;
//			}
//			dp[i][kLimit] = 999999999;
//			for (int k = i; k <= kLimit-1; k++)
//			{
//				dp[i][kLimit] = min(dp[i][kLimit], dp[i][k] + dp[k + 1][kLimit] + m[i - 1] * m[k] * m[kLimit]);
//			}
//		}
//	}
//}
