//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int dp[501][501];
//string X;
//string Y;
//
//void initDP();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N >> X >> Y;
//		initDP();
//		int maxVal = 0;
//		for (int i = 1; i <= X.length(); i++) {
//			for (int j = 1; j <= Y.length(); j++) {
//
//				if (X[i - 1] == Y[j - 1])
//				{
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//				}
//
//			}
//		}
//		cout << fixed;
//		cout.precision(2);
//		cout << "#" << t << " " << dp[N][N]/(double)N*100 << endl;
//	}
//}
//
//
//void initDP()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			dp[i][j] = 0;
//		}
//	}
//}