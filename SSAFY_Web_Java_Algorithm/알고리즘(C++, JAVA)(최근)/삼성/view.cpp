//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int t;
//	for (t = 1; t <= 10; t++)
//	{
//		int n;
//		cin >> n;
//
//		vector<int> v;
//		int temp;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//
//		int max;
//		int sum = 0;
//		int cnt;
//		for (int i = 2; i < n - 2; i++)
//		{
//			max = 0;
//			cnt = 0;
//			for (int j = i - 2; j <= i + 2; j++)
//			{
//				if (j == i)
//					continue;
//
//				if (v[j] < v[i])
//				{
//					cnt++;
//					if (v[j] > max)
//						max = v[j];
//				}
//			}
//			if (cnt == 4)
//			{
//				sum += v[i] - max;
//			}
//		}
//
//		cout << "#" << t << " " << sum << endl;
//	}
//	
//
//	return 0;
//}
