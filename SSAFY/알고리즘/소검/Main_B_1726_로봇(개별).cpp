	1. 2초 128MB
	2. 직진과 회전 +1, +3 으로 방향전환하는 문제
	3. M, N <= 100 // 시작점 1,1
	방향 정보 : 방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4로 주어진다.

	풀이 : bfs를 쓰면 어떨까
	이동은 무적권 3->2->1> 순으로
	방향은 이동가능한 방향으로 회전하는 경우를 다 따져보는걸로
	방향은 내멋대로 정하고 수정해준다.
	방향을 유지한 경우는 이동 + 1
	회전 이동일 경우, 이동 + 2
	방문처리는 음.. 해주고 진행방향의 역방향은 제외하자
	방문처리를 안해주면 3 + 1 이동과 2 + 2 가 두번 연산하게 된다
	또한 역방향 처리를 안해주면 + 3 -> -3 -> +3 을 반복할 수 있다.

	=> 역시 첫 계획은 항상 틀리는군 허헛


*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y;
	int x;
	int d;
	pos(int _y = 0, int _x = 0, int _d = 0) :y(_y), x(_x), d(_d) {}
};

int M, N;
int map[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 동 남 서 북 
bool r[101][101][4]; // 제자리 회전 체크
pos robot;
pos dest;
int minVal = 999999999;
void input();
int changeDir(int d);
void bfs(int y, int x, int d);
int main()
{
	input();
	bfs(robot.y, robot.x, robot.d);
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	int y, x, d;
	cin >> y >> x >> d;
	robot.y = y;
	robot.x = x;
	robot.d = changeDir(d);

	cin >> y >> x >> d;
	dest.y = y;
	dest.x = x;
	dest.d = changeDir(d);
}

int changeDir(int d)
{
	int dir = 0;
	switch (d)
	{
	case 1:
		dir = 0;
		break;
	case 2:
		dir = 2;
		break;
	case 3:
		dir = 1;
		break;
	case 4:
		dir = 3;
		break;
	}
	return dir;
}

void bfs(int y, int x, int d)
{
	queue<pos> que;
	que.push({ y,x,d });
	bool isFind = false;
	int curCnt;
	pos cur;
	int curY, curX, curD;
	int ny, nx;
	int cnt = 0;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;
			curD = cur.d;

			r[curY][curX][curD] = true;
			if (curY == dest.y && curX == dest.x && curD == dest.d)
			{
				cout << cnt;
				isFind = true;
				break;
			}
			
			for (int j = 1; j <= 3; j++) // 거리에 벽있는지, 범위 초과인지 확인
			{
				ny = curY + dir[curD][0]*j; // 현재방향으로 진행
				nx = curX + dir[curD][1]*j;

				if (r[ny][nx][curD])
					continue;
				if (ny < 1 || nx < 1 || ny > M || nx > N || map[ny][nx] == 1 ) // 범위 초과, 벽 
				{
					break;
				}
				else
				{
					que.push({ ny,nx,curD });
					r[ny][nx][curD] = true;
				}
			}

			if (!r[curY][curX][(curD + 1) % 4]) // 시계방향
			{
				que.push({ curY, curX, (curD + 1) % 4 });
				r[curY][curX][(curD + 1) % 4] = true;
			}
			if (!r[curY][curX][(curD + 3) % 4]) //반시계방향
			{
				que.push({ curY, curX, (curD + 3) % 4 });
				r[curY][curX][(curD + 3) % 4] = true;
			}
		}
		if (isFind)
			break;
		cnt++;
	}

}



