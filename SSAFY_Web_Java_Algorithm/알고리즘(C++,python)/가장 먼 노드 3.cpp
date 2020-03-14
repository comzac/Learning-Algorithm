//#include <vector>
//#include <queue>
//#include <utility>          //pair
//#include <functional>       //greater
//#include <algorithm>        //sort
//#include <iostream>
//
//using namespace std;
//
//bool DescendingOrder(const int a, const int b) {
//	return a > b;
//}
//
//int solution(int n, vector<vector<int>> edge) {
//	int answer = 0;
//	vector<int> min_dis(n, 0);
//	vector<bool> visited(n, false);
//	vector<vector<bool>> graph(n, vector<bool>(n, false));
//	for (auto vertex : edge) {
//		graph[vertex[0] - 1][vertex[1] - 1] = true;
//		graph[vertex[1] - 1][vertex[0] - 1] = true;
//	}
//
//	queue<pair<int, int>> q;
//	for (int i = 0; i < n; i++) {      //1번 노드의 연결된 노드들을 큐안에 넣음(초기값 넣어주기)
//		if (graph[0][i])
//		{
//			q.push(make_pair(i, 1));     //pair (node, cnt)
//			visited[0] = true;
//			visited[i] = true;
//			min_dis[i] = 1;
//		}
//	}
//
//	while (!q.empty()) {      //BFS
//		pair<int, int> temp = q.front();
//		q.pop();
//		for (int i = 0; i < n; i++) {
//			if (graph[temp.first][i] && !visited[i]) {
//				visited[i] = true;
//				min_dis[i] = 1 + temp.second;
//				q.push(make_pair(i, min_dis[i]));
//			}
//		}
//	}
//
//	sort(min_dis.begin(), min_dis.end(), DescendingOrder);
//	//sort(min_dis.begin(), min_dis.end(),greater<int>);    #<functional>
//	int max = min_dis.front();
//	for (auto a : min_dis) {
//		if (a == max) {
//			answer++;
//		}
//		else {
//			break;
//		}
//	}
//
//	return answer;
//}
//int main()
//{
//
//	int n = 6;
//	vector<vector<int>> v = { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
//	cout << solution(n, v) << endl;
//
//}