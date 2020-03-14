//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//vector<bool> visit;
//vector<int> v;
//vector<int> num;
//void dfs() {
//	if (v.size() == m) {
//		for (int i = 0; i < m; i++)
//			printf("%d ", v[i]);
//		printf("\n");
//		return;
//	}
//
//	for (int i = 0; i < num.size(); i++) {
//
//		v.push_back(num[i]);
//		dfs();
//		v.pop_back();
//
//	}
//}
//
//int main(void) {
//	cin >> n >> m;
//	num = { 9,8,7,1 };
//	visit = vector<bool>(num.size() + 1, false);
//
//	sort(num.begin(), num.end());
//	dfs();
//}
