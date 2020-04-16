///*2015~2035 20M
//	식재료의 수 N은 4이상 16이하의 짝수이다.
//	식재료들을 각각 N / 2개씩 나누어 두 개의 요리
//	1) 식재료 1을 식재료 2와 같이 요리했을 때 발생하는 시너지 S12는 5이다.
//	2) 식재료 2를 식재료 1과 같이 요리했을 때 발생하는 시너지 S21는 4이다.
//
//	만약 음식이 6개면 3개/3개로 나뉘고 1,2,3/4,5,6 이라고 가정하면
//	12, 21, 13, 31, 23, 32 경우를 더해야 한다.
//	풀이 :
//	넥퍼를 활용하여 음식 종류의 반을 나누는 경우의 수를 확보한 뒤,
//	각각의 집합마다 모든 경우의 수를 더해 차를 구한다.
//	이후, 최소값 비교를 통해 결과를 낸다.
//
//*/
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N;
//vector<int> np;
//vector<int> A, B;
//int table[16][16];
//int minVal;
//void input();
//int foodSum(vector<int> food);
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		minVal = 999999999;
//
//		do {
//			for (int i = 0; i < N; i++) // 조합 나누기,
//			{
//				if (np[i] == 0)
//					A.push_back(i);
//				else
//					B.push_back(i);
//			}
//			int a = foodSum(A);
//			int b = foodSum(B);
//
//			if (abs(a - b) < minVal)
//				minVal = abs(a - b);
//
//			A.clear();
//			B.clear();
//		} while (next_permutation(np.begin(), np.end()));
//
//		cout << "#" << t << " " << minVal << endl;
//		np.clear();
//	}
//	return 0;
//}
//
//void input()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> table[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (i < N / 2)
//			np.push_back(0);
//		else
//			np.push_back(1);
//	}
//}
//
//int foodSum(vector<int> food)
//{
//	int sum = 0;
//	for (int i = 0; i < N / 2; i++)
//	{
//		for (int j = 0; j < N / 2; j++)
//		{
//			if (i == j)
//				continue;
//			sum += table[food[i]][food[j]];
//		}
//	}
//	return sum;
//}
