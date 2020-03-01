///* 
//
//	점화식 개념이 뙇딱 생각이 안나는 스타일문제다
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
///*
//합이 k원 되도록만 만들어라
//횟수제한 ㄴㄴ
//순서만 다른것은 같은 경우로 취급
//총 경우의 수는?
//*/
//
//int num, target;
//int coin[101];
//int cnt[100001];
//
//int sol()
//{
//	cnt[0] = 1;
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = coin[i]; j <= target; j++)
//		{
//			cnt[j] += cnt[j - coin[i]];
//		}
//	}
//
//	return cnt[target];
//}
//int main()
//{
//	//while(1)
//	{
//		cin >> num >> target;
//		int temp;
//	
//		for (int i = 1; i <= num; i++)
//		{
//			cin >> temp;
//			coin[i] = temp;
//		}
//		cout << sol();
//	}
//	return 0;
//}
