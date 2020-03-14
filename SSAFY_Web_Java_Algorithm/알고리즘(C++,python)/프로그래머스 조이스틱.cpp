//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
///*
//	위아래로 어디가 가까울지
//	좌우로 최소 이동 횟수 해야할지
//	ABAAABA 1 + 4 / 1 + 3 
//	ABAAABBBAAAAAAAB 1 + 4 + 1 + 1 + 8 / 1 + 2 + 8 + 1 + 1
//	ABAABAB 1 + 2 + 2 / 1 + 3 + 2
//	  a B 
//	A     B
//	B     A
//	  B A
//*/
//
////A = 65
////Z = 90
////90 - 65 = 25 -> 알파벳 26개
////정방향 int(해당 문자) - 65
////역방향 (90 - 해당문자) + 1
////ex) D라면, 68
//// 68 - 65 = 3
//// 90 - 68 = 22
//// 65 66 ..... 89 90
//// 
//int check[20];
//int len;
//
//int rdistance(int cur, int idx)
//{
//	int distance;
//	if (idx >= cur)
//		distance = idx - cur;
//	else
//		distance = len-cur + idx;
//	return distance;
//}
//
//int ldistance(int cur, int idx)
//{
//	int distance;
//	if (idx <= cur)
//		distance = cur - idx;
//	else
//		distance = cur + len - idx;
//	return distance;
//}
//
//int wordcount(const char curword)
//{
//	int wn = int(curword);
//	int up, down;
//
//	up = wn - 65;
//	down = 90 - wn+1;
//
//	return up <= down ? up : down;
//}
//
//int solution(string name) {
//	int answer = 0;
//	int wr, wl;
//	int cur = 0; // 시작
//	int rc, lc;  // r, c current
//	int rd, ld;  // r, c 거리
//	len = name.length();
//	// ABAAAABA
//	int roop = 0;
//	for (int i = 0; i < len; i++)
//		if (name[i] == 'A')
//			roop++;
//	roop = len - roop;
//	while (roop-- != 0)
//	{
//		wr = wl = -1;
//		rc = lc = cur;
//		while (wr == -1)
//		{
//			if (!check[rc] && name[rc] != 'A')
//			{
//				wr = rc;
//			}
//			else
//			{
//				rc++;
//				if (rc == cur)
//					break;
//			}
//
//			if (rc >= len)
//				rc = 0;
//		}
//
//		while (wl == -1)
//		{
//			if (!check[lc] && name[lc] != 'A')
//			{
//				wl = lc;
//			}
//			else
//			{
//				lc--;
//				if (lc == cur)
//					break;
//			}
//			if (lc < 0)
//				lc = len - 1;
//		}
//
//		rd = rdistance( cur, rc);
//		ld = ldistance( cur, lc);
//		
//		if (rd <= ld)
//		{
//			answer += rd;
//			cur = rc;
//			check[rc] = true;
//			answer += wordcount(name[rc]);
//		}
//		else
//		{
//			answer += ld;
//			cur = lc;
//			check[lc] = true;
//			answer += wordcount(name[lc]);
//
//		}
//
//	}
//
//	return answer;
//}
//
//int main()
//{
//
//	cout << solution("ACA");
//
//	return 0;
//}