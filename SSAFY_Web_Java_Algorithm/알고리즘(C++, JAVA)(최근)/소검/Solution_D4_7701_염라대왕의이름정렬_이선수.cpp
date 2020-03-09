///*
//	이름의 길이가 짧을수록 이 앞에 있었고,
//	같은 길이면 사전 순으로 앞에 있었다.
//	같은 이름은 하나만 남겨놓기
//
//	이름 개수 N(1 ≤ N ≤ 20,000)
//	이름에는 공백이 포함되지 않으며 최소 1개, 최대 50개의 알파벳으로 이루어져 있다.
//*/
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <map>
//#include <queue>
//
//using namespace std;
//
//struct cmp {
//	bool operator()(const string& s1, const string& s2)
//	{
//		int len1 = s1.length();
//		int len2 = s2.length();
//
//		if (len1 == len2)
//			return s1 > s2;
//		else
//			return len1 > len2;
//	}
//};
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		int N;
//		cin >> N;
//		priority_queue<string, vector<string>, cmp> pq;
//		map<string, int> name;
//		string temp;
//		for (int i = 0; i < N; i++)
//		{
//			cin >> temp;
//			pq.push(temp);
//		}
//
//		cout << "#" << t << endl;
//		string before = "";
//		string answer = "";
//		while (!pq.empty())
//		{
//			if (pq.top() != before) {
//				answer += pq.top() + "\n";
//				before = pq.top();
//			}
//			pq.pop();
//		}
//		cout << answer;
//	}
//
//
//
//	return 0;
//}
