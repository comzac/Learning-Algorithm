///* 0305~0415 1H15M
//	1. 1초 256MB
//
//	풀이 :
//	일부만 채워진 매직스타라고 했으니, 최소 1개는 주어줄테고,
//	그럼 최대 11! 의 경우의 수를 검사해보면 된다.
//
//	스팟이 12개니깐, 일일이 지정해줘도 될 듯 하다.
//	5*9
//	조합을 짜내려가는 중, 26를 넘는 상황이 발생되면 백트래킹을 시전해준다.
//
//	각 라인의 총합을 나타낼 변수 6개
//	각 위치에 따른 라인을 알려줄 함수,
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
//};
//
//char map[5][9]; // 수정을 계속 진행할 것이다.
//int line[7]; // 1~6번 라인
//vector<pos> totalPos = { {0,4},{1,1},{1,3},{1,5},{1,7},{2,2},{2,6},{3,1},{3,3},{3,5},{3,7},{4,4} };
//bool numCheck[13];
//bool isFind;
//
//void input();
//vector<int> searchLine(pos cur);
//void combi(int idx);
//int main()
//{
//	input();
//	combi(0);
//
//	return 0;
//}
//
//void input()
//{
//	string temp;
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < 9; j++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] != '.' && temp[j] != 'x') // 알파벳
//			{
//				vector<int> nums = searchLine({ i,j });
//				for (int k = 0; k < nums.size(); k++)
//				{
//					line[nums[k]] += temp[j] - 'A' + 1;
//				}
//				numCheck[temp[j] - 'A' + 1] = true; // 이미 사용된 문자들
//			}
//		}
//	}
//}
//
//
//void combi(int idx)
//{
//	if (idx == 12) // 모든 위치를 만족하는 경우,
//	{
//		bool isSuccess = true;
//
//		for (int i = 1; i <= 6; i++)
//		{
//			if (line[i] != 26)
//			{
//				isSuccess = false;
//				break;
//			}
//		}
//
//		if (!isSuccess)
//			return;
//
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				cout << map[i][j];
//			}
//			cout << endl;
//		}
//
//		isFind = true;
//		return;
//	}
//
//	int y = totalPos[idx].y;
//	int x = totalPos[idx].x;
//
//	if (map[y][x] != 'x')
//	{
//		combi(idx + 1);
//		if (isFind)
//			return;
//	}
//	else // x면,
//	{
//		vector<int> lines = searchLine({ y,x });
//		bool isOver;
//		for (int i = 1; i <= 12; i++)
//		{
//			if (numCheck[i])
//				continue;
//			isOver = false;
//			for (int j = 0; j < lines.size(); j++)
//			{
//				if (line[lines[j]] + i > 26) // 현재 라인에 합이 26이 넘는다,
//				{
//					isOver = true;
//					break;
//				}
//			}
//			if (isOver) // 넘어가는 라인이 있으니깐 이 수는 넘어감
//				break;
//
//			map[y][x] = (char)('A' + i - 1); // 해당 문자로 바꿔주고
//			for (int j = 0; j < lines.size(); j++)
//			{
//				line[lines[j]] += i; // 수 더해주고,
//			}
//			numCheck[i] = true;
//			combi(idx + 1); // 다음 단계 넘겨주고,
//			if (isFind)
//				return;
//			numCheck[i] = false; // 해당 문자가 실패했으니 다시 false시켜주고,
//			for (int j = 0; j < lines.size(); j++)
//			{
//				line[lines[j]] -= i; // 수 빼주고,
//			}
//			map[y][x] = 'x';
//		}
//	}
//
//
//}
//
//vector<int> searchLine(pos cur)
//{
//	int y = cur.y;
//	int x = cur.x;
//
//	if (y == 0 && x == 4)
//	{
//		return { 1,3 };
//	}
//	else if (y == 1)
//	{
//		if (x == 1)
//		{
//			return { 4,5 };
//		}
//		else if (x == 3)
//		{
//			return { 1,4 };
//		}
//		else if (x == 5)
//		{
//			return { 3,4 };
//		}
//		else
//		{
//			return { 4,6 };
//		}
//	}
//	else if (y == 2)
//	{
//		if (x == 2)
//		{
//			return { 1,5 };
//		}
//		else
//		{
//			return { 3,6 };
//		}
//	}
//	else if (y == 3)
//	{
//		if (x == 1)
//		{
//			return { 1,2 };
//		}
//		else if (x == 3)
//		{
//			return { 2,5 };
//		}
//		else if (x == 5)
//		{
//			return { 2,6 };
//		}
//		else
//		{
//			return { 2,3 };
//		}
//	}
//	else
//	{
//		return { 5,6 };
//	}
//
//	return { 0 };
//}
