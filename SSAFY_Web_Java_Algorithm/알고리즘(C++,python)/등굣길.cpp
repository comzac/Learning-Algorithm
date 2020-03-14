//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(int m, int n, vector<vector<int>> puddles)
//{
//	int map[101][101] = { 0, };
//	int d[101][101] = { 0, };
//
//	for (auto v : puddles)
//		map[v[1]][v[0]] = -1;
//
//	d[1][0] = 1;
//	d[0][1] = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (map[i][j] == -1)
//				d[i][j] = 0;
//			else 
//				d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
//		}
//	}
//
//	return d[n][m];
//}
//
//int main()
//{
//	vector<vector<int>> vv = { {2,2} };
//	cout << solution(4, 3, vv) << endl;
//
//
//	return 0;
//}			