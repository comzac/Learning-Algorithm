//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int m;
//vector<int> bg;
//
//// 조건보고 단위 long long 인 것도 고려하기!!!
//int binarySearch(int mb, int ma)
//{
//	if (mb > ma)
//		return ma;
//	int mid = (mb + ma) / 2;
//	long long total = 0;
//
//	for (int j = 0; j < bg.size(); j++)
//	{
//		if (mid >= bg[j])
//			total += bg[j];
//		else
//			total += mid;
//	}
//
//	if (total > m)
//		return binarySearch(mb, mid-1);
//	else
//		return binarySearch(mid+1, ma);
//}
//
//int solution(vector<int> budgets, int M) {
//	int answer = 0;
//	m = M;
//	bg = budgets;
//	
//	int min = 100001;
//	int max = 0;
//	long long total = 0;
//
//	for (int i = 0; i < budgets.size(); i++)
//	{
//		if (min > budgets[i])
//			min = budgets[i];
//		if (max < budgets[i])
//			max = budgets[i];
//		total += budgets[i];
//	}
//
//	if (total <= M)
//		return max;
//	if (min > M)
//		answer = binarySearch(0, M);
//	else
//		answer = binarySearch(0, max);
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> budgets = { 120,110, 140,150 };
//	int M = 485;
//	cout << solution(budgets, M);
//
//	return 0;
//}