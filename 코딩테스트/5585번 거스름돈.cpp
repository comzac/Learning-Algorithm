//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int main()
//{
//	int pay;
//	cin >> pay;
//
//	int money[6] = { 500,100,50,10,5,1 };
//
//	int change = 1000 - pay;
//	int idx = 0;
//	int cnt = 0;
//	while (change != 0)
//	{
//		if (money[idx] <= change)
//		{
//			int temp;
//			temp = change / money[idx];
//			change -= money[idx] * temp;
//			cnt += temp;
//		}
//		idx++;
//	}
//
//	cout << cnt;
//	return 0;
//}
