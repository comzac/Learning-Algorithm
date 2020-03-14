//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<int> people;
//vector<int> v;
//vector<int> first;
//
//int dfs(int start, int cur, int count)
//{
//	if (v[cur])
//	{
//		if (start != first[cur])
//		{
//			return 0;
//		}
//
//		return count - v[cur];
//	}
//
//	first[cur] = start;
//	v[cur] = count;
//	return dfs(start, people[cur], count + 1);
//
//}
//
//int main()
//{
//	int n;
//	int a;
//	int T;
//
//	cin >> T;
//
//	for (int j = 0; j < T; j++)
//	{
//		cin >> n;
//
//		people = vector<int> (n+1, 0);
//		v = vector<int>(n+1, 0);
//		first = vector<int>(n+1, 0);
//
//		for (int i = 1; i < n+1; i++)
//		{
//			cin >> a;
//			people[i] = a;
//		}
//
//		int temp = 0;
//		for (int i = 1; i < people.size(); i++)
//		{
//			if(!v[i])
//				temp += dfs(i, i, 1);
//
//		}
//
//		cout << n - temp;
//	}
//
//
//	return 0;
//}
