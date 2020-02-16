//#include <iostream>
//#include <string>
//
//using namespace std;
//int T;
//int Y, X;
//int map[20][20];
//int cmd;
//string cmdLine;
//int ty, tx;
//int curDir;
//int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
//
//// . : 0 , * :1 , # : 2, - : 3
//// ^ : 0 À§, v : 1 ¾Æ·¡, < : 2 ¿ÞÂÊ, > : 3 ¿À¸¥ÂÊ
//// U : 0   , D : 1    , L :2      , R : 4
//// S shoot
//
//void input();
//void moveAndShoot(int y, int x, int d, int idx);
//void draw();
//void mapinit();
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input(); // ¸ÊÇü¼º
//
//		cin >> cmd;
//		cin >> cmdLine;
//
//		moveAndShoot(ty, tx, curDir, 0);
//
//		cout << "#" << t << " ";
//		draw();
//		mapinit();
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> Y >> X;
//
//	string s;
//	for (int i = 0; i < Y; i++)
//	{
//		cin >> s;
//		for (int j = 0; j < s.length(); j++)
//		{
//			switch (s[j])
//			{
//			case '.':
//				map[i][j] = 0;
//				break;
//			case '*':
//				map[i][j] = 1;
//				break;
//			case '#':
//				map[i][j] = 2;
//				break;
//			case '-':
//				map[i][j] = 3;
//				break;
//			case '^':
//				ty = i;
//				tx = j;
//				curDir = 0;
//				break;
//			case 'v':
//				ty = i;
//				tx = j;
//				curDir = 1;
//				break;
//			case '<':
//				ty = i;
//				tx = j;
//				curDir = 2;
//				break;
//			case '>':
//				ty = i;
//				tx = j;
//				curDir = 3;
//				break;
//			}
//		}
//	}
//}
//
//void moveAndShoot(int y, int x, int d, int idx)
//{
//	if (idx == cmd)
//	{
//		ty = y;
//		tx = x;
//		curDir = d;
//		return;
//	}
//
//	int ny, nx;
//	int ndir = d;
//	switch (cmdLine[idx])
//	{
//	case 'U':
//		ny = y + dir[0][0];
//		nx = x + dir[0][1];
//		ndir = 0;
//		break;
//	case 'D':
//		ny = y + dir[1][0];
//		nx = x + dir[1][1];
//		ndir = 1;
//		break;
//	case 'L':
//		ny = y + dir[2][0];
//		nx = x + dir[2][1];
//		ndir = 2;
//		break;
//	case 'R':
//		ny = y + dir[3][0];
//		nx = x + dir[3][1];
//		ndir = 3;
//		break;
//	case 'S':
//		int bulletY, bulletX;
//		bulletY = y;
//		bulletX = x;
//		ny = y;
//		nx = x;
//		while (bulletY >= 0 && bulletX >= 0 && bulletY < Y && bulletX < X)
//		{
//			bulletY += dir[ndir][0];
//			bulletX += dir[ndir][1];
//
//			if (map[bulletY][bulletX] == 1) // º®µ¹
//			{
//				map[bulletY][bulletX] = 0;
//				break;
//			}
//			else if (map[bulletY][bulletX] == 2) // °­Ã¶
//			{
//				break;
//			}
//		}
//		break;
//	}
//
//	if (ny < 0 || nx < 0 || ny >= Y || nx >= X || map[ny][nx] != 0)
//	{
//		moveAndShoot(y, x, ndir, idx + 1);
//	}
//	else
//	{
//		moveAndShoot(ny, nx, ndir, idx + 1);
//	}
//}
//
//void draw()
//{
//	for (int i = 0; i < Y; i++)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			if (i == ty && j == tx)
//			{
//				if (curDir == 0)
//				{
//					cout << "^";
//				}
//				else if (curDir == 1)
//				{
//					cout << "v";
//				}
//				else if (curDir == 2)
//				{
//					cout << "<";
//				}
//				else
//				{
//					cout << ">";
//				}
//				continue;
//			}
//
//			switch (map[i][j])
//			{
//			case 0:
//				cout << ".";
//				break;
//			case 1:
//				cout << "*";
//				break;
//			case 2:
//				cout << "#";
//				break;
//			case 3:
//				cout << "-";
//				break;
//			}
//		}
//		cout << endl;
//	}
//}
//
//void mapinit()
//{
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			map[i][j] = 0;
//		}
//	}
//}
