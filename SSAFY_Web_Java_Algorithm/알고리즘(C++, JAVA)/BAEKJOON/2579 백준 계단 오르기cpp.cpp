///*
//	1. 1초, 128MB
//	2. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
//	3. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
//	4. 마지막 도착 계단은 반드시 밟아야 한다.
//
//	계단에는 점수가 있고, 밟을때마다 획득
//	점수의 최댓값은?
//
//	풀이
//	1. 점화식
//	f(n) = max(f(n-2), f(n-3)+score[n-1]) + score[n];
//
//
//
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int score[301];
//int dp[301];
//#define MAX(X,Y) ((X) > (Y) ? (X) : (Y)) 
//int main()
//{
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> score[i];
//
//	dp[1] = score[1];
//	dp[2] = score[1] + score[2];
//	
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = MAX(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
//	}
//
//	cout << dp[n];
//	
//
//	return 0;
//}