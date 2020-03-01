//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//int dpl[60001];
//int dp(int n)
//{
//	if (dpl[n] != 0)
//		return dpl[n];
//	return dpl[n] = (dp(n - 1) + dp(n - 2))% 1000000007;
//}
//int solution(int n) {
//	int answer = 0;
//	dpl[1] = 1;
//	dpl[2] = 2;
//
//	answer = dp(n);
//
//	return answer;
//}
//
//int main()
//{
//	int n = 4;
//	cout << solution(n);
//
//	return 0;
//}