//// 함정. 음수가 최대값인 경우
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int maxv[100001];
//vector<int> arr;
///*
//	10 -4 3  1  5  6 -35 12 21 -1 
//
//	10  6 9 10 15 21 -14 12 33 32
//*/
//
//int sol(vector<int> arr)
//{
//	int len = arr.size();
//
//	maxv[0] = arr[0];
//
//	for (int i = 1; i < len; i++)
//	{
//		maxv[i] = max(arr[i], arr[i] + maxv[i - 1]);
//	}
//
//	int max = -1000000000;
//	for (int i = 0; i < len; i++)
//	{
//		if (maxv[i] > max)
//			max = maxv[i];
//	}
//
//	return max;
//}
//
//int main()
//{
//	int num;
//	cin >> num;
//	int temp;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> temp;
//		arr.push_back(temp);
//	}
//
//	cout << sol(arr);
//
//	return 0;
//}
//
///*
//
//8
//10 20 30 40 50 60 -2000 2100
//
//*/