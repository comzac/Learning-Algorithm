///*
//	1. (1,1) Ω√¿€
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N;
//int map[21][21];
//int l1, l2, l3, l4, l5;
//int minVal = 100*20*20;
//
//int total;
//vector<int> temp;
//
//void input();
//void check();
//
//int main()
//{
//	input();
//	check();
//
//	cout << minVal;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int temp;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			total += temp;
//		}
//	}
//
//}
//
//void check()
//{
//	int diff;
//	int d1, d2;
//	int td1, td2;
//	for (int y = 1; y <= N - 2; y++)
//	{
//		for (int x = 2; x <= N - 1; x++)
//		{
//			diff = N - y;
//			for (int d = 1; d < diff; d++)
//			{
//				d1 = d;
//				d2 = diff - d1 - 1;
//				if (x - d1 < 1 || x + d2 > N)
//					continue;
//				for (int l = d1; l > 0; l--)
//				{
//					for (int r = d2; r > 0; r--)
//					{
//						//1
//						int x1 = x;
//						if (y == 1)
//							x1 -= 1;
//						for (int row = 1; row < y + l; row++)
//						{
//							for (int col = 1; col <= x1; col++)
//							{
//								l1 += map[row][col];
//							}
//							if(row+1 >= y)
//								x1--;
//						}
//						//2
//						int x2 = x;
//						int y2 = y+r;
//						if (x + r == N)
//							y2 -= 1;
//						for (int row = 1; row <= y2; row++)
//						{
//							for (int col = x2+1; col <= N; col++)
//							{
//								l2 += map[row][col];
//							}
//							if (row >= y)
//								x2++;
//						}
//						//3
//						int x3 = x-l;
//						int y3 = y + l;
//						if (x - l == 1)
//							y3 += 1;
//
//						for (int row = y3; row <= N; row++)
//						{
//							for (int col = 1; col < x3; col++)
//							{
//								l3 += map[row][col];
//							}
//                            if (row + 1 > y + l + r)
//                            {
//                                x3 = x + r - l;
//                            }
//                            else
//                                x3++;
//							
//						}
//						//4
//						int x4 = x + r - l;
//						int y4 = y + r;
//						if (y + l + r == N)
//							x4 += 1;
//						for (int row = N; row > y4; row--)
//						{
//							for (int col = x4; col <= N; col++)
//							{
//								l4 += map[row][col];
//							}
//							if (row-1 <= y + r + l)
//								x4++;
//						}
//
//						l5 = total - (l1 + l2 + l3 + l4);
//						temp.push_back(l1);
//						temp.push_back(l2);
//						temp.push_back(l3);
//						temp.push_back(l4);
//						temp.push_back(l5);
//
//						int _min = *min_element(temp.begin(), temp.end());
//						int _max = *max_element(temp.begin(), temp.end());
//
//						if (minVal > _max - _min)
//							minVal = _max - _min;
//
//						temp.clear();
//
//						l1 = 0;
//						l2 = 0;
//						l3 = 0;
//						l4 = 0;
//					}
//				}
//			}
//		}
//	}
//}
