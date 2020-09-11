/* 2034~2100
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> alphaMap;
	string alpha = "A";

	for (int i = 0; i < 26; i++)
	{
		alphaMap[alpha] = i + 1;
		alpha = alpha[0] + 1;
	}

	int addCharMaxLen = 1;
	int lastNum = 26;
	for (int i = 0; i < msg.length(); i++)
	{
		int len = addCharMaxLen;

		while (len > 0)
		{
			string target = msg.substr(i, len);
			
			if (alphaMap[target] != 0) {
				answer.push_back(alphaMap[target]);
				string addAlpha;
				int adjustLen = i + len;
				if (i + len >= msg.length())
					adjustLen = msg.length() - i;
				addAlpha = target + msg[adjustLen];
				alphaMap[addAlpha] = ++lastNum;
				if (addCharMaxLen < addAlpha.length())
					addCharMaxLen = addAlpha.length();

				i = i + len - 1;
				break;
			}

			len--;

		}
	}




	return answer;
}

int main() {


	string msg = "ABABABABABABABAB";

	vector<int> result = solution(msg);

	for (auto a : result)
		cout << a << endl;

	return 0;
}