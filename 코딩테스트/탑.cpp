#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> st;
	stack<int> finalSt;
	deque<int> que;
	int count = 0;
	int length = heights.size();

	for (int i = 0; i < length; i++)
	{
		st.push(heights[i]);
	}

	while (!st.empty())
	{
		count = finalSt.size();

		que.push_back(st.top());
		st.pop();
	
		if (!st.empty())
		{
			while (que.front() >= st.top())
			{
				count++;
				que.push_back(st.top());
				st.pop();
				if (st.empty())
					break;
			}
		}

		finalSt.push(length - count - 1);

		while (!que.empty())
		{
			st.push(que.back());
			que.pop_back();
		}
		st.pop();
	}

	while (!finalSt.empty())
	{
		answer.push_back(finalSt.top());
		finalSt.pop();
	}
	return answer;
}


int main()
{
	/*	
		
		6  9  5  7  4



	*/
	vector<int> height = { 1,5,3,6,7,6,5};

	for(int i = 0 ; i < solution(height).size(); i++)
		cout << solution(height)[i] << endl;

	//solution(progresses, speeds);
	return 0;

}