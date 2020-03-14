//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int chu[1001];
//int check[1001];
//
//int main()
//{
//	int num;
//	cin >> num;
//	int temp;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> temp;
//		chu[i] = temp;
//	}
//
//	sort(chu, chu + num);
//
//	int start = 1;
//	/*
//	 5 4 2 1
//	 8  
//	*/
//	int idx;
//	int tempstart;
//	while (1)
//	{
//		if (start == 4)
//		{
//			cout << "얍";
//		}
//		tempstart = start;
//		while (1)
//		{
//			for (idx = 0; idx < num; idx++)
//			{
//				if (check[idx])
//					continue;
//				if (chu[idx] >= tempstart)
//				{
//					/*
//						지금 현재 start값을 하나씩 올리면서 배열에서 더 높거나 같은숫자를
//						만나면 빼는 처리를 해주는데 같은 숫자를 활용할 수 없으니깐
//						check를 넣어 줬는데 그러고보니 1 1 6 같은 경우,
//						6 보다 작은 수일 경우 1로 계속 빼지겠네 check랑 상관없이
//						이게 문제
//					
//					*/
//					break;
//				}
//			}
//			tempstart -= chu[idx];
//			check[idx] = true;
//			if (tempstart < 0)
//			{
//				cout << start;
//				return 0;
//			}
//			if (tempstart == 0)
//				break;
//		}
//
//		start++;
//		for (int i = 0; i < num; i++)
//		{
//			check[i] = false;
//		}
//	}
//	
//	
//
//	return 0;
//}
