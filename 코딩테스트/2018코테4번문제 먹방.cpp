
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	vector<pair<int, int>> vp;
	int time, temp;
	time = k;
	int size = food_times.size();

	vector<bool> check(size, false);

	for (int i = 0; i < food_times.size(); i++)
	{
		vp.push_back(make_pair(food_times[i], i));
	}

	sort(vp.begin(), vp.end());

	for (int i = 0; i < vp.size(); i++)
	{
		if (i == 0)
			temp = vp[i].first * size - i;
		else
			temp = (vp[i].first - vp[i - 1].first) * (size - i);


		if (time - temp < 0)
			break;

		time -= temp;
		check[vp[i].second] = true;
	}

	vector<int> v;
	for (int i = 0; i < check.size(); i++)
	{
		if (!check[i])
			v.push_back(i+1);
	}

	if (time == 0)
	{
		if (v.empty())
			answer = -1;
		else
			answer = v[0];
	}
	else
	{
		answer = v[(time)%v.size()];
	}

	return answer;
}

int main()
{
	vector<int> v = { 3,1,2};
	cout << solution(v, 5) << endl;

	/*
		3124 4
		2013 3
		1002 2
		0001 

		=> 3
	*/
	// 1 , 2 , 3 val
	// 1 , 2 , 0 idx
	// 1*3 + (2-1)*2 

}