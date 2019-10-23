//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
///*
//시작과 끝이 같으면 시작하자마자 끝난다는 개념
//끝과 다른 시작이 같아도 인정
//
//
//tc
//6
//1 3
//8 8
//4 8
//2 8
//6 8
//3 5
//
//
//*/
//
//bool pred(pair<int, int> a, pair<int, int>b)
//{
//	if(a.second == b.second)
//		return a.first < b.first;
//	return a.second < b.second;
//}
//
//int main()
//{
//	int num;
//	vector<pair<int, int>> meeting;
//	cin >> num;
//	int start, end;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> start >> end;
//		meeting.push_back(make_pair(start, end));
//	}
//	sort(meeting.begin(), meeting.end(), pred);
//	int cnt = 0;
//	int idx = 0;
//	int temp = 0;
//	while (idx != meeting.size())
//	{
//		if (meeting[idx].first >= temp)
//		{
//			cnt++;
//			temp = meeting[idx].second;
//		}
//		idx++;
//	}
//	cout << cnt;
//	return 0;
//}
