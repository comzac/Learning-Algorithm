#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int comNum, vector<bool>& check, vector<vector<int>> temp)
{
	if (check[comNum])
		return;
	check[comNum] = true;
	for (int i = 0; i < temp[comNum].size(); i++)
	{
		int NextComNum = temp[comNum][i];
		DFS(NextComNum, check, temp);
	}
}


int solution(int n, vector<vector<int>> computers) {
	
	int answer = 0;
	
	vector<vector<int>> temp;
	vector<int> miniTemp;

	vector<bool> check;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (computers[i][j] == 1)
				miniTemp.push_back(j);
		}
		temp.push_back(miniTemp);
		miniTemp.clear();
		check.push_back(false);
	}

	for (int i = 0; i < check.size(); i++)
	{
		if (!check[i])
		{
			DFS(i, check, temp);
			count++;
		}
	}

	answer = count;
	return answer;
}


int main()
{
	//풀이 방식이 같지만 굳이 그래프형성을 할 필요없었던거같다
	//그리고 값들이 0,1로 이루어진 경우 true ,false 개념으로도 사용가능함을 명시하자! 코드를 줄일수있다.
	int n = 3;
	//vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
	vector<vector<int>> computers = { {1,1,0},{1,1,1},{0,1,1} };

	cout << solution(n, computers) << endl;

	return 0;
}