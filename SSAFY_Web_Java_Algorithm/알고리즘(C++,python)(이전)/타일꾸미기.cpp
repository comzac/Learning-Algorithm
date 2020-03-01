//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//
//long long fibo2(int n, long long* memo)
//{
//	if (n < 0)
//		return 0;
//	else if (n == 1 || n == 2)
//		return 1;
//	else if (memo[n] > -1)
//		return memo[n];
//	else
//	{
//		memo[n] = fibo2(n - 1, memo) + fibo2(n - 2, memo);
//		return memo[n];
//	}
//
//}
//
//long long fibo(int n)
//{
//	long long * memo = new long long[n + 1];
//	for (int i = 0; i < n + 1; i++)
//		memo[i] = -1;
//	
//	return fibo2(n, memo);
//
//}
//
//long long solution(int N) {
//	long long answer = 0;
//
//	answer = fibo(N + 1) * 2 + fibo(N) * 2;
//
//	return answer;
//}
//
//int main()
//{
//	cout << solution(5) << endl;
//}