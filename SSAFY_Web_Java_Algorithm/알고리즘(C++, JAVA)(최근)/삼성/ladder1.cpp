//#include<iostream>
//#include<string>
//
//
//using namespace std;
//int map[101][101];
//bool check[101][101];
//int start;
//
//void dfs(int x, int y)
//{
//	if (check[y][x] || map[y][x] == 0)
//		return;
//	if (y == 100)
//	{
//		start = x;
//		return;
//	}
//	check[y][x] = true;
//
//	dfs(x + 1, y);
//	dfs(x - 1, y);
//	dfs(x, y + 1);
//}
//
//
//int main()
//{
//	for (int i = 0; i < 1; i++)
//	{
//		int qNum;
//		cin >> qNum;
//		int num;
//		for (int j = 100; j > 0; j--)
//		{
//			for (int k = 1; k <= 100; k++)
//			{
//				cin >> num;
//				map[j][k] = num;
//				check[j][k] = false;
//			}
//		}
//
//		int x;
//		int y = 1;
//
//		for (int j = 1; j <= 100; j++)
//		{
//			if (map[1][j] == 2)
//			{
//				x = j;
//				break;
//			}
//		}
//		dfs(x, y);
//		cout << "#" << qNum << " " << start << endl;
//
//	}
//
//
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}