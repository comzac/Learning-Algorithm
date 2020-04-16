///* 1450~1535 45M 한 큐
//	1. 1초 256MB
//	2. 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.
//	3. 0보다 더 줄진 않는다.
//	4. 녹아 없어진 빙산이 0이 됐을 때, 또 옆의 빙산에 영향을 준다.
//	5. 빙산이 두개로 나눠지는 최소 년수를 구하는데 다 녹을때까지 두덩이로 안나뉘면 0을 출력
//	6. N과 M은 3 <= <= 300
//	7. 빙산은 10000개 이하
//
//	풀이 :
//	크게 봤을 때,
//	while{
//	녹이기
//	구획검사 ( 1개일 때, 2개이상일 때, 0개일 때 구분)
//	} 인데, 
//	문제는 녹이기에서이다. 
//	'배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 
//	그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.' 이 조건을 보아
//	녹는과정에서 0이 되었다고 인접 빙산에 영향을 주는건 아닌거 같다.
//
//	빙산을 구조체에 담고, 주변 0의 개수를 저장한다.
//	해마다 0의 개수만큼 감소시키고 0보다 작아지면 0으로 변경하고 인접 빙산이 있다면 0을 ++해준다.
//	크게 맵, 방문처리(바다여부)를 가지고 진행한다.
//	구획검사에서 visit배열이 또 하나 필요하고 검사마다 초기화가 필요하다.
//	이때, 구조체가 더 효율적일까를 고려해보자.
//	구조체를 사용하지않으면 최대 300*300 (90000)을 순회하며 빙산일 경우, 인접 네구역을 확인하고 감소시킨다.
//	그런데 이렇게 하면 0이 된 경우, 인접 빙산에 영향을 주기때문에 구조체로 진행해보자
//	물론 구조체를 사용한 경우도, 즉각적인 0에 대한 값 ++ 이 아닌 별도의 add배열에 담아뒀다가 더해줘야한다.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct Iceburg {
//	int y;
//	int x;
//	int o;
//	Iceburg(int Y = 0, int X = 0, int O = 0):y(Y),x(X),o(O){}
//};
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X){}
//};
//
//int map[300][300];
//int add[300][300]; // 녹아서 0이 된 경우, 인접 빙산에 더해줄 값 일시 저장 ( 이 역시 초기화 필요 )
//bool isIceburg[300][300]; // 구획 확인에서 필요 ( 초기화 필요 ) 
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//int N, M;
//int iceburgNum;
//Iceburg iceburg[10000];
//int answer;
//
//void input();
//void adjoinOcean();
//void melt(); // 구조체 접근
//void addOcean();
//void devide(int y, int x); // 구획 확인
//void add_iceburg_init();
//
//int main()
//{
//	input();
//	adjoinOcean();
//	int years = 0;
//	bool isOver = false;
//	int curY, curX;
//
//	while (true)
//	{
//		int parts = 0;
//		for (int i = 0; i < iceburgNum; i++)
//		{
//			if (map[iceburg[i].y][iceburg[i].x] == 0 || isIceburg[iceburg[i].y][iceburg[i].x])
//				continue;
//			
//			devide(iceburg[i].y, iceburg[i].x);
//			parts++;
//			if (parts >= 2)
//			{
//				isOver = true;
//				answer = years;
//				break;
//			}
//		}
//		if (isOver)
//			break;
//		if (parts == 0)
//		{
//			answer = 0;
//			break;
//		}
//
//		melt();
//		addOcean();
//		add_iceburg_init();
//
//		years++;
//	}
//
//	cout << answer;
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
//
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp != 0)
//			{
//				iceburg[iceburgNum].y = i;
//				iceburg[iceburgNum].x = j;
//				iceburgNum++;
//			}
//		}
//	}
//}
//
//void adjoinOcean()
//{
//	int ny, nx;
//	int curY, curX;
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		for (int j = 0; j < 4; j++)
//		{
//			ny = curY + dir[j][0];
//			nx = curX + dir[j][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 0)
//				continue;
//			iceburg[i].o++;
//		}
//	}
//}
//
//void melt()
//{
//	int ny, nx;
//	int curY, curX;
//
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		if (map[iceburg[i].y][iceburg[i].x] == 0)
//			continue;
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		map[curY][curX] -= iceburg[i].o;
//		if (map[curY][curX] <= 0)
//		{
//			map[curY][curX] = 0;
//			for (int j = 0; j < 4; j++)
//			{
//				ny = curY + dir[j][0];
//				nx = curX + dir[j][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 0)
//					continue;
//				add[ny][nx]++;
//			}
//		}
//	}
//}
//
//void addOcean()
//{
//	int curY, curX;
//
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		if (map[iceburg[i].y][iceburg[i].x] == 0)
//			continue;
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		iceburg[i].o += add[curY][curX];
//		add[curY][curX] = 0;
//	}
//}
//
//void devide(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	isIceburg[y][x] = true;
//	
//	pos cur;
//	int curY, curX;
//	int ny, nx;
//
//	while (!que.empty())
//	{
//		cur = que.front();
//		que.pop();
//		curY = cur.y;
//		curX = cur.x;
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || isIceburg[ny][nx] || map[ny][nx] == 0)
//				continue;
//			que.push({ ny,nx });
//			isIceburg[ny][nx] = true;
//		}
//	}
//
//}
//
//void add_iceburg_init()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			isIceburg[i][j] = false;
//			add[i][j] = 0;
//		}
//	}
//}
