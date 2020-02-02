/*2010~2100
	1. 끝점을 기준으로 회전,
	2. 세대수 최대 10
	3. 100*100 좌표
	4. 방향이 반시계방향으로 해놓은 이유가 있었음(핵심)

	풀이방식

	(핵심)다음세대로 넘어갈때 직전세대의 방향지표의 끝부터 반시계방향으로 이동을 하면된다.
	세대를 거듭할 때 마다, vector에 방향정보를 담자
	ex1) 
	3
	3 3 0 1
	4 2 1 3
	4 2 2 1
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int dc[101][101];
int dir[4][2] = { {0,1},{-1, 0}, {0,-1},{1,0} }; // 90도 회전시 +3%4; -90도는 +1%4;
int g;
void dragon(int y, int x, int cur, vector<int>& list)
{
	dc[y][x] = true;
	int len;
	int ny, nx;
	int i;
	ny = y + dir[list[0]][0];
	nx = x + dir[list[0]][1];
	dc[ny][nx] = true;  // 1처리 중복되도 상관없다.(겹쳐도 된다는 조건)
	int cnt = cur;
	while (cnt < g)
	{
		len = list.size() - 1;

		for (i = len; i >= 0; i--)
		{
			int rotate = (list[i] + 1) % 4;

			while (rotate > 4)
				rotate %= 4;

			ny += dir[rotate][0];
			nx += dir[rotate][1];

			dc[ny][nx] = true;
			list.push_back(rotate);
		}
		cnt++;
	}
}

int searchSquare()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (dc[i][j] == 1 &&
				dc[i][j + 1] == 1 &&
				dc[i + 1][j] == 1 &&
				dc[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d;
		cin >> x >> y >> d >> g;
		vector<int> dirList;
		dirList.push_back(d);
		dragon(y, x, 0, dirList);
	}

	//커브확인 함수
	cout << searchSquare();
	return 0;
}
