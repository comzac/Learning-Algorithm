//// 2250~0110 2H20M
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//#define INF 999999999
//
//int N, M;
//int s, e, c;
//int FW[401][401];
//
//void input();
//void fwMethod();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		fwMethod();
//		int minVal = INF;
//		for (int i = 1; i <= N; i++)
//		{
//			if (minVal > FW[i][i])
//			{
//				minVal = FW[i][i];
//			}
//		}
//
//		if(minVal != INF)
//			cout <<"#" << t << " " << minVal << endl;
//		else
//			cout << "#" << t << " " << -1 << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N >> M;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			FW[i][j] = INF;
//		}
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		cin >> s >> e >> c;
//		FW[s][e] = c;
//	}
//
//}
//
//void fwMethod()
//{
//	for (int k = 1; k <= N; k++) 
//	{ 
//		for (int i = 1; i <= N; i++)
//		{ 
//			for (int j = 1; j <= N; j++) 
//			{ 
//				if (FW[i][k] != INF && FW[k][j] != INF)
//				{
//					if (FW[i][j] > FW[i][k] + FW[k][j])
//						FW[i][j] = FW[i][k] + FW[k][j];
//				}
//			} 
//		} 
//	}
//}
