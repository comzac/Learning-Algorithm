//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int solution(string s)
//{
//	int cnt = 0;
//	char before = '0';
//	char cur;
//	for (int i = 0; i < s.length(); i++)
//	{
//		cur = s[i];
//		if (cur != before)
//		{
//			cnt++;
//			before = cur;
//		}
//	}
//
//	return cnt;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false); 
//	cin.tie(NULL);
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++)
//	{
//		string s;
//		cin >> s;
//
//		cout << "#" << i + 1 << " " << solution(s) << endl;
//	}
//
//
//	return 0;
//}
