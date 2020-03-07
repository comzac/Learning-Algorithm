///* 1735~1755 20M
//	1. 2초 128MB
//	
//	풀이 : 문제 내용만 보면 dfs 같지만 범위를 보면 DP로 접근해야할 거 같다.
//	연속 3잔은 못마신다 가 조건이다.
//	점화식을 세워보자
//	dp[n] = dp[n-1] or arr[n] + dp[n-2] or arr[n]+arr[n-1]+dp[n-3] 중 큰값.
//
//	예제) 6 10 13 9 8 1
//	dp[6] = ?
//
//	dp[0] = 0, dp[1] = 6, dp[2] = 16
//
//	dp[3] = 16 or 6+6 or 13+10+0 => 23
//	dp[4] = 23 or 9+16 or 9+13+6 => 27
//	dp[5] = 27 or 8+23 or 8+9+16 => 33
//	dp[6] = 33 or 1+27 or 1+8+23 => 33
//
//*/
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N;
//int arr[10001];
//int dp[10001];
//
//int main()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		cin >> arr[i];
//	
//	dp[0] = 0;
//	dp[1] = arr[1];
//	dp[2] = arr[1] + arr[2];
//
//	for (int i = 3; i <= N; i++)
//	{
//		vector<int> v;
//		v.push_back(dp[i - 1]);
//		v.push_back(arr[i] + dp[i - 2]);
//		v.push_back(arr[i] + arr[i - 1] + dp[i - 3]);
//
//		dp[i] = *max_element(v.begin(), v.end());
//	}
//	cout << dp[N];
//	return 0;
//}
