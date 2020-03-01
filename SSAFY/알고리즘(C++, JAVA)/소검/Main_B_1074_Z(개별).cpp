#include <iostream>
#include <string>

using namespace std;

int N;
int limit;
int r, c;
int answer;
int cnt;

void dfs(int y, int x, int len);
int main()
{
	cin >> N >> r >> c;

	limit = 1;
	int n = N;
	while (n-- > 0)
	{
		limit *= 2;
	}

	dfs(0, 0, limit);
	cout << answer;

	return 0;
}

void dfs(int y, int x, int len)
{
	if (len == 2)
	{
		if (y == r && x == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		if (y == r && x + 1 == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		if (y + 1 == r && x == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		if (y + 1 == r && x + 1 == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
		return;
	}

	dfs(y, x, len / 2);
	dfs(y, x + len / 2, len / 2);
	dfs(y + len / 2, x, len / 2);
	dfs(y + len / 2, x + len / 2, len / 2);

}
