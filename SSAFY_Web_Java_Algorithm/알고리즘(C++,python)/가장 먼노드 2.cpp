//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <queue>
//using namespace std;
//
//#define INF 1000001
//
//
//int solution(int n, vector<vector<int>> edge) {
//	int answer = 0;
//	int d[20001];
//	for (int i = 1; i <= n; i++)
//	{
//		d[i] = INF;
//	}
//
//	sort(edge.begin(), edge.end());
//
//	d[1] = 0;
//
//	for (int i = 0; i < edge.size(); i++)
//	{
//		if (edge[i][0] < edge[i][1])
//		{
//			if (d[edge[i][1]] > d[edge[i][0]] + 1)
//			{
//				d[edge[i][1]] = d[edge[i][0]] + 1;
//			}
//		}
//		else
//		{
//			if (d[edge[i][0]] > d[edge[i][1]] + 1)
//			{
//				d[edge[i][0]] = d[edge[i][1]] + 1;
//			}
//		}
//	}
//	
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (max < d[i])
//		{
//			max = d[i];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (max == d[i])
//		{
//			answer++;
//		}
//	}
//
//
//	return answer;
//}
//
//int main()
//{
//
//	int n = 6;
//	vector<vector<int>> v = { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
//	cout << solution(n, v) << endl;
//
//}