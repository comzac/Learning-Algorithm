#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string a)
{
	vector<string> result;

	int before = 0;
	string head;
	string num = "";
	string tail = "";

	bool checkHead = false;
	int i;
	for (i = 0; i < a.length(); i++)
	{
		if (!checkHead && isdigit(a[i]))
		{
			head = a.substr(before, i - before);
			before = i;
			checkHead = true;
		}
		else if (checkHead && !isdigit(a[i]))
		{
			num = a.substr(before, i - before);
			before = i;
			checkHead = false;
			break;
		}
	}
	if (checkHead)
		num = a.substr(before);
	else
		tail = a.substr(before);

	transform(head.begin(), head.end(), head.begin(), ::toupper);

	result.push_back(head);
	result.push_back(num);
	if(tail != "")
		result.push_back(tail);

	return result;
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
	vector<string> A = split(a.second);
	vector<string> B = split(b.second);

	if (A[0] == B[0])
	{
		if (stoi(A[1]) == stoi(B[1]))
		{
			return a.first < b.first;
		}
		return stoi(A[1]) < stoi(B[1]);
	}

	return A[0] < B[0];

}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<pair<int, string>> v;

	for (int i = 0; i < files.size(); i++)
	{
		v.push_back(make_pair(i, files[i]));
	}

	sort(v.begin(), v.end(), cmp);

	for (auto a : v)
	{
		answer.push_back(a.second);
	}

	return answer;
}
int main()
{
	//vector<string> files = { "F - 5 Freedom Fighter", "B - 50 Superfortress", "A - 10 Thunderbolt II", "F - 14 Tomcat" };
	vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> result = solution(files);

	for (auto a : result)
	{
		cout << a << endl;
	}

	return 0;

}