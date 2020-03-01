#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int y;
	int x;
	int speed;
	int dir;
	int size;
	bool isActive;
};


int Y, X, M;
vector<int> spotNum[101][101];
Shark shark[10002];
int total;

bool compare(int a, int b)
{
	if (shark[a].size > shark[b].size)
		return true;
	return false;
}

//함수
void input();
void deleteShark(int time);
void moveShark();
void posChange(int idx);
void fight();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	int time = 0;

	while (++time <= X) // X를 지나치면 끝 ( 낚시왕 이동 )
	{
		deleteShark(time); // 초마다 해당 샤크 죽이기 ( 낚시 )
		moveShark();
		fight();
	}
	cout << total;

	return 0;
}

void input()
{
	cin >> Y >> X >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> shark[i].y;
		cin >> shark[i].x;
		cin >> shark[i].speed;
		cin >> shark[i].dir;
		cin >> shark[i].size;
		shark[i].isActive = true;
		spotNum[shark[i].y][shark[i].x].push_back(i);
	}
}

void deleteShark(int time)
{
	int near = 102; // 나올 수 없는 밑
	int idx = 0;
	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive) // 죽은애들은 스킵
			continue;
		if (shark[i].x == time)
		{
			if (near > shark[i].y)
			{
				near = shark[i].y;
				idx = i;
			}
		}
	}
	if (near != 102) // 못찾았으면 안죽이기
	{
		shark[idx].isActive = false; // 죽이기
		total += shark[idx].size;
		spotNum[shark[idx].y][shark[idx].x].clear();
	}
}

void moveShark()
{
	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive)
			continue;
		spotNum[shark[i].y][shark[i].x].clear();
	}

	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive)
			continue;
		posChange(i);
	}
}

void posChange(int idx)
{
	int sy = shark[idx].y;
	int sx = shark[idx].x;
	int dir = shark[idx].dir;
	int speed = shark[idx].speed;
	int diff;
	int repeat; // 방향 회전
	int rest; // 남은 수준
	int ny, nx; // 이동 후 위치
	ny = sy;
	nx = sx;
	switch (dir)
	{
	case 1: // 위
		diff = speed - (sy - 1); // 땅까지 가고 남는 스피드 (이동거리를 구하는 것)
		if (diff <= 0) // 땅까지도 가기 부족하면
			ny = sy - speed; // 스피드까지만 가도 방향변화에 문제없음
		else // 남는다면
		{
			repeat = diff / (Y - 1);
			rest = diff % (Y - 1);
			if (repeat % 2 == 0)
			{
				ny = 1 + rest;
				shark[idx].dir = 2;
			}
			else
			{
				ny = Y - rest;
			}
		}
		break;

	case 2: // 아래
		diff = speed - (Y - sy); // 해저까지 가고 남는 스피드 (이동거리를 구하는 것)
		if (diff <= 0) // 해저까지도 가기 부족하면
			ny = sy + speed; // 스피드까지만 가도 방향변화에 문제없음
		else // 남는다면
		{
			repeat = diff / (Y - 1);
			rest = diff % (Y - 1);
			if (repeat % 2 == 0)
			{
				ny = Y - rest;
				shark[idx].dir = 1;
			}
			else
			{
				ny = 1 + rest;
			}
		}
		break;

	case 3: // 오른쪽
		diff = speed - (X - sx); // 우측까지 가고 남는 스피드 (이동거리를 구하는 것)
		if (diff <= 0) // 해저까지도 가기 부족하면
			nx = sx + speed; // 스피드까지만 가도 방향변화에 문제없음
		else // 남는다면
		{
			repeat = diff / (X - 1);
			rest = diff % (X - 1);
			if (repeat % 2 == 0)
			{
				nx = X - rest;
				shark[idx].dir = 4;
			}
			else
			{
				nx = 1 + rest;
			}
		}
		break;

	case 4: // 왼쪽
		diff = speed - (sx - 1); // 우측까지 가고 남는 스피드 (이동거리를 구하는 것)
		if (diff <= 0) // 해저까지도 가기 부족하면
			nx = sx - speed; // 스피드까지만 가도 방향변화에 문제없음
		else // 남는다면
		{
			repeat = diff / (X - 1);
			rest = diff % (X - 1);
			if (repeat % 2 == 0)
			{
				nx = 1 + rest;
				shark[idx].dir = 3;
			}
			else
			{
				nx = X - rest;
			}
		}
		break;
	}

	// 위치가 정해졌으니 이동 정보수정해주고 카운트를 해준다.
	spotNum[ny][nx].push_back(idx);
	shark[idx].y = ny;
	shark[idx].x = nx;
}

void fight()
{
	int max;
	int idx;
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			idx = 10001;
			max = 0;
			if (spotNum[i][j].size() > 1)
			{
				sort(spotNum[i][j].begin(), spotNum[i][j].end(), compare);
				int live = spotNum[i][j][0];
				for (int k = 1; k < spotNum[i][j].size(); k++)
				{
					shark[spotNum[i][j][k]].isActive = false;
				}
				spotNum[i][j].clear();
				spotNum[i][j].push_back(live);
			}
		}
	}
}
