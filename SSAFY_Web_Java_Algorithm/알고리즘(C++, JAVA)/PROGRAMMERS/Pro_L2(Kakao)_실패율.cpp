//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//bool cmp(pair<double, int> a, pair<double, int> b) {
//	if (a.first == b.first)
//		return a.second > b.second;
//	return a.first < b.first;
//}
//
//vector<int> solution(int N, vector<int> stages) {
//	vector<int> answer;
//
//	sort(stages.begin(), stages.end());
//
//	int num = stages.size();
//	int limit = num;
//	vector<pair<double, int>> fail;
//
//	int level = 1;
//	int cur = 0;
//	int idx = 0;
//
//	// 1 2 2 2 3 3 4 6
//	int i;
//	for (i = 1; i <= N; i++) {
//
//		if (stages[idx] == i)
//		{
//			cur++;
//			idx++;
//			if (idx == limit) {
//				fail.push_back({ (double)cur / num, i });
//				break;
//			}
//			i--;
//		}
//		else
//		{
//			fail.push_back({ (double)cur / num, i });
//			num -= cur;
//			cur = 0;
//		}
//	}
//
//	if (i != N) {
//		for(int j = i+1; j <= N; j++)
//			fail.push_back({ 0, j });
//	}
//
//
//	sort(fail.rbegin(), fail.rend(), cmp);
//
//	for (auto a : fail) {
//		answer.push_back(a.second);
//	}
//	return answer;
//}
//
//int main()
//{
//	int N = 7;
//	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
//	
//	vector<int> result = solution(N, stages);
//	for(auto a : result)
//		cout << a << endl;
//
//
//
//
//	return 0;
//}