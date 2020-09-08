#include <iostream>
#include <string>
#include <vector>

using namespace std;
char alpha[] = { '0','1','2','3','4','5','6','7','8','9','A','B', 'C','D','E','F' };
string solution(int n, int t, int m, int p) {
	string answer = "";

	int counting = t * m + p;

	int N = 0;
	int cnt = 0;
	while(true){
		

		int num = N;
		string str = "";

		while (num != 0)
		{
			int rest = num % n;
			num = num / n;
			str = alpha[rest] + str;
		}

		for (int i = 0; i < str.length(); i++) {
			if ((cnt % m) == p-1) {
				answer += str[i];
				if (answer.length() == t)
					break;
			}
			cnt++;
		}

		if (str == "") {
			if ((cnt % m) == p-1) {
				answer += "0";
			}
			cnt++;
		}

		if (answer.length() == t)
			break;

		N++;
	}


	return answer;
}
int main()
{
	int n = 16;
	int t = 16;
	int m = 2;
	int p = 2;
	cout << solution(n, t, m, p) << endl;

	return 0;
}