/* 2205~2250 45M
	1. 2초 128MB
	2. N은 16보다 작거나 같은 자연수
	
	풀이 :
	순서대로 죽는 모든 경우를 살피며, 은진이가 죽은 날까지의 턴을 계산한다.
	은진이의 죽음에 따라 return 시켜서 백트래킹을 할 수 있다.
	밤의 선택에서 은진이는 무조건 선택하지 않고 진행한다.

	동일한 점수의 낮은 번호를 고르기 위해서는 
	max 비교에서 등호를 제외시켜 낮은 번호부터 순회시킨다.

*/
#include <iostream>
#include <string>

using namespace std;
int N;
int R[16][16]; // 플레이어 번호 0부터 시작
int guiltyScore[16];
bool isDead[16]; // 죽으면 불필요한 연산 제거
int maxDay; // 최대로 버틴 날
bool EJDead; // 은진이 죽음 확인
int mafiaNum;
int alivePerson;

void input();
void game(int days);

int main()
{
	input();
	alivePerson = N;
	game(0);
	cout << maxDay;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> guiltyScore[n];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> R[i][j];
		}
	}

	cin >> mafiaNum;
}

void game(int days)
{
	if (alivePerson % 2 == 0) // 밤
	{
		for (int i = 0; i < N; i++)
		{
			if (i == mafiaNum || isDead[i])
				continue;

			isDead[i] = true;
			for (int j = 0; j < N; j++)
			{
				if (isDead[j])
					continue;
				guiltyScore[j] += R[i][j];
			}

			alivePerson--;

			game(days + 1);

			alivePerson++;

			for (int j = 0; j < N; j++)
			{
				if (isDead[j])
					continue;
				guiltyScore[j] -= R[i][j];
			}
			isDead[i] = false;
		}
	}
	else // 낮
	{
		int maxScore = 0;
		int idx = 0;
		for (int i = 0; i < N; i++)
		{
			if (isDead[i])
				continue;
			if (maxScore < guiltyScore[i])
			{
				maxScore = guiltyScore[i];
				idx = i;
			}
		}

		if (idx == mafiaNum) // 은진이가 걸렸으면 빽
		{
			if (maxDay < days)
				maxDay = days;
			return;
		}

		isDead[idx] = true;
		alivePerson--;
		game(days);
		alivePerson++;
		isDead[idx] = false;
	}
}


