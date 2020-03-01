///* 1655~1805
//	1. 1~1000(N,M)
//	2. 한 개의 벽을 부수거나 말거나 최단경로 구하기 
//	3. 시작점 끝점 포함
//	4. 불가능할 땐 -1 출력
//
//
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
//	bool canDestroy;
//	pos(int _y, int _x, bool destroy) :y(_y), x(_x), canDestroy(destroy) {}
//};
//
//int N, M;
//int map[1001][1001];
//int visit[1001][1001][2];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int answer;
//bool isFind;
//void input();
//void bfs(int y, int x);
//
//int main()
//{
//	input();
//	bfs(1, 1);
//	if (isFind)
//		cout << answer;
//	else
//		cout << -1;
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	string temp;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j+1] = temp[j] - '0';
//		}
//	}
//
//}
//
//void bfs(int y, int x)
//{
//	int dis = 0;
//	
//	queue<pos> que;
//	que.push(pos(y, x, true));
//	visit[y][x][0] = 1;
//	dis++;
//	while (!que.empty())
//	{
//		int size = que.size();
//		while (size-- > 0)
//		{
//			pos cur = que.front();
//			que.pop();
//			bool isAble = cur.canDestroy;
//			
//			if (cur.y == N && cur.x == M)
//			{
//				answer = dis;
//				isFind = true;
//				return;
//			}
//
//			for (int d = 0; d < 4; d++)
//			{
//				int ny = cur.y + dir[d][0];
//				int nx = cur.x + dir[d][1];
//
//				if (ny < 1 || nx < 1 || ny > N || nx > M )
//					continue;
//				
//				if (map[ny][nx] == 1 && isAble) // 벽인데 부수기가 가능상태면
//				{
//					que.push(pos(ny, nx, false));
//					visit[ny][nx][isAble] = 1;
//				}
//				else if (map[ny][nx] == 0 && !visit[ny][nx][isAble])
//				{
//					que.push(pos(ny, nx, isAble));
//					visit[ny][nx][isAble] = 1;
//				}
//			}
//		}
//		dis++;
//	}
//	
//}
