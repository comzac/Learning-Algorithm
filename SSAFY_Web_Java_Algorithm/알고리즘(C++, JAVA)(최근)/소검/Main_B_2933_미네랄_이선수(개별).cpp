///* 0110~0250
//	1. 1초 128MB => 조건만 보고 얼추 예측해보기 연습, 단순 순회는 아니다
//	2. 인접 미네랄은 같은 클러스터,
//	3. 막대가 날아가다가 미네랄을 만나면, 그 칸에 있는 미네랄은 모두 파괴되고 막대는 그 자리에서 이동을 멈춘다.
//	4. 미네랄이 파괴된 이후에 남은 클러스터가 분리될 수도 있다.
//	5. 새롭게 생성된 클러스터가 떠 있는 경우에는 중력에 의해서 바닥으로 떨어지게 된다.
//	6. 떨어지는 동안 클러스터의 모양은 변하지 않는다.
//	7. 클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다.
//	8. 클러스터는 다른 클러스터 위에 떨어질 수 있고, 그 이후에는 합쳐지게 된다.
//
//	 (1 ≤ R,C ≤ 100)
//	  높이 1은 행렬의 가장 바닥, R은 가장 위를 의미한다.
//	  첫 번째 막대는 왼쪽에서 오른쪽으로 던졌으며,
//	  두 번째는 오른쪽에서 왼쪽으로,
//	  이와 같은 식으로 번갈아가며 던진다.
//	  공중에 떠 있는 미네랄 클러스터는 없으며,
//	  두 개 또는 그 이상의 클러스터가 동시에 떨어지는 경우도 없다.
//
//	  풀이 :
//	  요격하는 데 까지는 문제가 없지만,
//	  클러스터가 공중에 떠있는 경우를 파악하기 위해
//	  바닥의 미네랄들의 인접여부를 파악하여 공중에 떠있는 미네랄을 체크한다.
//
//	  그렇다면 분리된 클러스터의 추락은?
//	  => 나눠진 클러스터로 판단할 때, visit이 true가 된 부분이 있을텐데,
//	  나뉜 걸로 판단되면, 이 visit을 기점으로
//	  최하단의 좌표를 얻고
//	  y값을 하나씩 감소(증가)시키며 바닥이나, 다른 미네랄이 발견되면
//	  그 지점까지 쭉 내려준다.
//	  '그 클러스터의 맨 아래 부분이 바닥 또는 미네랄 위로 떨어지는 입력만 주어진다.'
//	  위 조건에서 보듯이 바닥이 아닌 다른 부분이 다른 미네랄에 겹쳐지는 경우는 제외해도 되니
//	  고려할 부분이 줄어든다.
//
//	  문제는 1초란 시간 내로 가능할까?
//	  대략적으로 100*(100*100 + 100*100) 정도의 시간 복잡도가 나오지 않을까 싶다.
//
//	  가보자
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = -1, int X = -1) :y(Y), x(X) {}
//};
//
//int Y, X;
//char map[100][100]; //하단이 1임을 잊지말자
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // bfs순회, 인접미네랄 확인용
//int cmdNum;
//int cmd[100]; // 던지기 높이 헷갈리지 않게 입력받을 때 부터 R-x로 받자
//int visit[100][100];
//
//void input();
//void roundCluster(pos adjoin);
//pos destroy(int idx); // idx % 2 == 0 ? 1 ?
//void moveCluster(); // 현 visit을 보고 변경,
//void visitInit(); // 인접확인을 마칠때마다 해줘야한다. 왜냐면 공중분해된 클러스터가 두개 일 수도 있다.
//
//int main()
//{
//	input();
//	
//	for (int i = 0; i < cmdNum; i++)
//	{
//		pos dpos = destroy(i);
//		if (dpos.y == -1) // 아무것도 안맞음
//			continue;
//
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[Y - 1][j] || map[Y-1][j] != 'x')
//				continue;
//			roundCluster({ Y-1,j });
//		}
//		moveCluster();
//		visitInit();
//	}
//	for (int i = 0; i < Y; i++)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> Y >> X;
//	string temp;
//	for (int i = 0; i < Y; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < X; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//
//	cin >> cmdNum;
//	int height;
//	for (int i = 0; i < cmdNum; i++)
//	{
//		cin >> height;
//		cmd[i] = Y - height;
//	}
//}
//
//void roundCluster(pos adjoin)
//{
//	queue<pos> que;
//	que.push({ adjoin.y, adjoin.x });
//	visit[adjoin.y][adjoin.x] = 1;
//	int curY, curX;
//	int ny, nx;
//	while (!que.empty())
//	{
//		curY = que.front().y;
//		curX = que.front().x;
//		que.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= Y || nx >= X || visit[ny][nx] == 1 || map[ny][nx] != 'x')
//				continue;
//			visit[ny][nx] = 1;
//			que.push({ ny,nx });
//		}
//	}
//}
//
//pos destroy(int idx)
//{
//	pos dpos;
//	int height = cmd[idx];
//	if (idx % 2 == 0) // 좌->우
//	{
//		for (int x = 0; x < X; x++)
//		{
//			if (map[height][x] == 'x')
//			{
//				dpos.y = height;
//				dpos.x = x;
//				map[height][x] = '.';
//				break;
//			}
//		}
//	}
//	else // 우 -> 좌
//	{
//		for (int x = X - 1; x >= 0; x--)
//		{
//			if (map[height][x] == 'x')
//			{
//				dpos.y = height;
//				dpos.x = x;
//				map[height][x] = '.';
//				break;
//			}
//		}
//	}
//	return dpos;
//}
//
//void moveCluster()
//{
//	// 가장 밑 지점 좌표 확보
//	int maxDis = Y;
//	int y, x;
//	for (int i = Y-1 ; i >=0; i--)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[i][j] == 0 && map[i][j] == 'x') // 땅하고 연결안됐는데 미네랄인애들
//			{
//				y = i;
//				x = j;
//				int fallDis = 0;
//				while (true) // 한칸씩 내리며 바닥 밑 미네랄 접점 길이 찾기
//				{
//					y++;
//					if ((map[y][x] == 'x' && visit[y][x]) || y == Y)
//						break;
//					fallDis++;
//				}
//				if (maxDis > fallDis)
//					maxDis = fallDis;
//			}
//		}
//	}
//
//	// fallDis를 구했으니 map에 적용
//	for (int i = Y - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[i][j] == 0 && map[i][j] == 'x')
//			{
//				map[i + maxDis][j] = 'x';
//				map[i][j] = '.';
//			}
//		}
//	}
//}
//
//void visitInit()
//{
//	for (int i = 0; i < Y; i++)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			visit[i][j] = 0;
//		}
//	}
//}
//
///*
//
//반례 만들기
//
//6 6
//xxxxxx
//x.xx.x
//x.xx.x
//x.xx.x
//..xx..
//..xx..
//6
//4 4 6 6 2 2
//
//6 6
//.....x
//.....x
//.....x
//xxxxxx
//.....x
//.....x
//2
//3 3
//
//
//
//*/