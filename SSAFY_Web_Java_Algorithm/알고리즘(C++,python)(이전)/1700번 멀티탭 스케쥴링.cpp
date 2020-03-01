//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//
//int hole;
//int num;
//vector<int> kind;
//int priority[101];
//
//int sol()
//{
//	if (hole >= num)
//		return 0;
//
//	for (int i = 0; i < hole; i++)
//		priority[i] = kind[i];
//
//	bool flag;
//	int max;
//	int cnt = 0;
//	for (int i = hole; i < kind.size(); i++)
//	{
//		max = -1;
//		flag = false;
//
//		for (int j = 0; j < hole; j++)
//		{
//			if (priority[j] == kind[i])
//			{
//				flag = true;
//				break;
//			}
//		}
//		if (!flag)
//		{
//			int idx = -1;
//			bool flag2;
//			for (int j = 0; j < hole; j++)
//			{
//				flag2 = false;
//				for (int k = i + 1; k < kind.size(); k++)
//				{
//					if (priority[j] == kind[k])
//					{
//						flag2 = true;
//						if (max < k)
//						{
//							max = k;
//							idx = j;
//						}
//						break;
//					}
//				}
//				if (!flag2)
//				{
//					max = num;
//					idx = j;
//				}
//			}
//			priority[idx] = kind[i];
//			cnt++;
//		}
//	}
//
//
//	return cnt;
//}
//
//int main()
//{
//	cin >> hole >> num;
//	int temp;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> temp;
//		kind.push_back(temp);
//	}
//
//	cout <<sol();
//
//	return 0;
//}
