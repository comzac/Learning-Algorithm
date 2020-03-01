/* 1633~1652 + 1700~
	1. rc 장난 안침
	2. 공청은 항상 0번째 열에 설치
	3. 크기는 두 행 차지
	4. 설치 안된 곳에 미먼있음
	5. 공청이 있거나 범위밖이면 확산 ㄴ
	6. 확산양 n/5  (확산이 동시인게 포인트)
	7. 확산되고 남은 양 n-(n/5)*(확산방향 개수)

	1. 공기청정기 작동 시, 바람 나오고 위쪽은 반시계방향 순환
		아래쪽은 시계방향 순환
	2. 바람이 불면 바람 방향대로 모두 한칸씩 이동한다.
	3.

	6  30   7   // 순회하면 망 // 확산량 따로 남아있는량 따로 조사
	*  10   0
	*   0  20

*/
#include <iostream>
#include <string>
using namespace std;

int R, C, T;
int rest[50][50];
int spoil[50][50];
int airPos[2][2]; // 0 : up, 1: down
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
// up의 바로 위는 사라지고 그 위는 현 위치로 위->오른쪽->아래->왼쪽(시작점)
int airDirUp[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int airDirDown[4][2] = { {1,0}, {0,1},{-1,0},{0,-1} };
bool isUp;
bool isDown;
void input()
{
	int temp;
	int cnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> temp;
			rest[i][j] = temp;
			if (temp == -1)
			{
				airPos[cnt][0] = i;
				airPos[cnt][1] = j;
				cnt++;
			}
		}
	}
}

void SP() // 확산
{
	int ny, nx;
	int spoil_mimun;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (rest[i][j] == -1 || rest[i][j] == 0) // 공기청정기일 경우 이 작업을 진행하지 않는다.
				continue;
			spoil_mimun = rest[i][j] / 5;
			for (int k = 0; k < 4; k++)
			{
				ny = i + dir[k][0];
				nx = j + dir[k][1];
				if (rest[ny][nx] == -1 || ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				spoil[ny][nx] += spoil_mimun;
				rest[i][j] -= spoil_mimun; // 음수를 걱정했는데 최대 4방향이고 /5를 하기때문에 그럴일 없을듯
			}
		}
	}
}
void curRest()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (spoil[i][j] == 0)
				continue;
			rest[i][j] += spoil[i][j];
			spoil[i][j] = 0;
		}
	}
}
void up(int y, int x, int d)
{
	int ny = y + airDirUp[d][0];
	int nx = x + airDirUp[d][1];

	if (ny == airPos[0][0] && nx == airPos[0][1])
	{
		rest[y][x] = 0;
		isUp = true;
		return;
	}
	if (ny < 0 || nx < 0 || (ny > airPos[0][0] && d !=3) || nx >= C)
	{
		int newY = y + airDirUp[d + 1][0];
		int newX = x + airDirUp[d + 1][1];
		rest[y][x] = rest[newY][newX]; // 받아오고
		up(newY, newX, (d + 1) % 4);
		if (isUp)
			return;
	}
	else
	{
		rest[y][x] = rest[ny][nx]; // 받아오고
		up(ny, nx, d % 4);
		if (isUp)
			return;
	}
}
void down(int y, int x, int d)
{
	int ny = y + airDirDown[d][0];
	int nx = x + airDirDown[d][1];

	if (ny == airPos[1][0] && nx == airPos[1][1])
	{
		rest[y][x] = 0;
		isDown = true;
		return;
	}
	if (ny >= R || nx < 0 || (ny < airPos[1][0] && d != 3) || nx >= C)
	{
		int newY = y + airDirDown[d + 1][0];
		int newX = x + airDirDown[d + 1][1];
		rest[y][x] = rest[newY][newX]; // 받아오고
		down(newY, newX, d + 1);
		if (isDown)
			return;
	}
	else
	{
		rest[y][x] = rest[ny][nx]; // 받아오고
		down(ny, nx, d);
		if (isDown)
			return;
	}
}
void air()
{
	//up
	/*
		up의 바로 위는 사라지고 그 위는 현 위치로 위->오른쪽->아래->왼쪽(시작점)
	*/
	rest[airPos[0][0] - 1][airPos[0][1]] = 0; // 흡수됨
	isUp = false;
	up(airPos[0][0] - 1, airPos[0][1], 0); // 청정기 위 부터 시작, 위로 가는 방향으로

	//down
	/*
		down의 바로 아래는 사라지고 그 아래는 현 위치로 아래->오른쪽->위->왼쪽(시작점)
	*/
	rest[airPos[1][0] + 1][airPos[1][1]] = 0; // 흡수됨
	isDown = false;
	down(airPos[1][0] + 1, airPos[1][1], 0);// 청정기 아래 부터 시작, 아래로 가는 방향으로

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	input();
	while (T-- > 0)
	{
		SP();
		curRest();
		air();
	}

	int Sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Sum += rest[i][j];
		}
	}
	cout << Sum+2;

	return 0;
}
