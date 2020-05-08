///* 1655~
//	1. 1초 128MB
//	2. 핀은 수평, 수직 방향으로 인접한 핀을 뛰어넘어서 그 핀의 다음 칸으로 이동하는 것만 허용된다. 
//	 인접한 핀의 다음 칸은 비어있어야 하고 그 인접한 핀은 제거된다.
//	 현재 게임판에 꽂혀있는 핀의 상태가 주어진다. 이때, 핀을 적절히 움직여서 게임판에 남아있는
//	 핀의 개수를 최소로 하려고 한다. 또, 그렇게 남기기 위해 필요한 최소 이동횟수를 구하는 프로그램을 작성하시오.
//	3. 1 <= N <= 100 (테케 수)
//	4.  '.'는 빈 칸, 'o'는 핀이 꽂혀있는 칸, '#'는 구멍이 없는 칸이다.
//	핀의 개수는 최대 8이며, 각 테스트 케이스는 빈 줄로 구분되어져 있다.
//
//	풀이
//	1. 핀의 개수가 최대 8개니깐, 좌표와 활성화상태를 갖는 구조체나 클래스를 활용해서 백터에 담는다.
//	2. 이후 dfs
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int oCnt;
//char map[5][9];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int minPin = 10;
//void input();
//void dfs(int p);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		oCnt = 0;
//		minPin = 10;
//		input();
//		dfs(oCnt);
//
//		if (oCnt == 0)
//		{
//			cout << 0 << " " << 0 << endl;
//		}
//		else
//		{
//			cout << minPin << " " << oCnt-minPin << endl;
//		}
//	}
//
//
//
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string s;
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> s;
//		for (int j = 0; j < 9; j++)
//		{
//			map[i][j] = s[j];
//			if (s[j] == 'o')
//				oCnt++;
//		}
//	}
//
//}
//
//void dfs(int p)
//{
//	int ny, nx;
//	int nny, nnx;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (map[i][j] != 'o')
//				continue;
//
//			for (int k = 0; k < 4; k++)
//			{
//				ny = i + dir[k][0];
//				nx = j + dir[k][1];
//
//				if (ny < 0 || nx < 0 || ny >= 5 || nx >= 9 || map[ny][nx] == '.' || map[ny][nx] == '#')
//					continue;
//
//				nny = ny + dir[k][0];
//				nnx = nx + dir[k][1];
//
//				if (nny < 0 || nnx < 0 || nny >= 5 || nnx >= 9)
//					continue;
//
//				if (map[nny][nnx] == '.')
//				{
//					map[nny][nnx] = 'o';
//					map[i][j] = '.';
//					map[ny][nx] = '.';
//					dfs(p - 1);
//					map[ny][nx] = 'o';
//					map[i][j] = 'o';
//					map[nny][nnx] = '.';
//				}
//			}
//		}
//	}
//
//	if (minPin > p)
//	{
//		minPin = p;
//	}
//}
