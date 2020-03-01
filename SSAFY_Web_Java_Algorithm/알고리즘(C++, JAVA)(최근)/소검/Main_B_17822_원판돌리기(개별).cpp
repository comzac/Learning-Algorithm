/*1610~1700 + 1815~1915 => 50+60 => 1H50M

*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int circle[51][51];
int N, M, T;
int num, dir, dis;
int k;
int adjoin[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
set<pair<int, int>> posCheck;
double sum;
int cnt;
void rotate();
void swap(int row);
void adjoinCheck();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> circle[i][j];
			sum += circle[i][j];
		}
	}
	cnt = N * M;
	for (int t = 0; t < T; t++)
	{
		cin >> num >> dir >> dis;


		rotate();
		adjoinCheck();
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += circle[i][j];
		}
	}

	cout << answer;

	return 0;
}

void rotate()
{
	// 방향 정규화 (한 방향으로 맞춰주기
	if (dir == 0)
	{
		k = dis;
	}
	else // 반시계
	{
		k = M - dis;
	}

	for (int i = 0; i < N; i++)
	{
		if ((i + 1) % num != 0)
			continue;
		swap(i);
	}
}

void swap(int row)
{
	vector<int> temp;
	for (int i = M - k; i < M; i++) // 범위 넘어 돌아가는 애들 잠시 빼놓기
	{
		temp.push_back(circle[row][i]);
	}

	for (int i = M - 1; i >= k; i--) // 다른애들 이동
	{
		circle[row][i] = circle[row][i - k];
	}

	for (int i = 0; i < k; i++) // 넘어갔던애들 붙혀주기
	{
		circle[row][i] = temp[i];
	}

	temp.clear();
}

void adjoinCheck()
{
	int ny, nx;
	int base;
	bool isCollect;
	bool isSame = false;
	for (int i = 0; i < N; i++) // 인접처리
	{
		for (int j = 0; j < M; j++)
		{
			if (circle[i][j] == 0)
				continue;
			base = circle[i][j];
			isCollect = false;

			for (int k = 0; k < 4; k++)
			{
				ny = i + adjoin[k][0];
				nx = j + adjoin[k][1];

				if (ny < 0 || ny >= N) // 원판을 벗어나는 건 스킵
					continue;
				if (nx < 0)
				{
					nx = M - 1;
				}
				else if (nx >= M)
				{
					nx = 0;
				}

				if (circle[ny][nx] == 0) // 제거된 값은 처리하지 않는다
					continue;

				if (base == circle[ny][nx])
				{
					posCheck.insert({ ny,nx });
					isCollect = true;
					isSame = true;

				}
			}
			if (isCollect)
			{
				posCheck.insert({ i,j });
			}
		}
	}

	double avg;
	if (!isSame) // 하나도 같은 게 없다면
	{
		avg = sum / cnt;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (circle[i][j] == 0)
					continue;

				if (circle[i][j] < avg)
				{
					circle[i][j]++;
					sum++;
				}
				else if (circle[i][j] > avg)
				{
					circle[i][j]--;
					sum--;
				}
			}
		}
	}
	else // 있었다면,
	{
		for (auto a : posCheck)
		{
			sum -= circle[a.first][a.second];
			cnt--;
			circle[a.first][a.second] = 0;
		}
		posCheck.clear();
	}


}

