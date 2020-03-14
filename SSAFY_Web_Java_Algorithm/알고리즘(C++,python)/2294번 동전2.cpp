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
//vector<int> coin;
//int cnt[100001];
//
//int sol()
//{
//	int answer = 0;
//	int min;
//
//	for (int i = 1; i <= target; i++)
//	{
//		if (cnt[i])
//			continue;
//		vector<int> temp;
//		min = 100001;
//		for (int j = 0; j < num; j++)
//		{
//			if (i - coin[j] < 0 || !cnt[i-coin[j]] || !cnt[coin[j]])
//				break;
//			/*
//			3	4
//			3
//			5
//			7
//			*/
//			// i = 4 -> minsum[1] + minsum[3] = 0+1
//			if (min > cnt[i - coin[j]] + cnt[coin[j]])
//				min = cnt[i - coin[j]] + cnt[coin[j]];
//		}
//
//		if(min != 100001)
//			cnt[i] = min;
//	}
//
//	answer = cnt[target];
//	return answer == 0 ? -1 : answer;
//}
//int main()
//{
//	//while (1)
//	{
//		cin >> num >> target;
//		int temp;
//
//		for (int i = 0; i < num; i++)
//		{
//			cin >> temp;
//			coin.push_back(temp);
//			cnt[temp] = 1;
//		}
//		sort(coin.begin(), coin.end());
//		cout << sol();
//	}
//	return 0;
//}
