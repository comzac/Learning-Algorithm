///* 1520~1605
//	단서
//	1. 도로가 파여진 깊이에 비례해서 복구 시간은 증가한다
//	2. 출발지에서 도착지까지 가는 경로 중에 복구 시간이 가장 짧은 경로에 대한 총 복구 시간을 구하시오.
//	3. 깊이가 1이라면 복구에 드는 시간이 1이라고 가정한다.
//
//	풀이
//	1. bfs를 활용한 dp로 풀어보자
//	2. dfs를 활용한 백트래킹도 방법이다. => 돌려보니 시간초과가 난다.
//	 => 아마 처음에 최소값에 가까운 값이 나오면 가지치기가 많이 되겠지만,
//	 최악의 경우 전체 탐색을 하게 된다.
//
//	그럼 일단 쉬운 dfs부터 해보자,
//	그럼 dp로 다시 가자
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0):y(Y),x(X){}
//};
//
//int map[100][100];
//int dp[100][100];
//int N;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//void input();
//void bfsDP(int y, int x);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		bfsDP(0, 0);
//		cout << "#" << t << " " << dp[N-1][N-1] << endl;
//	}
//}
//
//void input()
//{
//	cin >> N;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = temp[j]-'0';
//			dp[i][j] = -1;
//		}
//	}
//}
//
//void bfsDP(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	dp[y][x] = map[y][x];
//	
//	int curY, curX;
//	int ny, nx;
//	while (!que.empty())
//	{
//		curY = que.front().y;
//		curX = que.front().x;
//		que.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
//				continue;
//
//			if (dp[ny][nx] != -1) // 방문한 적이 있다면,
//			{
//				if (dp[ny][nx] > dp[curY][curX] + map[ny][nx])
//				{
//					dp[ny][nx] = dp[curY][curX] + map[ny][nx];
//					que.push({ ny,nx });
//				}
//			}
//			else
//			{
//				dp[ny][nx] = dp[curY][curX] + map[ny][nx];
//				que.push({ ny,nx });
//			}
//		}
//
//	}
//}
//
