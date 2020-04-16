/* 2250~
	1. 2초 256MB
	2. 구역별 더 큰 값을 갖는 구역으로 이동을 하는데,
	최대 이동 횟수(일 수)를 구하는 문제다.
	1) 무조건 최대한 차이가 적은 쪽으로의 이동이 답일까?
	-> 이건 아니다. 반례가 생긴다.
	
	2) 그럼 가능한 방향을 다 살펴볼까?
	-> 가능하지만 시간복잡도를 고려해보자
	-> 모든 구역 탐색, 최대값 500*500
	-> 각 구역에서 탐색 최소 1, 최대 500*500
	-> 500*500 + 500*499 + 500*498 + ... + 500*1 => 500 * ( (500*501) / 2 ) 약 n^3
	-> 125000000 애매하다 아마 메모리에서부터 터질거다
	
	3) DP 같다. 보통 이럴 땐, DP다
	그런데, 시작점에 따라 DP를 설정할 것인가?
	그렇게 한다면 시작점마다 맵을 순회해야할 거고 500*500 탐색을 계속 해야한다.
	뭔가 한큐에 끝낼 방법
	=> 결국 전 구역을 순회하되, dp값을 비교하여 백트래킹해주는 방식으로 가보자
	=> 이로 인해, 연산량을 줄일 수 있고, 최종적으로 맵의 dp값을 확인하여 최대값이 답
*/
#include <iostream>
#include <string>
#include <queue> // bfs에 필요
#include <algorithm>

using namespace std;

int N;//맵 크기
int map[500][500]; // 0~ 시작
bool visit[500][500];
int dp[500][500];
int sy, sx;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void input();
void search();
int dfs(int y, int x, int dep);
int maxSearch();

int main()
{
	input();
	search();
	cout << maxSearch();

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

void search()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] > 0)
				continue;
			dp[i][j] = dfs(i, j, 1);
		}
	}
}

int dfs(int y, int x, int dep)
{
	bool isFind = false;
	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dir[i][0];
		nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] <= map[y][x])
			continue;
		isFind = true;
		if (dp[ny][nx] == 0)
		{
			int nextDep = dfs(ny, nx, dep);
			if(dp[y][x] < dep + nextDep)
				dp[y][x] = dep + dfs(ny, nx, dep);
		}
		else
		{
			if(dp[y][x] < dep + dp[ny][nx])
				dp[y][x] = dep + dp[ny][nx];
		}
	}

	if (isFind)
		return dp[y][x];
	else
		return dp[y][x] = dep;
}

int maxSearch()
{
	int maxVal = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] > maxVal)
				maxVal = dp[i][j];
		}
	}

	return maxVal;
}


