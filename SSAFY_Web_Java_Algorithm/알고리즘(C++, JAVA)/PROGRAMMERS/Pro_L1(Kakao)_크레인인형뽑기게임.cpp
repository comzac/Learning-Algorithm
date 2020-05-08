///* 1030~1045
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//queue<int> col[31];
//stack<int> side;
//
//int solution(vector<vector<int>> board, vector<int> moves) {
//	int answer = 0;
//	int size = board.size();
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (board[i][j] == 0)
//				continue;
//			col[j+1].push(board[i][j]);
//		}
//	}
//
//	for (int i = 0; i < moves.size(); i++)
//	{
//
//		if (col[moves[i]].empty())
//			continue;
//
//		int doll = col[moves[i]].front();
//		col[moves[i]].pop();
//
//		if (side.empty())
//		{
//			side.push(doll);
//		}
//		else
//		{
//			if (side.top() == doll)
//			{
//				answer += 2;
//				side.pop();
//			}
//			else
//			{
//				side.push(doll);
//			}
//		}
//	}
//
//	return answer;
//}
//int main()
//{
//	vector<vector<int>> v = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
//	vector<int> m = { 1,5,3,5,1,2,1,4 };
//	cout << solution(v, m);
//
//	return 0;
//}