#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int k) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	
	while (pq.top() < k)
	{
		answer++;
		if (pq.size() == 1)
			return -1;
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		int newDish = x + y * 2;
		pq.push(newDish);

	}
	return answer;
}

int main()
{
	vector<int> scoville = { 1,2,3,9,10,12 };

	int k = 7;
	
	cout << solution(scoville, k) << endl;

	return 0;
}