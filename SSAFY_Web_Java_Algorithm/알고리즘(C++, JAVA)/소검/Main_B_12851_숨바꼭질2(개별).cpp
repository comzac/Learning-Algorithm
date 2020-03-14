/* 2015~2030

*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int subin;
int sister;
int cnt;
int time;
bool v[100001];
void bfs();

int main()
{
	cin >> subin >> sister;

	if (subin > sister)
	{
		cout << subin - sister << endl;
		cout << 1;
		return 0;
	}
	bfs();

	cout << time << endl;
	cout << cnt;

	return 0;
}

void bfs()
{
	vector<int> t;
	queue<int> que;
	que.push(subin);
	bool isFind = false;
	while (!que.empty())
	{
		int size = que.size();
		
		while (size-- > 0)
		{
			int cur = que.front();
			v[cur] = true;
			que.pop();
			if (cur == sister)
			{
				isFind = true;
				t.push_back(time);
			}
			
			if (cur > sister)
			{
				t.push_back(time + cur - sister);
			}
			else
			{
				if (cur * 2 != 0 && cur*2 <= 100000 && !v[cur*2])
					que.push(cur * 2);
				if (cur + 1 <= 100000 && !v[cur+1])
					que.push(cur + 1);
				if (cur - 1 >= 0 && !v[cur-1])
					que.push(cur - 1);
			}

		}
		if (isFind)
			break;
		time++;
	}

	int minVal = *min_element(t.begin(), t.end());

	for (int i = 0; i < t.size(); i++)
	{
		if (minVal == t[i])
			cnt++;
	}
	time = minVal;
}
