//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool cmp(vector<int> a, vector<int> b)
//{
//	return a.size() < b.size();
//}
//vector<int> solution(string s) {
//	vector<int> answer;
//	int len = s.length();
//
//	vector<vector<int>> temp;
//	vector<int> t;
//	int num = 0;
//	bool isFlag = false;
//	for (int i = 0; i < len; i++)
//	{
//		if (i == 0 || i == len - 1)
//			continue;
//		
//		if (isFlag == false)
//		{
//			if (s[i] == '{')
//			{
//				isFlag = true;
//			}
//		}
//		else
//		{
//			if (isdigit(s[i]))
//			{
//				num *= 10;
//				num += s[i] - '0';
//			}
//			else if (s[i] == ',')
//			{
//				t.push_back(num);
//				num = 0;
//			}
//			else if (s[i] == '}')
//			{
//				t.push_back(num);
//				num = 0;
//				temp.push_back(t);
//				t.clear();
//				isFlag = false;
//			}
//		}
//
//
//	}
//	sort(temp.begin(), temp.end(), cmp);
//
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		for (int j = 0; j < temp[i].size(); j++)
//		{
//			if (find(answer.begin(), answer.end(), temp[i][j]) != answer.end())
//				continue;
//			answer.push_back(temp[i][j]);
//		}
//	}
//
//	return answer;
//}
//int main()
//{
//	//string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
//	string s = "{{20,111},{111}}";
//	vector<int> t = solution(s);
//	for (auto a : t)
//		cout << a << endl;
//
//	return 0;
//}