//#include <string>
//#include <vector>
//#include <iostream>
//#include <deque>
//using namespace std;
//
//#include <stack> 
//
//int solution(vector<int> priorities, int location) {
//	int answer = 0;
//	deque<pair<int, int>> deq;
//	for (int i = 0; i < priorities.size(); i++)
//		deq.push_back(make_pair(i, priorities[i]));
//
//	while (!deq.empty())
//	{
//		int i = 0;
//		int temp = deq.front().second;
//		int count = 0;
//
//		for (i = 1; i < deq.size(); i++)
//		{
//			if (temp < deq[i].second)
//			{
//				deq.push_back(deq.front());
//				deq.pop_front();
//				break;
//			}
//		}
//
//		if (i == deq.size())
//		{
//			answer++;		
//			if (deq.front().first == location)
//			{
//				return answer;
//			}
//			deq.pop_front();	
//		}
//	}
//	return answer;
//}
//
//int main()
//{
//	vector<int> prio = { 1,1,9,1,1,1};
//	int location = 0;
//	vector<int> prio1 = { 2,1,3,2 };
//	int location1 = 2;
//
//	cout << solution(prio, location) << endl;
//	cout << solution(prio1, location1) << endl;
//
//	return 0;
//
//}