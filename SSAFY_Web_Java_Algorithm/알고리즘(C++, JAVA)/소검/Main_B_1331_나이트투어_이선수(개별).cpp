/* 0055~0115
	1. 2초 128MB
	2. 체스의 말의 이동 (8방향)으로 모든 지점을 한번씩만 방문하고,
	마지막 지점에서 다시 시작점으로 돌아오는 경로가 옳은지 판단하는 문제

	풀이 :
	연산을 줄이기 위해, 
	제일 처음과 마지막만 비교해서 안되면 Invalid 출력
	되면 이동을 진행해본다.
	y이동값과 x이동값의 절대값이 1과 2로 이루어져있으면 통과시키고
	지점을 찍을때마다 visit을 true시켜 true에 재방문하면 false 시킨다.
	열은 기존과 같지만 행이 반대로 되어있는걸 조심한다.

	다른풀이 : 이걸 먼저해보자.
	map을 활용한 중복체크,
	연달아 오는 인풋값에서 체크

*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	bool isFalse = false;
	string startPos;
	string oldPos;
	string newPos;
	cin >> oldPos;
	startPos = oldPos;
	m[startPos] = 1;
	for (int i = 1; i < 36; i++)
	{
		cin >> newPos;

		if (m.find(newPos) != m.end())
		{
			isFalse = true;
			break;
		}
		m[newPos] = 1;
		int diffY = abs(oldPos[0] - newPos[0]);
		int diffX = abs(oldPos[1] - newPos[1]);

		if (diffY * diffX != 2)
		{
			isFalse = true;
			break;
		}
		oldPos = newPos;
	}
	if (isFalse)
	{
		cout << "Invalid";
		return 0;
	}
	int diffY = abs(oldPos[0] - startPos[0]);
	int diffX = abs(oldPos[1] - startPos[1]);

	if (diffY * diffX != 2)
	{
		cout << "Invalid";
		return 0;
	}

	cout << "Valid";

	return 0;
}
