//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m;
//vector<bool> visit;
//vector<int> v;
//void dfs(int idx, int cnt) {
//	if (cnt == m) {
//		for (int i = 0; i < m; i++)
//			printf("%d ", v[i]);
//		printf("\n");
//		return;
//	}
//
//	for (int i = idx; i <= n; i++) {
//
//		v.push_back(i);
//		dfs(i, cnt+1);
//		v.pop_back();
//	}
//}
//
//int main(void) {
//	cin >> n >> m;
//	visit = vector<bool>(n + 1, false);
//
//	dfs(1, 0);
//}
