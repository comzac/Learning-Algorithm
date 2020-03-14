/*2350~2440
	1. A 회전시 맞닿은 B의 극이 다르면 A의 회전과 반대방향으로 회전
	2. 극이 같으면 회전 ㄴㄴ

	최종 톱니바퀴의 상태를 구해라
	톱니(홈)는 8개로 구성 12시 기준 시계방향 순으로 극 주어짐
	톱니바퀴는 4개로 고정
	1<= 회전횟수 <= 100
	톱니 번호 / 방향
	1 = 시계방향, -1 = 반시계방향
	최대 회전의 경우, 
	하나의 바퀴 회전에 따라 좌우로 99개의 바퀴를 검사하고
	회전이 100번이면
	100*100
	
	=> 시뮬로 ㄱ
	
	1. 톱니바퀴의 2번 (시작을 0으로 정했을 때)와 6번을 검사해야한다
	1-1. 시작과 끝은 6번과 2번 제외
	2. 해당 톱니바퀴를 기점으로 우측 좌측 나눠서 검사하고
	3. 비트연산자를 활용하면 유용할 듯 하다. (벡터 insert, remove도 8개이기때문에 무리가 없을듯 하다.)

	시간이 늦었으니 벡터로 해보고, 메모리측면의 효율성을 고려해서 다음에 비트도해보자


*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
vector<vector<int>> v;
int rot;
int rotList[100];

void vector_change(int idx, int dir)
{
	int val;
	if (dir == 1)
	{
		val = v[idx][7];
		v[idx].pop_back();
		v[idx].insert(v[idx].begin(), val);
	}
	else
	{
		val = v[idx][0];
		v[idx].erase(v[idx].begin());
		v[idx].push_back(val);
	}
}

void rot_recursive_R(int cur, int dir)
{
	if (cur >= 4) // 범위 한정
		return;

	if (v[cur - 1][2+dir] == v[cur][6])
		return;
	else
	{
		vector_change(cur, dir*-1);
		rot_recursive_R(cur + 1, dir*-1);
	}
}
void rot_recursive_L(int cur, int dir)
{
	if (cur < 0) // 범위 한정
		return;

	if (v[cur][2] == v[cur+1][6+dir])
		return;
	else
	{
		vector_change(cur, dir*-1);
		rot_recursive_L(cur - 1, dir*-1);
	}
}
void rot_recursive(int idx, int dir)
{
	vector_change(idx, dir); // 시작 톱니바퀴의 회전을 시작으로 ㄱ

	rot_recursive_R(idx+1, dir);
	rot_recursive_L(idx-1, dir);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	v = vector<vector<int>>(4, vector<int>(8, 0));
	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	cin >> rot;
	int index;
	int direction;
	for (int i = 0; i < rot; i++)
	{
		cin >> index >> direction;
		rot_recursive(index-1, direction);
	}

	int sum = 0;
	int mul = 1;
	for (int i = 0; i < 4; i++)
	{
		if (v[i][0])
		{
			sum += pow(2, i);
		}
	}
	cout << sum;
	


	return 0;
}
