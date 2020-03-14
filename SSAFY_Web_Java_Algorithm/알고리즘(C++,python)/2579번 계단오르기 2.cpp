//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
///*
//1,2 점프가능
//연속 1,1,1 불가능
//마지막 꼭 밟기
//시작점 상관없기
//최소 횟수는 조건에 ㄴㄴ
//점수 최대값이 중요
//*/
//
///*
//	dn = dn-1 + vn
//	dn = dn-2 + vn
//
//	d3 = v1+v3
//	d3 = v2+v3
//	d2 = v1+v2
//	d4 = d3+v4 = v2+v3+v4
//	d4 = d2+v4 = v1+v2+v4
//	10 20 1000 10 2000 
//	3020 = 20+1000+2000  ->
//	2040 = 10+20+10+2000 ->
//
//*/
//
//int stair[301];
//int maxst[301][2];
//int top;
//
//// 0 비연속, 1 연속
//int sol()
//{
//	int answer = 0;
//
//	maxst[1][0] = stair[1];
//	maxst[2][0] = stair[2];
//	maxst[2][1] = stair[1] + stair[2];
//
//	for (int i = 3; i <= top; i++)
//	{
//		maxst[i][0] = max({ maxst[i][0], maxst[i - 2][0] + stair[i], maxst[i - 2][1] + stair[i] });
//		maxst[i][1] = max(maxst[i][1], maxst[i - 1][0]+ stair[i]);
//	}
//
//	answer = max(maxst[top][0], maxst[top][1]);
//	return answer;
//}
//
//int main()
//{
//	cin >> top;
//	int temp;
//	for (int i = 1; i <= top; i++)
//	{
//		cin >> temp;
//		stair[i] = temp;
//	}
//
//	cout << sol();
//
//	
//	return 0;
//}
//
////6
////1000
////1000
////1000
////10
////10
////10