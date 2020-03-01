//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//bool recurse(string a, string b, int aLen, int bLen, int k)
//{
//	if (a[k] != b[k])
//	{
//		return a[k] > b[k];
//	}
//	else
//	{
//		
//		if (aLen == k + 1 || bLen == k + 1)
//		{
//			return a[aLen - 1] > b[bLen - 1];
//		}
//
//		return recurse(a, b, aLen, bLen, k + 1);
//	}
//}
//
//struct MyStruct
//{
//	bool operator()(int a, int b)
//	{
//		string A = to_string(a);
//		string B = to_string(b);
//		int Alen = A.length();
//		int Blen = B.length();	
//		int k = 0;
//		return recurse(A, B, Alen, Blen, k);	
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
//	if (stoi(answer) == 0)
//		return "0";
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> array = {34,3435};
//	
//	vector<int> array2 = { 3,30,0,34,5,0};
//
//	cout << solution(array) << endl;
//	cout << solution(array2) << endl;
//
//
//	return 0;
//}