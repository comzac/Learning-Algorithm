//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//vector<int> solution(int N, vector<int> stages) {
//	vector<int> answer;
//
//	vector<pair<float,int>> fail;
//	float mom;
//	float son;
//
//	for (int i = 0; i < N; i++)
//	{
//		mom = 0;
//		son = 0;
//		for (int j = 0; j < stages.size(); j++)
//		{
//			if (stages[j] >= i + 1)
//				mom++;
//			if (stages[j] == i + 1)
//				son++;
//		}
//		fail.push_back(make_pair(-(son / mom), i + 1));
//	}
//
//	sort(fail.begin(), fail.end());
//
//	for (auto a : fail)
//	{
//		answer.push_back(a.second);
//	}
//
//	return answer;
//}
//
//int main()
//{
//	int n = 5;
//	int n2 = 4;
//	vector<int> stage = { 2, 1, 2, 6, 2, 4, 3, 3 };
//	vector<int> stage2 = { 4,4,4,4,4 };
//
//	for (auto a : solution(n2, stage2))
//	{
//		cout << a << endl;
//	}
//}