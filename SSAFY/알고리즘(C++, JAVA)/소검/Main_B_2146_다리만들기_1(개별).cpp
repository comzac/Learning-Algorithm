/* 2255~2330 = 35M
	1. 2초 192MB
	2. 섬은 세개가 아니다 두개 이상이다.
	3. 다리는 직선이 아니다 격자도 된다 -> 무조건 직선이 짧지 않을까했는데 반례가 있다.
	 ex )
	 1 1 0 0 0 0 0 1 => 다음과 같을 때, 직선이 아닌 경우는 3이란 좌상 - 하 의 다리도 있는데
	 1 1 0 0 0 0 0 1	직선만 하는 경우는 답이 5 (좌상-우상) 으로 나올것이다.
	 0 0 0 0 0 0 0 0
	 0 0 0 0 0 0 0 0
	 0 0 1 1 0 0 0 0
	
	풀이 :
	1) 구역을 1,2,... n 으로 나눈다.
	2) 구역별 시작지점 넘버를 갖고 bfs를 통해 최단 다른 넘버를 갖는 섬에 도착했을 때 값을 vector에 담는다
	3) vector의 최소값을 출력한다.
	4) 아쉬운 부분은 1-2도 계산하고 2-1도 계산할 것이다. 일단 마지막 구역은 검사를 하지 않아도 되지만
	시간초과가 난다면 이 부분을 개선하는거도 방법일듯 하다.
	시간복잡도?
	음.. 구역나누기 100*100
				+
	구역별 최소거리 찾기 최대 100
	5) DP를 활용하여 최소거리를 업데이트하는 걸 생각해봤으나, 섬이 2개 초과일 때, 애매해지며
	시작점 데이터를 가지고 역추적하며 값을 바꿔주는게 비효율적일 거 같다.

*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y;
	int x;
	pos(int Y = 0, int X = 0):y(Y), x(X) {}
};
int N;
int numbering = 1;
int map[100][100];
bool devideV[100][100]; 
bool minDisV[100][100];
vector<int> disV;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int startNum;

void input();
void devide(int y, int x); // 공간절약을 위해 numbering 변수를 전역으로 뺌
void minDis(int y, int x);
void visitInit();

int main()
{
	input();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (devideV[i][j])
				continue;
			if (map[i][j] == 1)
			{
				devide(i, j);
				numbering++;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (minDisV[i][j])
				continue;
			if (map[i][j] != 0)
			{
				startNum = map[i][j];
				minDis(i, j);
				visitInit();
			}
		}
	}
	
	cout << *min_element(disV.begin(), disV.end());


	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void devide(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	devideV[y][x] = true;
	map[y][x] = numbering;
	
	pos cur;
	int curY, curX;
	int ny, nx;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;

		for (int i = 0; i < 4; i++)
		{
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || devideV[ny][nx] || map[ny][nx] != 1)
				continue;
			que.push({ ny,nx });
			devideV[ny][nx] = true;
			map[ny][nx] = numbering;
		}
	}
}

void minDis(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	minDisV[y][x] = true;

	pos cur;
	int curY, curX;
	int ny, nx;

	int dis = 0;
	bool isFind = false;

	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;

			if (map[curY][curX] != 0 && map[curY][curX] != startNum)
			{
				disV.push_back(dis-1);
				isFind = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || minDisV[ny][nx] || map[ny][nx] == startNum)
					continue;

				que.push({ ny,nx });
				minDisV[ny][nx] = true;

			}
		}
		if (isFind)
			break;
		dis++;

	}
}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			minDisV[i][j] = false;
		}
	}
}
