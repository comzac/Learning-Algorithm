///* 2250~2350 + 0100~0150 = 1H 50M
//	1. 우, 하 방향으로만 순회하며 0,0 에서 N-1,M-1에 도착하는 경로에 있는
//	알파벳들을 합쳐 이름을 정하는데,
//	사전순으로 빠른 애를 출력하는 거다.
//	2. 만약 범위가 작았다면 모든 경우를 담아서 정렬시켰으면 되겠지만
//	범위가 최대 2000이다. 
//	3. 방향이 두 경우 밖에 없으니, 더 작은 알파벳을 갖는 방향으로 이동을 하는 식으로 짠다면,
//	예제 1) 같은 경우, 시작점 a에 인접한 두 알파벳이 동일하다.
//	bfs를 활용하는데, 연속된 string값을 오름차순 정렬하는 최소힙을
//	사용한다.
//	그리고 앞에서 부터 동일한 값을 갖는 경우만 남기고 진행하는 방식으로 해보면 어떨까 싶다.
//	또한, 같은 위치 string에 같은 위치를 갖는 경우도 제외시킨다.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct name {
//	int y;
//	int x;
//};
//
//int N, M;
//char map[2000][2000];
//bool visit[2000][2000];
//int dir[2][2] = { {0,1},{1,0} };
//string answer;
//
//void input();
//string bfs();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		answer = "";
//		string str(1, map[0][0]);
//		answer += str;
//		bfs();
//		cout <<"#"<< t <<" "<< answer << endl;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				visit[i][j] = false;
//			}
//		}
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N >> M;
//
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//string bfs()
//{
//	queue<name> que;
//	que.push({ 0,0 });
//	visit[0][0] = true;
//	int curY, curX;
//	int ny, nx;
//	char nextChar;
//	while (!que.empty())
//	{
//		int size = que.size();
//		queue<name> que2;
//		char minWord = '}';
//		while (size-- > 0)
//		{
//			name cur = que.front();
//			que.pop();
//			curY = cur.y;
//			curX = cur.x;
//
//			if (curY == N - 1 && curX == M - 1)
//				return answer;
//
//			for (int i = 0; i < 2; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//				if (ny >= N || nx >= M || visit[ny][nx])
//					continue;
//				nextChar = map[ny][nx];
//				if (minWord > nextChar)
//				{
//					while (!que2.empty())
//						que2.pop();
//					que2.push({ ny,nx });
//					minWord = nextChar;
//				}
//				else if (minWord == nextChar)
//				{
//					que2.push({ ny,nx });
//				}
//				visit[ny][nx] = true;
//			}
//		}
//		answer += minWord;
//		que = que2;
//	}
//
//	return answer;
//}
