/* 0125~0145
	1. 2초 128MB
	2. ‘F’는 앞으로 한 칸 움직인 것이고,
	‘L'과 ’R'은 방향을 왼쪽 또는 오른쪽으로 전환한 것이다.
	즉, 90도를 회전하면서, 위치는 그대로인 것이다.

	풀이 :
	시작점을 알 수 없으니 넉넉한 맵의 중앙에 놓고 시작을 한다.
	이후 이동경로는 방문처리를 해주고,
	방문처리 된 영역중 최소최대 y,x값을 파악해준다.
	이후, 영역내에서 false면 # true면 . 을 출력해준다.

	최대 내용이 50보다 작으니 약 101?이면 되겠지만,
	낭낭하게~ 120정도 준다.


*/
#include <iostream>
#include <string>

using namespace std;
struct pos {
	int y;
	int x;
};

int map[120][120];
bool visit[120][120];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
string cmd;
int N;
void dfs(int y, int x, int d, int cmdNum);
int main()
{
	cin >> N;
	cin >> cmd;

	dfs(60, 60, 2, 0);

	int minY, minX, maxY, maxX;
	maxY = maxX = 0;
	minY = minX = 500;

	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (visit[i][j])
			{
				if (minY > i)
					minY = i;

				if (minX > j)
					minX = j;

				if (maxY < i)
					maxY = i;

				if (maxX < j)
					maxX = j;
			}
		}
	}

	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (visit[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << endl;
	}

	return 0;
}

void dfs(int y, int x, int d, int cmdNum)
{
	visit[y][x] = true;
	if (cmdNum == N)
	{
		return;
	}
	switch (cmd[cmdNum])
	{
	case 'L':
		dfs(y, x, (d + 3) % 4, cmdNum + 1);
		break;
	case 'R':
		dfs(y, x, (d + 1) % 4, cmdNum + 1);
		break;
	case 'F':
		int ny, nx;
		ny = y + dir[d][0];
		nx = x + dir[d][1];
		dfs(ny, nx, (d), cmdNum + 1);
		break;
	}
}
