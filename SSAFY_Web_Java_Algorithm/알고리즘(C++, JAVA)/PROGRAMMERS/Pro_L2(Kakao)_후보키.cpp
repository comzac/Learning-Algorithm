#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int column;
int row;
string table[20][8];
int check[8];
vector<string> candi;

bool cmp(string a, string b) {
	return a.length() < b.length();
}
bool dup() {
	
	vector<int> candi;
	set<string> s;
	for (int i = 0; i < column; i++)
	{
		if (check[i])
			candi.push_back(i);
	}
	for (int i = 0; i < row; i++) {
		string str = "";
		for (auto a : candi) {
			str += table[i][a] + " ";
		}
		int beforeSize = s.size();
		s.insert(str);
		if (beforeSize == s.size())
			return false;
	}
	return true;
}
void primary(int cidx) {

	if (dup()) {
		
		string temp = "";
		for (int i = 0; i < column; i++) {
			if (check[i])
				temp += to_string(i);
		}
		candi.push_back(temp);
		return;
	}


	for (int i = cidx + 1; i < column; i++) {
		check[i] = true;
		primary(i);
		check[i] = false;
	}

}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	row = relation.size();
	column = relation[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			table[i][j] = relation[i][j];
		}
	}

	for (int i = 0; i < column; i++) {
		check[i] = true;
		primary(i);
		check[i] = false;
	}
	
	sort(candi.begin(), candi.end(), cmp);

	for (int i = 0; i < candi.size(); i++)
	{
		string s = candi[i];

		for (int j = i + 1; j < candi.size(); j++)
		{
			bool isCheck = false;
			for (int k = 0; k < s.length(); k++)
			{
				if (candi[j].find(s[k]) == -1)
				{
					isCheck = true;
					break;
				}
			}
			if (!isCheck)
			{
				candi.erase(candi.begin() + j);
				j--;
			}
		}
	}

	answer = candi.size();

	return answer;
}

int main() {

	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	cout << solution(relation) << endl;


	return 0;
}