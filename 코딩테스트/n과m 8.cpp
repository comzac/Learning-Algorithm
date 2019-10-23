//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//vector<bool> visit;
//vector<int> v;
//vector<int> num;
//void dfs(int idx) {
//	if (v.size() == m) {
//		for (int i = 0; i < m; i++)
//			printf("%d ", v[i]);
//		printf("\n");
//		return;
//	}
//
//	for (int i = idx; i < num.size(); i++) {
//
//		v.push_back(num[i]);
//		dfs(i);
//		v.pop_back();
//
//	}
//}
//
//int main(void) {
//	cin >> n >> m;
//	num = { 9,8,7,1 };
//	sort(num.begin(), num.end());
//
//	visit = vector<bool>(num[num.size()-1] +1, false);
//
//	dfs(0);
//}
