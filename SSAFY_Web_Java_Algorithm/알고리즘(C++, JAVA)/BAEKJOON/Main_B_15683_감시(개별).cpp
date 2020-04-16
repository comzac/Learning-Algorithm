/*1400~1530 
	1. cctv의 종류에 따라 검사 방법이 다름
		1) 한방향
		2) 양방향
		3) 직각방향
		4) 세방향
		5) 전 방향
	2. 방향에 있는 칸 전체를 감시할 수 있다 (행 열 주르륵)
	3. 벽은 통과못함
	4. 감시 못하는 부분을 사각지대라 함
	5. 회전이 가능한데 항상 90도 방향이여야 한다. 가로 세로는 회전하면서는 감시못한다는 거 같다.
	6. cctv는 벽은 통과 못해도 cctv는 통과한다.
	0은 빈 칸, 6은 벽, 1~5는 cctv 번호

	방향을 잘 정해서~ 사각지대를 최소화하는 최소 크기를 구해라.

	사무실 최대 크기 8
	다섯가지 cctv의 회전을 고려했을 때 경우의 수는,
	1) 4가지
	2) 2가지
	3) 4가지
	4) 4가지
	5) 1가지

	최대의 경우, 8x8크기에 cctv(1)가 8개인 경우,
	4^8(경우의 수) * 8*8(사무실 순회)
	2^22 => 2^10^2 => 1,000,000 연산
	할만함

	풀이방식
	1. 사무실을 순회하며 0, 6이 아닌 숫자를 발견하면 좌표를 담고 그 숫자에 맞는 함수호출
	2. 모든 경우를 재귀로 탐색하며, 전체 방향을 설정했을 때마다 bool배열의 변화값을 살펴
	   최소값을 비교
	3. 매번 bool 배열을 초기화 해준다. (벽은 이때 고려하지 않고 마지막 출력값에서 빼준다)

	12기준 0도 0, 90도 1, 180도 2, 270도 3
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int room[8][8];
int Y, X;
int numbering;
int pos[8][3];
int kind;
int minVal; // 방 최대개수 이상 설정
int delta[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<vector<int>> angle = { {0},{0,2},{0,1},{3,0,1},{0,1,2,3} }; //초기 12345번 시시티비 각도

void monitor(int kind, int index, int dir, vector<vector<bool>>& v)
{

	for (int i = 0; i < angle[kind-1].size(); i++)
	{
		int y = pos[index][1];
		int x = pos[index][2];

		while (true)
		{
			int ny = y + delta[(angle[kind-1][i] + dir) % 4][0];
			int nx = x + delta[(angle[kind-1][i] + dir) % 4][1];
			
			if (ny >= Y || ny < 0 || nx >= X || nx < 0) //범위초과
				break;
			if (room[ny][nx] == 6) //벽
				break;
			y = ny;
			x = nx;
			if (room[ny][nx] != 0)
				continue;
			v[ny][nx] = true;

		}
	}
	
}
int sumCheck(vector<vector<bool>> v)
{
	int sum = 0;
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
		{
			if (!v[i][j])
				sum++;
		}
	return sum;
}

void check(int index, int dir, vector<vector<bool>> v)
{
	if (index >= numbering)
	{
		// 최소값 비교,
		int cursum = sumCheck(v);
		if (minVal > cursum)
			minVal = cursum;
		return;
	}

	monitor(pos[index][0], index, dir, v);

	check(index + 1, 0, v); // 0도
	check(index + 1, 1, v); // 90도
	check(index + 1, 2, v); // 180도
	check(index + 1, 3, v); // 270도
}

void initCheck(vector<vector<bool>> v)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			v[i][j] = false;
}

int main()
{
	int wall_camera = 0;
	cin >> Y >> X;
	int temp;
	minVal = 65;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> temp;
			room[i][j] = temp;
			if (temp == 0 || temp == 6)
			{
				if (temp == 6)
					wall_camera++;
				continue;
			}
			pos[numbering][0] = temp; // 종류
			pos[numbering][1] = i; // y 좌표
			pos[numbering][2] = j; // x 좌표
			numbering++;
			wall_camera++;
		}
	}
	vector<vector<bool>> isChecked(8, vector<bool>(8, false));

	for (int i = 0; i < 4; i++)
	{
		initCheck(isChecked);
		check(0, i, isChecked); // 시작의 네가지 방향
	}

	cout << minVal - wall_camera;
	return 0;
}
