//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
///*
//뭐가 문제인지를 모르겠는뎅 ㅜㅜㅜ
//*/
//using namespace std;
//
//string num;
//
//void sol()
//{
//	//if (num.find('0') == string::npos)
//	//{
//	//	cout << "-1";
//	//	return;
//	//}
//
//	long long sum = 0;
//	bool zerocheck = false;
//	vector<int> temp;
//	for (int i = 0; i < num.length(); i++)
//	{
//		int digit = num[i] - '0';
//		if (digit == 0)
//			zerocheck = true;
//		sum += digit;
//		//temp.push_back(digit);
//	}
//
//	if (sum % 3 != 0 || !zerocheck)
//	{
//		cout << "-1";
//		return;
//	}
//
//	sort(num.begin(), num.end());
//	long long ten = 1;
//	long long answer = 0;
//	for (int i = 0; i < num.size(); i++)
//	{
//		answer += ten * (num[i]-'0');
//		ten *= 10;
//	}
//
//	cout << answer;
//	return;
//}
//
//int main()
//{
//	cin >> num;
//
//	sol();
//
//	return 0;
//}
