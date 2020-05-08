//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//
//vector<string> userId;
//vector<string> banId;
//int k;
//vector<string> temp;
//bool visit[8];
//set<string> result;
//void dfs(int cnt) {
//
//	if (cnt == k)
//	{
//		// ºñ±³
//		int count = 0;
//		bool isChecked[8];
//		memset(isChecked, false, 8);
//		bool isCheck;
//		for (int i = 0; i < temp.size(); i++)
//		{
//			for (int j = 0; j < k; j++)
//			{
//				if (isChecked[j])
//					continue;
//
//				int len = banId[j].length();
//				if (len != temp[i].length())
//					continue;
//				isCheck = true;
//				for (int k = 0; k < len; k++)
//				{
//					if (temp[i][k] != banId[j][k])
//					{
//						if (banId[j][k] == '*')
//							continue;
//						else
//						{
//							isCheck = false;
//							break;
//						}
//					}
//				}
//				if (isCheck)
//				{
//					count++;
//					isChecked[j] = true;
//					break;
//				}
//			}
//		}
//		if (!isCheck)
//			return;
//		if (count == k)
//		{
//			string str = "";
//			vector<string> ttemp = temp;
//			sort(ttemp.begin(), ttemp.end());
//
//			for (int i = 0; i < ttemp.size(); i++)
//				str += ttemp[i];
//
//			result.insert(str);
//		}
//		return;
//	}
//
//	for (int i = 0; i < userId.size(); i++)
//	{
//		if (visit[i])
//			continue;
//		visit[i] = true;
//		temp.push_back(userId[i]);
//		dfs(cnt + 1);
//		temp.pop_back();
//		visit[i] = false;
//	}
//
//}
//int solution(vector<string> user_id, vector<string> banned_id) {
//	int answer = 0;
//	userId = user_id;
//	banId = banned_id;
//	k = banned_id.size();
//	dfs(0);
//	
//	return answer = result.size();
//}
//int main()
//{
//	vector<string> ui = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
//	vector<string> bi = { "fr*d*", "*rodo", "******", "******" };
//	cout << solution(ui, bi);
//	return 0;
//}