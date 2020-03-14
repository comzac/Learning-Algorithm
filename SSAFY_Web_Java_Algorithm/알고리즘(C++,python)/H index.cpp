#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int length = citations.size();

	sort(citations.begin(), citations.end());

	for (int i = 0; i < length ; i++)
	{
		if (citations[i] >= length - i)
		{
			answer = length - i;
			break;
		}
	
	}
	return answer;
}

int main()
{
	/*
                         0 1 2 3 4 5   LEN = 6
	 이런 경우가 있겠군!	 0 1 2 5 6 7
	 이런 경우 답은 3인데
	 위의 함수로는 2가 나오겠군

	    0 1 2 3 4 5 6 7 8 9

		1,1,1,4,8,6,3,2,0,6  
		0,1,1,1,2,3,4,6,6,8   len = 10 

		1,4,8,6,3,4,0,6
		0,1,3,4,4,6,6,8
	*/
	vector<int> array = { 0,1,3,5,6 };
	//					  0,1,3,5,6    len = 5
	cout << solution(array) << endl;


	return 0;
}