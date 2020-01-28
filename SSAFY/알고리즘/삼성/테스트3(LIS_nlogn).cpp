#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int arr[1001] = { 0, };
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		v.clear();
		v.push_back(-1);

		for (int j = 0; j < N; j++)
		{
			if (v.back() <= arr[j])
				v.push_back(arr[j]);
			else
			{
				vector<int>::iterator it = lower_bound(v.begin(), v.end(), arr[j]);
				while (*it == arr[j])
					it++;
				*it = arr[j];
			}
		}
		cout << "#" << i + 1 << " " << v.size()-1 << endl;
	}
	return 0;
}
