///* 2155~2005
//	1. 1√  256MB
//*/
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int len[501];
//int dp[501][501];
//int N;
//
//int main()
//{
//	cin >> N;
//
//	int f, e;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> f >> e;
//		len[i] = f;
//		if (i == N - 1)
//		{
//			len[i + 1] = e;
//		}
//	}
//
//	for (int l = 2; l <= N; l++)
//	{
//		for (int i = 1; i <= N - l + 1; i++)
//		{
//			int kLimit = i + l - 1;
//			dp[i][kLimit] = 999999999;
//
//			for (int k = i; k <= kLimit; k++)
//			{
//				dp[i][kLimit] = min(dp[i][kLimit], dp[i][k] + dp[k + 1][kLimit] + len[i - 1] * len[k] * len[kLimit]);
//			}
//		}
//	}
//
//	cout << dp[1][N] << endl;
//
//}
