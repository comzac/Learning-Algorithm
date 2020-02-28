/*2310~2315
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> a;
vector<int> b;

int main()
{
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i] * b[i];
	}

	cout << sum;
	return 0;
}
