//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int solution(string arrangement) {
//	int answer = 0;
//	int temp = 0;
//	bool open = false;
//	queue<char> que;
//	for (int i = 0; i < arrangement.length(); i++)
//	{
//		que.push(arrangement[i]);
//	}
//	while (!que.empty())
//	{
//		switch (que.front())
//		{
//			case '(':
//				open = true;
//				temp += 1;
//				break;
//			case ')':
//				if (open)
//				{
//					temp -= 1;
//					answer += temp;
//				}
//				else
//				{
//					answer += 1;
//					temp -= 1;
//				}
//				open = false;
//				break;		
//		}
//		que.pop();
//	}
//	return answer;
//}
//
//int main()
//{
//	//틀리지 않았지만 굳이 큐를 쓴 의미가 있을까?
//	//스텍을 활용하면 직전에 무엇을 썼었는지를 활용할 수 있다.
//	//그 부분으로 응용하자!
//
//	string Q = "()(((()())(())()))(())";
//	cout << solution(Q) << endl;
//
//	return 0;
//
//}