/* 2315~2350
	행은 1~8
	열은 A~H ( -A하면 0~7)

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos {
	int y;
	int x;
	pos(int Y=0, int X= 0):y(Y),x(X){}
};

pos king;
pos stone;
int map[9][9];
int N;
vector<string> cmd;

void input();
void move();
vector<int> cmdDirChange(string str);
int main()
{
	input();
	move();
	
	cout << char('A' + king.x) << 8 - king.y << endl;
	cout << char('A' + stone.x) << 8- stone.y << endl;


	return 0;
}

void input()
{
	string temp;
	cin >> temp;
	king.x = temp[0] - 'A';
	king.y = 8 - (temp[1] - '0');

	cin >> temp;
	stone.x = temp[0] - 'A';
	stone.y = 8 - (temp[1] - '0');

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		cmd.push_back(temp);
	}
}

void move()
{
	int curY, curX;
	int ny, nx;

	vector<int> curCmd;
	for (int i = 0; i < N; i++)
	{
		curY = king.y;
		curX = king.x;
		curCmd = cmdDirChange(cmd[i]);
		ny = curY + curCmd[0];
		nx = curX + curCmd[1];

		if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) // 범위밖
			continue;
		if (ny == stone.y && nx == stone.x)
		{
			stone.y += curCmd[0];
			stone.x += curCmd[1];
			if (stone.y < 0 || stone.x < 0 || stone.y >= 8 || stone.x >= 8) // 범위밖
			{
				stone.y -= curCmd[0];
				stone.x -= curCmd[1];
				continue;
			}
		}
		king.y = ny;
		king.x = nx;
	}
}

vector<int> cmdDirChange(string str)
{
	vector<int> v(2, 0);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'R')
		{
			v[1] += 1;
		}
		else if (str[i] == 'L')
		{
			v[1] -= 1;
		}
		else if (str[i] == 'B')
		{
			v[0] += 1;
		}
		else if (str[i] == 'T')
		{
			v[0] -= 1;
		}
	}
	return v;
}
