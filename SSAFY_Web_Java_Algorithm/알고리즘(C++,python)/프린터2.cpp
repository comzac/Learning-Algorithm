//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int solution(vector<int> priorities, int location) {
//	int answer = 0;
//	int loca = location;
//	int count = 0;
//	queue<int> que;
//
//	for (int i = 0; i < priorities.size(); i++)
//	{
//		que.push(priorities[i]);
//	}
//
//	while (!que.empty())
//	{
//		for (int i = 0; i < priorities.size(); i++)
//		{
//			if (que.front() < priorities[i])
//			{
//				int temp = que.front();
//				que.pop();
//				que.push(temp);
//				count = 0;
//
//				if (loca == 0)
//				{
//					loca += que.size() - 1;
//				}
//				else
//					loca -= 1;
//
//				// 여기서부터 다시하자★★★★★★★★★★★★★★★★★★★★
//			}
//			else
//			{
//				count++;
//				if (count == que.size())
//				{
//					count = 0;
//					que.pop();	
//					answer += 1;
//
//					if (loca == 0)
//					{
//						return answer;
//					}
//					loca -= 1;
//
//
//				}
//			}
//			
//		}
//	}
//
//	return answer;
//}
//
//
//int main()
//{
//	//틀리지 않았지만 굳이 큐를 쓴 의미가 있을까?
//	//스텍을 활용하면 직전에 무엇을 썼었는지를 활용할 수 있다.
//	//그 부분으로 응용하자!
//
//	vector<int> prio = { 1,1,9,1,1,1};
//	int location = 0;
//
//	cout << solution(prio, location) << endl;
//
//
//	return 0;
//
//}