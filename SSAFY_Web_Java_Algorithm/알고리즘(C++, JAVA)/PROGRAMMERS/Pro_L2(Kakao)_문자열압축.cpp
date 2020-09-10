#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b)
{
	return a.length() < b.length();
}
int solution(string s) {
	int answer = 0;
	if (s.length() == 1)
		return 1;
	int len = s.length();
	int half = len / 2;
	vector<string> strV;
	int before;
	for (int i = 1; i <= half; i++)
	{
		string temp = "";
		before = 0;
		int cnt = 1;
		for (int j = 0; j < len; j += i)
		{
			string str1 = s.substr(before, i);
			string str2 = "";
			if(before+i < len)
				str2 = s.substr(before + i, i);
			if (str1 == str2)
			{
				cnt++;
			}
			else
			{
				if (cnt != 1)
					temp += to_string(cnt) + str1;
				else
					temp += str1;
				cnt = 1;
			}
			before = before + i;
		}
		strV.push_back(temp);
	}
	sort(strV.begin(), strV.end(), cmp);
	answer = strV[0].length();

	return answer;
}
int main()
{
	string s = "a";

	cout << solution(s);

	return 0;
}