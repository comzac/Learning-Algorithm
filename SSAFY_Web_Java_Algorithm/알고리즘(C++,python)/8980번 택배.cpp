//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int vilage;
//int capacity;
//pair<pair<int, int>, int> info[10001];
//int num;
//
//bool pred(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
//{
//	if (a.first.second == b.first.second)
//	{
//		return a.first.first < b.first.first;
//	}
//	return a.first.second < b.first.second;
//}
//int main()
//{
//	cin >> vilage >> capacity;
//	cin >> num;
//
//	for (int i = 0; i < num; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		info[i] = make_pair(make_pair(a,b),c);
//	}
//
//	sort(info, info + num, pred);
//	
//	int truck_c = 0;
//	vector<int> destbox(vilage+1, 0);
//
//	int cur = 1;
//	int answer = 0;
//	while (cur != vilage + 1)
//	{
//		truck_c -= destbox[cur];
//		answer += destbox[cur];
//		destbox[cur] = 0;
//
//		for (int i = 0; i < num; i++)
//		{
//			if (info[i].first.first == cur && truck_c != capacity)
//			{
//				if (truck_c + info[i].second <= capacity)
//				{
//					destbox[info[i].first.second] += info[i].second;
//					truck_c += info[i].second;
//				}
//				else
//				{
//					destbox[info[i].first.second] += capacity - truck_c;
//					truck_c = capacity;
//				}
//			}
//			else
//				continue;
//		}
//		cur++;
//	}
//
//	cout << answer;
//
//	return 0;
//}
