#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Dist;
int N;
int minVal = 987654321;


void check(vector<int>& weak)
{
	sort(Dist.begin(), Dist.end());

	do {
		int wIdx = 0;
		int dIdx = 0;
	
		while (wIdx != weak.size())
		{
			int endPoint = weak[wIdx] + Dist[dIdx];

			while (endPoint >= weak[wIdx])
			{
				wIdx++;
				
				if (wIdx == weak.size())
					break;
			}

			dIdx++;
			if (dIdx == Dist.size())
				break;
		}
		
		if (minVal > dIdx && wIdx == weak.size())
			minVal = dIdx;


	} while (next_permutation(Dist.begin(), Dist.end()));
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	N = n;


	int cnt = 0;

	while (true)
	{
		// func
		Dist = dist;

		check(weak);

		int front = weak[0];
		weak.erase(weak.begin());
		weak.push_back(front + n);

		cnt++;
		if (cnt == weak.size())
			break;
	}

	if (minVal == 987654321)
		minVal = -1;
	answer = minVal;

	return answer;
}

int main() {


	int n = 12;
	vector<int> weak = { 1,5,6,10 };
	vector<int> dist = { 1,2,3,4 };
	//vector<int> weak = { 1,5,10 };
	//vector<int> dist = { 2,2 };
	//vector<int> weak = { 1,3,4,9,10 };
	//vector<int> dist = { 3,5,7 };
	cout << solution(n, weak, dist);


	return 0;
}