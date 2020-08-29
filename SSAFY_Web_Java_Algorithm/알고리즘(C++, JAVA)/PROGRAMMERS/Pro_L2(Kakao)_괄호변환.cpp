///* 15:23
//
//1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
//2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
//3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
//  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
//4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
//  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
//  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
//  4-3. ')'를 다시 붙입니다. 
//  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
//  4-5. 생성된 문자열을 반환합니다.
//
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string divide(string str) {
//
//	if (str.length() == 0)
//		return "";
//
//	string result = "";
//
//	int cnt = 0;
//	string pre, post;
//	int i;
//	bool isCorrect = true;
//
//	for (i = 0; i < str.length(); i++) {
//		if (str[i] == '(')
//			cnt++;
//		else
//			cnt--;
//		if (cnt == 0) {
//			pre = str.substr(0, i + 1);
//			break;
//		}
//		else if (cnt < 0)
//			isCorrect = false;
//	}
//
//	post = str.substr(i+1, -1);
//
//	if (isCorrect) {
//		return pre + divide(post);
//	}
//	else {
//		result += "(";
//		result += divide(post);
//		result += ")";
//		int len = pre.length();
//		pre = pre.substr(1, len - 2);
//		for (int i = 0; i < pre.length(); i++)
//		{
//			if (pre[i] == '(')
//				result += ')';
//			else
//				result += '(';
//		}
//	}
//
//	return result;
//}
//string solution(string p) {
//	string answer = "";
//
//	if (p.length() == 0)
//		return answer;
//
//	answer = divide(p);
//
//	return answer;
//}
//int main()
//{
//	string p = "()))((()";
//	cout << solution(p) << endl;
//	
//	return 0;
//}