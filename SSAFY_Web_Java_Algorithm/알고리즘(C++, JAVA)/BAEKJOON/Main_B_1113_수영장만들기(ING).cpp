/*1510~
	1. 2초 128MB
	2. 1<= N,M <= 50 => 1일땐 0
	3. 높이는 1<= <=9
	4. 좌우상하로 가장 높은 애를 찾는다 (전값보다 낮아지는 지점이 발견되면 브레이크)
	5. 현 지점 기준 좌우상하 중 최소값과 현재값의 차를 구한다.
	6. DP를 사용하지 않고 계산한다 가정했을 때,
	최악의 경우, 50*50 일 때,
	가장자리가 2이고 내부가 1일 때,
	50*50[순회]*(50+50)[좌우상하 순회]

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct pos {
	int y;
	int x;
	pos(int Y = 0,int X = 0):y(Y),x(X){}
};

int N, M;
int map[50][50];
int dp[50][50][4]; // 사방의 현재 최대값(높이)를 보유 //값이 0 일때, 순회 // 0이 아닐 때,적용
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // 상, 하, 좌, 우
int parent[50][50][2];
int visit[50][50];
int hole[50][50];
// 50*50*8 = 400*50 = 20000*4byte = 80000byte면 괜찮을 듯 하다.
int total;
vector<int> mVec;

void input();
int heightCheck(int y, int x);
void holeCheck(int y, int x);
void visitInit();
int main()
{
	input();

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (hole[i][j])
				continue;
			holeCheck(i, j);
		}
	}


	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (hole[i][j])
				continue;
			total += heightCheck(i, j);
		}
	}

	cout << total;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				parent[i][j][k] = -1;
			}
		}
	}
}

int heightCheck(int y, int x)
{
	int depth = 0;
	int d[4];
	int curY, curX, curH;
	int idxY, idxX;
	curH = map[y][x];
	int maxH;

	for (int i = 0; i < 4; i++)
	{
		curY = idxY = y;
		curX = idxX = x;
maxH = curH;
if (dp[y][x][i] != -1)
{
	d[i] = dp[y][x][i];
}
else
{
	do {
		if (map[curY][curX] >= maxH) // 동일하더라도 끝점을 찾고, 동일한 높이 연산시, 음수는 0처리해주자
		{
			maxH = map[curY][curX];
			idxY = curY;
			idxX = curX;
		}
		curY += dir[i][0];
		curX += dir[i][1];
	} while (curY >= 0 && curX >= 0 && curY < N && curX < M);

	if (idxY == y && idxX == x) // 사방중 하나라도 나보다 높은게 없다면,
		return 0;

	switch (i)
	{
	case 0: // 상
		for (int Y = y; Y > idxY; Y--)
		{
			dp[Y][x][i] = maxH;
		}
		break;
	case 1: // 하
		for (int Y = y; Y < idxY; Y++)
		{
			dp[Y][x][i] = maxH;
		}
		break; // 좌
	case 2:
		for (int X = x; X > idxX; X--)
		{
			dp[y][X][i] = maxH;
		}
		break;
	case 3:
		for (int X = x; X < idxX; X++)
		{
			dp[y][X][i] = maxH;
		}
		break;
	}

	d[i] = dp[y][x][i];
}
	}

	mVec.clear();

	for (int i = 0; i < 4; i++)
	{
		mVec.push_back(d[i]);
	}

	depth = *min_element(mVec.begin(), mVec.end()) - curH;

	if (depth < 0)
		return 0;
	else
		return depth;
}

void holeCheck(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	visit[y][x] = true;
	int curY, curX, ny, nx;
	int curH;
	bool hasHole = false;
	while (!que.empty())
	{
		pos cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;
		curH = map[curY][curX];

		for (int i = 0; i < 4; i++)
		{
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (map[curY][curX] < map[ny][nx]) // 높이차
				continue;

			if (ny <= 0 || nx <= 0 || ny >= N - 1 || nx >= M - 1)
			{
				parent[ny][nx][0] = curY;
				parent[ny][nx][1] = curX;
				hasHole = true;
				break;
			}
			else if (hole[ny][nx])
			{
				hasHole = true;
				ny = y;
				nx = x;
				break;
			}
			if (visit[ny][nx])
				continue;



			que.push({ ny,nx });
			parent[ny][nx][0] = curY;
			parent[ny][nx][1] = curX;
			visit[ny][nx] = true;
		}
		if (hasHole)
			break;
	}

	if (hasHole)
	{
		hole[ny][nx] = true;
		int py, px;
		py = parent[ny][nx][0];
		px = parent[ny][nx][1];
		while (!(py == -1 && px == -1))
		{
			hole[py][px] = true;
			ny = py;
			nx = px;
			py = parent[ny][nx][0];
			px = parent[ny][nx][1];
		}
	}

	visitInit();

}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
		}
	}
}

/*
1630~
반례 만들어보기
5 7
6666666
6616166
6111116
6616166
6666166

구멍체크를 해야하는데
bfs를 돌리면서 부모 노드를 남기고 구멍이 있을 시,
부모들에게 전부 구멍이 있는 지점을 표시해준다.

구멍지점이 아닌 애들은 bfs를 적용하게 되는데 
이때, 구멍지점을 만나는 애들도 전부 구멍이 있는걸로 처리한다.
그럼 
6666666
6616166
6211116
6616166
6666166
이런 경우, (2,1)의 2의 경우에도 (1,2)의 bfs에서 해당되지 않았지만 본인이 bfs를 수행하면서
(2,2)를 만나 hole이 있음을 알 수 있다.

이후, hole이 없는 지점만 깊이 체크를 하면
5 7
6666666
6616166
6211516
6611166
6666166
이와 같은 경우 (1,4)와 (2,5)에서 물이 채워진다.

끝난줄알았지만 새로운 반례 발견 ~1715
5 5
16666
63636
66146
13236
66666

out = 14
ans = 6

*/