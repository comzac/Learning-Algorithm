//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//
//using namespace std;
//
//
//string solution(vector<string> a, vector<string> b)
//{
//	string answer;
//
//	map<string, int> m;
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (m.find(a[i]) != m.end())
//		{
//			m[a[i]]++;
//		}
//		else
//			m[a[i]] = 1;
//	}
//	for (int i = 0; i < b.size(); i++)
//	{
//		m[b[i]]--;
//	}
//
//	for (auto elem : m)
//	{
//		if (elem.second != 0)
//			return elem.first;
//	}
//
//	return answer;
//}
//
//int main()
//{
//
//	vector<string> part = { "leo", "kiki", "eden" };
//	vector<string> comp = { "eden" , "kiki" };
//
//	cout << solution(part, comp) << endl;
//
//
//
//	return 0;
//}
