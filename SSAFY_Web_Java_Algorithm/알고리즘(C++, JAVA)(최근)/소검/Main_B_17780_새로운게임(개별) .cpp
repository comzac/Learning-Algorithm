///* 1415~1430 + 1450~1630 + 2030~2100 = 15M+1H40M+30M = 2H25M
//	1. 0.5초, 512MB
//	2.	새로운 게임은 크기가 N×N인 체스판에서 진행되고, 사용하는 말의 개수는 K개이다.
//		말은 원판모양이고, 하나의 말 위에 다른 말을 올릴 수 있다.
//		체스판의 각 칸은 흰색, 빨간색, 파란색 중 하나로 색칠되어있다.
//	3. 턴 한 번은 1번 말부터 K번 말까지 순서대로 이동시키는 것이다.
//	4. 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.
//	5. 말의 이동 방향에 있는 칸에 따라서 말의 이동이 다르며 아래와 같다.
//	 => 현재위치가 아닌 이동하려는 칸의 색에 따라 다름
//
//	1) 쌓인 순서를 어떻게 표현할지?
//	2) 쌓인 순서를 뒤집을 때 어떻게 할 것인지?
//	3) 종료조건을 고려해야 시간 조건을 통과할까?
//	4) 말은 최대 10개지만 한세트라도 4개이상되면 끝난다.
//
//	말은 구조체로 저장하고, 구조체 내에 deque을 넣자
//	일반적인 업기에서는 push_back(pop_front)을 해주고
//	빨간색 업기에서는 push_back(pop_back)
//	빈칸 빨간색 push_back(pop_back) // 별도로 que나 deque생성
//
//*/
//#include <iostream>
//#include <string>
//#include <deque>
//#include <vector>
//
//using namespace std;
//struct unit {
//	deque<pair<int, int>> Ndir;
//	int y;
//	int x;
//	bool isActive;
//	unit() {}
//};
//
//int N, K;
//int map[13][13]; // (1,1)이 시작
//int curNum[13][13];
//int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }; // 우, 상, 좌, 하
//unit units[11];
//int turn;
//int answer;
//bool isFour;
//void input();
//void move();
//int dirChange(int d);
//int main()
//{
//	input();
//
//	while (true)
//	{
//		turn++;
//		if (turn > 1000)
//		{
//			answer = -1;
//			break;
//		}
//		move();
//		if (isFour)
//		{
//			answer = turn;
//			break;
//		}
//	}
//	cout << answer;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	int d;
//	int y, x;
//	for (int k = 1; k <= K; k++)
//	{
//		cin >> y >> x;
//		units[k].y = y;
//		units[k].x = x;
//		cin >> d;
//		units[k].Ndir.push_back({ k,dirChange(d) });
//		curNum[y][x] = k;
//		units[k].isActive = true;
//	}
//}
//
//void move()
//{
//	int ny, nx;
//	int curY, curX;
//	int d;
//	for (int k = 1; k <= K; k++)
//	{
//		if (!units[k].isActive)
//			continue;
//		d = units[k].Ndir.front().second;
//		curY = units[k].y;
//		curX = units[k].x;
//
//		ny = curY + dir[d][0];
//		nx = curX + dir[d][1];
//
//		if (ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx] == 2) // 벗어나거나 파란색일 때,
//		{
//			ny = curY + dir[(d + 2) % 4][0];
//			nx = curX + dir[(d + 2) % 4][1];
//
//			if (ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx] == 2) // 또그러면
//			{
//				//int _dir = units[k].dir.front(); // 방향만 전환
//				units[k].Ndir.pop_front();
//				units[k].Ndir.push_front({ k,(d + 2) % 4 });
//			}
//			else
//			{
//				//int _dir = units[k].dir.front(); // 방향만 전환
//				units[k].Ndir.pop_front();
//				units[k].Ndir.push_front({ k,(d + 2) % 4 });
//				d = units[k].Ndir.front().second;
//
//				if (map[ny][nx] == 0)
//				{
//					if (curNum[ny][nx] == 0) //암것도 없을 때
//					{
//						curNum[ny][nx] = k; // 번호이동
//						curNum[curY][curX] = 0; // 이전위치 제거
//						units[k].y = ny;
//						units[k].x = nx;
//					}
//					else // 다른 사람이 있을 때,
//					{
//						int old = curNum[ny][nx];
//						while (!units[k].Ndir.empty()) // 쌓이는 중
//						{
//							int newDir = units[k].Ndir.front().second;
//							int newK = units[k].Ndir.front().first;
//							units[old].Ndir.push_back({ newK,newDir });
//							units[k].Ndir.pop_front();
//						}
//						curNum[curY][curX] = 0; // 이전위치 제거
//						units[k].isActive = false;
//
//						if (units[old].Ndir.size() >= 4)
//							isFour = true;
//					}
//				}
//				else if (map[ny][nx] == 1)
//				{
//					if (curNum[ny][nx] == 0) //암것도 없을 때
//					{
//						//curNum[ny][nx] = k; // 번호이동
//						curNum[curY][curX] = 0; // 이전위치 제거
//						units[k].y = ny;
//						units[k].x = nx;
//
//						deque<pair<int,int>> temp; //방향 뒤집기
//						while (!units[k].Ndir.empty())
//						{
//							int newDir = units[k].Ndir.back().second;
//							int newK = units[k].Ndir.back().first;
//							temp.push_back({ newK,newDir });
//							units[k].Ndir.pop_back();
//						}
//						units[k].Ndir = temp;
//
//						int curBottom = units[k].Ndir.front().first;
//						units[curBottom].Ndir = units[k].Ndir;
//						units[curBottom].y = units[k].y;
//						units[curBottom].x = units[k].x;
//						units[curBottom].isActive = true;
//						if(curBottom != k)
//							units[k].isActive = false;
//						curNum[ny][nx] = curBottom;
//					}
//					else // 다른 사람이 있을 때,
//					{
//						int old = curNum[ny][nx];
//						while (!units[k].Ndir.empty()) // 뒤접어서 쌓이는 중
//						{
//							int newDir = units[k].Ndir.back().second;
//							int newK = units[k].Ndir.back().first;
//							units[old].Ndir.push_back({ newK,newDir });
//							units[k].Ndir.pop_back();
//						}
//						curNum[curY][curX] = 0; // 이전위치 제거
//						units[k].isActive = false;
//
//						if (units[old].Ndir.size() >= 4)
//							isFour = true;
//					}
//				}
//			}
//		}
//		else
//		{
//			switch (map[ny][nx])
//			{
//			case 0: // 흰색
//				if (curNum[ny][nx] == 0) //암것도 없을 때
//				{
//					curNum[ny][nx] = k; // 번호이동
//					curNum[curY][curX] = 0; // 이전위치 제거
//					units[k].y = ny;
//					units[k].x = nx;
//				}
//				else // 다른 사람이 있을 때,
//				{
//					int old = curNum[ny][nx];
//					while (!units[k].Ndir.empty()) // 쌓이는 중
//					{
//						int newDir = units[k].Ndir.front().second;
//						int newK = units[k].Ndir.front().first;
//						units[old].Ndir.push_back({ newK,newDir });
//						units[k].Ndir.pop_front();
//					}
//					curNum[curY][curX] = 0; // 이전위치 제거
//					units[k].isActive = false;
//
//					if (units[old].Ndir.size() >= 4)
//						isFour = true;
//				}
//				break;
//			case 1: // 빨간색
//				if (curNum[ny][nx] == 0) //암것도 없을 때
//				{
//					//curNum[ny][nx] = k; // 번호이동
//					curNum[curY][curX] = 0; // 이전위치 제거
//					units[k].y = ny;
//					units[k].x = nx;
//
//					deque<pair<int, int>> temp; //방향 뒤집기
//					while (!units[k].Ndir.empty())
//					{
//						int newDir = units[k].Ndir.back().second;
//						int newK = units[k].Ndir.back().first;
//						temp.push_back({ newK,newDir });
//						units[k].Ndir.pop_back();
//					}
//					units[k].Ndir = temp;
//
//					int curBottom = units[k].Ndir.front().first;
//					units[curBottom].Ndir = units[k].Ndir;
//					units[curBottom].y = units[k].y;
//					units[curBottom].x = units[k].x;
//					units[curBottom].isActive = true;
//					if (curBottom != k)
//						units[k].isActive = false;
//					curNum[ny][nx] = curBottom;
//				}
//				else // 다른 사람이 있을 때,
//				{
//					int old = curNum[ny][nx];
//					while (!units[k].Ndir.empty()) // 뒤접어서 쌓이는 중
//					{
//						int newDir = units[k].Ndir.back().second;
//						int newK = units[k].Ndir.back().first;
//						units[old].Ndir.push_back({ newK,newDir });
//						units[k].Ndir.pop_back();
//					}
//					curNum[curY][curX] = 0; // 이전위치 제거
//					units[k].isActive = false;
//
//					if (units[old].Ndir.size() >= 4)
//						isFour = true;
//				}
//				break;
//			}
//			if (isFour)
//				return;
//		}
//	}
//}
//
//int dirChange(int d)
//{
//	int dir;
//	switch (d)
//	{
//	case 1:
//		dir = 0;
//		break;
//	case 2:
//		dir = 2;
//		break;
//	case 3:
//		dir = 1;
//		break;
//	case 4:
//		dir = 3;
//		break;
//	}
//	return dir;
//}
//
///*
//4 1
//0 0 0 0
//0 2 1 2
//0 0 0 0
//0 0 0 0
//2 2 1
//
//4 1
//0 0 0 0
//0 0 1 2
//0 0 0 0
//0 0 0 0
//2 2 1
//
//4 4
//0 0 2 0
//0 0 1 0
//0 0 1 2
//0 2 0 0
//2 1 1
//3 2 3
//2 2 1
//4 1 2
//*/