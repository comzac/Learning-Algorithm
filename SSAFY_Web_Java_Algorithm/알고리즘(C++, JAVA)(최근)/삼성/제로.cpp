//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	int line;
//	for (int i = 0; i < n; i++)
//	{
//		stack<int> s;
//		cin >> line;
//		for (int j = 0; j < line; j++)
//		{
//			int temp;
//			cin >> temp;
//			if (temp != 0)
//				s.push(temp);
//			else
//				s.pop();
//		}
//
//		int sum = 0;
//		while (!s.empty())
//		{
//			sum += s.top();
//			s.pop();
//		}
//		cout << "#" << i + 1 << " " << sum << endl;
//	}
//
//	return 0;
//}
