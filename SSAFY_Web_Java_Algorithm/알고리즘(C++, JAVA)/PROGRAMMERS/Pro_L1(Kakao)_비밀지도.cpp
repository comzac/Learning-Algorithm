#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back(arr1[i] | arr2[i]);
	}
	for (int i = 0; i < n; i++) {
		string str = "";
		int num = temp[i];
		int cnt = n;
		while (cnt != 0) {
			if ((num & (1<<(cnt-1))) == 0)
				str += " ";
			else
				str += "#";
			cnt--;
		}

		answer.push_back(str);
	}


	return answer;
}
int main()
{
	int n = 5;
	vector<int> arr1 = { 9,20,28,18,11 };
	vector<int> arr2 = { 30,1,21,17,28 };

	vector<string> result = solution(n, arr1, arr2);
	for (auto a : result)
	{
		cout << a << endl;
	}

	string test = "";
	test = " " + test;
	cout << test << "a" << endl;
	return 0;
}