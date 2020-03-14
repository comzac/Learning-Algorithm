//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <queue>
//
//using namespace std;
//
//bool stringCheck(string a, string b)
//{
//	int cnt = 0;
//	for (int i = 0; i < a.length(); i++)
//	{
//		if (a[i] != b[i])
//			cnt++;
//
//		if (cnt >= 2)
//			return false;
//	}
//	if (cnt == 0)
//		return false;
//	return true;
//}
//
//
//int solution(string begin, string target, vector<string> words) {
//	int answer = 0;
//	map<string, int> d;
//	queue<string> q;
//	vector<bool> v(words.size(), 0);
//
//	for (int i = 0; i < words.size(); i++)
//	{
//		d[words[i]] = -1;
//	}
//
//	q.push(begin);
//	d[begin] = 0;
//
//	while (!q.empty())
//	{
//		string temp = q.front();
//		q.pop();
//		for (int i = 0; i < words.size(); i++)
//		{
//			if (v[i]) continue;
//
//			if (stringCheck(temp, words[i]))
//			{
//				d[words[i]] = d[temp] + 1;
//				v[i] = true;
//				q.push(words[i]);
//
//				if (words[i] == target)
//					return d[words[i]];
//			}
//		}
//	}
//
//	return answer;
//}
//
//int main()
//{
//
//	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
//	string a = "hit";
//	string b = "cog";
//
//	cout << solution(a, b, words) << endl;
//
//
//	return 0;
//}
