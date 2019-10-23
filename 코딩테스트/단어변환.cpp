//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//int stringCheck(string s1, string s2)
//{
//	int count = 0;
//	for (int i = 0; i < s1.length(); i++)
//	{
//		if (s1[i] == s2[i])
//			count++;
//	}
//
//	return count == s1.length()-1 ? 1 : 0;
//}
//
//int solution(string begin, string target, vector<string> words) {
//
//	int answer = 0;
//	map<string, int> counting;
//	for (int i = 0; i < words.size(); i++)
//	{
//		counting[words[i]] = -1;
//	}
//
//	queue<string> que;
//	//int idx = 0;
//	
//	que.push(begin);
//	counting[que.front()] = 0;
//
//	while (!que.empty())
//	{
//		string start = que.front();
//		que.pop();
//
//		for (int idx = 0; idx < words.size(); idx++)
//		{
//			if (counting[words[idx]] == -1)
//			{
//				if (stringCheck(start, words[idx]))
//				{		
//					counting[words[idx]] = counting[start] + 1;	
//
//					que.push(words[idx]);
//					if (target == words[idx])
//						return counting[words[idx]];
//				}
//			}
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	//BFS 검색 형태이다
//
//	string begin = "hit";
//	string target = "cog";
//	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
//
//	cout << solution(begin, target, words) << endl;
//
//	return 0;
//}