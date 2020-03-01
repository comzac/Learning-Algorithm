/*1450~1550 
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//struct tree {
//	int age;
//	int y;
//	int x;
//	bool isActive;
//	bool wasDead;
//	tree(int a, int _y, int _x) :age(a), y(_y), x(_x), isActive(true), wasDead(false) {};
//};

//bool compare(tree a, tree b){
//	return a.age < b.age;
//}


int map[10][10];
int add[10][10];
int N, M, K;
vector<int> tree[10][10];
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
void input();
void spring_summer();
void fall();
void winter();

int main()
{
	input();
	while (K-- > 0)
	{
		spring_summer();
		fall();
		winter();
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tree[i][j].size() == 0)
				continue;
			cnt += tree[i][j].size();
		}
	}

	cout << cnt;

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = 5;
		}
	}

	int age, y, x;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> age;
		tree[y-1][x-1].push_back(age);
	}

}

void spring_summer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tree[i][j].size() == 0)
				continue;
			int dead = 0;
			vector<int> temp;
			sort(tree[i][j].begin(), tree[i][j].end());
			int age;
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				age = tree[i][j][k];
				if (map[i][j] >= age)
				{
					map[i][j] -= age;
					temp.push_back(age + 1);
				}
				else
				{
					dead += age / 2;
				}
			}
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
			{
				tree[i][j].push_back(temp[k]);
			}
			map[i][j] += dead;
		}
	}
}

void fall()
{
	int ny, nx;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tree[i][j].size() == 0)
				continue;
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				if (tree[i][j][k] % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						ny = i + dir[l][0];
						nx = j + dir[l][1];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N)
							continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}

}

void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] += add[i][j];
		}
	}
}


