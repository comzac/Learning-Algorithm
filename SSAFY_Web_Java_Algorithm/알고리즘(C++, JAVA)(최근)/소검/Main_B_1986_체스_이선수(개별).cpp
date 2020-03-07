///* 1630~1700
//	1. 2초 128MB
//	2. 그리고 Pawn은 상대팀의 말은 잡을 수 없다고 하자
//	(즉, 장애물의 역할만 한다는 것이다).
//	3. 1<= n,m <= 1000
//	4. Knight, Queen, Pawn의 개수는 각각 100을 넘지 않는다.
//
//	풀이 : 
//	모든 말에 대해서 가능 이동 경로마다 -1씩 해주고 N*M과 연산하면 될 듯 하다.
//	그런데 범위와 개수를 고려해보자.
//	pawn의 경우, 입력부터 true시키며 갯수 차감을 시키고,
//	퀸이 100개 경우, 좌우상하 검사를 하면 2000*100이다. 
//	나이트의 경우 100개일때, 4*100
//	시간상 크게 문제가 없을듯하다.
//
//	모든 말의 위치는 true가 되고, 시작된다.
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//struct unit {
//	int y;
//	int x;
//};
//
//int N, M;
//int total;
//unit units[3][100]; // 0: Q, 1:K, 2:P
//int unitsNum[3];
//int map[1001][1001];
//bool visit[1001][1001];
//int qdir[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1, -1} };
//int kdir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
//
//void input();
//void routeCheck();
//
//int main()
//{
//	input();
//	routeCheck();
//	cout << total;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	total = N * M;
//	int nums;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> nums;
//		unitsNum[i] = nums;
//		int y, x;
//		for (int j = 0; j < nums; j++)
//		{
//			cin >> y >> x;
//			units[i][j].y = y;
//			units[i][j].x = x;
//			map[y][x] = 1;
//			visit[y][x] = 1;
//			total--;
//		}
//	}
//}
//
//void routeCheck()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < unitsNum[i]; j++)
//		{
//			if (i == 0) // 퀸
//			{
//				int y, x;
//
//				for (int k = 0; k < 8; k++)
//				{
//					y = units[i][j].y;
//					x = units[i][j].x;
//
//					while (true)
//					{
//						y += qdir[k][0];
//						x += qdir[k][1];
//
//						if (y < 1 || x < 1 || y > N || x > M || map[y][x] == 1)
//							break;
//						if (visit[y][x])
//							continue;
//						visit[y][x] = true;
//						total--;
//					}
//				}
//			}
//			else // 나이트
//			{
//				int ny, nx;
//				for (int k = 0; k < 8; k++)
//				{
//					ny = units[i][j].y + kdir[k][0];
//					nx = units[i][j].x + kdir[k][1];
//
//					if (ny < 1 || nx < 1 || ny > N || nx > M || map[ny][nx] == 1)
//						continue;
//					if (visit[ny][nx])
//						continue;
//					visit[ny][nx] = true;
//					total--;
//				}
//			}
//		}
//	}
//}
