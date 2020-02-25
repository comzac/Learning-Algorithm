/* 1615~1715 + 2120~2230 = 1H + 1H 10M
	1. 2초, 256MB
	2. 다솜이가 7명을 꾸려야 하는데 항상 다솜파 > 도연파가 만족해야한다.
	3. 모든 경우의 수를 구해라 인데

	풀이 :
	bfs와 dfs를 모두 거쳐 최종적으로 내린 풀이방식
	dfs로 할 경우 소위 ㅗ 모양의 종류를 하나하나 지정해줘야하는데 테트로미노는 이외의 모형이
	4개여서 가능했다. 하지만 이거는.. 12+8+4 = 총 24개를 지정해줘야하는데 코딩의 의미가 있나모르겠다.
	bfs로 할 경우, 양옆으로 퍼진 경우를 한곳에 저장하자니 다른 시점에서 출발해도 같은 모형이 나올때가 있어서 난감했다.

	따라서, 25개 한정이니 조합을 뽑자
	
	이때, np를 사용하게 되면 백트래킹이 안된다. 일부가능하지만 
	dfs보다 효율이 떨어진다.
	예를 들어, np의 경우에도 인접체크를 하기전 다솜네랑 도연네수를 세어 인접 연산을 빽트래킹할 수 있다.
	하지만 애초에 1234xxx라는 숫자가 들어올 때, 1234에서 도연네 수가 4면 다음부터는 1234xxx는 다 안하면 되는데
	np는 그게 불가능하다. 그래서 dfs를 통해 안되는 경우가 있을 때 그 뒤에 올 것들도 싹다 날려버리는데 있어서
	연산량이 확줄어 25C7임에도 불구하고 가능하다.

	그렇기때문에 dfs로 구역마다 체크를 하며 도연이팀이 3개가 넘어가면 빽해주고
	문제없을때마다 visit을 체크해준다. 
	합이 7에 도달했을때 visit인 애들은 bfs를 통해 인접했는지 확인해주고
	값을 올려준다.


*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct pos {
	int y;
	int x;
	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
};

char map[5][5];
int visit[5][5];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer;
void input();
void dfs(int n, int numS, int numY);
bool adjoin();
bool bfs(int y, int x);
int main()
{
	input();

	dfs(0, 0, 0);

	cout << answer;

	return 0;
}

void input()
{
	string temp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = temp[j];
		}
	}
}

void dfs(int n, int numS, int numY)
{
	if (numY > 3)
		return;
	if (numY + numS > 7)
		return;
	else if (numY + numS == 7)
	{
		if (adjoin())
		{
			answer++;
		}
		return;
	}

	int y;
	int x;

	for (int i = n; i < 25; i++) // 0이 아닌 n은 중복을 막으려는 방법
	{
		y = i / 5;
		x = i % 5;
		if (visit[y][x])
			continue;
		visit[y][x] = true;
		if (map[y][x] == 'S')
			dfs(i, numS + 1, numY);
		else
			dfs(i, numS, numY + 1);
		visit[y][x] = false;
	}
}

bool adjoin()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (visit[i][j])
			{
				return bfs(i, j);
			}
		}
	}

	return false;
}

bool bfs(int y, int x)
{
	bool team[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			team[i][j] = false;
		}
	}

	queue<pos> que;
	que.push({ y,x });
	team[y][x] = true;
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
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || team[ny][nx] || !visit[ny][nx])
				continue;
			que.push({ ny,nx });
			team[ny][nx] = true;
		}
	}

	if (cnt == 7)
		return true;
	else
		return false;
}

