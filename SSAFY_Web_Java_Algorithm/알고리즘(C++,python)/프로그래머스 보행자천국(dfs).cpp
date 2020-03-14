//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int MOD = 20170805;
//int M;
//int N;
////int check[501][501];
//int cmap[501][501];
//pair<int,int> p[501][501];
//int cnt;
//
//// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
//// DFS 문제로 추정된다
//bool areacheck(int x, int y)
//{
//	if (x >= N || y >= M) // 범위초과의 경우,
//		return true;
//	return false;
//}
//
//void dfs(int x, int y)
//{
//	if (areacheck(x, y)) // 범위 초과의 경우,
//		return;
//
//	//if (check[y][x]) // 방문한 경우,
//		//return;
//
//	if (cmap[y][x] == 1) // 통행금지의 경우,
//		return;
//
//	else if (x == N-1 && y == M-1) // 도착지점인 경우,
//	{
//		cnt++;
//		if (cnt > MOD)
//			cnt %= MOD;
//		return;
//	}
//	
//	else if (cmap[y][x] == 0) // 0번 유형의 경우,
//	{
//		p[y][x + 1] = { y,x }; // 우측
//		dfs(x + 1, y);
//
//		p[y + 1][x] = { y,x }; // 하단
//		dfs(x, y + 1);
//	}
//
//	else if (cmap[y][x] == 2) // 2번 유형의 경우,
//	{
//		if (p[y][x].first == y)
//		{
//			//if (areacheck(x + 1, y))
//				//return;
//			p[y][x + 1] = { y,x };
//			dfs(x + 1, y);
//		}
//		else
//		{
//			//if (areacheck(x, y+1))
//				//return;
//			p[y + 1][x] = { y,x };
//			dfs(x, y + 1);
//		}
//	}	
//}
//int solution(int m, int n, vector<vector<int>> city_map) {
//
//	int answer = 0;
//	M = m; N = n;
//	cnt = 0;
//
//	for (int i = 0; i < 501; i++)
//	{
//		for (int j = 0; j < 501; j++)
//		{
//			//check[i][j] = 0;
//			p[i][j] = { 0,0 };
//		}
//	}
//
//	for (int i = 0; i < city_map.size(); i++)
//	{
//		for (int j = 0; j < city_map[i].size(); j++)
//		{
//			cmap[i][j] = city_map[i][j];
//		}
//	}
//
//	dfs(0, 0);
//	answer = cnt;
//	return answer;
//}
//
//int main()
//{
//	int m, n;
//	m = 3;
//	n = 6;
//	vector<vector<int>> v = { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} };
//	cout << solution(m, n, v) << endl;
//	
//
//
//	return 0;
//}
