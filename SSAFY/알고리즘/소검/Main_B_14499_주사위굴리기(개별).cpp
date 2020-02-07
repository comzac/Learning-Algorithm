/*
	1. 0으로 초기화 되어있는 주사위를 굴리며 바닥이 0일땐 바닥에 숫자를 복사, 
	숫자일땐, 주사위에 복사되고 바닥면은 0으로 바뀜
	2. 범위를 벗어날땐 명령을 무시하고 출력도 하면 안됨
	3. 굴릴때마다 주사위 윗면에 써있는 숫자를 출력

	풀이방식
	U, D, L, R, F, B 을 지정하고,
	회전 방향에 따라 서로 스왑해준다.

*/
#include <iostream>
#include <string>
using namespace std;
int N, M;
int map[20][20];
int square[7]; // 주사위
int y, x;
bool isAble;

//enum dir {
//	U = 1,
//	F = 5,
//	D = 6,
//	B = 2,
//	R = 3,
//	L = 4
//};

void copy()
{
	if (map[y][x] == 0)
	{
		map[y][x] = square[6];
	}
	else
	{
		square[6] = map[y][x];
		map[y][x] = 0;
	}
}

void rotate(int num)
{
	switch (num)
	{
		int temp;
	case 1: //동
		if (x + 1 >= M)
		{
			isAble = false;
			break;
		}
		x += 1;
		
		temp = square[1];
		square[1] = square[4];
		square[4] = square[6];
		square[6] = square[3];
		square[3] = temp;
		break;
	case 2: //서
		if (x - 1 < 0)
		{
			isAble = false;
			break;
		}
		x -= 1;
		temp = square[1];
		square[1] = square[3];
		square[3] = square[6];
		square[6] = square[4];
		square[4] = temp;
		break;

	case 3: //북
		if (y - 1 < 0)
		{
			isAble = false;
			break;
		}
		y -= 1;
		temp = square[1];
		square[1] = square[5];
		square[5] = square[6];
		square[6] = square[2];
		square[2] = temp;
		
		break;
	case 4: //남
		if (y + 1 >= N)
		{
			isAble = false;
			break;
		}
		y += 1;
		temp = square[1];
		square[1] = square[2];
		square[2] = square[6];
		square[6] = square[5];
		square[5] = temp;
		break;
	}
	if(isAble)
		copy();
}


int main()
{

	int linesNum;
	cin >> N >> M >> y >> x >> linesNum;

	for (int i = 0; i < N; i++) // 맵 초기화
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= linesNum; i++)
	{
		int temp;
		cin >> temp;

		isAble = true;
		rotate(temp);
		if (!isAble)
			continue;

		if(i == linesNum)
			cout << square[1];
		else
			cout << square[1] << endl;
	}


	return 0;
}

