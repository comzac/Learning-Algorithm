//
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include <map>
//#include <set>
//
//using namespace std;
//
///*
//vector<vector<int>> 형태로 키조합
//dfs활용하고 인덱스 지정해서 중복 조합 제거
//키조합 벡터를 활용해서 relation string 조합 후
//set 컨테이너에 담아서 중복값 제거시키고
//relation의 크기랑 비교해서 같으면 후보키 ++;
//후보키에 등록이 된 사항들은 제거시켜준다.
//길이가 8이니깐 괜찮을듯?
//*/
//
//vector<vector<int>> comv;
//vector<bool> visit;
//vector<int> v;
//
//int sizeCheck(vector<bool> c)
//{
//	int cnt = 0;
//	for (int i = 0; i < c.size(); i++)
//		if (!c[i])
//			cnt++;
//	return cnt;
//}
//
//void dfs(int idx, int size, int num)
//{
//
//	if (v.size() == num)
//	{
//		comv.push_back(v);
//		return;
//	}
//
//	for (int i = idx; i < size; i++)
//	{
//		if (!visit[i])// && !check[i])
//		{
//			v.push_back(i);
//			visit[i] = true;
//			dfs(i, size, num);
//			visit[i] = false;
//			v.pop_back();
//		}
//	}
//
//}
//
//int solution(vector<vector<string>> relation) {
//	int answer = 0;
//	int comnum = 1;
//	int size = relation[0].size();
//	set<string> s;
//	string temp;
//	bool flag;
//	//check = vector<bool>(size, false);
//	vector<string> key;
//	while (comnum <= size)
//	{
//		visit = vector<bool>(size, false);
//
//		v.clear();
//		comv.clear();
//		dfs(0, size, comnum);
//
//		for (int i = 0; i < comv.size(); i++)
//		{
//
//			for (int j = 0; j < relation.size(); j++)
//			{
//				temp = "";
//				for (int k = 0; k < comv[i].size(); k++)
//				{
//					temp += relation[j][comv[i][k]];
//
//				}
//				s.insert(temp);
//
//			}
//
//			if (s.size() == relation.size())
//			{
//
//				if (key.size() == 2)
//				{
//
//				}
//				// answer++;
//				temp = "";
//				for (int k = 0; k < comv[i].size(); k++)
//				{
//					temp += to_string(comv[i][k]);
//				}
//				flag = true;
//				for (int i = 0; i < key.size(); i++)
//				{
//					if (temp.find(key[i]) <= temp.size())
//						flag = false;
//				}
//				if(key.empty() || flag)
//					key.push_back(temp);
//			}
//			s.clear();
//		}
//		comnum++;
//		
//	}
//
//	answer = key.size();
//	return answer;
//}
//
//int main()
//{
//	vector<vector<string>> re = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
//	cout << solution(re) << endl;
//	string a = "abcde";
//
//	//cout << a.find("g");
//}