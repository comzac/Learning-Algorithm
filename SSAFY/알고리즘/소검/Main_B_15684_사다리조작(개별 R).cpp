///*1635~
//	1. N개, M개, H개
//	2. 가로선은 인접할 수 없다.
//	3. i번 세로선의 결과가 i번이 나오게끔하는 가로선 최소 개수
//	4. b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미
//
//	풀이방식
//
//	순회) int ladder[21][31], ladder[s][e], ladder[e][s] 식으로 방향을 의미할 수 있는 1, -1을 입력한다.
//	위에서부터 순회하며 0이 아닌 수에 도달했을 때, 값에 따라 이동하도록
//
//	추가) 최대가 세개로 지정되어 있기때문에 위치별 1,2,3개까지 조사해보고 안될시에 리턴하면 된다.
//	그렇다면, 시간복잡도를 고려했을 때, 최대로 가정하고
//	1의 경우, 9*30 = 270
//	2의 경우, 270*269 = 72000
//	3의 경우, 270*269*268 = 19460000
//
//		핵심) 구간당 짝수의 가로줄이 존재해야 한다. 그럼 결과적으로 자기한테 돌아오게 돼있다.
//	필요 변수
//	int[][] 방향 (고정 가능)
//
//	순회하며 1)인접의 경우, 2) 범위 제한, 3) 일정 가로줄 개수를 설치한 경우, 확인
//
//	정답이 3보다 크면 -1, 불가능해도 -1
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm> // 넥퍼사용
//
//using namespace std;
//int X, lines, Y;
//int ladder[32][11]; // X는 0~10(11개) Y는 0~1~30~31 (32개) 
//bool isSuccess;
//int minimum = 5;
//
//bool searchLadder()
//{
//	//시작지점 0,lineNum 부터 아래로 Y에 도달했을 때, lineNum, destNum 비교
//	isSuccess = true;
//	bool isHorMove = false;
//	int curX;
//	for (int i = 1; i <= X; i++)
//	{
//		curX = i;
//		for (int j = 1; j <= Y; j++)
//		{
//			if (ladder[j][curX])
//				curX += 1;
//			else if (ladder[j][curX - 1])
//				curX -= 1;
//		}
//
//		if (curX != i)
//			return false;
//	}
//
//	return true;
//}
//void search(int cnt, int y) // 최대개수를 넘는지 확인할 cnt, 현지점을 파악할 y,x
//{
//	//기저조건
//	if (cnt > 3) // 3개를 넘지 않는다 했으니,
//		return;
//
//	if (searchLadder()) // 순회 // 제일 처음에 가로선 없는 상태에서도 진행
//	{
//		if (minimum > cnt)
//			minimum = cnt;
//		return;
//	}
//
//
//	for (int i = y; i <= Y; i++)
//	{
//		for (int j = 1; j <= X; j++)
//		{
//			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j-1]) // 설치조건 파악
//				continue;
//			ladder[i][j] = true;
//			search(cnt + 1, i);
//			ladder[i][j] = false;
//		}
//	}
//
//}
//int main()
//{
//	cin >> X >> lines >> Y; // X 세로 라인 수
//	int a, b;
//	for (int i = 0; i < lines; i++)
//	{
//		cin >> a >> b;
//		ladder[a][b] = true;
//	}
//
//	search(0, 1);
//
//	if (minimum == 5)
//		cout << -1;
//	else
//		cout << minimum;
//
//	return 0;
//}
