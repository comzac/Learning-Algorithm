///* 2100~2220
//	1. 1초 256MB
//	2. 1 ≤ R, C ≤ 1500 => 일반적인 BFS로 풀면 안될듯.
//
//	풀이 : 
//	1. 모래성쌓기느낌으로 다음으로 녹을 빙하를 담을 que를 만든다.
//	2. 백조하나의 최대 이동경로를 담을 큐를 하나만들고, 경로를 탐색할 큐를 하나 만든다.
//	3. 빙하는 인접해있는 다음 X를 담으면 되지만, 백조의 경우, 빙하가 부서지고 다음이 빙하가 아닌
//	 바다면 다음 빙하를 만날때까지 순회를 해야 한다.
//	4. 백조큐가 순회중에 다른 백조를 만나면 종료한다.
//
//	방문처리는 백조만 만들고, 빙하는 맵에 변화에 따라 진행하도록 하자.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0 , int X = 0):y(Y), x(X){}
//};
//int N, M;
//char map[1500][1500];
//bool visitL[1500][1500]; // 백조용
//pos L1, L2;
//queue<pos> W, L;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//void input();
//bool melt();
//int main()
//{
//	input();
//
//	int days = 0;
//	while (!melt())
//	{
//		days++;
//	}
//	cout << days;
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	string temp;
//	int cnt = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j ++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] == 'L')
//			{
//				if (cnt == 0)
//				{
//					L1.y = i;
//					L1.x = j;
//					cnt++;
//				}
//				else
//				{
//					L2.y = i;
//					L2.x = j;
//				}
//				W.push({ i,j });
//			}
//			else if (temp[j] == '.')
//			{
//				W.push({ i,j });
//			}
//		}
//	}
//}
//
//bool melt()
//{
//	int curY, curX, ny, nx;
//	queue<pos> NL;
//	L.push({ L1.y, L1.x });
//	visitL[L1.y][L1.x] = true;
//	// 백조 이동시키고,
//	while (!L.empty())
//	{
//		curY = L.front().y;
//		curX = L.front().x;
//		L.pop();
//
//		if (curY == L2.y && curX == L2.x) // 초장에 같은 공간에 있는 경우, 조건에 그런일 없다는건 안보인다. '그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.' 이건가? 혹시모르니 ㄱ
//		{
//			return true;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visitL[ny][nx])
//				continue;
//			if (map[ny][nx] == 'X')
//			{
//				NL.push({ ny,nx });
//				visitL[ny][nx] = true;
//			}
//			else
//			{
//				L.push({ ny,nx });
//				visitL[ny][nx] = true;
//			}
//		}
//	}
//
//	// 빙하 녹이고,
//	int size = W.size();
//	while (size-- > 0) 
//	{
//		curY = W.front().y;
//		curX = W.front().x;
//		W.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '.' || map[ny][nx] == 'L')
//				continue;
//
//			W.push({ ny,nx });
//			map[ny][nx] = '.';
//		}
//	}
//
//
//	L = NL;
//
//	return false;
//}
