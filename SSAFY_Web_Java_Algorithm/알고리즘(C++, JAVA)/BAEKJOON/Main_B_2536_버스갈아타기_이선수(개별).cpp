/* 0300~0405
	1. 1초 256MB
	2. xy 반대임
	3. (1 ≤ m,n ≤ 100,000)
	4. 버스의 수 k (1 ≤ k ≤ 5,000)
	5. 모든 입력에 대하여, 출발지와 목적지는 다르게 주어지며 출발지에서 목적지로
		가는 방법은 한 가지 이상 존재한다.

	풀이 :
	일단 현재 위치에서 탈 수 있는 버스를 체크하고
	이동 중에 만나는 버스 체크하고 
	이런식으로는 답이 없을 거 같다.

	일단 최소 환승 횟수니깐 bfs로 접근을 해보자.
	한칸씩 이동한다치면 최대 100억번이다. 이건 아니다.

	환승 횟수가 주 목적이니, 거리는 크게 상관이 없다.
	그렇다면, 버스간의 인접관계를 파악하고,
	다익스트라로 접근해보는건 어떨까?

	그려서 확인해보니 인접관계만 graph형태로 나타내면 bfs를 해도 금방 답이 나온다.

	문제는, 버스간의 인접을 어떤방법으로 표현하는 것이냐다. 
	최대 5000개의 버스 어떻게 할 것인지,
	5,000*5,000 은 25,000,000 이고,
	이후, bfs를 한다해서 최대 연산은 5000번이니깐, 1초안에 되지 않을까?
	근데 그럴려면 완탐과정에서 추가 연산이 네번만 이뤄져도 1억번이다.
	하지만, 버스가 5개라고 할 때, 
	1 번 - 2,3,4,5 와 검사를 하면
	2 번은 3,4,5하고만 검사를 하면 된다.
	따라서 N*N보다는 작은 (N*N)/2가 되고 약 12,500,000 연산이기 때문에 가능할 거 같다.
	한번 해보자



*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
struct pos {
	int x;
	int y;
};
struct Bus {
	int x1;
	int y1;
	int x2;
	int y2;
};
int N, M;
int B;
queue<int> que;
Bus bus[5001];
bool visit[5001];
vector<int> graph[5001];
vector<int> endV;
pos startP;
pos endP;
void input();
void adjCheck(int idx);
int bfs();
int main()
{
	input();

	for (int i = 1; i <= B; i++)
	{
		adjCheck(i);
	}

	cout << bfs();

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	cin >> B;
	int num, x1, y1, x2, y2;
	for (int i = 1; i <= B; i++)
	{
		cin >> num >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2)
		{
			if (y1 < y2)
			{
				bus[num].x1 = x1;
				bus[num].y1 = y1;
				bus[num].x2 = x2;
				bus[num].y2 = y2;
			}
			else
			{
				bus[num].x1 = x1;
				bus[num].y1 = y2;
				bus[num].x2 = x2;
				bus[num].y2 = y1;
			}
		}
		else
		{
			if (x1 < x2)
			{
				bus[num].x1 = x1;
				bus[num].y1 = y1;
				bus[num].x2 = x2;
				bus[num].y2 = y2;
			}
			else
			{
				bus[num].x1 = x2;
				bus[num].y1 = y1;
				bus[num].x2 = x1;
				bus[num].y2 = y2;
			}
		}
	}

	cin >> startP.x;
	cin >> startP.y;
	cin >> endP.x;
	cin >> endP.y;
}

void adjCheck(int idx)
{
	int x1, y1, x2, y2;
	x1 = bus[idx].x1;
	y1 = bus[idx].y1;
	x2 = bus[idx].x2;
	y2 = bus[idx].y2;

	if (x1 <= startP.x && startP.x <= x2 && y1 <= startP.y && startP.y <= y2)
	{
		que.push(idx);
		visit[idx] = true;
	}

	if (x1 <= endP.x && endP.x <= x2 && y1 <= endP.y && endP.y <= y2)
	{
		endV.push_back(idx);
	}

	int nx1, ny1, nx2, ny2;
	for (int i = idx + 1; i <= B; i++)
	{
		nx1 = bus[i].x1;
		ny1 = bus[i].y1;
		nx2 = bus[i].x2;
		ny2 = bus[i].y2;

		if ((x1 <= nx1 && nx1 <= x2 && ny1 <= y1 && y1 <= ny2) || (nx1 <= x1 && x1 <= nx2 && y1 <= ny1 && ny1 <= y2))
		{
			graph[idx].push_back(i);
			graph[i].push_back(idx);
		}
	}
}

int bfs()
{
	int dis = 1;
	int cur;
	int next;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();

			for (int i = 0; i < endV.size(); i++)
			{
				if (cur == endV[i])
				{
					return dis;
				}
			}
			for (int i = 0; i < graph[cur].size(); i++)
			{
				if (visit[graph[cur][i]])
					continue;
				que.push(graph[cur][i]);
				visit[graph[cur][i]] = true;
			}
		}
		dis++;

	}


	return dis;
}
