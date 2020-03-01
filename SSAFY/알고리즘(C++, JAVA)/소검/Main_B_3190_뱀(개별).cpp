///*
//	1. 뱀게임
//	2. 자기몸이나 벽부딪히면 사망
//	3. 맨처음 오른쪽
//	4. 이동방식 : 몸을 늘려 머리를 앞칸에 위치시키고 사과가 있으면 사과가 없어지고 늘어진 상태유지
//	4-1, 없다면, 꼬리를 머리위치로 이동
//
//	Q. 매 초 방향에 한칸씩 나가는데, 주어진 방향(회전) 정보를 받아 게임이 언제 끝나는지 맞춰라
//
//	풀이방식, 
//	방향 변수를 오른쪽 기준으로 구십도씩 딱딱 변하게 설정하고, 우회전 시, +1, 좌회전시 +3해서 방향을 지정해준다
//	재귀로 풀것이다.
//	벽에 부딪히는 경우는 간단하지만, 내 몸과 부딪히는 경우를 고려하기 위해 현재 배 몸이 있는 위치를 표현해야한다.
//	일단 visit변수가 떠오르는데, 흠.
//	몸의 길이를 고려해 현재 없는 부분은 false 시켜줘야 한다.
//	특정 지점마다 회전을 하기 때문에 몸도 따라와야하는데 그걸 어떻게 할지 고민하자.
//	1. 회전스팟을 기록하자, 특정 스팟에 도달하면 visit을 다시 false 시켜주는 것도 바꿔주자~?!?
//
//	방향 변환 횟수가 100 이하이니깐, 재귀로 해도 크게 문제 없을 듯 보인다.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct command {
//	int second;
//	string rotate;
//};
//
//struct Pos {
//	int y;
//	int x;
//	int d;
//};
//
//int curBody[101][101];
//int apples[101][101];
//int N;
//int K; // 사과 갯수
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//bool isOver;
//int answer;
//int C; // command
//command cd[100];
//int cdSec;
//int cdIdx;
//bool isRotate;
//Pos tailPos;
//queue<Pos> curve;
//
//void input();
//void move(int y, int x, int d);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	input();
//
//	tailPos.y = 1;
//	tailPos.x = 1;
//	tailPos.d = 0;
//	cdSec = cd[0].second;
//	answer = 0;
//	move(1, 1, 0); // 0,0 위치에서 오른쪽으로 0 초로 시작
//
//	cout << answer;
//	return 0;
//}
//void input()
//{
//	cin >> N >> K;
//	int y;
//	int x;
//
//	for (int i = 0; i < K; i++)
//	{
//		cin >> y >> x;
//		apples[y][x] = 1;
//	}
//
//	cin >> C;
//	for (int i = 0; i < C; i++)
//	{
//		cin >> cd[i].second;
//		cin >> cd[i].rotate;
//	}
//
//}
//void move(int y, int x, int d)
//{
//	if (isOver) // 끝났으면
//		return;
//	
//	curBody[y][x] = true;
//	int _d = d;
//
//	if (answer == cdSec) // 다음턴에 회전되도록
//	{
//		if (cd[cdIdx].rotate == "D")
//		{
//			_d += 1;
//		}
//		else
//		{
//			_d += 3;
//		}
//		curve.push({ y,x,_d % 4 });
//		cdIdx += 1;
//		cdSec = cd[cdIdx].second;
//	}
//
//	_d %= 4;
//
//	int ny, nx;
//	ny = y + dir[_d][0];
//	nx = x + dir[_d][1];
//
//	if (curBody[ny][nx] || ny <= 0 || nx <= 0 || ny > N || nx > N)
//	{
//		isOver = true;
//		answer++;
//		return;
//	}
//	else if (apples[ny][nx] == 1)
//	{
//		apples[ny][nx] = 0;
//		answer++; // 1초 증가
//		move(ny, nx, _d);
//		if (isOver)
//			return;
//	}
//	else
//	{
//		int ey, ex;
//		int cy, cx;
//		ey = tailPos.y;
//		ex = tailPos.x;
//
//		curBody[ey][ex] = false;
//
//		if (!curve.empty())
//		{
//			cy = curve.front().y;
//			cx = curve.front().x;
//
//			//curBody[ey][ex] = false;
//
//			if (cy == ey && cx == ex) // 커브지점이면
//			{
//				tailPos.y = ey + dir[curve.front().d][0];
//				tailPos.x = ex + dir[curve.front().d][1];
//				tailPos.d = curve.front().d;
//				curve.pop();
//			}
//			else
//			{
//				tailPos.y = ey + dir[tailPos.d][0];
//				tailPos.x = ex + dir[tailPos.d][1];
//			}
//		}
//		else
//		{
//			tailPos.y = ey + dir[tailPos.d][0];
//			tailPos.x = ex + dir[tailPos.d][1];
//		}
//		answer++; // 1초 증가
//		move(ny, nx, _d);
//		if (isOver)
//			return;
//	}
//	
//}