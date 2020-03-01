#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int subin;
int sister;
int parent[100001];
int curPosMintime[100001];
bool visit[100001];
stack<int> route;
int minVal = 999999999;
vector<int> time;
void bfs();
int main()
{
	cin >> subin >> sister;
	if (subin > sister) // 처음부터 수빈이 동생보다 먼 경우,
	{
		cout << subin - sister << endl;
		for (int i = subin; i >= sister; i--)
		{
			cout << i << " ";
		}
		return 0;
	}
	else if (subin == sister)
	{
		cout << 0 << endl;
		cout << subin << endl;
		return 0;
	}
	bfs();

	cout << minVal << endl;
	while (!route.empty())
	{
		cout << route.top() << " ";
		route.pop();
	}

	return 0;
}

void bfs()
{
	queue<int> que;
	bool isFind = false;
	que.push(subin);
	//visit[subin] = true;
	curPosMintime[subin] = 0;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			int cur = que.front();
			que.pop();

			if (cur == sister)
			{
				time.push_back(curPosMintime[cur]);
				//isFind = true;
			}
			else if (cur > sister)
			{
				if (curPosMintime[sister] == 0)
				{
					curPosMintime[sister] = curPosMintime[cur] + cur - sister;
					parent[sister] = sister + 1;
				}
				else if (curPosMintime[sister] > curPosMintime[cur] + cur - sister)
				{
					curPosMintime[sister] = curPosMintime[cur] + cur - sister;
					parent[sister] = sister + 1;
				}
				time.push_back(curPosMintime[cur] + cur - sister);
			}
			else
			{
				if (cur * 2 != 0 && cur * 2 <= 100000)// && !visit[cur * 2])
				{
					if (curPosMintime[cur * 2] == 0)
					{
						curPosMintime[cur * 2] = curPosMintime[cur] + 1;
						parent[cur * 2] = cur;
						que.push(cur * 2);
						//visit[cur * 2] = true;

					}
					else
					{
						if (curPosMintime[cur * 2] > curPosMintime[cur] + 1)
						{
							curPosMintime[cur * 2] = curPosMintime[cur] + 1;
							parent[cur * 2] = cur;
							que.push(cur * 2);
							//visit[cur * 2] = true;
						}
					}
				}
				if (cur + 1 <= 100000)// && !visit[cur + 1])
				{
					// 시간관리
					if (curPosMintime[cur + 1] == 0)
					{
						curPosMintime[cur + 1] = curPosMintime[cur] + 1;
						parent[cur + 1] = cur;
						que.push(cur + 1);
						//visit[cur + 1] = true;
					}
					else
					{
						if (curPosMintime[cur + 1] > curPosMintime[cur] + 1)
						{
							curPosMintime[cur + 1] = curPosMintime[cur] + 1;
							parent[cur + 1] = cur;
							que.push(cur + 1);
							//visit[cur + 1] = true;
						}
					}
				}
				if (cur - 1 >= 0)// && !visit[cur - 1])
				{
					if (curPosMintime[cur - 1] == 0)
					{
						curPosMintime[cur - 1] = curPosMintime[cur] + 1;
						parent[cur - 1] = cur;
						que.push(cur - 1);
						//visit[cur - 1] = true;

					}
					else
					{
						if (curPosMintime[cur - 1] > curPosMintime[cur] + 1)
						{
							curPosMintime[cur - 1] = curPosMintime[cur] + 1;
							parent[cur - 1] = cur;
							que.push(cur - 1);
							//visit[cur - 1] = true;

						}
					}
				}
			}

		}
		//if (isFind)
			//break;
	}
	
	minVal = curPosMintime[sister];

	route.push(sister);
	while (parent[sister] != subin)
	{
		route.push(parent[sister]);
		sister = parent[sister];
	}
	route.push(subin);

}
