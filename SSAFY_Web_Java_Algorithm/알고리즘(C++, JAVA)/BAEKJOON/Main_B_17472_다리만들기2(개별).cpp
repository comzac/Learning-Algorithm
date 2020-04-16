#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct bridge {
	int dis;
	int from;
	int to;
	bridge(int d, int f, int t) :dis(d), from(f), to(t) {}
};

struct pos {
	int y;
	int x;
	pos(int _y, int _x) : y(_y), x(_x) {}
};

bool cmp(bridge a, bridge b)
{
	return a.dis < b.dis;
}

int N, M;
int map[11][11];
bool visit[11][11];
int islandNum;
vector<bridge> edge; // 연결선 저장
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int set[7];

void input();
void bfs_divide_part(); // 구역별 번호부여 
void bfs_adjoin(int y, int x, int num);
void make_bridge(int idx);
int kruskal();
int getParent(int idx);
void make_set();
int find_set(int a, int b);
void unionParent(int a, int b);
void bfs(int startIdx, int y, int x);
void visitInit();
bool sameParent();
int main()
{
	input();
	bfs_divide_part();

	visitInit();

	for (int i = 1; i <= islandNum; i++)
	{
		make_bridge(i);
	}

	cout << kruskal() << endl;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void bfs_divide_part()
{
	int numbering = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] || map[i][j] == 0)
				continue;
			bfs_adjoin(i, j, numbering);
			numbering++;
		}
	}
	islandNum = numbering - 1;
}

void bfs_adjoin(int y, int x, int num)
{
	int ny, nx;
	queue<pos> que;
	que.push(pos(y, x));
	visit[y][x] = true;

	while (!que.empty())
	{
		pos cur = que.front();
		que.pop();
		map[cur.y][cur.x] = num;

		for (int i = 0; i < 4; i++)
		{
			ny = cur.y + dir[i][0];
			nx = cur.x + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 0)
				continue;

			visit[ny][nx] = true;
			que.push(pos(ny, nx));
		}
	}

}


void make_bridge(int idx)
{

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (visit[y][x])
				continue;
			if (map[y][x] == idx)
			{
				bfs(idx, y, x);
			}
		}
	}
}

void bfs(int startIdx, int y, int x)
{
	int ny, nx;
	int dy, dx;
	queue<pos> que;
	que.push(pos(y, x));
	visit[y][x] = true;

	while (!que.empty())
	{
		pos cur = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int distance = 0;
			dy = cur.y + dir[i][0];
			dx = cur.x + dir[i][1];

			while (dy >= 0 && dx >= 0 && dy < N && dx < M && map[dy][dx] == 0)
			{
				distance++;
				dy = dy + dir[i][0];
				dx = dx + dir[i][1];
			}

			if (distance < 2)
				continue;
			if (dy >= N || dx >= M || dy < 0 || dx < 0)
				continue;
			if (map[dy][dx] == startIdx)
				continue;
			edge.push_back(bridge(distance, startIdx, map[dy][dx]));
		}


		for (int i = 0; i < 4; i++)
		{
			ny = cur.y + dir[i][0];
			nx = cur.x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 0)
				continue;
			visit[ny][nx] = true;
			que.push(pos(ny, nx));

		}


	}

}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
		}
	}
}

bool sameParent()
{
	int cnt = 0;
	for (int i = 2; i <= islandNum; i++)
	{
		if (set[i] < 0)
		{
			cnt++;
			if (cnt > 1)
				return false;
		}
	}
	return true;
}

int kruskal()
{
	int _edge = 0;
	int distance = 0;
	if (edge.size() == 0)
		return -1;
	sort(edge.begin(), edge.end(), cmp);
	make_set();
	for (int i = 0; i < edge.size(); i++)
	{
		int from = edge[i].from;
		int to = edge[i].to;
		if (!find_set(from, to))
		{
			distance += edge[i].dis;
			unionParent(from, to);
			_edge++;
		}
	}
	if (!sameParent() || (_edge != islandNum-1))
		return -1;
	return distance;
}

int getParent(int idx)
{
	if (set[idx] < 0)
	{
		return idx;
	}
	return set[idx] = getParent(set[idx]);
}

void make_set()
{
	for (int i = 1; i <= islandNum; i++)
	{
		set[i] = -1;
	}
}

int find_set(int a, int b)
{
	int rootA = getParent(a);
	int rootB = getParent(b);

	if (rootA == rootB)
		return 1;
	else
		return 0;
}

void unionParent(int a, int b)
{
	int rootA = getParent(a);
	int rootB = getParent(b);

	if (set[rootA] < set[rootB]) // rootA가 더 큰 집합이라면
	{
		set[rootA] += set[rootB];
		set[rootB] = rootA;

	}
	else
	{
		set[rootB] += set[rootA];
		set[rootA] = rootB;
	}
}


