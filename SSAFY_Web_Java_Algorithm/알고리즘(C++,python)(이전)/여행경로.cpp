//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string destCompare(vector<string> temp)//, string begin, vector<bool>& visited)
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
//	vector<string> temp;
//	vector<bool> visited(tickets.size(), false);
//
//	string begin = "ICN";
//	answer.push_back(begin);
//
//	while (answer.size() < tickets.size() + 1)
//	{
//		for (int i = 0; i < tickets.size(); i++)
//		{
//			if (tickets[i][0] == begin && !visited[i])
//			{
//				temp.push_back(tickets[i][1]);
//			}
//
//		}
//
//
//		string next = destCompare(temp);
//
//		for (int j = 0; j < tickets.size(); j++)
//		{
//			if (tickets[j][0] == begin && tickets[j][1] == next)
//				visited[j] = true;
//		}
//		begin = next;
//		answer.push_back(next);
//
//		temp.clear();
//
//	}
//	return answer;
//}
//
//int main()
//{
//
//	vector<vector<string>> tickets = { {"ICN","SFO"}, {"ICN","ATL"}, {"SFO","ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} };
//	
//	for(int i = 0 ; i < solution(tickets).size() ; i++)
//		cout << solution(tickets)[i] << endl;
//
//	return 0;
//}