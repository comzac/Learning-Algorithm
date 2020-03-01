#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/*
	1. 4<= N <= 20
	2. 전력차가 최소가 되는 경우의 최솟값을 출력해라
	3. 


*/
int n;
vector<int> v;
int power[20][20];
vector<int> team0;
vector<int> team1;

void com(vector<int> v)
{
	vector<int> temp0;
	vector<int> temp1;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i])
			temp1.push_back(i);
		else
			temp0.push_back(i);
	}

	team0 = temp0;
	team1 = temp1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			v.push_back(0);
		else
			v.push_back(1);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> power[i][j];

	int min = 100 * 20 * 20;

	do {
		com(v);
		int sum0 = 0;
		int sum1 = 0;

		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				sum0 += power[team0[i]][team0[j]];
				sum1 += power[team1[i]][team1[j]];
			}
		}

		if (abs(sum1 - sum0) < min)
			min = abs(sum1 - sum0);
	} while (next_permutation(v.begin(), v.end()));

	cout << min;

	return 0;
}
