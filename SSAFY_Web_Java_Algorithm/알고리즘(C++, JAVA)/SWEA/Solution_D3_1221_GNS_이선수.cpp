//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//string num[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
//vector<int> v;
//int N;
//
//int change(string s);
//void input();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		sort(v.begin(), v.end());
//		string answer = "";
//		for (int i = 0; i < v.size(); i++)
//		{
//			answer += num[v[i]] + " ";
//		}
//		cout << "#" << t << " " << answer << endl;
//
//		v.clear();
//	}
//}
//
//int change(string s)
//{
//	if (s == "ZRO")
//	{
//		return 0;
//	}
//	else if (s == "ONE")
//	{
//		return 1;
//	}
//	else if (s == "TWO")
//	{
//		return 2;
//	}
//	else if (s == "THR")
//	{
//		return 3;
//	}
//	else if (s == "FOR")
//	{
//		return 4;
//	}
//	else if (s == "FIV")
//	{
//		return 5;
//	}
//	else if (s == "SIX")
//	{
//		return 6;
//	}
//	else if (s == "SVN")
//	{
//		return 7;
//	}
//	else if (s == "EGT")
//	{
//		return 8;
//	}
//	else
//	{
//		return 9;
//	}	
//}
//
//void input()
//{
//	string qnum;
//	cin >> qnum;
//	cin >> N;
//
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		v.push_back(change(temp));
//	}
//}
