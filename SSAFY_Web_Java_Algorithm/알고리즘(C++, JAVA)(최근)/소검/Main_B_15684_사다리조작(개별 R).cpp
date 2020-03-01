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
void search(int cnt, int y) 
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
		for (int j = 1; j <= X; j++) // j = x 로 초기화하면 다음 재귀함수에서 행바꿈을 하는 과정에서 첫 사다리부터 조회해야하는데 x부터 시작하게 된다. 그래서 1로 초기화
		{																		
			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j-1]) 
				continue;
			ladder[i][j] = true;
			search(cnt + 1, i);
			ladder[i][j] = false;
		}
	}

}
																								/*
																									ㅣ		ㅣ		ㅣ* 지점을 가로선 생성한 뒤, 다음 재귀함수로 x값인
																									ㅣ		ㅣㅡㅡ*	ㅣ3을 전달하게 되면 3을 검사하고 다음으로 넘어가 
																									ㅣ		ㅣ		ㅣy값이 +1 되고 다시 1번 세로선부터 조사해야하는데 
																									ㅣ		ㅣ		ㅣj=x로 되어있으면 또 3번을 검사한다. 				   
																								*/
int main()
{
	cin >> X >> lines >> Y; 
	int a, b;
	for (int i = 0; i < lines; i++)
	{
		cin >> a >> b;
		ladder[a][b] = true;
	}

	search(0, 1);

	if (minimum == 5)
		cout << -1;
	else
		cout << minimum;

	return 0;
}