/* 2235~2300
	1. 1초 128MB
	2.
	비어있는 곳은 '.'로 표시되어 있고,
	물이 차있는 지역은 '*', 
	돌은 'X'로 표시되어 있다.
	비버의 굴은 'D'로, 
	고슴도치의 위치는 'S'로 나타내어져 있다.
	3. 탈출 못하면 KAKTUS
	4. 굴로 탈출할수있는 가장 빠른 시간 출력


*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;
int R, C;
char map[50][50];
queue<pair<int, int>> water;
queue<pair<int, int>> gosm;
pair<int, int> Dpos;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
string answer;

void input();
void bfs(int y, int x);
int main()
{
	input();
	int y = gosm.front().first;
	int x = gosm.front().second;
	bfs(y, x);
	cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;

	string temp;
	for (int i = 0; i < R; i++)
	{
		cin >> temp;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == '*')
				water.push({ i,j });
			else if (temp[j] == 'S')
				gosm.push({ i,j });
			else if (temp[j] == 'D')
				Dpos = { i,j };
		}
	}
}

void bfs(int y, int x)
{
	pair<int, int> curWater;
	int waterNy, waterNx;
	pair<int, int> curGosm;
	int gosmNy, gosmNx;
	int time = 0;
	bool isFind = false;
	while (!gosm.empty())
	{
		int waterSize = water.size();
		while (waterSize-- > 0)
		{
			curWater = water.front();
			water.pop();
			for (int d = 0; d < 4; d++)
			{
				waterNy = curWater.first + dir[d][0];
				waterNx = curWater.second + dir[d][1];

				if (waterNy < 0 || waterNx < 0 || waterNy >= R || waterNx >= C || map[waterNy][waterNx] == 'D' || map[waterNy][waterNx] == 'X' || map[waterNy][waterNx] == '*')
					continue; // 범위를 벗어나거나 빈칸이 아니면 컨티뉴

				map[waterNy][waterNx] = '*';
				water.push({ waterNy, waterNx });
			}
		}

		int gosmSize = gosm.size();
		while (gosmSize-- > 0)
		{
			curGosm = gosm.front();
			gosm.pop();
			if (curGosm == Dpos)
			{
				isFind = true;
				break;
			}
			for (int d = 0; d < 4; d++)
			{
				gosmNy = curGosm.first + dir[d][0];
				gosmNx = curGosm.second + dir[d][1];

				if (gosmNy < 0 || gosmNx < 0 || gosmNy >= R || gosmNx >= C || map[gosmNy][gosmNx] == '*' || map[gosmNy][gosmNx] == 'X' || map[gosmNy][gosmNx] == 'S')
					continue; // 범위를 벗어나거나 빈칸이 아니면 컨티뉴

				map[gosmNy][gosmNx] = 'S';
				gosm.push({ gosmNy, gosmNx });
			}
		}
		if (isFind)
			break;
		time++;
	}

	if (isFind)
		answer = to_string(time);
	else
		answer = "KAKTUS";

}
