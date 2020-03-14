#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

bool isChoiced[17]; // 이 값의 관계에 대해서 지정해준 게 있나?
int position[17][17]; // [y][x] 기준, y가 x보다 앞에 있는 경우, 1 / 반대 경우 -1 / 모르는 경우 0
bool visit[17]; // dfs 과정에서 선택되었는지?
ll dp[1 << 17]; // 나열? 배치?가 되어있는 모든 경우를 고려
int N, M;

void input();
void interPosition(int fix, int val); // 위에서 주어진 position 값을 활용해서 연쇄적인 관계도 파악해놓기
ll dfs(int curPos, ll bitmask); // cur : 1~N번째 중, 어느 위치에 배치 될 지, bitmask 배치 모든 경우,
void reset();
int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		input();// 여기까지 진행되면 주어진 조건에 대해서는 정보가 있지만, 
				// 예를 들어 1->2 , 2->5 의 경우, 1->5 도 성립하기 때문에
				// 이 관계를 다음 함수에서 지정해준다.
		for (int i = 1; i <= N; i++)
		{
			interPosition(i, i); // 모든 번호에 대해서 조사해보는 데, other은 일단 관계없는 숫자를 넣고,
		}

		dfs(0, 0); //  현재 채워진 자리가 없기때문에 bitmask는 0으로 시작,

		cout << "#" << t << " " << dp[0] << endl;
		reset();
	}
}

void input()
{
	cin >> N >> M;
	int front, end;

	for (int i = 0; i < M; i++)
	{
		cin >> front >> end;
		position[front][end] = 1;  // 앞선다는 정보
		position[end][front] = -1; // 뒤쳐진다는 정보
		isChoiced[front] = true;   // 관계가 주어졌기 때문에 조건에 맞는 경우만 배치 될 수 있고,
		isChoiced[end] = true;	   // 위와 같음
	}

	for (ll i = 0; i <= 1 << N; i++)
	{
		dp[i] = -1; // dp에 방문한 적이 있는지 파악하기 위해 
	}
}

void interPosition(int fix, int val) // 처음으로 들어오는 파라미터는 fix와 val이 같다. fix는 이 함수의 호출 목적인 fix와 연관된 값을 찾는것이고,
{									 // val은 fix와 연관있는 값을 다음 val값을 넣기 위해서이다. 예를 들어, 1->2라는 관계를 찾았으면,									 // 이후, 2와 관계를 갖는 값을 찾고자 하기 때문에, fix는 고정, val은 변동값이다.
	for (int i = 1; i <= N; i++) // 1번부터 N번까지 관계를 살펴보기
	{
		if (position[val][i] == 1) // fix(지금 알아보려는 고정값)과 관계가 앞뒤인 i를 찾아서,
		{
			position[fix][i] = 1;  // 첫호출에서는 이미 있는 값에 재정의하는 꼴이지만,
			position[i][fix] = -1; // 재귀가 더해질수록 새로운 정의가 이루어진다.
			interPosition(fix, i);
		}
	}
}

ll dfs(int curPos, ll bitmask)
{
	// dp 값 유무 체크
	if (dp[bitmask] != -1)
		return dp[bitmask];

	// 기재조건 체크
	if (curPos == N && bitmask == (1 << N) - 1) // 모든 위치에 대한 탐색이 끝났고 && bitmask가 다 채워진 경우, 
	{										  // 예를 들어 N이 5면, bitmask가 00011111 일 때, 모든 자리를 채웠으니 더이상 살펴볼 게 없다.
		dp[bitmask] = 1;					  // 이때, 현 상태의 경우의 수는 하나이기때문에 1넣고 반환한다.
		return dp[bitmask];					  // DP값 갱신의 시작이라고 볼 수 있다.
	}

	// 위에서 어느 조건에도 해당하지 않는다면, 지금부터 현 위치의 dp값을 구할것이기 때문에 기존 -1에서 0으로 바꿔준다.
	dp[bitmask] = 0;

	// 현 위치에 배치할 값 찾기
	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) // 이미 배치에 포함된 상태라면 스킵
			continue;

		// 아직 사용되지 않은 숫자라면, 관계여부를 파악해본다.

		if (isChoiced[i]) // 관계가 있는 숫자라면
		{
			bool isAble = true;
			for (int j = 1; j <= N; j++) // 모든 번호와 관계를 살펴보자.
			{
				if (visit[j]) // 배치에 이미 있는 경우,
					continue;

				 // 아직 배치가 안된 번호인 경우,
				if (position[j][i] == 1) // 아직 배치가 안된 후보 번호가 지금 나보다 앞에 있는 관계가 있다면,
				{
					isAble = false; // 지금 배치 될 수 없음.
				}
			}

			if (isAble) // 남은 번호에 비교하여 앞자리에 있어도 되는 경우라면,
			{

				visit[i] = true; // 사용도 했다.										// 첫 사이클이라는 가정한다면, bitmask는 0, 초기상태이고
				dp[bitmask] += dfs(curPos + 1, bitmask | (1 << (i - 1)));			// 이 상태에서 (첫 배치가 1이 들어간 경우) 뒤의 배치를 살피러 재귀를 도는거다.
				visit[i] = false;													// 따라서 다음 위치를 보고자 curPos에 +1을 해줬고, 
																					// 기존의 비트마스크에 번호에 따른 표시를 해주기 위해 | 연산을 해준다.																																				
			}
		}
		else // 관계가 없는 숫자라면 => 어디에도 배치가 될 수 있다.
		{
			visit[i] = true; // 앞선 검사를 할 필요없이 바로 포함해준다.
			dp[bitmask] += dfs(curPos + 1, bitmask | (1 << (i - 1)));
			visit[i] = false;
		}
	}

	return dp[bitmask];
}

void reset()
{
	for (int i = 0; i <= N; i++)
	{
		isChoiced[i] = false;
		visit[i] = false;
		for (int j = 0; j <= N; j++)
		{
			position[i][j] = 0;
		}
	}
}
