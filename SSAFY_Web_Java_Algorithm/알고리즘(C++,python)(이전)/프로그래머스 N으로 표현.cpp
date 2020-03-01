//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <unordered_set>
//using namespace std;
//
//int solution(int N, int number) {
//	int answer = 0;
//	unordered_set<int> nset[8];
//
//	int base = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		base = base * 10 + 1;
//		nset[i].insert(base*N);
//	}
//
//	for (int i = 1; i < 8; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (i + j >= 8)
//				return -1;
//			for (auto a : nset[i - 1])
//			{
//				for (auto b : nset[j]) // 0,0 1,0 1,1 
//				{
//					nset[i+j].insert(a + b);
//					nset[i+j].insert(a - b);
//					nset[i+j].insert(a * b);
//
//					if (b != 0)
//					{
//						nset[i+j].insert(a / b);
//					}
//
//				}
//			}
//			if (nset[i + j].count(number) > 0)
//			{
//				return i + j + 1;
//			}
//		}
//	}
//
//	return answer;
//}
//int main()
//{
//	int n = 5;
//	int num = 12;
//
//	cout << solution(n, num) << endl;
//
//	return 0;
//}
