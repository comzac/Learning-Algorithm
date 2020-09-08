//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//struct temp {
//
//	bool operator() (const string& a, const string& b)const {
//		if (a.length() == b.length())
//			return a < b;
//		return a.length() > b.length();
//	}
//};
//
//
//int main()
//{
//	map<string, string, temp> test;
//	test.insert(make_pair("za", "A"));
//	test.insert(make_pair("abc", "d"));
//	test.insert(make_pair("abc", "c"));
//
//
//	map<string, string> ::iterator it;
//	it = test.begin();
//
//
//	for (; it != test.end(); it++) {
//		cout << it->first << endl;
//	}
//
//	return 0;
//}