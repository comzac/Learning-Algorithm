//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int a, b;
//	vector<vector<int>> people;
//	for (int i = 0; i < 4; i++)
//	{
//		vector<int> temp;
//		cin >> a >> b;
//		temp.push_back(a);
//		temp.push_back(b);
//		people.push_back(temp);
//
//	}
//
//	int rest = 0;
//	int temp;
//	for (auto elem : people)
//	{
//		temp = elem[1] - elem[0] + rest;
//		if (rest < temp)
//		{
//			rest = temp;
//		}
//	}
//
//	cout << rest;
//
//
//	return 0;
//}