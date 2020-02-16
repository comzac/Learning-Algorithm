///* 1830~1945
//	1. 걷는 경우, +1만 된다면 넘어가는 경우를 고려해야겠지만 -1도 가능하기 때문에 절대거리가 가까운
//	경우를 구하면 될듯하다.
//	2. 걷기와 순간이동을 비교하여 절대거리가 짧은 경우를 선택하는 방식으로 진행하면 될 거 같다.
//	-> 망했다.
//	3. bfs로 재도전
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//
//int sister;
//int bfs(int subin);
//int minVal = 99999999;
//bool visit[100001];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int sb;
//
//	cin >> sb >> sister;
//
//	cout << bfs(sb);
//
//	return 0;
//}
//
//int bfs(int subin)
//{
//	queue<int> que;
//	que.push(subin);
//	int size;
//	int time = 0;
//	while (!que.empty())
//	{
//		size = que.size();
//		bool isOk = false;
//		while (size-- > 0)
//		{
//			int curX = que.front();
//			que.pop();
//			visit[curX] = true;
//
//			if (curX == sister)
//			{
//				isOk = true;
//				if (minVal > time)
//					minVal = time;
//			}
//			else if (curX > sister)
//			{
//				if (minVal > time + curX - sister)
//					minVal = time + curX - sister;
//			}
//
//			if (curX - 1 >= 0 && !visit[curX - 1])
//				que.push(curX - 1);
//			if (curX + 1 <= 100000 && !visit[curX + 1])
//				que.push(curX + 1);
//			if (curX * 2 <= 100000 && curX*2 != 0 && !visit[curX*2])
//				que.push(curX * 2);
//		}
//
//		if (isOk)
//			break;
//		time++;
//	}
//	return time;
//}
