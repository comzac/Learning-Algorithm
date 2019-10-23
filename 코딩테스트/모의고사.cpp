//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//#define FIR 5
//#define SEC 8
//#define THR 10
//
//vector<int> solution(vector<int> answers) {
//	vector<int> answer;
//	int first[FIR] = { 1,2,3,4,5 };
//	int second[SEC] = { 2,1,2,3,2,4,2,5 };
//	int third[THR] = { 3,3,1,1,2,2,4,4,5,5 };
//	int count[3] = {};
//	vector<pair<int, int>> check;
//
//	for (int i = 0; i < answers.size(); i++)
//	{
//		if (first[i%FIR] == answers[i])
//			count[0]++;
//
//		if (second[i%SEC] == answers[i])
//			count[1]++;
//
//		if (third[i%THR] == answers[i])
//			count[2]++;
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		check.push_back(make_pair(count[i], i+1));
//	}
//
//	sort(check.rbegin(), check.rend());
//
//	/*for (int i = 0; i < 3; i++)
//	{
//		cout << check[i].first << endl;
//	}*/
//
//	if (check[0].first == check[1].first)
//	{
//		if (check[1].first == check[2].first)
//		{
//			answer.push_back(check[0].second);
//			answer.push_back(check[1].second);
//			answer.push_back(check[2].second);
//		}
//		else
//		{
//			answer.push_back(check[0].second);
//			answer.push_back(check[1].second);
//		}
//	}
//	else
//	{
//		answer.push_back(check[0].second);
//	}
//
//	sort(answer.begin(), answer.end());
//
//	return answer;
//}
//
//int main()
//{
//	
//	vector<int> answer = {1,3,6,6,6};
//	//solution(answer);
//
//	for(int i = 0; i < solution(answer).size(); i++)
//		cout << solution(answer)[i] << endl;
//
//	return 0;
//}