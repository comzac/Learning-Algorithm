//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int visit[26][26];
//int len;
//
//void dfs(vector<vector<int>> v, int x, int y, int num)
//{
//	if (num == x || num == y || x < 0 || y < 0)
//	{
//		return;
//	}
//
//	if (visit[y][x] || v[y][x] == 0)
//	{
//		return;
//	}
//	visit[y][x] = true;
//	len++;
//
//	dfs(v, x + 1, y, num); 
//	dfs(v, x - 1, y, num);
//	dfs(v, x, y + 1, num);
//	dfs(v, x, y - 1, num);
//}
//
//void solution(vector<vector<int>> m)
//{
//	vector<int> length;
//	int x, y;
//	x = y = 0;
//	int num = m.size();
//	int size = 0;
//	for (int i = 0; i < m.size(); i++)
//	{
//		for (int j = 0; j < m[i].size(); j++)
//		{
//			len = 0;
//			if (m[i][j] == 1 && !visit[i][j])
//			{
//				dfs(m, j, i, num);
//				length.push_back(len);
//			}
//		}
//	}
//	cout << length.size() << endl;
//	sort(length.begin(), length.end());
//	for (int i = 0; i < length.size(); i++)
//		cout << length[i] << endl;
//
//
//
//}
//
//
//int main()
//{
//	int num;
//	cin >> num;
//	string row;
//	vector<vector<int>> map(num, vector<int>(num,0));
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> row;
//		for (int j = 0; j < row.length(); j++)
//		{
//			map[i][j] = row[j] - '0';
//		}
//	}
//
//	solution(map);
//
//	return 0;
//}