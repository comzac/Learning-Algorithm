///*
//	1. 1초 256MB
//	2. 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수
//	3. 1 <= n <= 1,000
//	
//	풀이
//	1. 점화식을 세운다.
//	=> f(n) = 
//	아래의 타일이 n번째에 포함됐을 경우를 나눠 생각한다.
//	1×2, f(n-2)
//	2×1, f(n-1)
//	2×2, f(n-2)
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int dp[1001];
//int main()
//{
//	int n;
//	cin >> n;
//	dp[1] = 1;
//	dp[2] = 3;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = dp[i - 2] * 2 + dp[i - 1];
//		dp[i] %= 10007;
//	}
//	
//	cout << dp[n];
//
//	return 0;
//}