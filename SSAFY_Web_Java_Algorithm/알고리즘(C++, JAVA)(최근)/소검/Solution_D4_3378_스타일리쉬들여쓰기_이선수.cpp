///*
//
//9
//5 4
//(Follow.my.style
//.........starting.from.round.brackets)
//{then.curly.brackets
//.....[.and.finally
//.......square.brackets.]}
//(Thank.you
//{for.showing.me
//[all
//the.secrets]})
//
//마스터가 몇 번 들여쓰기를 하는지 정확하지 않아서
//자신의 코드도 몇 번 들여쓰기를 해야 하는지 유일하게 결정되지 않는다면 -1을 출력한다.
//*/
//
//#include <iostream>
//#include <string>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//
//int p, q;
//string ex[10];
//string test[10];
//bool RCS[21][21][21];
//stack<int> rs, cs, ss;
//int R, C, S;
//vector<int> answer;
//
//void input();
//void init();
//void rcsCheck(int dr, int dc, int ds, int cnt);
//void pointCheck();
//int findRCS(int dr, int dc, int ds);
//void caseTest();
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		init();
//		pointCheck();
//		caseTest();
//		cout << "#" << t << " ";
//		for (int i = 0; i < answer.size(); i++)
//			cout << answer[i] << " ";
//		cout << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> p >> q;
//	for (int i = 0; i < p; i++)
//		cin >> ex[i];
//	for (int i = 0; i < q; i++)
//		cin >> test[i];
//}
//
//void init()
//{
//	for (int i = 1; i < 21; i++)
//	{
//		for (int j = 1; j < 21; j++)
//		{
//			for (int k = 1; k < 21; k++)
//			{
//				RCS[i][j][k] = true; // 모든 게 된다고 가정하고, 하나씩 검사
//			}
//		}
//	}
//
//	answer.clear();
//	while (!rs.empty()) rs.pop();
//	while (!cs.empty()) cs.pop();
//	while (!ss.empty()) ss.pop();
//
//}
//
//void rcsCheck(int dr, int dc, int ds, int cnt)
//{
//	for (int i = 1; i < 21; i++)
//	{
//		for (int j = 1; j < 21; j++)
//		{
//			for (int k = 1; k < 21; k++)
//			{
//				if (!RCS[i][j][k])
//					continue;
//				if (i*dr + j * dc + k * ds != cnt)
//					RCS[i][j][k] = false;
//			}
//		}
//	}
//}
//
//void pointCheck()
//{
//	bool isPoint;
//	int cnt;
//	for (int i = 0; i < p; i++)
//	{
//
//		isPoint = false;
//		cnt = 0;
//		for (int j = 0; j < ex[i].length(); j++)
//		{
//			if (ex[i][j] == '.' && j == 0)
//			{
//				isPoint = true;
//			}
//
//			if (isPoint)
//			{
//				if (ex[i][j] == '.')
//				{
//					cnt++;
//				}
//				else
//				{
//					rcsCheck(rs.size(), cs.size(), ss.size(), cnt);
//					isPoint = false;
//				}
//			}
//
//			switch (ex[i][j])
//			{
//			case '(':
//				rs.push(ex[i][j]);
//				break;
//			case ')':
//				if (rs.top() == '(')
//					rs.pop();
//				break;
//			case '{':
//				cs.push(ex[i][j]);
//				break;
//			case '}':
//				if (cs.top() == '{')
//					cs.pop();
//				break;
//			case '[':
//				ss.push(ex[i][j]);
//				break;
//			case ']':
//				if (ss.top() == '[')
//					ss.pop();
//				break;
//			default:
//				break;
//			}
//		}
//			
//	}
//}
//
//int findRCS(int dr, int dc, int ds)
//{
//	int oldVal = -1;
//	int newVal = -1;
//
//	for (int i = 1; i < 21; i++)
//	{
//		for (int j = 1; j < 21; j++)
//		{
//			for (int k = 1; k < 21; k++)
//			{
//				if (RCS[i][j][k])
//				{
//					newVal = dr * i + dc * j + ds * k;
//					if (oldVal != -1)
//					{
//						if (oldVal != newVal)
//							return -1;
//					}
//					else
//					{
//						oldVal = newVal;
//					}
//				}
//			}
//		}
//	}
//
//	return newVal;
//}
//
//void caseTest()
//{
//	stack<int> r, c, s;
//	for (int i = 0; i < q; i++)
//	{
//		int spaceVal = findRCS(r.size(), c.size(), s.size());
//		answer.push_back(spaceVal);
//		for (int j = 0; j < test[i].length(); j++)
//		{
//			switch (test[i][j])
//			{
//			case '(':
//				r.push(test[i][j]);
//				break;
//			case ')':
//				if (r.top() == '(')
//					r.pop();
//				break;
//			case '{':
//				c.push(test[i][j]);
//				break;
//			case '}':
//				if (c.top() == '{')
//					c.pop();
//				break;
//			case '[':
//				s.push(test[i][j]);
//				break;
//			case ']':
//				if (s.top() == '[')
//					s.pop();
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	
//}
//
///*
//1
//5 4
//(Follow.my.style
//.........starting.from.round.brackets)
//{then.curly.brackets
//.....[.and.finally
//.......square.brackets.]}
//(Thank.you
//{for.showing.me
//[all
//the.secrets]})
//
//*/