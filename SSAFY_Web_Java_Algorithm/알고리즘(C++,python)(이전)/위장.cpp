//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//
//using namespace std;
//
//
//int solution(vector<vector<string>> clothes) {
//	int answer = 1;
//	map<string, int> check;
//
//	for (int i = 0; i < clothes.size(); i++)
//	{
//		if (check.find(clothes[i][1]) != check.end())
//		{
//			check[clothes[i][1]]++;
//		}
//		else
//			check.insert(make_pair(clothes[i][1], 1));
//	}
//
//	for (auto elem : check)
//	{
//		answer *= elem.second+1;
//	}
//
//	return answer-1;
//}
//
//
//int main()
//{
//	vector<string> contents;
//	vector<vector<string>> clothes;
//
//	contents.push_back("A");
//	contents.push_back("hat");
//
//	clothes.push_back(contents);
//	contents.clear();
//
//	contents.push_back("B");
//	contents.push_back("hat");
//
//	clothes.push_back(contents);
//	contents.clear();
//
//	contents.push_back("C");
//	contents.push_back("face");
//
//	clothes.push_back(contents);
//	contents.clear();
//
//
//	 cout << solution(clothes);
//
//	return 0;
//
//}