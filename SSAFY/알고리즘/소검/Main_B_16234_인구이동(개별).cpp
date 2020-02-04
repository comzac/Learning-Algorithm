/*

	1. N*N 땅에서 인접한 두 나라의 인구 차이가 L이상 R이하이면 국경선을 제거한다.
	2. 조건에 따라 국경선을 다 열었다면 인구이동을 시작한다.
	3. 연합을 이루고 있는 각 나라는 (연합의 인구수 / 연합 개수 ) 가 된다. 소수점은 버린다(int)
	4. 다 이동했으면 모든 국경선을 닫는다.
	5. 1번부터 다시 시작하여 국경선이 하나도 제거안되는 때 까지 인구이동 수는?

	1. 1 <= N <= 50  1<= L <= R <= 100
	2. r = y , c = x

	# 틀린 풀이 방식 (시간초과)
	1. 인구수 체크를 어떻게 할 건지? => 우향, 하향 재귀 ㄱㄱ
	2. 연합을 어떻게 파악할 지? => bfs로 방문처리하면서 좌표 담기?
	3. while(true)
		{
			국경선 리셋 (bool 배열)

			인구수체크 => 국경선 변화

			if(국경선체크(국경선) == 국경선 x) (for bool 배열 순회)
				break;

			cnt ++;

			연합파악 ( bfs로 연합별 vector에 담기 )

			연합별 인구 수정 ( 연합에 해당하는 국가들 인원수 수정)
		}

	
	# 맞는 풀이 방식

	1. 위의 풀이방식은 맵 순회를 꽤 많이했다. 50*50이라고만 생각해서 어느정도 연산이 있어도 문제없겠지라고 생각했다.
	2. 하지만, 최대 2,000번의 인구이동이 가능하고 L, R 조건비교, 불변수 초기화 등 연산량이 꽤 많았고 시간초과가 났다.
	3. 처음 풀이하려던 방식은 단계를 세분화해서 DFS를 활용한 국경선을 찾고, BFS를 통해 연합 집단을 파악하려고 했다.
	4. 하지만, 연합집단을 파악할 때부터 국경선 검사가 가능함에도 불구하고 불필요한 순회 연산을 늘리게 됐다.
	5. 이후, BFS를 활용해서 진행했지만 2중 while문 내에서 모든 연합 구역을 설정하려 해서 내부 while문에서 나올때마다 새롭게 지정할 
	pos를 찾는데 또 연산이 추가됐다. 
	6. 결국, BFS를 진행하는 단계에서 visit 처리를 하며 (1), 각 BFS에서 사방탐색을 하기때문에 우향 하향으로 진행되는 2중 for문을 활용하여
		미방문 상태에서만 BFS를 진행시켜 newPos를 구하는 연산을 제거했다.
	7. 마지막으로 인구이동이 일어나지 않는 모든 구역이 단독연합이 된 상태에서도 BFS는 문제없이 진행되는 점이었다.
	8. 이 부분을 해소하기 위해 호출되는 BFS의 횟수를 전역변수를 통해 확인했다. BFS의 탈출 조건은 더이상 인접한 지역이 없는 경우이므로
	 BFS가 실행된만큼 구역이 나뉘었다고 생각할 수 있다.
	9. 따라서, 전역변수의 값과 맵의 크기(N x N)과 동일한 순간, 인구이동은 끝났다고 파악할 수 있다.
	  
===============================================================================================
*/

#include <iostream>
#include <string>
#include <vector> // 연합 좌표 담기
#include <queue> // bfs용

using namespace std;

int N, L, R;

int popul[51][51]; // 0 ~ 49
bool visit[51][51]; // 0 ~ 49
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int localsNum;

void bfs(int y, int x)
{
	localsNum++;
	queue<pair<int, int>> que;
	pair<int, int> tempPos;

	int cy, cx;
	cy = y;
	cx = x;

	int diff;
	int sumPopul;

	vector<pair<int, int>> pos;
	que.push(make_pair(cy, cx));
	sumPopul = 0;

	while (!que.empty())
	{
		tempPos = que.front();
		que.pop();
		cy = tempPos.first;
		cx = tempPos.second;

		if (visit[cy][cx])
			continue;
		visit[cy][cx] = true;

		sumPopul += popul[cy][cx];
		pos.push_back(make_pair(cy, cx));

		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = cy + dir[i][0];
			nx = cx + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			diff = abs(popul[cy][cx] - popul[ny][nx]);
			if ((diff >= L && diff <= R) && !visit[ny][nx]) // 오른 개방
				que.push(make_pair(ny, nx));
		}
	}

	// pos에 담긴 연합 수와 인원 조정
	int ava = sumPopul / pos.size();

	for (int i = 0; i < pos.size(); i++)
	{
		popul[pos[i].first][pos[i].second] = ava;
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> popul[i][j];
		}
	}

	int cnt = 0;

	while (true)
	{
		reset(); // 방문, 국경선 리셋

		localsNum = 0;
		for(int i = 0 ; i < N; i++)
			for(int j = 0 ; j < N; j++)
				if(!visit[i][j])
					bfs(i, j);

		if (localsNum == N*N)
		{
			cout << cnt;
			break;
		}
		cnt++;
	}



	return 0;
}
