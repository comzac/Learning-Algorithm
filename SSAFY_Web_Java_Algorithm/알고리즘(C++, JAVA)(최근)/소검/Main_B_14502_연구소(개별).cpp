/*
	1. 주어진 맵에서 벽을 세개 세워 (최대일 필요가 없는게 빈공간이 최소 3개가 있다고 한다.)
	  바이러스확산에 안전한 구역의 최대값을 구하는 문제

	풀이방식
	1. 재귀 안에 for문을 활용하여 방문처리를 키고 꺼주며 3개의 벽을 세울때마다
	-> 바이러스 확산을 시키고 -> 안전지역 (0)인 장소를 센다.
	끝
*/

#include <iostream>
#include <string>
using namespace std;

int Y, X;
int map[8][8]; // 좌표접근이 따로 없으므로 9로 지정하지 않아도 헷갈리지 않는다.
bool visit[8][8]; //바이러스나 벽위에 벽을 세울 수 없으니 필요없을 거 같다.
int tempmap[8][8]; // 확산체크를 할 때 맵을 복원시키기 힘드므로 복사한다.
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 바이러스 사방확산용
int maxVal;

#define MAX(A, B)(A > B ? A : B)

void visitReset()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			visit[i][j] = false;
		}
	}

}
void virus(int y, int x)
{
	visit[y][x] = true;
	tempmap[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= Y || nx >= X || visit[ny][nx])
			continue;
		if (map[ny][nx] == 1)
			continue;
		virus(ny, nx);
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt == 3)
	{
		int sum = 0;
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				tempmap[i][j] = map[i][j];
			}
		}

		// 확산
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if (!visit[i][j] && map[i][j] == 2){
					virus(i, j);
				}
			}
		}
		// 안전 구역 확인
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if (tempmap[i][j] == 0)
					sum++;
			}
		}

		maxVal = MAX(maxVal, sum);
		visitReset();
		return;
	}


	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (map[i][j] != 0)
				continue;
			map[i][j] = 1;
			dfs(i, j, cnt+1);
			map[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> map[y][x];
		}
	}

	dfs(0, 0, 0);
	
	cout << maxVal;

	return 0;
}
