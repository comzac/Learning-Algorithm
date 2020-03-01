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
//
////struct pred
////{
////
////};
//
//bool operator<(vector<int> a, vector<int> b)
//{
//	return a[1] > b[1];
//}
//
//int solution(vector<vector<int>> jobs) {
//	int answer = 0;
//	int stayPoint = 0;
//	int vectorIdx = 0;
//	int restWork = 0;
//	int totalWork = 0;
//
//	sort(jobs.begin(), jobs.end());// , less<vector<int>>());
//	priority_queue <  vector<int>, vector<vector<int>> > pq;
//	
//
//	while (true)
//	{
//		while (vectorIdx != jobs.size())
//		{
//			if (jobs[vectorIdx][0] == stayPoint)
//			{
//				pq.push(jobs[vectorIdx]);
//				vectorIdx++;
//			}
//			else
//				break;
//		}
//
//		if (!pq.empty() && restWork <= 0)
//		{
//			restWork = pq.top()[1];
//			totalWork += pq.top()[1];
//			pq.pop();
//		}
//
//		restWork--;
//		totalWork += pq.size();
//		stayPoint++;
//		
//		if (restWork <= 0 && vectorIdx == jobs.size() && pq.empty())
//			break;
//	}
//
//	answer = totalWork / jobs.size();
//
//	return answer;
//}
//
//int main()
//{
//	/*
//		대기시점이 빠른 작업부터 수행하고 끝났을 당시에 포함되는 대기시점중 작업량이 적은 작업부터
//		시작한다!
//		일단 그렇다면 이중백터를 오름차순으로 정렬한다. (시점이 앞에서부터 검색되야하기 때문에!)
//		때문에, sort 를 활용하고 오름차순이기때문에 less (기본형)으로 적용한다.
//		less의 개념은 a, b 에서 a < b 라면 bool 값을 true로 반환하여 a의 값을 앞자리에 위치하게 하는 방식이다
//
//		이후에 대기시점을 한 사이클마다 1씩증가하면서 해당 대기시점의 값들을 오름차순으로 만들어진
//		우선순위 큐에 담아준다
//		할당된 작업량이 끝날때마다 우선순위 큐를 검색하여 top의 작업량을 부여받는다
//
//		최종적으로 이중백터의 검색이 끝났고, 잔여 작업량이 0이고, 우선순위 큐가 empty한 경우 반복을 마친다
//
//
//
//	*/
//
//	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
//
//	cout << solution(jobs) << endl;
//
//	return 0;
//}