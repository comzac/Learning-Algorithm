#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
struct Pred {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

bool Pred1(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	priority_queue<vector<int>, vector<vector<int>>, Pred> temp;
	sort(jobs.begin(), jobs.end(), Pred1);
	vector<int> temp1;
	int answer = 0;
	int total = 0;
	int work = 0;   //현재 수행한 작업
	int need_work = 0;  //해야할 작업
	int i = 0;
	while (1) {
		while (i != jobs.size()) {
			if (jobs[i][0] == work)
			{
				temp.push(jobs[i]);
				i++;
			}
			else break;
		}
		if (need_work <= 0 && !temp.empty())
		{
			temp1 = temp.top();
			temp.pop();
			need_work = temp1[1];
			total += temp1[1];
		}

		total += temp.size();
		need_work--;
		work++;
		if (temp.empty() && need_work == 0 && i == jobs.size()) {
			break;
		}
	}
	answer = total / jobs.size();
	return answer;
}

int main()
{
	/*

	*/
	// { 0,1   1,1}
	vector<vector<int>> jobs = { {0,3},{1,9},{2,6},{4,8},{5,1} };

	cout << solution(jobs) << endl;

	return 0;
}