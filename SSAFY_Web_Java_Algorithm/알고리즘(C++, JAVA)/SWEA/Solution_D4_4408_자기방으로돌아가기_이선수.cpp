//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int T;
//int N;
//
//struct Home {
//	int start;
//	int dest;
//	//Home(int s, int d) : start(s), dest(d) {};
//};
//struct pos {
//	int s;
//	int d;
//	pos(int s, int d) : s(s), d(d) {};
//};
//vector<pos> v;
//Home student;
//int via[201];
//int maxLen;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		maxLen = 0;
//		cin >> N;
//		for (int i = 0; i < 201; i++)
//			via[i] = 0;
//		int s, e;
//		int temp;
//		for (int n = 0; n < N; n++)
//		{
//			cin >> s >> e;
//			if (s % 2 == 1)
//				s++;
//			if (e % 2 == 1)
//				e++;
//			if (e < s)
//			{
//				temp = s;
//				s = e;
//				e = temp;
//			}
//
//			student.start = s/2;
//			student.dest = e/2;
//			if (student.dest > maxLen)
//				maxLen = student.dest;
//
//			for (int i = student.start; i <= student.dest; i++)
//				via[i]++;
//		}
//
//		int maxVal = 0;
//		for (int i = 1; i <= maxLen; i++)
//		{
//			if (maxVal < via[i])
//				maxVal = via[i];
//		}
//		
//		cout << "#" << t << " " << maxVal << endl;
//
//	}
//
//	return 0;
//}
//
//
