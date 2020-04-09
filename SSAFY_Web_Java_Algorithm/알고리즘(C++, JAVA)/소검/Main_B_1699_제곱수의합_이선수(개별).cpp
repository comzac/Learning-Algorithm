//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//
//int dp[100001];
//
//int main()
//{
//	int N;
//	cin >> N;
//	
//	for (int i = 1; i <= N; i++)
//		dp[i] = i;
//	
//	for (int i = 3; i <= N; i++)
//	{
//		for (int j = 1; j*j <= i; j++)
//		{
//			if (dp[i] > dp[i - j*j] + 1)
//			{
//				dp[i] = dp[i - j*j] + 1;
//			}
//		}
//	}
//	cout << dp[N];
//}
//
