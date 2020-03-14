///* 2035~2050
//
//*/
//#include <iostream>
//#include <string>
//#include <set>
//#include <algorithm>
//
//using namespace std;
//
//int K;
//string str;
//int len;
//set<string> subStr;
//string answer;
//
//void input();
//void dfs(int l, int idx);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		subStr.clear();
//		answer = "none";
//		input();
//		len = str.length();
//		for(int i = 1; i <= len; i++)
//			dfs(i, 0);
//
//		set<string>::iterator it = subStr.begin();
//		int cnt = 0;
//		for (it; it != subStr.end(); it++)
//		{
//			if (cnt == K-1)
//			{
//				answer = *it;
//				break;
//			}
//			cnt++;
//		}
//		cout << "#" << t << " " << answer << endl;
//	}
//}
//
//void input()
//{
//	cin >> K;
//	cin >> str;
//}
//
//void dfs(int l, int idx)
//{
//	if (idx+l > len)
//		return;
//	subStr.insert(str.substr(idx, l));
//	dfs(l, idx + 1);
//}
