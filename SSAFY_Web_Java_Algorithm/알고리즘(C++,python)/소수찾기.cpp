//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//#define MAX 31
//int c[MAX];
//int p[MAX];
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//	int answer = 0;
//	int count = 0;
//
//	for (int i = 0; i < lost.size(); i++)
//	{
//		for (int j = 0; j < reserve.size(); j++)
//		{
//			if (lost[i] == reserve[j])
//			{
//				c[reserve[j]] = true;
//				p[reserve[j]] = true;
//			}
//		}
//	}
//
//	for (int i = 0; i < lost.size(); i++)
//	{
//		for (int j = 0; j < reserve.size(); j++)
//		{
//			if (c[reserve[j]]) continue;
//			p[reserve[j]] = true;
//
//			if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
//			{
//				c[reserve[j]] = true;
//				p[lost[i]] = true;
//			}
//		}
//
//	}
//
//	for (int i = 0; i < lost.size(); i++)
//	{
//		if (!p[lost[i]])
//			count++;
//	}
//	answer = n - count;
//
//	return answer;
//}
//
//int main()
//{
//
//
//	vector<int> a = { 3,4 };
//	vector<int> b = { 4,5 };
//
//	cout << solution(5, a, b) << endl;
//
//
//
//}