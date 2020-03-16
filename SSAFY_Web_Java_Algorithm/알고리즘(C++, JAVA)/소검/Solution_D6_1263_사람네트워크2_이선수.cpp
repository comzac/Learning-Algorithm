///* 2220~2255 35M
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int N;
//int fw[1001][1001];
//
//void input();
//void make_fw();
//int minDis();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		make_fw();
//		cout << "#" << t << " " << minDis() << endl;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				fw[i][j] = 0;
//			}
//		}
//	}
//}
//
//void input()
//{
//	cin >> N;
//	
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> fw[i][j];
//			if (fw[i][j] == 0)
//				fw[i][j] = 999999999;
//		}
//	}
//}
//
//void make_fw()
//{
//	for (int k = 0; k < N; k++) 
//	{ 
//		for (int i = 0; i < N; i++)
//		{ 
//			for (int j = 0; j < N; j++) 
//			{ 
//				if (fw[i][k] != 999999999 && fw[k][j] != 999999999)
//				{
//					if (fw[i][j] > fw[i][k] + fw[k][j])
//						fw[i][j] = fw[i][k] + fw[k][j];
//				}
//			} 
//		} 
//	}
//}
//
//int minDis()
//{
//	int minVal = 999999999;
//	int sum;
//	for (int i = 0; i < N; i++)
//	{
//		sum = 0;
//		for (int j = 0; j < N; j++)
//		{
//			if (i == j)
//				continue;
//			sum += fw[i][j];
//		}
//		if (minVal > sum)
//			minVal = sum;
//	}
//	return minVal;
//}
