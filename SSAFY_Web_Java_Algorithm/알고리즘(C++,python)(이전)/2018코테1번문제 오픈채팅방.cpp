//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//
//using namespace std;
//
//vector<string> solution(vector<string> record) {
//	vector<string> answer;
//	map<string, string> idinf;
//	vector<vector<string>> inf;
//	int curidx;
//	int stridx;
//
//	for (int i = 0; i < record.size(); i++)
//	{
//		curidx = 0;
//		int j;
//		vector<string> temp;
//
//		for (j = 0; j < record[i].size(); j++)
//		{
//			if (record[i][j] == ' ')
//			{
//				temp.push_back(record[i].substr(curidx, j-curidx));
//				curidx = j+1;
//			}	
//		}
//		temp.push_back(record[i].substr(curidx, j));
//		inf.push_back(temp);
//	}
//
//	for (int i = 0; i < inf.size(); i++)
//	{
//		if(inf[i][0][0] != 'L')
//			idinf[inf[i][1]] = inf[i][2];	
//	}
//
//	for (int i = 0; i < inf.size(); i++)
//	{
//		if (inf[i][0][0] == 'E')
//		{
//			answer.push_back(idinf[inf[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
//		}
//		else if (inf[i][0][0] == 'L')
//		{
//			answer.push_back(idinf[inf[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
//		}
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector<string> str = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
//	
//	for (int i = 0; i < solution(str).size(); i++)
//	{
//		cout << solution(str)[i] << endl;
//	}
//}