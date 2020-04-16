///* 2130~2150
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//struct pos {
//	int xy;
//	int xx;
//	pos(int y = 0, int x = 0):xy(y), xx(x){}
//};
//int N;
//vector<pos> v;
//bool visit[11];
//int startXY;
//int startXX;
//int maxVal;
//int maxXY;
//int maxXX;
//
//int main();
//
//void input();
//void dfs(int XY, int XX, int cnt);
//void output(int XY, int XX);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		v.clear();
//		maxVal = 0;
//		for (int i = 0; i < 11; i++)
//			visit[i] = false;
//		input();
//
//		
//		for (int i = 0; i < v.size(); i++)
//		{
//			startXY = v[i].xy;
//			startXX = v[i].xx;
//			dfs(startXY, startXX, 1);
//		}
//
//		cout << "#" << t << " ";
//		output(maxXY, maxXX);
//		cout << endl;
//	}
//}
//
//void input()
//{
//	cin >> N;
//	int xy, xx;
//
//	for (int i = 0; i < N; i++)
//	{	
//		cin >> xy >> xx;
//		v.push_back({ xy, xx });
//	}
//	
//}
//
//void dfs(int XY, int XX, int cnt)
//{
//	if (maxVal < cnt)
//	{
//		maxVal = cnt;
//		maxXY = startXY;
//		maxXX = startXX;
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].xy == XX)
//		{
//			dfs(XX, v[i].xx, cnt + 1);
//		}
//	}
//}
//
//void output(int XY, int XX)
//{
//	cout << XY << " " << XX << " ";
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].xy == XX)
//		{
//			output(XX, v[i].xx);
//		}
//	}
//}
