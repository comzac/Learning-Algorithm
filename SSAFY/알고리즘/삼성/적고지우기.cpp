
//#include <iostream>
//#include <map>
//#include <string>
//
//using namespace std;
//
//int solution(string s)
//{
//	int answer = 0;
//	map<char, int> m;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (m.find(s[i]) != m.end())
//		{
//			m[s[i]] = !m[s[i]];
//		}
//		else
//		{
//			m[s[i]] = 1;
//		}
//	}
//	int sum = 0;
//	for (auto a : m)
//	{
//		sum += a.second;
//	}
//	answer = sum;
//	return answer;
//}
//int main()
//{
//	int n = 3;
//	string q[3] = { "121","0123456789","555555" };
//	for (int i = 0; i < n; i++)
//	{
//		cout << "#" << i+1 << " " << solution(q[i]) << endl;
//	}
//
//}
