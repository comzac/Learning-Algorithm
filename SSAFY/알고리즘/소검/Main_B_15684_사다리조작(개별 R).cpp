#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int X, lines, Y;
int ladder[32][11];
bool isSuccess;
int minimum = 5;

bool searchLadder()
{
	int curX;
	for (int i = 1; i <= X; i++)
	{
		curX = i;
		for (int j = 1; j <= Y; j++)
		{
			if (ladder[j][curX])
				curX += 1;
			else if (ladder[j][curX - 1])
				curX -= 1;
		}

		if (curX != i)
			return false;
	}

	return true;
}
void search(int cnt, int y, int x) 
{

	if (cnt > 3)
		return;

	if (searchLadder()) 
	{
		if (minimum > cnt)
			minimum = cnt;
		return;
	}


	for (int i = y; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j-1]) 
				continue;
			ladder[i][j] = true;
			search(cnt + 1, i, j);
			ladder[i][j] = false;
		}
	}

}
int main()
{
	cin >> X >> lines >> Y; 
	int a, b;
	for (int i = 0; i < lines; i++)
	{
		cin >> a >> b;
		ladder[a][b] = true;
	}

	search(0, 1, 1);

	if (minimum == 5)
		cout << -1;
	else
		cout << minimum;

	return 0;
}