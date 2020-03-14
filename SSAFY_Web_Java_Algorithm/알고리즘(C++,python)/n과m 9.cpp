//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//int n, m;
//vector<bool> visit;
//vector<int> v;
//vector<int> num;
//set<string> Visit;
//
//bool Duplicate()
//{
//	string Temp = "";
//	for (int i = 0; i < v.size(); i++)
//	{
//		char A = v[i] + '0';
//		Temp = Temp + A;
//	}
//
//	if (Visit.find(Temp) == Visit.end())
//	{
//		Visit.insert(Temp);
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//void dfs() {
//	if (v.size() == m) {
//
//		if (Duplicate() == false)
//		{
//			for (int i = 0; i < m; i++)
//				printf("%d ", v[i]);
//			printf("\n");
//		}
//
//		return;
//	}
//
//	for (int i = 0; i < num.size(); i++) {
//
//		if (!visit[i])
//		{
//			v.push_back(num[i]);
//			visit[i] = true;
//			dfs();
//			visit[i] = false;
//			v.pop_back();
//		}
//	}
//}
//
//int main(void) {
//	cin >> n >> m;
//	num = { 9,7,9,1 };
//	sort(num.begin(), num.end());
//
//	visit = vector<bool>(num.size() + 1, false);
//
//	dfs();
//}
