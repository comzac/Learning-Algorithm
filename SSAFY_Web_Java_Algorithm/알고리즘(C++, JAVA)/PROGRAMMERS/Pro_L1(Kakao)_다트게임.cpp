#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	int before = 0;
	int num[3] = { 0,0,0 };
	vector<string> number;
	int i;
	for (i = 1; i < dartResult.length(); i++)
	{
		if (!isdigit(dartResult[i - 1]) && isdigit(dartResult[i])) {
			number.push_back(dartResult.substr(before, i - before));
			before = i;
		}
	}
	number.push_back(dartResult.substr(before, i - before));


	for (int j = 0; j < number.size(); j++) {
		string numstr = "";
		int n;
		for (int i = 0; i < number[j].length(); i++) {
			if (isdigit(number[j][i])) {
				numstr += number[j][i];
			}
			else {
				if(i > 0 && isdigit(number[j][i-1]))
					n = stoi(numstr);

				switch (number[j][i])
				{
				case 'S':
					n = pow(n, 1);
					break;
				case 'D':
					n = pow(n, 2);
					break;
				case 'T':
					n = pow(n, 3);
					break;
				case '*':
					if (j > 0) {
						num[j - 1] *= 2;
					}
					n *= 2;
					break;
				case '#':
					n *= -1;
					break;
				}
			}
		}
		num[j] = n;
	}
	for (int i = 0; i < 3; i++)
		answer += num[i];
	return answer;
}
int main()
{
	string dartResult = "1D#2S*3S";
	cout << solution(dartResult) << endl;
	return 0;
}