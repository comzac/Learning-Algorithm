//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//int limit;
//int maxF;
//
//vector<pair<int, int>> v;
//
//void solution(int idx, int calSum, int favSum)
//{
//	if (calSum >= limit || idx == v.size())
//		return;
//
//	int curCal = v[idx].first + calSum;
//	int curFav = v[idx].second + favSum;
//
//	if (curCal <= limit)
//	{
//		if (maxF < curFav)
//			maxF = curFav;
//	}
//
//
//
//	for (int i = idx + 1; i < v.size(); i++)
//	{
//		solution(i, curCal, curFav);
//	}
//
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int answer;
//	int T;
//	cin >> T;
//
//
//	int fav;
//	int cal;
//
//	for (int i = 0; i < T; i++)
//	{
//		maxF = 0;
//		v.clear();
//		cin >> n >> limit;
//
//		for (int j = 0; j < n; j++)
//		{
//			cin >> fav >> cal;
//			v.push_back(make_pair(cal, fav));
//		}
//
//		sort(v.rbegin(), v.rend());
//		
//		for (int j = 0; j < v.size(); j++)
//		{
//			solution(j, 0, 0);
//		}
//
//		answer = maxF;
//
//		cout << "#" << i + 1 << " " << answer << endl;
//
//	}
//
//
//	return 0;
//}
