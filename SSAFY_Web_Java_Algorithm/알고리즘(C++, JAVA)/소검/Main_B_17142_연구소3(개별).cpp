/* 1630~1800 + 1900~1950
	1. 바이러스 중 지정한 개수만큼만 골라서 확산했을 시, 가득 바이러스가 차는 경우의 최소시간을 구해라
	2. 그런데 문제의 속도제한이 0.25이다.
	3. 당장떠오르는 방법은 각각 바이러스들 중 3개씩 고르는 경우,
	bfs를 통해 매 초마다 확산 후, 방상태를 점검하는 방식을 진행하여 시간을 파악하는것이다.
	이후, 더이상 확산이 안되는 상황에서 방 체크 시, 전부 퍼지지 않았으면 -1를 출력한다.
	방체크는 가장 처음부터 진행한다.
	비활성 바이러스도 바이러스로 봄
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y;
	int x;
	pos(int i, int j) :y(i), x(j) {}
};

int map[50][50];
int temp[50][50];
//int visit[50][50];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N, M;
int virusNum;
vector<pos> virusPos;
vector<int> posCombi;
queue<pos> que;
bool visit[101][101];
void input();
int spoil();
void copy();
bool check();
int minVal = 9999999;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int minute;
	input();

	do {
		copy(); // 확산 상태 진행해볼 별도의 맵 생성
		while (!que.empty())
			que.pop();
		for (int i = 0; i < virusNum; i++)
			if (posCombi[i] == 1)
			{
				int vy, vx;
				vy = virusPos[i].y;
				vx = virusPos[i].x;
				que.push({ vy, vx }); // 바이러스 M개를 누굴 선택했는지 
				temp[vy][vx] = 3;
			}
		// 확산 (각 초마다 체크)
		
		minute = spoil();

		// bool 값이 true면 최소값 비교 , false면 스킵
		if (minute == -1)
			continue;
		else
		{
			if (minute == 0)
			{
				minVal = 0;
				break;
			}
			else if (minVal > minute)
				minVal = minute;
		}

	} while (next_permutation(posCombi.begin(), posCombi.end()));

	// 한번도 최소값에 변동이 없었다면, 전부 안된 경우니깐 -1출력
	if (minVal == 9999999)
		cout << -1;
	else
		cout << minVal;

	return 0;
}

void input()
{
	cin >> N >> M;
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (temp == 2)
			{
				virusPos.push_back(pos(i, j));
				virusNum++;
			}
		}
	}
	posCombi = vector<int>(virusPos.size() - M, 0);
	for (int i = 0; i < M; i++)
		posCombi.push_back(1);
}

int spoil()
{
	bool isFull = false;
	int time = 0;
	int ny, nx;
	while (!que.empty())
	{
		if(check())
		{
			isFull = true;
			break;
		}
		time++;

		int size = que.size();
		while (size-- > 0)
		{
			pos vpos = que.front();
			que.pop();
			for (int d = 0; d < 4; d++)
			{
				ny = vpos.y + dir[d][0];
				nx = vpos.x + dir[d][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || temp[ny][nx] == 1 || temp[ny][nx] == 3 )
					continue;
				que.push(pos(ny, nx));
				temp[ny][nx] = 3;
			}
		}
	}

	if (isFull)
		return time;
	return -1;
}

void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

bool check()
{
	bool isFull = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] == 0)
			{
				isFull = false;
				break;
			}
		}
		if (!isFull)
			break;
	}

	return isFull;
}
