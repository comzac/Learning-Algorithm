#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<double, int> timetable;

vector<string> split(string str, char div) {

	int before = 0;

	vector<string> v;
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == div) {
			string temp = str.substr(before, i - before);
			v.push_back(temp);
			before = i+1;
		}
	}
	string temp = str.substr(before);
	v.push_back(temp);

	return v;
}

double dup(double time) {

	if (timetable.find(time) == timetable.end())
		return time;
	else
		return dup(time - 0.0000001);
}

int count(vector<int> v)
{
	int cnt = 0;
	for (auto a : v)
	{
		if (a == 1)
			cnt++;
	}
	return cnt;
}
int solution(vector<string> lines) {
	int answer = 0;


	for (int i = 0; i < lines.size(); i++) {
		vector<string> splitStr = split(lines[i], ' ');
		vector<string> end = split(splitStr[1], ':');
		
		double endTime = stod(end[0]) * 60 * 60 + stod(end[1]) * 60 + stod(end[2]);
		double during = stod(splitStr[2].substr(0, splitStr[2].length() - 1));
		double startTime = (endTime - during + 0.001f) + (-1 + 0.001f) - 0.0001f;

		timetable[dup(startTime)] = i;
		timetable[dup(endTime)] = i;
	}

	map<double, int> ::iterator it;
	it = timetable.begin();

	vector<int> traffic(lines.size(), 0);

	int max = 0;
	for (; it != timetable.end(); it++) {

		if (traffic[it->second] == 0)
			traffic[it->second] = 1;
		else
			traffic[it->second] = 0;

		int cnt = count(traffic);
		if (max < cnt)
			max = cnt;
	}

	answer = max;

	return answer;
}


int main()
{
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s" };

	cout << solution(lines) << endl;

	return 0;
}