//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
///*
//d1 = 0
//d2 = 1
//d3 = 1
//
//d4 = 2
//d5 = 3
//d6 = 2
//d7 = 3
//d8 = 3
//d9 = 2
//d10 = 3
//d11 = 4
//d12 = 3
//d13 = 4
//d14 = 4
//d15 = 4
//d16 = 4
//*/
//
//int n[1000001];
//int target;
//int dp(int num)
//{
//	if (num == 1)
//		return 0;
//	else if (num == 2)
//		return 1;
//	else if (num == 3)
//		return 1;
//
//	int f, s, th;
//	f = s = th = 1000000;
//
//	if (num % 3 == 0)
//		if (n[num / 3] == 0)
//			f = dp(num / 3) + 1;
//		else
//			f = n[num / 3] + 1;
//	if (num % 2 == 0)
//		if (n[num / 2] == 0)
//			s = dp(num / 2) + 1;
//		else
//			s = n[num / 2] + 1;
//	if (num > 1)
//		if (n[num - 1] == 0)
//			th = dp(num - 1) + 1;
//		else
//			th = n[num - 1] + 1;
//
//	if (f < s)
//	{
//		if (f < th)
//			n[num] = f;
//		else
//			n[num] = th;
//	}
//	else
//	{
//		if (s < th)
//			n[num] = s;
//		else
//			n[num] = th;
//	}
//
//	return n[num];
//
//}
//int sol(int num)
//{
//	return dp(target);
//}
//
//int main()
//{
//
//	cin >> target;
//	cout << sol(target);
//
//	return 0;
//}