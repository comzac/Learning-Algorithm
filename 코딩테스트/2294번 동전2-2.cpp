//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
///*
//동전의 종류는 같을 수 있다.
//동전의 횟수는 제한없다
//최소회수로 만족하는 걸 찾아라
//안될시에 -1 출력
//사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
//*/
//int num;
//int target;
//int coin[101];
//int cnt[100001];
//
//int sol()
//{
//	int answer = 0;
//
//	for (int i = 1; i <= target; i++)
//		cnt[i] = 100001;
//	cnt[0] = 0;
//
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = coin[i]; j <= target; j++)
//		{
//			cnt[j] = min(cnt[j], cnt[j - coin[i]] + 1);
//		}
//	}
//	if (cnt[target] == 100001) cnt[target] = -1;
//
//	return cnt[target];
//}
//int main()
//{
//	//while (1)
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
