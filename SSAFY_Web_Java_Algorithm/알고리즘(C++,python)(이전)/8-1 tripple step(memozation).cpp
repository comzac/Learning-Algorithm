//#include <iostream>
//#include <string>
//
//using namespace std;
//int recurse( int n, int* memo)
//{
//	if (n < 0)
//		return 0;
//	else if (n == 0)
//		return 1;
//	else if (memo[n] > -1)
//	{
//		return memo[n];
//	}
//	else
//	{
//		memo[n] = recurse(n - 1, memo) + recurse(n - 2, memo) + recurse(n - 3, memo);
//		return memo[n];
//	}
//}
//
//int solution(int n)
//{
//	int answer;
//	
//	int* memo = new int[n + 1];
//	memset(memo, -1, sizeof(memo));
//
//	//for (int i = 0; i < n + 1; i++)
//		//memo[i] = -1;
//
//	answer = recurse(n, memo);
//
//	return answer;
//}
//
//
//int main()
//{
//	//어떤 아이가 n개의 계단을 오를때, 1,2,3 계단씩 오를수 있다면 계단을 오르는 방법은 몇가지있을까?
//
//	int n = 60;
//
//	cout << solution(n) << endl;
//
//
//
//
//	return 0;
//
//}