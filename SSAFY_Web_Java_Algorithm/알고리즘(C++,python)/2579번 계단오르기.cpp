//#include <iostream>
//#include <string>
//
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
//*/
//
//int stair[301];
//int maxst[301];
//int top;
//int flag;
//
//int dp(int level)
//{
//	if (level < 1)
//		return 0;
//	if (level == 1)
//	{
//		if (flag <= 1)
//		{
//			flag++;
//			return maxst[1] = stair[1];
//		}
//		else
//			return 0;
//
//	}
//	else if (level == 2)
//	{
//		if (flag == 0)
//		{
//			maxst[2] = stair[1] + stair[2];
//			flag += 2;
//		}
//		else
//		{
//			maxst[2] = stair[2];
//		}
//		return maxst[2];
//	}
//
//
//
//	int m1, m2;
//	m1 = m2 = 0;
//
//	if (flag < 2)
//	{
//		if (maxst[level - 1] == 0)
//		{
//			m1 = dp(level - 1) + stair[level];
//		}
//		else
//		{
//			m1 = maxst[level - 1] + stair[level];
//		}
//	}
//
//
//	if (maxst[level - 2] == 0)
//	{
//		m2 = dp(level - 2) + stair[level];
//	}
//	else
//	{
//		m2 = maxst[level - 2] + stair[level];
//	}
//
//
//	if (m1 > m2)
//	{
//		maxst[level] = m1;
//		flag++;
//	}
//	else
//	{
//		maxst[level] = m2;
//		flag = 0;
//	}
//
//	return maxst[level];
//}
//
//int sol()
//{
//	return dp(top);
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