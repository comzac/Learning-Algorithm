#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int sum = brown + red;
	int width;
	int height;
	int i = 3;

	while (1)
	{
		if (sum%i == 0)
		{
			width = i;
			height = sum / i;

			if (red == (width - 2)*(height - 2) && width >= height)
			{
				answer.push_back(width);
				answer.push_back(height);
				break;
			}
		}
		i++;
	}

	return answer;
}

int main()
{

	int brown[3] = { 10,8,24 };
	int red[3] = { 2,1,24 };

	for (int i = 0; i < 3; i++)
	{
		for(int j = 0 ; j < solution(brown[i], red[i]).size(); j++)
			cout << solution(brown[i], red[i])[j] << endl;
	}


	return 0;
}