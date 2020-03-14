//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string>
//#include <vector>
//
//using namespace std;
///*
//	일단 stock < k 면, stock 보다 처음으로 같거나 작은 dates에 supplies를 받아야한다.
//	stock+= supplies가 되고 또 다시 stock < k 면, stock 보다 같거나 처음으로 작은 dates의 supplies를 받아야한다.
//
//	핵심이 처음으로 작은인거같군 // => 이건 틀렸어.. ★ 마지막 공급일자가 진죽에 끊겨서 미리 받아놔야하는 상황도있다.
//
//	우선순위 큐의 장점? 특성은 원하는 정렬 방식으로 데이터들을 저장한다는거야
//
//	이 문제에서 어떻게 활용할 수 있을까?
//
//*/
//int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
//	int answer = 0;
//	priority_queue<int> pq;
//	int start = 0;
//
//	while (stock < k)
//	{
//		for (int i = start; i < dates.size(); i++)
//		{
//			if (dates[i] <= stock)
//			{
//				pq.push(supplies[i]);
//			}
//			else
//			{
//				start = i;
//				break;
//			}
//		}
//
//		stock += pq.top();
//		pq.pop();
//		answer++;
//	}
//
//	return answer;
//}
//
//int main()
//{
//	int stock = 4;
//	vector<int> dates =    { 4,5,6,7,8,9,10,11 }; // 이런 경우 11만 계속 들어감
//	vector<int> supplies = { 20,5,10,20,30,60,30,20 }; // 답은 3번인데 5번나올걸?
//	int k = 100;
//	
//
//	cout << solution(stock, dates, supplies, k) << endl;
//
//	return 0;
//}