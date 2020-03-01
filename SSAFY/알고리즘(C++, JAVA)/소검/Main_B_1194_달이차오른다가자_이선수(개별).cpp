/*1930~2000 + (drx vs grf) + 0015~0045 = 1H
	1. 2초, 128MB
	2. 새벽 네시 반, => 필요할 줄 알았는데 필요없고~!
	3. 같은 타입의 열쇠가 여러 개 있을 수 있고, 문도 마찬가지이다.
	4. 영식이가 열쇠를 숨겨놓는 다면 문에 대응하는 열쇠가 없을 수도 있다.
	5. 열쇠는 여러 번 사용할 수 있다.
	6. 만약 민식이가 미로를 탈출 할 수 없으면, -1을 출력한다.
	7. 최소이동 값 출력

	풀이 :
	일단 이건 visit배열을 고민해봐야한다.
	일직선으로만 생각했을 때, 
	visit 배열이 없어야 열쇠를 줍고 다시 왔던길을 되돌아가던지 할텐데
	최대용량이 128인걸로 보아 그건 안될듯싶다.
	따라서, 이 문제 역시 3차원 배열 visit 변수가 필요할 듯하다.
	대신, n,m이 최대 50이기때문에
	visit[50][50][26] < 26은 알파벳 갯수
	열쇠를 갖고 있는 상태에서 접근한적이 있는지를 파악하는 것이다.
	그렇다면 열쇠 소유 여부를 파악해야하는데,
	민식이가 뭘 갖고 있는지 바로 검색하는데 있어서 연산량을 줄이려면
	map이 적절할듯 하다.
	그리고 

	....1
	#A###
	0a..#
	.a...
	...#.
	이런 경우를 생각해보자.
	a를 이미 갖고있는데 a로 가는것이 의미가 있을까?
	위의 상황은 배제하는것이 맞다.

	#A###
	0a..#
	.a...
	#.###
	....1

	이런 상황이라면, 배제했을 경우, 출구를 찾지 못한다.
	따라서 이동조건에서 소유 열쇠는 포함시키지 않는다.

	예제 1)
	f0.F..1
	이런 상황은 위의 계획에 걸맞지만,
	만약, 열쇠가 여러개라면 visit처리를 어떻게 할 것인가?
	갖고 있는 열쇠 종류 모두 visit이 트루이면 이동불가?
	비트마스킹을 써보는게 어떨까? => X 효율적일 수 있지만 비트연산도 필요로 된다. 만약, 메모리부족이 발생하면 도전해보도록 하자

	int형이 32비트, 26개에 충당하며
	갖고 있는 열쇠 번호를 1로 갖고있다가

	=> 일단 여기까지하고 보고와서 하자!!

	조건을 다시보니 열쇠랑 문이 a~f이기 때문에 최대 보유 경우가 64가지이다.
	그렇다면 visit[50][50][64]로 설정하여, 
	보유 열쇠의 합으로 관리해도 될듯하다.
	a 1
	b 2
	c 4
	d 8
	e 16
	f 32

	큰 틀 :
	- bfs로 이동
	- visit은 player의 열쇠 소유 값으로 확인한다.
	- 문에 도달했을 때, 'C' - 'A' 값의 배열 값 {1,2,4,8,16,32}에 접근하여
	둘의 &연산을 통해 1이 나오면 통과 0이면 막힘
	- key, door 를 islower, isDigit으로 판별

*/


#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct pos {
	int y;
	int x;
	int key; // 합으로 갖고 있을 예정
};

char map[50][50];
bool visit[50][50][64]; // 1~63
int bitNum[7] = { 1,2,4,8,16,32 };
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pos player;

int N, M;

void input();
int bfs(pos p);

int main()
{
	input();
	cout << bfs(player);
	
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == '0')
			{
				map[i][j] = '.';
				player.y = i;
				player.x = j;
				player.key = 0;
			}
		}
	}
}

int bfs(pos p)
{
	int dis = 0;
	queue<pos> que;
	que.push(p);
	visit[p.y][p.x][p.key] = true;
	int curY, curX, curKey;
	int ny, nx;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			pos cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;
			curKey = cur.key;

			if (islower(map[curY][curX]))
			{
				if((curKey & bitNum[map[curY][curX] - 'a']) == 0)
					curKey += bitNum[map[curY][curX] - 'a'];
			}

			if (isdigit(map[curY][curX])) // 1 발견
			{
				return dis;
			}

			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '#' || visit[ny][nx][curKey])
					continue;

				if (isupper(map[ny][nx]))
				{
					int keyNum = bitNum[map[ny][nx] - 'A'];
					if ((curKey&keyNum) != 0) // 보유하고있으면
					{
						que.push({ ny,nx,curKey });
						visit[ny][nx][curKey] = true;
					}
				}
				else
				{
					que.push({ ny,nx,curKey });
					visit[ny][nx][curKey] = true;
				}
			}
		}
		dis++;
	}
	return -1;
}
