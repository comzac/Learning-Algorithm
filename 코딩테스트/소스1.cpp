//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> student; //학생이 가리키는 다른 학생 번호
//vector<int> first_student; //첫 번째로 dfs를 시작한 학생 번호
//vector<int> visited; //방문 유무
//
//int dfs(int start, int current, int cnt) {
//
//	if (visited[current]) {
//
//		//첫 번째로 dfs를 시작한 학생이 맞는지, 사이클이 맞는지
//		if (first_student[current] != start)
//			return 0;
//
//		//사이클에 해당되는 학생 수
//		return cnt - visited[current];
//	}
//
//	first_student[current] = start;
//	visited[current] = cnt;
//	return dfs(start, student[current], cnt + 1);
//}
//
//int main() {
//
//	int T;
//	cin >> T;
//
//	int n;
//	for (int testCase = 0; testCase < T; testCase++) {
//
//		scanf("%d", &n);
//
//		student = vector<int>(n + 1, 0);
//		first_student = vector<int>(n + 1, 0);
//		visited = vector<int>(n + 1, 0);
//
//		for (int i = 1; i <= n; i++)
//			scanf("%d", &student[i]);
//
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			if (!visited[i]) {
//				ans += dfs(i, i, 1);
//			}
//		}
//
//		printf("%d\n", n - ans);
//	}
//
//	return 0;
//}
