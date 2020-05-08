/* 2123~

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXVAL 200000001
int solution(vector<int> stones, int k) {
	int answer = 0;
	int len = stones.size();
	bool isFlag;
	int maxVal = MAXVAL;
	int minVal = 1;
	int offset;
	while (true)
	{
		int continueCnt = 0;
		isFlag = true;
		offset = (minVal + maxVal) / 2;

		for (int i = 0; i < len; i++)
		{
			if (stones[i] - offset <= 0)
				continueCnt++;
			else
				continueCnt = 0;

			if (continueCnt >= k)
			{
				isFlag = false;
				break;
			}
		}


		if (!isFlag)
		{
			maxVal = offset-1;		
		}
		else
		{
			minVal = offset+1;
		}

		if (minVal > maxVal)
		{
			answer = minVal;
			break;
		}
	}
	return answer;
}
int main()
{
	vector<int> a = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 4;
	cout << solution(a, k);
	return 0;
}