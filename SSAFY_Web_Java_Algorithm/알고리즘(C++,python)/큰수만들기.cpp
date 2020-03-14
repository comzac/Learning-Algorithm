//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
////string solution(string number, int k) {
////	string answer = "";
////	int stringLength = number.length();
////	int length = stringLength - k;
////	int start = 0;
////
////	char max = '0';
////
////
////	for (int i = 0; i <= k; i++)
////	{
////		if (number[i] > max)
////		{
////			max = number[i];
////			start = i;
////		}
////	}
////	answer += max;
////
////	while (1)
////	{
////		length--;
////		if (length == 0)
////			break;
////		max = '0';
////		for (int i = start + 1; i <= stringLength - length; i++)
////		{
////			if (number[i] > max)
////			{
////				max = number[i];
////				start = i;
////			}
////		}
////		answer += max;	
////	}
////
////	return answer;
////}
//
//string solution(string number, int k) {
//	string answer = "";
//	answer = number.substr(k);
//	for (int i = k - 1; i >= 0; i--) {
//		int j = 0;
//		do {
//			if (number[i] >= answer[j]) {
//				char temp = answer[j];
//				answer[j] = number[i];
//				number[i] = temp;
//				j++;
//			}
//			else {
//				break;
//			}
//		} while (1);
//	}
//
//
//
//	return answer;
//}
//
//int main()
//{
//	string  s = "1854879";
//	int k = 2;
//	//85879
//
//	cout << solution(s,k) ;
//
//
//	//cout << solution(s) << endl;
//}