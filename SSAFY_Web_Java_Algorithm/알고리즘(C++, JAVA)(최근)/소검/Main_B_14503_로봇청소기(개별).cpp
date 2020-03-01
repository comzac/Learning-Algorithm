#include <iostream>
#include <string>
using namespace std;
/*
시작시간 18:30

1. 청소하는 영역의 개수
2. r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수
3. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
  a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
  b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
  c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
  d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

  0 북, 1 동, 2 남, 3 서
  빈칸 0, 벽 1

*/
/* 풀이과정 // 벽과 청소한 곳을 같게 봐도 될듯, 따라서 맵을 굳이 구성할 필요 없을듯?
1. 맵 형성
2. 시작위치를 기점으로 방향 기준 왼쪽 (이 부분 구현) 탐색
 2-false) 그 방향으로 회전 -> 한칸 전진 -> 2번 // 이때 방향전환 및 청소 처리
 2-true) 벽이거나 청소를 이미 했으면 회전회전회전~ => 이때 카운트
3. 돌고돌았는데 다 청소했거나 벽이면 현 바라보는 방향기준 후진 한칸
4. 후진조차 못하면 끝
*/

int map[50][50];
bool v[50][50];   //북   //서  // 남  //동
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int cnt;
int ver, hor; // 수직, 수평 

void clean(int y, int x, int d)
{
	int _d = d%4; // 방향
	int rotate = 0; // 회전횟수
	if (v[y][x] == 0) 
	{
		cnt++;
		v[y][x] = 1;
	}

	int ny, nx;

	while(true)
	{
		if (rotate == 4)
		{
			ny = y + dir[(_d + 2) % 4][0];
			nx = x + dir[(_d + 2) % 4][1];
			if (map[ny][nx] == 1)
				break;
			clean(ny, nx, _d);
			break;
		}

		_d++;
		ny = y + dir[(_d) % 4][0];
		nx = x + dir[(_d) % 4][1];

		if (map[ny][nx] == 1 || v[ny][nx]) // 벽확인 && 청소 확인
		{
			rotate++;
			continue;
		}

		// 영역 문제는 없고, 청소도 안했는데 벽도 아니다
		clean(ny, nx, _d);
		break;
	}

}

int main()
{
	
	cin >> ver >> hor;
	int sy, sx, d;
	cin >> sy >> sx >> d;
	switch (d)
	{
	case 0:
		d = 0;
		break;
	case 1:
		d = 3;
		break;
	case 2:
		d = 2;
		break;
	case 3:
		d = 1;
		break;
	}

	// 맵 형성 (1은 벽이지만 청소해도 1로 바꿔줄 예정)
	// => 했는데 청소한 바닥은가도 벽은 못가니 안됨 
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < hor; j++)
		{
			cin >> map[i][j];
		}
	}

	clean(sy, sx, d);

	cout << cnt;
	return 0;
}
