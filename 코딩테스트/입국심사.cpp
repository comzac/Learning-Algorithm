//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//unsigned long long solution(int n, vector<int> times) {
//	unsigned long long answer = 0;
//
//	sort(times.begin(), times.end());
//
//	unsigned long long max = times[times.size() - 1] * n;
//	unsigned long long min = 1;
//	unsigned long long total = 0;
//	unsigned long long mid = 0;
//
//	while (min <= max)
//	{
//		 mid = (max + min) / 2;
//
//		 total = 0;
//
//		for (int i = 0; i < times.size(); i++)
//			total += mid / times[i];
//
//		if (total == n)
//		{
//			min = mid;
//			break;
//		}
//		else if (total > n)
//			max = mid - 1;
//		else
//			min = mid + 1;
//	}
//
//	while (1)
//	{
//		total = 0;
//		for (int i = 0; i < times.size(); i++)
//		{
//			total += min / times[i];
//		}
//
//		if (total < n)
//		{
//
//			answer = min + 1;
//			break;
//		}
//		min--;
//	}
//	
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> v = {1,1,1,10};
//	cout << solution(4,v ) << endl;
//
//
//	return 0;
//}