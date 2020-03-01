/* 1930~2005

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct oper {
	int r;
	int c;
	int s;
};
int N, M, K;
int map[101][101]; // (1,1) 기준
int baseMap[101][101];
int r, c, s;
vector<oper> v; // 회전연산 담는용
vector<int> np; // 넥퍼용(조합)
int minVal = 999999999;

void minCheck(); // 행간의 총합과 최소값 비교
void rotate(); // 전역변수 인자값을 활용한 회전
void copyMap();
void input();
int main()
{
	input();

	do {
		copyMap();
		//연산순 회전
		rotate();
		//최소값 확인
		minCheck();
	} while (next_permutation(np.begin(), np.end()));

	cout << minVal;


	return 0;
}

void rotate()
{
	int r, c, s;
	int sy, sx, ey, ex;

	for (int i = 0; i < K; i++)
	{
		r = v[np[i]].r;
		c = v[np[i]].c;
		s = v[np[i]].s;

		sy = r - s;
		sx = c - s;
		ey = r + s;
		ex = c + s;

		while ((ey - sy != 0) && (ex - sx != 0)) // 최소 2*2를 만족하는 형태에서만 회전
		{
			int startPos = map[sy][sx]; // 하나 빼놓고
			for (int y = sy + 1; y <= ey; y++) // 왼쪽처리
			{
				map[y - 1][sx] = map[y][sx];
			}

			for (int x = sx + 1; x <= ex; x++) // 아래처리
			{
				map[ey][x - 1] = map[ey][x];
			}

			for (int y = ey - 1; y >= sy; y--) // 오른쪽처리
			{
				map[y + 1][ex] = map[y][ex];
			}

			for (int x = ex - 1; x > sx; x--) // 오른쪽처리
			{
				map[sy][x + 1] = map[sy][x];
			}

			map[sy][sx + 1] = startPos;

			sx++;
			sy++;
			ex--;
			ey--;
		}
	}
}

void copyMap()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = baseMap[i][j];
		}
	}
}

void minCheck()
{
	int row;

	for (int i = 1; i <= N; i++)
	{
		row = 0;
		for (int j = 1; j <= M; j++)
		{
			row += map[i][j];
		}
		if (minVal > row)
			minVal = row;
	}
	
}


void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> baseMap[i][j];
		}
	}


	int r, c, s;
	for (int k = 0; k < K; k++)
	{
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

	for (int i = 0; i < K; i++)
	{
		np.push_back(i);
	}
}
