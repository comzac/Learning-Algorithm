//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//bool check(string a, string b)
//{
//	if (a > b)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//struct MyStruct
//{
//	bool operator()(int a, int b)
//	{
//		string A = to_string(a);
//		string B = to_string(b);
//		string C = A + B;
//		string D = B + A;
//		return check(C, D);
//	}
//};
//
//
//string solution(vector<int> numbers) {
//	string answer = "";
//
//	sort(numbers.begin(), numbers.end(), MyStruct());
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		answer += to_string(numbers[i]);
//	}
//
//	if (answer[0] == '0')
//		answer = "0";
//
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> array = { 0,1,0,0 };
//
//	vector<int> array2 = { 3,30,0,34,5,0 };
//
//	cout << solution(array) << endl;
//	cout << solution(array2) << endl;
//
//
//	return 0;
//}