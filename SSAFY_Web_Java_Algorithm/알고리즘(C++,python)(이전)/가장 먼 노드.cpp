//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int d[20001];
//int c[20001];
//
//int solution(int n, vector<vector<int>> edge) {
//	int answer = 0;
//	sort(edge.begin(), edge.end());
//
//	d[1] = true;
//	for (int i = 0; i < edge.size(); i++)
//	{
//		if (edge[i][0] == 1)
//		{
//			d[edge[i][1]]++;
//			c[edge[i][1]] = true;
//		}
//		else
//		{
//			if (c[edge[i][0]] && c[edge[i][1]])
//				continue;
//			else if (c[edge[i][0]] || !c[edge[i][1]])
//			{
//				d[edge[i][1]] = d[edge[i][0]] + 1;
//				c[edge[i][1]] = true;
//			}
//			else if (!c[edge[i][0]] || c[edge[i][1]])
//			{
//				d[edge[i][0]] = d[edge[i][1]] + 1;
//				c[edge[i][0]] = true;
//			}
//			else
//			{
//
//			}
//		}
//	}
//
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (max < d[i])
//			max = d[i];
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (d[i] == max)
//			answer++;
//
//	}
//	return answer;
//
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