//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<vector<int>> routes) {
//	int answer = 0;
//
//	if (routes.size() == 1)
//		return 1;
//
//	sort(routes.begin(), routes.end());
//	
//	int front = routes[0][0];
//	int back = routes[0][1];
//	answer++;
//	for (int i = 1; i < routes.size(); i++)
//	{
//		if (routes[i][0] <= back)
//		{
//			front = routes[i][0];
//
//			if (routes[i][1] <= back)
//				back = routes[i][1];
//
//		}
//		else
//		{
//			answer++;
//			front = routes[i][0];
//			back = routes[i][1];
//		}
//	}
//	return answer;
//}
//
//
//int main()
//{
//	//cout << solution(vector<vector<int>>({ {-20,15},{-14,-5},{-18,-13},{-5,-3} }));
//	cout << solution(vector<vector<int>>({ {5,8},{6,7},{8,10},{1,3},{2,4},{8,9} }));
//
//	return 0;
//}