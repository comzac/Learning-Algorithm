//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//
//	vector<int> answer;
//	vector<int> temp;
//
//	int i;
//	int j;
//	int k;
//
//	for (int n = 0; n < commands.size(); n++)
//	{
//		i = commands[n][0];
//		j = commands[n][1];
//		k = commands[n][2];
//
//		for (int m = i-1; m < j; m++)
//		{
//			temp.push_back(array[m]);
//		}
//
//		sort(temp.begin(), temp.end());
//
//		answer.push_back(temp[k - 1]);
//		temp.clear();
//	}
//	return answer;
//}
//
//int main()
//{
//	vector<int> array = { 1,5,2,6,3,7,4 };
//	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
//	//solution(array, commands);
//	for (int i = 0; i < solution(array, commands).size(); i++)
//	{
//		cout << solution(array, commands)[i] << endl;
//	}
//
//
//	return 0;
//}