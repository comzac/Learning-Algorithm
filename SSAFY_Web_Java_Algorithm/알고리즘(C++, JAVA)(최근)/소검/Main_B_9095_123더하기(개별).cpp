/*2010~2012
	
*/
#include <iostream>
#include <string>

using namespace std;

int cnt;
void dfs(int cur, int target);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int num;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> num;
		cnt = 0;
		dfs(0, num);
		cout << cnt << endl;
	}


	return 0;
}

void dfs(int cur, int target)
{
	if (cur >= target)
	{
		if (cur == target)
		{
			cnt++;
		}
		return;
	}
	dfs(cur + 1, target);
	dfs(cur + 2, target);
	dfs(cur + 3, target);
}
