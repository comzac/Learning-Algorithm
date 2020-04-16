//#include <iostream>
//#include <string>
//#include <vector>
//#include <math.h>
//using namespace std;
//int sum;
//void solution(vector<int> v)
//{
//	if (v.size() == 1)
//		return;
//	vector<int> temp;
//	for (int i = 0; i < v.size(); i+=2)
//	{
//		sum += abs(v[i] - v[i + 1]);
//		temp.push_back(v[i] > v[i + 1] ? v[i] : v[i + 1]);
//	}
//	solution(temp);
//}
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++)
//	{
//		int n;
//		cin >> n;
//		n = pow(2, n);
//		vector<int> v;
//		for (int j = 0; j < n; j++)
//		{
//			int temp;
//			cin >> temp;
//			v.push_back(temp);
//		}
//		solution(v);
//		cout << "#" << i + 1 << " " << sum << endl;
//		sum = 0;
//	}
//
//
//	return 0;
//}
