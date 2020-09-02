#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool cmp(string s1, string s2) {
	if (s1[0] == s2[0])
		return s1[1] < s2[1];
	return s1[0] < s2[0];
}
int solution(string str1, string str2) {
	int answer = 0;
	
	vector<string> s1, s2;

	// str1 분해
	for (int i = 1; i < str1.length(); i++) {
		if (isalpha(str1[i]) && isalpha(str1[i - 1])) {
			string str = str1.substr(i - 1, 2);
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			s1.push_back(str);
		}
	}
	// str2 분해
	for (int i = 1; i < str2.length(); i++) {
		if (isalpha(str2[i]) && isalpha(str2[i - 1])) {
			string str = str2.substr(i - 1, 2);
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			s2.push_back(str);
		}
	}

	if (s1.size() == 0 && s2.size() == 0)
		return 1 * 65536;
	sort(s1.begin(), s1.end(), cmp);
	sort(s2.begin(), s2.end(), cmp);


	vector<string> inter(s1.size() + s2.size());
	auto iter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inter.begin());
	inter.erase(iter, inter.end());

	vector<string> unionSet(s1.size() + s2.size());
	iter = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), unionSet.begin());
	unionSet.erase(iter, unionSet.end());

	float result = inter.size() / (double)unionSet.size();
	result *= 65536;
	answer = (int)result;

	return answer;
}
int main()
{
	string str1 = "FRANCE";
	string str2 = "french";
	cout << solution(str1, str2);
	string test = "aa1+aa2";

	return 0;
}