///* 2040~
//	공식을 만듦
//	0~9) 45 + (10*0) // n 은 몫? 같은 개념
//	10~19) 45 + (10*1)
//*/
//#include <iostream>
//#include <string>
//
//typedef long long ll;
//using namespace std;
//ll a, b;
//ll answer;
//
//void calcu(ll a, ll b, ll mul);
//void numCheck(ll num, ll mul);
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		answer = 0;
//		cin >> a >> b;
//
//		calcu(a, b, 1);
//		cout << "#" << t << " " << answer << endl;
//	}
//
//	return 0;
//}
//
//void calcu(ll a, ll b, ll mul)
//{
//	
//	ll numA, numB;
//	numA = a;
//	numB = b;
//
//	if (numA == numB)
//	{
//		numCheck(numA, mul);
//		return;
//	}
//
//	if (numA == 0 && numB == 0)
//		return;
//
//	if (numA != 0)
//	{
//		while (numA % 10 != 0)
//		{
//			numCheck(numA, mul); // 각 자리수 더해주고
//			numA++;
//			if (numA == numB)
//				break;
//		}
//	}
//
//	if (numA == numB)
//	{
//		numCheck(numA, mul);
//		return;
//	}
//
//	if (numB != 0)
//	{
//		while (numB % 10 != 9)
//		{
//			numCheck(numB, mul);
//			numB--;
//			if (numB <= 0)
//				break;
//			if (numA == numB)
//				break;
//		}
//	}
//
//
//	if (numA == 0 && numB == 0)
//		return;
//
//	if (numA == numB)
//	{
//		numCheck(numA, mul);
//		return;
//	}
//	
//
//	answer += ((numB/10) - (numA/10) + 1)*45*mul;
//	calcu(numA/10, numB/10, mul * 10);
//}
//
//void numCheck(ll num, ll mul)
//{
//	ll n = num;
//
//	while (n != 0)
//	{
//		answer += (n % 10) * mul;
//		n /= 10;
//	}
//}
//
//// 11111111111111 11111111111112
