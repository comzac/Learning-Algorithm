//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//bool stringCheck(string s1, string s2)
//{
//	int count = 0;
//	for (int i = 0; i < s1.length(); i++)
//	{
//		if (s1[i] == s2[i])
//			count++;
//	}
//	return count == s1.length() - 1 ? true : false;
//}
//
//int solution(string begin, string target, vector<string> words) {
//
//	int answer = 0;
//	int count = 0;
//	vector<bool> isVisited;
//	queue<string> que;
//	int idx = 0;
//
//	for (int i = 0; i < words.size() + 1; i++)
//	{
//		isVisited.push_back(false);
//	}
//
//
//	que.push(begin);
//	isVisited[idx] = true;
//
//	while (!que.empty())
//	{
//		string start = que.front();
//		que.pop();
//
//		for (int i = 0; i < words.size(); i++)
//		{
//			if (stringCheck(start, words[i]))
//			{
//				if (!isVisited[i + 1])
//				{
//					if (target == words[i])
//						return count;
//
//					que.push(words[i]);
//					isVisited[i + 1] = true;
//				}
//			}
//		}
//		count++;
//	}
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