//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//
//
//int Strike(string num, int baseNum)
//{
//	int strikeCount = 0;
//	for (int i = 0; i < num.length(); i++)
//	{
//		if (to_string(baseNum)[i] == num[i])
//			strikeCount++;
//	}
//	return strikeCount;
//}
//
//int Ball(string num, int baseNum)
//{
//	int ballCount = 0;
//	for (int i = 0; i < num.length(); i++)
//	{
//		if (to_string(baseNum).find(num[i]) != to_string(baseNum).npos)
//			ballCount++;
//	}
//	return ballCount;
//}
//
//int solution(vector<vector<int>> baseball) {
//	int answer = 0;
//	stack<string> allNum;
//	bool check = true;
//
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			for (int k = 1; k < 10; k++)
//			{
//				if (i != j && j != k && k != i)
//				{
//					allNum.push(to_string(i * 100 + j * 10 + k));
//				}
//			}
//		}
//	}
//
//	while (!allNum.empty())
//	{
//		string num = allNum.top();
//		allNum.pop();
//		for (int i = 0; i < baseball.size(); i++)
//		{
//			
//			int strike = Strike(num, baseball[i][0]);
//			int ball = Ball(num, baseball[i][0]) - strike;
//
//			if (strike != baseball[i][1] || ball != baseball[i][2])
//			{
//				check = false;
//				break;
//			}
//		}
//		if (check)
//			answer++;
//		check = true;
//	}
//	return answer;
//}
//
//int main()
//{
//	vector<vector<int>> Baseball;
//	Baseball = { {123,1,1}, {356,1,0}, {327,2,0},{489,0,1} };
//
//	cout << solution(Baseball) << endl;
//
//	return 0;
//}