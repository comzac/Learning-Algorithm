//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//
//int solution(vector<vector<int>> triangle) {
//	int answer = 0;
//	int size = triangle.size();
//	vector<vector<int>> memo(size, vector<int>(size, 0));
//
//	for (int i = 0; i < triangle.size(); i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (i == 0 && j == 0)
//				memo[i][j] = triangle[i][j];
//			else if (j == 0)
//			{
//				memo[i][j] = memo[i - 1][j] + triangle[i][j];
//			}
//			else if (j == triangle[i].size() - 1)
//			{
//				memo[i][j] = memo[i - 1][j - 1] + triangle[i][j];
//			}
//			else
//			{
//				memo[i][j] = max(memo[i - 1][j - 1] + triangle[i][j], memo[i - 1][j] + triangle[i][j]);
//			}
//		}
//	}
//
//	
//	for (int i = 0; i < memo[memo.size()-1].size(); i++)
//	{
//		answer = max(memo[memo.size() - 1][i],answer);
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector < vector<int>> tri = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
//	cout << solution(tri) << endl;
//
//
//	return 0;
//}