//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m;
//vector<bool> visit;
//vector<bool> check;
//vector<int> v;
//void dfs(int idx) {
//	if (v.size() == m) {
//		for (int i = 0; i < m; i++)
//			printf("%d ", v[i]);
//		printf("\n");
//		return;
//	}
//
//	for (int i = idx+1; i <= n; i++) {
//		if (!visit[i]) {
//			visit[i] = true;
//			v.push_back(i);
//			dfs(i);
//
//			visit[i] = false; 
//			v.pop_back();
//		}
//		
//	}
//}
//
//int main(void) {
//	cin >> n >> m;
//	visit = vector<bool>(n + 1, false);
//
//	dfs(0);
//}
