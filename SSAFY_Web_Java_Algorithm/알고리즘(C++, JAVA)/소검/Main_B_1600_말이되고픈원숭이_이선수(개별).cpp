/*1730~1750
	1. 2초 256MB
	2. 참고로 말은 장애물을 뛰어넘을 수 있다.
	3. 원숭이는 능력이 부족해서 총 K번만 위와 같이 움직일 수 있고,
	그 외에는 그냥 인접한 칸으로만 움직일 수 있다.
	대각선 방향은 인접한 칸에 포함되지 않는다.
	4. 격자판의 맨 왼쪽 위에서 시작해서 맨 오른쪽 아래까지 가야한다.
	5. 인접한 네 방향으로 한 번 움직이는 것, 말의 움직임으로 한 번 움직이는 것,
	모두 한 번의 동작으로 친다.
	6. 출력 : 원숭이가 최소한의 동작으로 시작지점에서 도착지점까지 갈 수 있는 방법
	최소횟수를 출력해라

	풀이 :
	벽부수기처럼  말뛰기 했을 시, 안했을 시로 구분해서 bfs로 접근하면 될 듯하다.

*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pos{
	int y;
	int x;
	int cnt;
};

int K, N, M;

int visit[200][200][31];
int map[200][200];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int horseDir[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1} };

void input();
int bfs(int y, int x);

int main()
{
	input();
	int answer = bfs(0, 0);
	cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int bfs(int y, int x)
{
	queue<pos> que;
	que.push({ y,x,0 });
	visit[y][x][0] = true;
	int curY, curX, ny, nx;
	int curCnt;
	int move = 0;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			pos cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;
			curCnt = cur.cnt;
			if (curY == N - 1 && curX == M - 1)
			{
				return move;
			}
			if (curCnt < K)
			{
				for (int i = 0; i < 8; i++)
				{
					ny = curY + horseDir[i][0];
					nx = curX + horseDir[i][1];

					if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 1 || visit[ny][nx][curCnt+1])
						continue;
					que.push({ ny, nx, curCnt + 1 });
					visit[ny][nx][curCnt+1] = true;
				}
			}
			
			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 1 || visit[ny][nx][curCnt])
					continue;
				que.push({ ny, nx, curCnt});
				visit[ny][nx][curCnt] = true;
			}
		}
		move++;
	}

	return -1;
}
