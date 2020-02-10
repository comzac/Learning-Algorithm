/* 1425~1555


*/
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int y, x, k;
int Y, X;
int A[101][101];
set<int> idx;
int countN[101];
void input();
void rowSort();
void colSort();
bool isOver;
struct info {
	int number;
	int cnt;
	info(int n, int c ): number(n), cnt(c){}
};

struct cmp {
	bool operator()(info& a, info& b)
	{
		if (a.cnt == b.cnt)
		{
			if (a.number > b.number)
				return true;
			else
				return false;
		}
		else
		{
			if (a.cnt > b.cnt)
				return true;
			return false;
		}
	}
};



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	int time = 0;

	while (true)
	{
		if (A[y][x] == k)
		{
			break;
		}
		else if (time > 100)
		{
			isOver = true;
			break;
		}
		time++;

		if (Y >= X)
		{
			rowSort();
		}
		else
		{
			colSort();
		}



		idx.clear();
		for (int i = 1; i < 101; i++)
			countN[i] = 0;
	}

	if (isOver)
		cout << -1;
	else
		cout << time;

	return 0;
}

void input()
{
	cin >> y >> x >> k;
	Y = X = 3;
	for (int i = 1; i <= Y; i++)
		for (int j = 1; j <= X; j++)
			cin >> A[i][j];
}

void rowSort()
{
	for (int i = 1; i <= Y; i++)
	{
		priority_queue<info, vector<info>, cmp> pq;

		for (int j = 1; j <= X; j++) // 后档 技扁
		{
			if (A[i][j] == 0) continue;

			countN[A[i][j]]++;
			idx.insert(A[i][j]);
		}

		for (auto a : idx)
		{
			pq.push(info(a, countN[a]));
			countN[a] = 0;
		}

		int size = pq.size();
		if (X < size * 2)
			X = size * 2;
		int k = 1;
		for (int c = 1; c <= X; c++)
			A[i][c] = 0;
		while (!pq.empty())
		{
			info temp = pq.top();
			A[i][k] = temp.number;
			A[i][k + 1] = temp.cnt;
			pq.pop();
			k += 2;
		}

		idx.clear();
	}
	
}

void colSort()
{
	for (int i = 1; i <= X; i++)
	{
		priority_queue<info, vector<info>, cmp> pq;

		for (int j = 1; j <= Y; j++) // 后档 技扁
		{
			if (A[j][i] == 0) continue;

			countN[A[j][i]]++;
			idx.insert(A[j][i]);
		}

		for (auto a : idx)
		{
			pq.push(info(a, countN[a]));
			countN[a] = 0;
		}

		int size = pq.size();
		if (Y < size * 2)
			Y = size * 2;
		int k = 1;
		for (int c = 1; c <= Y; c++)
			A[c][i] = 0;
		while (!pq.empty())
		{
			info temp = pq.top();
			A[k][i] = temp.number;
			A[k + 1][i] = temp.cnt;
			pq.pop();
			k += 2;
		}
		idx.clear();
	}

}


