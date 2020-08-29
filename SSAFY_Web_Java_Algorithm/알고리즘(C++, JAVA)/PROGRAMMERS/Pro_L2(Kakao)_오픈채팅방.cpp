//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<string> solution(vector<string> record) {
//	vector<string> answer;
//	map<string, string> nick;
//
//	int before = 0;
//	for (int i = 0; i < record.size(); i++)
//	{
//		vector<string> temp;
//		before = 0;
//		for (int j = 0; j < record[i].length(); j++) {
//			if (record[i][j] == ' ')
//			{
//				string str = record[i].substr(before, j - before);
//				before = j+1;
//				temp.push_back(str);
//			}
//		}
//		temp.push_back(record[i].substr(before));
//		if(temp.size() == 3)
//			nick[temp[1]] = temp[2];
//	}
//
//
//	for (int i = 0; i < record.size(); i++)
//	{
//		vector<string> temp;
//		before = 0;
//		for (int j = 0; j < record[i].length(); j++) {
//			if (record[i][j] == ' ')
//			{
//				string str = record[i].substr(before, j - before);
//				before = j + 1;
//				temp.push_back(str);
//			}
//		}
//		temp.push_back(record[i].substr(before));
//
//		if (temp[0][0] == 'E')
//		{
//			answer.push_back(nick[temp[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
//		}
//		else if (temp[0][0] == 'L')
//		{
//			answer.push_back(nick[temp[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
//		}
//	}
//
//
//	return answer;
//}
//int main()
//{
//	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
//	
//	vector<string> result = solution(record);
//	for (auto a : result) {
//		cout << a << endl;
//	}
//
//	return 0;
//}