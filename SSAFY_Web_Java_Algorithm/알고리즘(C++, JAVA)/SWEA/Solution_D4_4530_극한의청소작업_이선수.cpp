///*
//	풀이)
//	9진번변환 -> 10진법 변환
//	실수가 많았던 부분은 범위에 따른 경우? 달라지는 연산방식? 부호? 등이 문제였다.
//
//	책페이지 문제처럼 풀어봐야하는데 ..크흠..
//
//*/
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//long long from;
//long long to;
//long long change10to9to10(long long num);
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> from >> to;
//		
//		bool isSame = true;
//		if (from < 0 && to > 0)
//			isSame = false;
//	
//		from = abs(from);
//		to = abs(to);
//
//		from = change10to9to10(from);
//		to = change10to9to10(to);
//
//		if(isSame)
//			cout << "#" << t << " " << abs(to - from) << endl;
//		else
//			cout << "#" << t << " " << to + from - 1 << endl;
//
//	}
//
//}
//
//long long change10to9to10(long long num)
//{
//	long long n = num;
//	long long newNum = 0;
//	long long nineNum = 0;
//	while (n != 0)
//	{
//		int rest = n % 10;
//		n /= 10;
//		if (rest >= 4)
//			rest--;
//		newNum += rest * pow(9, nineNum);
//		nineNum++;
//	}
//
//	return newNum;
//}
