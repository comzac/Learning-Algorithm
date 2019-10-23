//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <queue>
//#include <functional>
//using namespace std;
//
//int solution(int n, vector<vector<int>> edge) {
//	int answer = 0;
//	vector<vector<bool>> graph(n, vector<bool>(n, false));
//	vector<bool> v(n, false);
//	vector<int> d(n, 0);
//
//	queue<pair<int, int>> q;
//
//	for (auto a : edge)
//	{
//		graph[a[0] - 1][a[1] - 1] = true;
//		graph[a[1] - 1][a[0] - 1] = true;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (graph[0][i])
//		{
//			v[0] = true;
//			v[i] = true;
//			d[i] = d[0] + 1;
//			q.push(make_pair(i, d[i]));
//		}
//	}
//
//	while (!q.empty())
//	{
//		pair<int,int> cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < n; i++)
//		{
//			if (graph[cur.first][i] && !v[i])
//			{
//				v[i] = true;
//				d[i] = d[cur.first] + 1;
//				q.push(make_pair(i, d[i]));
//			}
//		}
//	}
//
//	sort(d.begin(), d.end(), greater<int>());
//
//	int max = d.front();
//
//	for (int i = 0; i < d.size(); i++)
//	{
//		if (max == d[i])
//			answer++;
//		else
//			break;
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