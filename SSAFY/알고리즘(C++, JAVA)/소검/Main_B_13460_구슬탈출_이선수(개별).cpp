#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos
{
	int y;
	int x;
	pos(int _y, int _x): y(_y), x(_x) {};
};

int Y;
int X;
char map[10][10];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; // 하 우 상 좌 (+2 % 4 하면 반대방향 나옴)
pos red = { 0,0 };
pos blue = { 0,0 };
pos hole = { 0,0 };
int answer = 999999999;
bool dropRed;
bool dropBlue;
void input();
void move(int d, int cnt, pos red, pos blue);
#define Min(a,b)(a<b?a:b)

int main()
{
	input();
	move(-11, 1, red, blue); // 첫 방향 매우 작게 가기 ( 나눠도 음수이도록 )
	
	if (answer == 999999999)
		cout << -1;
	else
		cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X;

	string temp;
	char c;
	for (int y = 0; y < Y; y++)
	{
		cin >> temp;
		for (int x = 0; x < X; x++)
		{
			c = temp[x];
			map[y][x] = c;
			if (c == 'R')
			{
				red.y = y;
				red.x = x;
			}
			else if (c == 'B')
			{
				blue.y = y;
				blue.x = x;
			}
			else if (c == 'O')
			{
				hole.y = y;
				hole.x = x;
			}
		}
	}


}

void move(int d, int cnt, pos red, pos blue)
{


	if (cnt > 10)
		return;
	if (red.x == hole.x && red.y == hole.y)
	{
		answer = Min(cnt, answer);
		return;
	}

	int _d = d % 4; // 안쓸듯?
	int notD = (_d + 2) % 4; // 반대방향 (안그러면 계속 왔다갔다)

	for (int i = 0; i < 4; i++)
	{
		dropRed = false;
		dropBlue = false;
		if (i == notD)
			continue;
		// 빨간
		int rny = red.y;
		int rnx = red.x;
		
		while (true) // 정한 방향으로 계속 이동
		{
			rny += dir[i][0]; // 막는게 없다면 계속 굴러가
			rnx += dir[i][1];

			if (map[rny][rnx] == '#')
			{
				rny -= dir[i][0];
				rnx -= dir[i][1];
				break;
			}
			if (map[rny][rnx] == 'O')
			{
				dropRed = true;
				break;
			}
		}

		// 파란
		int bny = blue.y;
		int bnx = blue.x;
		
		while (true) // 정한 방향으로 계속 이동
		{
			bny += dir[i][0]; // 막는게 없다면 계속 굴러가
			bnx += dir[i][1];
			if (map[bny][bnx] == '#')
			{
				bny -= dir[i][0];
				bnx -= dir[i][1];
				break;
			}
			if (map[bny][bnx] == 'O')
			{
				dropBlue = true;
				break;
			}
		}

		if (dropRed && !dropBlue)
		{
			answer = Min(cnt, answer);
			continue;
		}
		else if((!dropRed && dropBlue) || (dropRed && dropBlue))
		{
			continue;
		}

		if (rny == red.y && rnx == red.x && bny == blue.y && bnx == blue.x)
			continue;

		// 다 굴렀으면,
		if (rny == bny && rnx == bnx) // 이동해보니 같은 곳이라면
		{
			switch (i)
			{
			case 0: // 하
				if (red.y > blue.y) // 레드가 아래에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny - 1, bnx)); // 블루 한칸 위로
				}
				else // 블루가 아래있었다면
				{
					move(i, cnt + 1, pos(rny - 1, rnx), pos(bny, bnx)); // 레드 한칸 위로
				}

				break;
			case 1: // 우
				if (red.x > blue.x) // 레드가 오른쪽에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx - 1)); // 블루 한칸 왼쪽으로
				}
				else // 블루가 오른쪽에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx - 1), pos(bny, bnx)); // 레드 한칸 위로
				}
				break;
			case 2: // 상
				if (red.y > blue.y) // 레드가 아래에 있었다면
				{
					move(i, cnt + 1, pos(rny + 1, rnx), pos(bny, bnx)); // 블루 한칸 위로
				}
				else // 블루가 아래에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny + 1, bnx)); // 레드 한칸 위로
				}
				break;
			case 3: // 좌
				if (red.x > blue.x) // 레드가 오른쪽에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx + 1), pos(bny, bnx)); // 블루 한칸 왼쪽으로
				}
				else // 블루가 오른쪽에 있었다면
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx + 1)); // 레드 한칸 위로
				}
				break;
			}
		}
		else
		{
			move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx));
		}

		

	}
}
