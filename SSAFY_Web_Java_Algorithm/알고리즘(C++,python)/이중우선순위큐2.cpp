//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string>
//#include <vector>
//#include <stack>
//#include <functional>
//
//using namespace std;
//
//
//vector<int> solution(vector<string> operations) {
//	vector<int> answer = { 0,0 };
//	char first;
//	int* number = new int[operations.size()];
//	int count = 0;
//	priority_queue<int, vector<int>> pq; // 내림차순
//	priority_queue<int, vector<int>, greater<int>> pq1; // 오름차순
//
//
//	for (int i = 0; i < operations.size(); i++)
//	{
//		first = operations[i][0];
//		operations[i].erase(operations[i].begin());
//		number[i] = stoi(operations[i]);
//
//		switch (first)
//		{
//		case 'I':
//			pq.push(number[i]);
//
//			break;
//
//		case 'D':
//			if (number[i] == 1)
//			{
//				if (!pq.empty())
//					pq.pop();
//			}
//			else
//			{
//				if (!pq.empty())
//				{
//					while (!pq.empty())
//					{
//						pq1.push(pq.top());
//						pq.pop();
//					}
//					pq1.pop();
//					while (!pq1.empty())
//					{
//						pq.push(pq1.top());
//						pq1.pop();
//					}
//				}
//			}
//			break;
//
//		default:
//			break;
//		}
//
//	}
//
//	if (pq.empty())
//	{
//		return answer;
//	}
//	else
//	{
//		answer.clear();
//		answer.push_back(pq.top());
//		while (!pq.empty())
//		{
//			pq1.push(pq.top());
//			pq.pop();
//		}
//		answer.push_back(pq1.top());
//
//	}
//	return answer;
//}
//
//int main()
//{
//	/*
//
//	*/
//
//	vector<string> operations = { "I 16", "D 1" };
//	vector<string> operations2 = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
//	//solution(operations);
//
//	for (int i = 0; i < 2; i++)
//	{
//		//cout << solution(operations)[i] << endl;
//		cout << solution(operations2)[i] << endl;
//	}
//
//
//	return 0;
//}