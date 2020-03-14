//#include <vector>
//#include <iostream>
//#include <string>
//using namespace std;
//
//// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
//
//int temp;
//int dir[4][2];
//int map[101][101];
//int visit[101][101];
//int maxy, maxx;
//
//void dfs(int y, int x, int num)
//{
//	if (visit[y][x] || x < 0 || y < 0 || x >= maxx || y >= maxy)
//		return;
//
//	if (map[y][x] != num)
//		return;
//
//	visit[y][x] = true;
//	temp++;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dir[i][0];
//		int ny = y + dir[i][1];
//		dfs(ny, nx, num);
//	}
//}
//
//vector<int> solution(int m, int n, vector<vector<int>> picture) {
//
//	temp = 0;
//	dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//	map[101][101] = { 0, };
//	visit[101][101] = { 0, };
//
//	maxx = n;
//	maxy = m;
//
//	//picture = {{0,0,0,0},{1,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,0,0},{0,0,10}};
//
//	for (int i = 0; i < picture.size(); i++)
//	{
//		for (int j = 0; j < picture[i].size(); j++)
//		{
//			map[i][j] = picture[i][j];
//		}
//	}
//
//	int number;
//	vector<int> area;
//	for (int i = 0; i < m; i++) // y값
//	{
//		for (int j = 0; j < n; j++) // x값
//		{
//			if (!visit[i][j] && map[i][j])
//			{
//				temp = 0;
//				number = map[i][j];
//				dfs(i, j, number);
//				//if(temp != 0)
//				area.push_back(temp);
//			}
//		}
//	}
//
//
//	int max = 0;
//	for (int i = 0; i < area.size(); i++)
//	{
//		if (max < area[i])
//		{
//			max = area[i];
//		}
//	}
//
//
//	vector<int> answer(2);
//	answer[0] = area.size();
//	answer[1] = max;
//
//	return answer;
//}
//
//int main()
//{
//	int m = 13;
//	int n = 18;
//	vector<vector<int>> temp = { {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
//								 {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
//								 {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
//								 {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
//								 {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
//								 {0,1,1,1,1,2,1,1,1,1,2,1,1,1,1,0},
//								 {0,1,1,1,2,1,2,1,1,2,1,2,1,1,1,0},
//								 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
//								 {0,1,3,3,3,1,1,1,1,1,1,3,3,3,1,0},
//								 {0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,0},
//								 {0,0,1,1,1,1,1,2,2,1,1,1,1,1,0,0},
//								 {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
//								 {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0} };
//	//6 11
//
//	vector<int> a = solution(m, n, temp);
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << endl;
//	}
//
//
//
//	return 0;
//}