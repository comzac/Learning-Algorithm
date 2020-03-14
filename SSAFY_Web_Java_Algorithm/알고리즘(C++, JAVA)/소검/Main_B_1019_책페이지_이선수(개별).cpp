//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int page[10];
//
//void pageCount(int num, int mul);
//void calcu(int num, int mul);
//int main()
//{
//	int n;
//	cin >> n;
//
//	pageCount(n, 1);
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << page[i] << " ";
//	}
//}
//
//void pageCount(int num, int mul)
//{
//	int lastPage = num;
//
//	while (lastPage != 0 && lastPage % 10 != 9)
//	{
//		calcu(lastPage, mul);
//		lastPage--;
//	}
//
//	if (lastPage == 0)
//		return;
//	
//	for (int i = 0; i < 10; i++)
//	{
//		page[i] += (lastPage / 10 + 1)*mul;
//		if (i == 0)
//			page[i]-= mul;
//	}
//
//
//	pageCount(lastPage / 10, mul * 10);
//}
//
//void calcu(int num, int mul)
//{
//	int n = num;
//
//	while (n != 0)
//	{
//		page[n % 10] += mul;
//		n /= 10;
//	}
//}