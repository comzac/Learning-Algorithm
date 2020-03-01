// 0010~0230
//	1. 2초 512MB
//	2. 이동 중 중간에 있는 구멍은 무시
//	3. N, M <= 50
//
//	풀이 :
//	문제만 읽었을 땐, 왜 G1인지 모르겠는데
//	0,0 시작으로 4방향 고르고 아웃되거나 구멍에 빠졌을 때만 리턴
//	횟수 매개변수로 가져가면서 최대값 비교하고
//
//	최악을 생각해보자
//	1111....11111 1로 구성된 50*50 맵이라고 생각해보자 4 ^ 50 => 2 ^ 100 여기서 터질듯싶다.
//	1
//	1
//	.
//	.
//	.
//	1
//	1
//	1
//	DP를 사용해야할 거 같다.
//	현 이동 지점의 끝을 맞이했을 때, 리턴해오는 과정에서 DP값을 수정해주고
//	더 큰 값일 땐 수정, 아니면 pass, 다음에 이 위치에 도달했을 때, 해당 방향으로 가려고하면
//	값을 알려주고 가지 않게 하도록?
//	그러면 dp[50][50][4] 이런식으로 방향에 대한 값을 주어주면 좋을 듯하다.
//
//	근데, 만약 
//
//	3 x x 3
//	x x x x
//	x x x x
//	3 x x 3
//	이런식이면, 우,하,좌,상을 반복적으로 선택하면 무한 루프아닌가?
//	하다못해 우좌우좌만 반복해도 무한이다.
//
//	같은 숫자가 반복해서 나오면 안되는 조건도 없고,
//	방향도 자의적 선택이다.
//
//	출력조건에 있다..ㅎㅎ;; 무한번 움직이면 -1 출력
//
//	(발견 1)그말은 즉슨, 현재의 값에서 다음 값으로 이동했을 때, 동일한 값이 나오면 그건 무한루프다
//	하지만, 또 ..
//	3 1 2 2 
//	x x x x
//	x x x x
//	3 x x 3
//	이런 경우에도 우,좌,우,좌 반복하면 무한루프다.
//	발견 1 -> 실패
//
//	뭔가 접근을 아직 기재조건(구멍이나 범위초과)가 발생하지 않은 상태에서 시작지점으로 돌아온 경우를
//	검사해야할 거 같다.
//
//	그러면, 각 위치의 진행중이라는 것을 알릴 변수,
//	기재조건을 만났다는 것을 알릴 변수,
//	방향에 맞는 DP값(최대 이동횟수)을 담을 변수,
//
//
//	'문제만 읽었을 땐, 왜 G1인지 모르겠는데' -> 이제 알겠다 어렵다.

#include <iostream>
#include <string>

using namespace std;

int N, M;
char map[50][50];
bool ing[50][50];
bool isInfiniteLoop; 
int dp[50][50]; 
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int maxDis;

void input();
int coinMove(int y, int x);

int main()
{
	input();
	int dpzero = coinMove(0, 0);
	if (isInfiniteLoop)
		cout << -1;
	else
		cout << dpzero;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j];
			dp[i][j] = -1;
		}
	}
}

int coinMove(int y, int x)
{
	if (x < 0 || y < 0 || y >= N || x >= M || map[y][x] == 'H')
		return 0;

	if (ing[y][x] == true)
	{
		isInfiniteLoop = true;
		return 0;
	}
	if (dp[y][x] != -1) 
		return dp[y][x];

	ing[y][x] = true;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + ((map[y][x]-'0') * dir[i][0]);
		int nx = x + ((map[y][x]-'0') * dir[i][1]);

		int nDp = coinMove(ny, nx) + 1;
		if (isInfiniteLoop)
			return 0;
		if (dp[y][x] < nDp)
			dp[y][x] = nDp;
	}
	ing[y][x] = false;
	return dp[y][x];

}