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
//	priority_queue<int, vector<int>> pq1; // 내림차순
//	priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순
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
//			pq1.push(number[i]);
//			pq2.push(number[i]);
//			count++;
//			break;
//
//		case 'D':
//			if (number[i] == 1)
//			{
//				if (count > 0)
//				{
//					pq1.pop();			
//					count--;
//				}
//			}
//			else
//			{
//				if (count > 0)
//				{
//					pq2.pop();
//					count--;
//				}
//			}
//			
//			break;
//
//		default:
//			break;
//		}
//
//		if (pq1.empty() || pq2.empty())
//		{
//			while (!pq1.empty())
//				pq1.pop();
//			while (!pq2.empty())
//				pq2.pop();
//		}
//
//	}
//
//	if (count <= 0)
//	{
//		return answer;
//	}
//	else
//	{
//		answer.clear();
//		answer.push_back(pq1.top());
//		answer.push_back(pq2.top());
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
//	vector<string> operations = {"I 16", "D 1"};
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