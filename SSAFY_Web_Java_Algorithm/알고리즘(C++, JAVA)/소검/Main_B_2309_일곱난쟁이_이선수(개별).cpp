///* 2120~2130
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int height[9];
//bool visit[9];
//bool isFind;
//vector<int> answer;
//
//void dfs(int idx, int sum, int cnt);
//int N;
//int main()
//{
//	N = 9;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> height[i];
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		visit[i] = true;
//		dfs(i, height[i], 1);
//		if (isFind)
//			break;
//		visit[i] = false;
//	}
//
//	sort(answer.begin(), answer.end());
//	for (auto a : answer)
//	{
//		cout << a << endl;
//	}
//}
//
//void dfs(int idx, int sum, int cnt)
//{
//	if (sum > 100)
//		return;
//	if (cnt == 7 && sum == 100)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (visit[i])
//			{
//				answer.push_back(height[i]);
//			}
//		}
//		isFind = true;
//		return;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (visit[i])
//			continue;
//		visit[i] = true;
//		dfs(i, sum + height[i], cnt+1);
//		if (isFind)
//			return;
//		visit[i] = false;
//	}
//}
