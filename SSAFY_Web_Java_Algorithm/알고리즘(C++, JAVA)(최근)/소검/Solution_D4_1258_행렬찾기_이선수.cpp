//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct matrix {
//	int row;
//	int col;
//	int size;
//	matrix(int r, int c, int s) :row(r), col(c), size(s){}
//};
//
//bool compare(matrix a, matrix b)
//{
//	if (a.size == b.size)
//	{
//		return a.row < b.row;
//	}
//	else
//	{
//		return a.size < b.size;
//	}
//}
//
//int map[100][100];
//bool v[100][100];
//vector<matrix> matV;
//int N;
//int startX, startY;
//int endX, endY;
//void input();
//void check();
//void Init();
//void makeMatrix(int y, int x);
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		check();
//		
//		cout << "#" << t << " " << matV.size() << " ";
//		sort(matV.begin(), matV.end(), compare);
//		for (int i = 0; i < matV.size(); i++)
//		{
//			cout << matV[i].row << " " << matV[i].col << " ";
//		}
//		cout << endl;
//		matV.clear();
//		Init();
//	}
//
//
//
//	return 0;
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
//
//}
//
//void check()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (v[i][j] || map[i][j] == 0)
//				continue;
//			makeMatrix(i, j);
//		}
//	}
//
//}
//
//void Init()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = 0;
//			v[i][j] = false;
//		}
//	}
//}
//
//void makeMatrix(int y, int x)
//{
//	startX = x;
//	startY = y;
//
//	int i;
//	for (i = x; i < N; i++)
//	{
//		if (map[y][i] == 0)
//			break;
//	}
//	endX = i - 1;
//
//	for (i = y; i < N; i++)
//	{
//		if (map[i][x] == 0)
//			break;
//	}
//	endY = i - 1;
//
//	int row = endY - startY + 1;
//	int col = endX - startX + 1;
//	int size = row * col;
//
//	matV.push_back(matrix(row, col, size));
//
//	for (int i = y; i <= endY; i++)
//	{
//		for (int j = x; j <= endX; j++)
//		{
//			v[i][j] = true;
//		}
//	}
//}
