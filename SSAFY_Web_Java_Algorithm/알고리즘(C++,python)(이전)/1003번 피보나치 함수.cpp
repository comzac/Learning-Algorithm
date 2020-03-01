//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int n;
//vector<int> answer;
//int zeroone[41][2];
///*
//	2 = 1 + 0  
//	3 = 2 + 1 = 1 + 0 + 1
//	4 = 3 + 2 = 2 + 1 + 1 + 0 = 1 + 0 + 1 + 1 + 0
//*/
//vector<int> dp(int n)
//{
//	zeroone[0][0] = 1;
//	zeroone[0][1] = 0;
//	zeroone[1][0] = 0;
//	zeroone[1][1] = 1;
//
//	for (int i = 2; i <= n; i++)
//	{
//		zeroone[i][0] = zeroone[i - 1][0] + zeroone[i - 2][0];
//		zeroone[i][1] = zeroone[i - 1][1] + zeroone[i - 2][1];
//	}
//
//	answer.push_back(zeroone[n][0]);
//	answer.push_back(zeroone[n][1]);
//	return answer;
//}
//
//vector<int> sol(int n)
//{
//	return dp(n);
//}
//int main()
//{
//	cin >> n;
//	int temp;
//	vector<int> tv;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		tv = sol(temp);
//		cout << tv[0] << " " << tv[1] << endl;
//		answer.clear();
//	}
//	
//	return 0;
//}
