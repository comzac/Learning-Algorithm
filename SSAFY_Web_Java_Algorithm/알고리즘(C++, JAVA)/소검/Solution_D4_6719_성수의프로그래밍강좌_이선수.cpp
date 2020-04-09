//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, K;
//vector<int> M;
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N >> K;
//		int temp;
//		for (int i = 0; i < N; i++)
//		{
//			cin >> temp;
//			M.push_back(temp);
//		}
//
//		sort(M.begin(), M.end());
//
//		double answer = 0;
//		for (int i = N - K; i < M.size(); i++)
//		{
//			answer = (answer + M[i]) / 2;
//		}
//		
//		cout << fixed;
//		cout.precision(6);
//		cout << "#" << t << " " << answer << endl;
//
//		M.clear();
//	}
//}
//
//
