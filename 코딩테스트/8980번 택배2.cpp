/*
일단 스킵
*/
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int MAX = 10000 + 1;
//
//int N, C, M;
//
//int capacity[2000 + 1]; //idx에서 트럭에 차 있는 박스 양
//
//pair<pair<int, int>, int> arr[MAX]; //출발, 도착, 박스
//
//bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
//{
//
//	//도착점 기준
//
//	if (a.first.second < b.first.second)
//
//		return true;
//
//	//도착점이 동일할 경우 시작점 기준
//
//	else if (a.first.second == b.first.second)
//
//		if (a.first.first < b.first.first)
//
//			return true;
//
//	return false;
//
//}
//
//
//
//int main(void)
//
//{
//
//	ios_base::sync_with_stdio(0);
//
//	cin.tie(0); //cin 실행속도 향상
//
//	cin >> N >> C >> M;
//
//
//
//	for (int i = 0; i < M; i++)
//
//		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
//
//
//
//	sort(arr, arr + M, cmp);
//
//
//
//	int result = 0;
//
//	for (int i = 0; i < M; i++)
//	{
//
//		int boxCnt = 0;
//
//		//해당 구간을 돌면서 가장 많이 적재된 양
//
//		for (int j = arr[i].first.first; j < arr[i].first.second; j++)
//
//			boxCnt = max(boxCnt, capacity[j]);
//
//		//트럭에 더 심을 수 있는 양
//
//		int leftSpace = min(arr[i].second, C - boxCnt);
//
//		result += leftSpace;
//
//		//해당 구간에 더 적재 시킨다
//
//		for (int j = arr[i].first.first; j < arr[i].first.second; j++)
//
//			capacity[j] += leftSpace;
//
//	}
//
//	cout << result << "\n";
//
//	return 0;
//
//}