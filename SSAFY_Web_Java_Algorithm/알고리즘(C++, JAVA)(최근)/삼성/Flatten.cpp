//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	for (int t = 1; t <= 10; t++)
//	{
//		vector<int> v;
//		int min;
//		int max;
//		int minidx;
//		int maxidx;
//
//		int cnt;
//		cin >> cnt;
//
//		int temp;
//		for (int n = 0; n < 100; n++)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//
//		for (int i = 0; i < cnt; i++)
//		{
//			min = *min_element(v.begin(), v.end());
//			max = *max_element(v.begin(), v.end());
//			minidx = min_element(v.begin(), v.end()) - v.begin();
//			maxidx = max_element(v.begin(), v.end()) - v.begin();
//			v[minidx]++;
//			v[maxidx]--;
//
//		}
//		min = *min_element(v.begin(), v.end());
//		max = *max_element(v.begin(), v.end());
//		cout << "#" << t << " " << max - min << endl;
//	}
//
//	
//
//	return 0;
//}
