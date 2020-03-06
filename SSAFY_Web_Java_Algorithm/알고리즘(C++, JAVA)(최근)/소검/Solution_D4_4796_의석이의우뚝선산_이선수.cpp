///* 1950~2120
//
//	1. 10개 1초, 256MB
//	2. 문제는 나열된 산을 보고 여기서 제시하는 우뚝 선 산의 '구간'의 갯수를 구하는것이다.
//
//	풀이 : 
//	
//	시작점과 끝점을 갖는 큰 최고 우뚝산을 찾는다.
//	그리고 가장 높은 꼭대기 인덱스를 갖고
//	좌측값 * 우측값으로 구간을 알 수 있다.
//
//	이후, 이 끝점은 새로운 시작점이 되며, 우뚝 산은 찾는다. 
//
//	쓰다보니 이게 답같다
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int height[50001];
//int N;
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N;
//		for (int i = 1; i <= N; i++)
//			cin >> height[i];
//
//		int startIdx;
//		int endIdx;
//		int highestIdx;
//		startIdx = highestIdx = 1;
//		endIdx = 2;
//		int oldHeight;
//		oldHeight = height[startIdx];
//		bool isClimb = height[startIdx] < height[endIdx];
//		int answer = 0;
//		while (endIdx != N+1)
//		{
//			if (isClimb)
//			{
//				if (oldHeight < height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					endIdx++;
//
//				}
//				else if (oldHeight > height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					highestIdx = endIdx - 1;
//					endIdx++;
//					isClimb = false;
//				}
//			}
//			else
//			{
//				if (oldHeight > height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					endIdx++;
//
//				}
//				else if (oldHeight < height[endIdx])
//				{
//					answer += (highestIdx - startIdx) * (endIdx - 1 - highestIdx);
//					startIdx = endIdx - 1;
//					endIdx = startIdx;
//					endIdx++;
//					isClimb = true;
//				}
//			}
//			if (!isClimb && endIdx == N + 1)
//			{
//				if (endIdx == N + 1)
//				{
//					answer += (highestIdx - startIdx) * (endIdx - 1 - highestIdx);
//				}
//			}
//		}
//		cout << "#" << t << " " << answer << endl;
//	}
//
//
//	return 0;
//}
//
///*
//1
//7
//9 7 2 4 5 3 1
//
//
//*/