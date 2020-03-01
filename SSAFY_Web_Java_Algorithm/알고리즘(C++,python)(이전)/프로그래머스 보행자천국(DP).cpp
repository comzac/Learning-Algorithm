#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MOD = 20170805;
int rig[501][501];
int down[501][501];

int solution(int m, int n, vector<vector<int>> city_map) {

	int answer = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			rig[i][j] = 0;
			down[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int type = city_map[i-1][j-1];
			if (i == 1 && j == 1)
			{
				rig[i][j] = 1;
				down[i][j] = 1;
			}
			else
			{
				if (type == 0)
				{
					rig[i][j] = (rig[i][j - 1] + down[i - 1][j]) % MOD;
					down[i][j] = (rig[i][j - 1] + down[i - 1][j]) % MOD;
				}
				else if (type == 1)
				{
					rig[i][j] = 0;
					down[i][j] = 0;
				}
				else
				{
					rig[i][j] = rig[i][j - 1];
					down[i][j] = down[i - 1][j];
				}
			}
		}
	}



	return rig[m][n];
}

int main()
{
	int m, n;
	m = 3;
	n = 6;
	vector<vector<int>> v = { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} };
	cout << solution(m, n, v) << endl;



	return 0;
}
