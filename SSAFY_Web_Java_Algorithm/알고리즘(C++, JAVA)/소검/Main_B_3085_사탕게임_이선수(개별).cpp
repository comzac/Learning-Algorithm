///* 2135~2220
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//int N;
//char map[50][50];
//bool visit[50][50];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int maxVal;
//
//void input();
//int longest();
//
//int main()
//{
//	input();
//	int ny, nx;
//	char temp;
//	maxVal = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			visit[i][j] = true;
//			for (int k = 0; k < 4; k++)
//			{
//				ny = i + dir[k][0];
//				nx = j + dir[k][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
//					continue;
//
//				if (map[i][j] == map[ny][nx])
//					continue;
//
//				temp = map[ny][nx];
//				map[ny][nx] = map[i][j];
//				map[i][j] = temp;
//
//				int len = longest();
//
//				if (maxVal < len)
//					maxVal = len;
//
//				temp = map[ny][nx];
//				map[ny][nx] = map[i][j];
//				map[i][j] = temp;
//			}
//		}
//	}
//
//	cout << maxVal;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//int longest()
//{
//	char s, e;
//	int cnt = 0;
//	int maxLen = 0;
//	s = e = map[0][0];
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			e = map[i][j];
//			if (s == e)
//			{
//				cnt++;
//			}
//			else
//			{
//				if (maxLen < cnt)
//					maxLen = cnt;
//				s = e;
//				cnt = 1;
//			}
//		}
//		if (maxLen < cnt)
//			maxLen = cnt;
//		cnt = 0;
//		if (i + 1 < N)
//			s = map[i + 1][0];
//	}
//	
//
//	s = e = map[0][0];
//	for (int j = 0; j < N; j++)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			e = map[i][j];
//			if (s == e)
//			{
//				cnt++;
//			}
//			else
//			{
//				if (maxLen < cnt)
//					maxLen = cnt;
//				s = e;
//				cnt = 1;
//			}
//		}
//		if (maxLen < cnt)
//			maxLen = cnt;
//		cnt = 0;
//		if (j + 1 < N)
//			s = map[0][j+1];
//	}
//
//	return maxLen;
//}
