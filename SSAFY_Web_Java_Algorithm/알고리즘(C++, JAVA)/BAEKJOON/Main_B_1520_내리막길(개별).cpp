#include <iostream>
#include <string>

using namespace std;

int M, N;
int map[501][501];
int route[501][501];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int dfs(int y, int x)
{
	if (route[y][x] != -1)
		return route[y][x];
	if (x < 0 || x >= M || y < 0 || y >= N)
		return 0;
	if (x == 0 && y == 0)
		return 1;


	int ny, nx;
	route[y][x] = 0; //# 놓침 (접근한 경우 0처리를 해줘야 하는데 -1로 두니깐 계속 변화가없었음)

	for (int k = 0; k < 4; k++) {
		ny = y + dir[k][0];
		nx = x + dir[k][1];
		if (map[ny][nx] > map[y][x])
		{
			route[y][x] += dfs(ny, nx);
		}
	}

	return route[y][x];

}
int main()
{
	cin >> N >> M;

	int temp;

	for (int i = 0; i <  N; i++)
	{
		for (int j = 0; j <  M; j++)
		{
			cin >> temp;
			map[i][j] = temp;
		}
	}
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			route[i][j] = -1;
		}
	}
	cout << dfs(N-1, M-1);

	return 0;
}
