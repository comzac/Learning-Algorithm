/* 0010~0050
	1. 2초 128MB
	2. 비트 연산을 통한 벽유무 파악
	3. 범위 밖도 벽으로 취급
	-> 벽검사 -> 범위 검사 (부술 때)
	풀이 :
	1. 이 성에 있는 방의 개수
	 : visit처리하면서 전구역 돌면서 bfs 돌아간 횟수 조사
	2. 가장 넒은 방의 넓이
	 : 1 과정에서 종료마다 카운트 vector에 저장 max_element 조사
	3. 벽부수고 이동하기 같은 개념 visit[n][m][2] (부숨/아직) 으로 카운팅 최대값 조사
	=> 이 부분이 잘못됐다. 부수고 말고를 검사하며 이동하는 경우는 최종 목적지까지의 최소걸이 일때는
	bfs를 종료하면서 가능하지만 이 문제는 룸의 크기를 찾아야하기때문에 이 벽 부셨을 때랑 저 벽 부셨을 때랑
	기재조건을 정할 수 없어서 크기의 최대값을 찾을 수 없었다.
	따라서, 조합비스무리하게 벽을 허물고 세워주고를 반복해주며 2번에서 사용한 함수를 재활용했다.
	또한, 2번은 한번의 과정으로 서로 겹치는 방이없이 진행되기 때문에 visit배열을 초기화 할 필요없지만
	이 문제에서는 이 벽과 저 벽을 허물었을 때, 겹치는 방이 존재할 것이므로 visit을 매 검사마다 초기화해줬다.

	2,3 을 동시에 할 수 있는가?
	: 떠오르질 않는다.

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
	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
};
vector<int> roomSize;
vector<int> destroyRoomSize;

int bitMask[4] = { 1,2,4,8 }; // 서, 북, 동, 남
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
bool visitRoomCheck[50][50];
int map[50][50];
int M, N;

void input();
int roomCheck(int y, int x);
void destroyBfs();
void visitInit();
int main()
{
	input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visitRoomCheck[i][j])
				continue;
			roomSize.push_back(roomCheck(i, j));
		}
	}
	destroyBfs();
	cout << roomSize.size() << endl;
	cout << *max_element(roomSize.begin(), roomSize.end()) << endl;
	cout << *max_element(destroyRoomSize.begin(), destroyRoomSize.end()) << endl;
	
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int roomCheck(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	visitRoomCheck[y][x] = true;

	pos cur;
	int curY, curX;
	int ny, nx;
	int cnt = 0;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			if (bitMask[i] & map[curY][curX])
				continue;
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visitRoomCheck[ny][nx])
				continue;
			que.push({ ny,nx });
			visitRoomCheck[ny][nx] = true;
		}
	}
	return cnt;
}

void destroyBfs()
{
	int ny, nx;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++)
			{
				if (bitMask[k] & map[i][j])
				{
					ny = i + dir[k][0];
					nx = j + dir[k][1];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M)
						continue;
					visitInit();
					map[i][j] -= bitMask[k];
					destroyRoomSize.push_back(roomCheck(i, j));
					map[i][j] += bitMask[k];
				}
			}
		}
	}
}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visitRoomCheck[i][j] = false;
		}
	}
}
