///* 2100~2125
//	1. 1초 256MB
//	2. 고슴도치 문제랑 똑같다.
//	다만, 최대 넓이가 1000인데,
//	100개의 테케가 1초다.
//	음 1000*1000 짜리가 100tc나온다 가정했을 때,
//	불과 상근이가 가장 멀며 동시에 둘의 중심에서 출구가 가장 
//	멀다고 가정하면 대략 50만*4 => 200만 정도 연산량이 나올듯하다.
//	그럼, 최악의 경우 약 2억의 연산이므로 애매하지만 경험에 의하면 가능할듯하다.
//	(꼭 1억번에 1초는 아니더라)
//
//	풀이:
//	상근이 위치와 불의 위치를 큐에 담는다,
//	불의 이동 -> 상근이 이동을 반복하며, 상근이가 더이상 이동할 곳이 없을 때,
//	impossible!
//	범위 밖으로 나갔을 때, 거리를 세준다.
//	문자에 따른 이동을 결정할 것이기 때문에 상근이의 이동 visit변수만 있으면 될 듯하다.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//};
//
//queue<pos> sang;
//queue<pos> fire;
//char map[1000][1000];
//bool visit[1000][1000];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int N, M;
//
//void input();
//int bfs();
//void reset();
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		input();
//		int answer = bfs();
//		if (answer == -1)
//			cout << "IMPOSSIBLE" << endl;
//		else
//			cout << answer << endl;
//		reset();
//	}
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> M >> N;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin	>> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] == '*')
//			{
//				fire.push({ i,j });
//			}
//			else if (temp[j] == '@')
//			{
//				sang.push({ i,j });
//				visit[i][j] = true;
//			}
//		}
//	}
//}
//
//int bfs()
//{
//	int dis = 0;
//	int curY, curX, ny, nx;
//	while (!sang.empty())
//	{
//		int size = fire.size();
//		while (size-- > 0)
//		{
//			curY = fire.front().y;
//			curX = fire.front().x;
//			fire.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '*' || map[ny][nx] == '#')
//					continue;
//				map[ny][nx] = '*';
//				fire.push({ ny,nx });
//			}
//		}
//
//		size = sang.size();
//		while (size-- > 0)
//		{
//			curY = sang.front().y;
//			curX = sang.front().x;
//			sang.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
//					return dis+1;
//				if(visit[ny][nx] || map[ny][nx] == '*' || map[ny][nx] == '#')
//					continue;
//				visit[ny][nx] = true;
//				sang.push({ ny,nx });
//			}
//		}
//		dis++;
//	}
//	return -1;
//}
//
//void reset()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//	while (!sang.empty())
//		sang.pop();
//	while (!fire.empty())
//		fire.pop();
//
//}
