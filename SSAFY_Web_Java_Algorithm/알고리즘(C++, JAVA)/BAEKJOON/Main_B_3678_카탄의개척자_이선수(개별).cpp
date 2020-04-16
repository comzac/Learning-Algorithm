///* 0050~0250
//	1. 1초 128MB
//	2.
//	각 타일은 자원을 하나씩 포함하고 있다. 
//	자원은 총 다섯 가지 종류가 있으며, 점토, 재목, 양모, 곡물, 광석이다.
//	각 자원은 1부터 5까지 순서로 나타낼 수 있다.
//	- 새로운 타일은 '이미' 채워진 인접한 타일에 들어있는 자원과 다른 자원이어야 한다.
//	- 가능한 자원이 여러 가지인 경우에는, 보드에 가장 적게 나타난 자원을 선택한다.
//	- 그러한 경우도 여러 가지라면, 번호가 작은 것을 선택한다.
//	테스트 케이스의 개수 c (1 ≤ c ≤ 200)
//	정수 n이 주어진다. (1 ≤ n ≤ 10000)
//
//	n이 10000이면 연산해도 될 거 같은데,
//	육각형이 완성되는 순간만 인접한 곳이 3곳이고,
//	평소에는 2개이다.
//	따라서,
//	1, 1+6, 1+6+12 와 같은 지역은, 본인 라인의 직전, 처음, 전라인의 마지막 번호를 검사하면 된다.
//	뿐만 아니라, 꼭지점? 각진 부분이 아닌 부분들도 인접지역이 세군데다.
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int catan[10001];
//int c;
//int cmd[200];
//int largeNum;
//int cnt[6]; // 1~5 횟수,
//
//void input();
//int findNum(vector<int> van);
//int edge(int lineNum, int num);
//int main()
//{
//	input();
//	catan[1] = 1;	catan[2] = 2;	catan[3] = 3;	
//	catan[4] = 4;	catan[5] = 5;
//	catan[6] = 2;	catan[7] = 3;
//	// 여기까지 딱 두라인,
//	
//	// cnt 정정
//	for (int i = 1; i <= 7; i++)
//	{
//		cnt[catan[i]]++;
//	}
//
//	int line = 2; // 1이 0라인,
//	int edgeNum = 1;
//	int curEdge = edge(line, edgeNum);
//	int back, oldCompare, oldCompareNext;
//	int oldLineFirst;
//	oldLineFirst = 2;
//	bool isNewLine = true;
//	for (int i = 8; i <= largeNum; i++) // 6부터 최대 번호까지 완성한 뒤,
//	{
//		if (isNewLine) // 처음 라인에 들어섰을 때, 이전 번호와, 전 라인 첫 번호 비교
//		{
//			back = i-1;
//			oldCompare = oldLineFirst;
//			oldCompareNext = oldLineFirst;
//			catan[i] = findNum({ catan[back], catan[oldLineFirst] });
//			isNewLine = false;
//			oldLineFirst = i; // 이전 라인 새로운 값 초기화
//		}
//		else
//		{
//			if (i == curEdge) // 이전 비교번호, 전 번호
//			{
//				if (edgeNum == 6)
//				{
//					back = i - 1;
//					oldCompare = oldCompareNext;
//					oldCompareNext = oldLineFirst;
//					catan[i] = findNum({ catan[back], catan[oldCompare], catan[oldCompareNext] });
//					line++;
//					edgeNum = 1;
//					curEdge = edge(line, edgeNum);
//					isNewLine = true;
//				}
//				else
//				{
//					back = i - 1;
//					oldCompare = oldCompareNext;
//					catan[i] = findNum({ catan[back], catan[oldCompare] });
//					edgeNum++;
//					curEdge = edge(line, edgeNum);
//				}
//			}
//			else // edge가 아닐땐, 1) 이전 번호, 이전 비교 번호, 이전 비교 번호 다음
//			{
//				back = i - 1;
//				oldCompare = oldCompareNext;
//				oldCompareNext = oldCompare + 1;
//				catan[i] = findNum({ catan[back], catan[oldCompare], catan[oldCompareNext] });
//			}
//		}
//	}
//
//	for (int i = 0; i < c; i++) // 정답출력,
//	{
//		cout << catan[cmd[i]] << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> c;
//	for (int i = 0; i < c; i++)
//	{
//		cin >> cmd[i];
//		if (cmd[i] > largeNum)
//			largeNum = cmd[i];
//	}
//}
//
//int findNum(vector<int> van)
//{
//	int minIdx;
//	int minVal = 999999999;
//
//	bool isAble;
//	for (int i = 1; i <= 5; i++)
//	{
//		isAble = true;
//
//		for (int j = 0; j < van.size(); j++)
//		{
//			if (i == van[j])
//			{
//				isAble = false;
//				break;
//			}
//		}
//		if (!isAble)
//			continue;
//		if (minVal > cnt[i])
//		{
//			minVal = cnt[i];
//			minIdx = i;
//		}
//	}
//
//	cnt[minIdx]++;
//	return minIdx;
//}
//
//int edge(int lineNum, int num)
//{
//	return 1 + 3* lineNum*(lineNum +1) - (6-num)*lineNum; // 계차수열
//}
