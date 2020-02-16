/* 2050~2130

*/
#include <iostream>
#include <string>

using namespace std;

int N;
int cost[10][10];
int visit[10];
int start;
int minVal = 1000000*12;

void input();
void dfs(int idx, int sum, int cnt);

int main()
{
	input();
	
	for (int i = 0; i < N; i++)
	{
		visit[i] = true;
		start = i;
		dfs(i, 0, 1);
		visit[i] = false;
	}

	cout << minVal;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}
}

void dfs(int idx, int sum, int cnt)
{
	if (cnt == N)
	{
		if (cost[idx][start] == 0)
			return;
		if (sum + cost[idx][start] < minVal)
			minVal = sum + cost[idx][start];
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] || cost[idx][i] == 0)
			continue;
		visit[i] = true;
		dfs(i, sum + cost[idx][i], cnt + 1);
		visit[i] = false;
	}
	
}
