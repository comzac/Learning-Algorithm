//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> cnts;
//int cnt;
//void dfs(int num)
//{
//	if (num == 1)
//	{
//		cnts.push_back(cnt);
//	}
//
//	if (num % 3 == 0)
//	{
//		cnt++;
//		dfs(num / 3);
//		cnt--;
//	}
//
//	if (num % 2 == 0)
//	{
//		cnt++;
//		dfs(num / 2);
//		cnt--;
//	}
//
//	if (num > 1)
//	{
//		cnt++;
//		dfs(num - 1);
//		cnt--;
//	}
//
//}
//
//int main()
//{
//	int n;
//
//	cin >> n;
//
//	dfs(n);
//
//	sort(cnts.begin(), cnts.end());
//
//
//	cout << cnts[0];
//
//
//
//	return 0;
//}