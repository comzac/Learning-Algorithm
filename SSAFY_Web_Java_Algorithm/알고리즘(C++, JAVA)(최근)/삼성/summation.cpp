//#include "pch.h"
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//pair<int,int> solution(string s)
//{
//	vector<int> v;
//	int cur = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//		{
//			string sub = s.substr(cur, i - cur);
//			cur = i;
//			v.push_back(stoi(sub));
//		}
//	}
//	v.push_back(stoi(s.substr(cur, s.size() - cur)));
//
//	int max = 0;
//	int min = 1000001;
//	for (int i = 0; i < v.size(); i++)
//	{
//		int sum = 0;
//		int num = v[i];
//		while (num != 0)
//		{
//			sum += num % 10;
//			num /= 10;
//		}
//		
//		if (sum > max)
//			max = sum;
//		if (sum < min)
//			min = sum;
//	}
//
//	return make_pair(max,min);
//}
//int main()
//{
//	string n;
//	getline(cin,n);
//	vector<int> v;
//
//	string s;
//	
//	for (int i = 0; i < stoi(n); i++)
//	{
//		getline(cin, s);
//
//		cout << "#" << i+1 << " " << solution(s).first << " " << solution(s).second << endl;
//	}
//
//}
