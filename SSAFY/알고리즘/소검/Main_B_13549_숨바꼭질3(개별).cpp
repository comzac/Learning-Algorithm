/* 2140~2235 

*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int subin;
int sister;
int visit[100001];
int curtime[100001];
int bfs();

int main()
{
	cin >> subin >> sister;

	if (subin > sister)
	{
		cout << subin - sister;
		return 0;
	}

	int t = bfs();

	cout << t;

	return 0;
}

int bfs()
{
	vector<int> candidate; // ½Ã°£
	bool isFind = false;
	queue<int> que;
	que.push(subin);
	
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			int cur = que.front();
			que.pop();
			visit[cur] = true;
			
			if (cur == sister)
			{
				candidate.push_back(curtime[cur]);
				isFind = true;
			}
			else if(cur > sister)
			{
				candidate.push_back(curtime[cur] + cur - sister);
			}
			else
			{
				if (cur * 2 != 0 && cur * 2 <= 100000 && !visit[cur * 2] )
				{
					que.push(cur * 2);
					if (curtime[cur * 2] == 0)
						curtime[cur * 2] = curtime[cur] + 0;
					else
					{
						curtime[cur * 2] = curtime[cur] < curtime[cur * 2] ? curtime[cur] : curtime[cur * 2];
					}
				}

				if (cur + 1 <= 100000 && !visit[cur + 1])
				{
					que.push(cur + 1);
					if (curtime[cur + 1] == 0)
						curtime[cur + 1] = curtime[cur] + 1;
					else
					{
						curtime[cur + 1] = (curtime[cur]+1) < curtime[cur + 1] ? curtime[cur] + 1 : curtime[cur + 1];
					}
				}

				if (cur - 1 >= 0 && !visit[cur - 1])
				{
					que.push(cur - 1);
					if (curtime[cur - 1] == 0)
						curtime[cur - 1] = curtime[cur] + 1;
					else
					{
						curtime[cur - 1] = (curtime[cur]+1) < curtime[cur - 1] ? (curtime[cur] + 1) : curtime[cur - 1];
					}
				}
			}
		}

		if (isFind)
			break;
	}

	int minVal = *min_element(candidate.begin(), candidate.end());
	return minVal;
}