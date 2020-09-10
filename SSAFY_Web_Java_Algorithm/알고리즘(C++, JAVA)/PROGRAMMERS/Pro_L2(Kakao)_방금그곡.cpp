#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
vector<string> split(string a, char d)
{
	int before = 0;
	vector<string> result;
	
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == d)
		{
			string str = a.substr(before, i - before);
			result.push_back(str);
			before = i+1;
		}
	}
	result.push_back(a.substr(before));

	return result;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	string M = "";
	for (int i = 0; i < m.length() - 1; i++)
	{
		if (m[i + 1] == '#')
			transform(m.begin() + i, m.begin() + i + 1, m.begin() + i, ::tolower);
		if(m[i] != '#')
			M += m[i];
	}

	if (m[m.length() - 1] != '#')
		M += m[m.length() - 1];

	vector<pair<int, int>> result;
	vector<string> titleV;

	for (int i = 0; i < musicinfos.size(); i++)
	{
		vector<string> info = split(musicinfos[i], ',');
		string start = info[0];
		string end = info[1];
		string title = info[2];
		string scale = info[3];
		titleV.push_back(title);
		string parse_scale = "";
		for (int i = 0; i < scale.length() - 1; i++)
		{
			if (scale[i + 1] == '#')
				transform(scale.begin() + i, scale.begin() + i + 1, scale.begin() + i, ::tolower);
			if (scale[i] != '#')
				parse_scale += scale[i];
		}

		if (scale[scale.length() - 1] != '#')
			parse_scale += scale[scale.length() - 1];

		vector<string> startV = split(start, ':');
		vector<string> endV = split(end, ':');

		int time_diff = (stoi(endV[0]) * 60 + stoi(endV[1])) - (stoi(startV[0]) * 60 + stoi(startV[1]));

		string music = "";
		int len = parse_scale.length();
		for (int i = 0; i < time_diff; i++)
		{
			music += parse_scale[i%len];
		}

		if (music.find(M) != string::npos)
		{
			result.push_back(make_pair(time_diff, i));
		}
	}

	if (result.size() == 0)
		return "(None)";
	sort(result.begin(), result.end(), cmp);
	answer = titleV[result[0].second];

	return answer;
}
int main()
{
	string m = "CC#BCC#BCC#BCC#B";
	vector<string> v = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };

	cout << solution(m, v);

	return 0;
}