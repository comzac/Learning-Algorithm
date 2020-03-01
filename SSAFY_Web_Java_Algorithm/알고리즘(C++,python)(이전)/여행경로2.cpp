//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//string destCompare(vector<string> temp)
//{
//	string min = temp[0];
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		if (min > temp[i])
//			min = temp[i];
//	}
//	return min;
//}
//
//vector<string> solution(vector<vector<string>> tickets) {
//	vector<string> answer;
//	queue<string> que;
//	//priority_queue<string, vector<string>, greater<>> pq;
//	vector<bool> isUsed(tickets.size(), false);
//	vector<string> temp;
//
//
//	que.push("ICN");
//	answer.push_back("ICN");
//
//	while (answer.size() -1 != tickets.size())
//	{
//		string start = que.front();
//		que.pop();
//		
//		for (int i = 0; i < tickets.size(); i++)
//		{
//			if (tickets[i][0] == start && isUsed[i] == false)
//			{
//				temp.push_back(tickets[i][1]);
//			}
//		}
//
//		string next = destCompare(temp);
//		que.push(next);
//
//		for (int i = 0; i < tickets.size(); i++)
//		{
//			if (tickets[i][0] == start && tickets[i][1] == next)
//			{
//				isUsed[i] = true;
//				break;
//			}
//		}
//
//		answer.push_back(next);
//		temp.clear();
//	}
//
//
//	return answer;
//}
//
//int main()
//{
//
//	vector<vector<string>> tickets = { {"ICN","SFO"}, {"ICN","ATL"}, {"SFO","ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} };
//
//	for (int i = 0; i < solution(tickets).size(); i++)
//		cout << solution(tickets)[i] << endl;
//
//	return 0;
//}