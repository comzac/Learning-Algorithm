/* 1310~1420
	1. 2초 128MB
	2. 회전 조건 : 중심점 기준 팔방 1이 있으면 안됨
	3. 최소 횟수로 BBB가 EEE에 도달하게 하기

	풀이 : bfs로 해보자
	방문처리는 [][][가로/세로] 이런식으로 넣고
	입력함수,
	bfs함수
	회전함수
	정도 만들면 될듯하다. 
	중심점을 기점으로 이동한다.
	따라서, 회전에서는 가로세로일때가 크게 상관없지만 이동일 땐, 제한 조건을 달리 줘야한다.

*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct center {
	int y;
	int x;
	int d; // 0 수평, 1 수직
	center() {}
	center(int Y, int X, int D):y(Y),x(X),d(D){}
};
int N;
int answer;
center tree;
center dest;
char map[51][51];
bool v[51][51][2]; // 0 수평, 1 수직
int dir1[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // 직선
int dir2[4][2] = { {1,1},{-1,-1},{1,-1},{-1,1} }; // 대각선

void input();
void bfs(center treePos);
bool rotatable(center cur);
int main()
{
	input();
	bfs(tree);
	cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string temp;
	int bCnt = 0;
	int by, bx, ey, ex;
	int eCnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == 'B')
			{
				bCnt++;
				if (bCnt == 1)
				{
					by = i;
					bx = j;
				}
				else if (bCnt == 2)
				{
					if (by == i)
					{
						tree.y = i;
						tree.x = j;
						tree.d = 0;
					}
					else if (bx == j)
					{
						tree.y = i;
						tree.x = j;
						tree.d = 1;
					}
				}
			}
			else if (temp[j] == 'E')
			{
				eCnt++;
				if (eCnt == 1)
				{
					ey = i;
					ex = j;
				}
				else if (eCnt == 2)
				{
					if (ey == i)
					{
						dest.y = i;
						dest.x = j;
						dest.d = 0;
					}
					else if (ex == j)
					{
						dest.y = i;
						dest.x = j;
						dest.d = 1;
					}
				}
			}
		}
	}
}

void bfs(center treePos)
{
	center cur;
	int curY, curX, curD;
	int nx, ny;
	int cnt = 0;
	bool isFind = false;
	//
	queue<center> que;
	que.push(treePos);
	v[treePos.y][treePos.x][treePos.d] = true;

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

			if (curY == dest.y && curX == dest.x && curD == dest.d)
			{
				answer = cnt;
				isFind = true;
			}

			if (rotatable(cur)) // 회전이 가능하다면
			{
				que.push({ curY, curX, !curD }); // 회전시킨 값 푸시(이것도 1회로 처리)
				v[curY][curX][!curD] = true;
			}

			for (int i = 0; i < 4; i++)//이동
			{
				ny = curY + dir1[i][0];
				nx = curX + dir1[i][1];

				if (curD == 0) // 수평일 때,
				{
					if (ny < 0 || ny >= N ||				// 중심
						nx - 1 < 0 || nx + 1 >= N ||		// 양옆
						map[ny][nx] == '1' || map[ny][nx - 1] == '1' || map[ny][nx + 1] == '1' || // 전부 충돌
						v[ny][nx][curD])
					{
						continue;
					}
				}
				else // 수직일 때,
				{
					if (nx < 0 || nx >= N ||				// 중심
						ny - 1 < 0 || ny + 1 >= N ||		// 양옆
						map[ny][nx] == '1' || map[ny - 1][nx] == '1' || map[ny + 1][nx] == '1' || // 전부 충돌
						v[ny][nx][curD])
					{
						continue;
					}
				}

				que.push({ ny, nx, curD });
				v[ny][nx][curD] = true;
			}
		}
		if (isFind)
			break;
		cnt++;
	}
	if (!isFind)
		answer = 0;

}

bool rotatable(center cur)
{
	bool isRotatable = true;
	int ny, nx;
	int curY, curX;
	curY = cur.y;
	curX = cur.x;

	if (v[curY][curX][!cur.d]) // 이미 해본적 있는 액션
		return false;


	for (int i = 0; i < 4; i++)
	{
		ny = curY + dir1[i][0];
		nx = curX + dir1[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
		{
			return false;
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		ny = curY + dir2[i][0];
		nx = curX + dir2[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
		{
			return false;
		}
	}

	return isRotatable;
}
