//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<int> prices) {
//	vector<int> answer;
//	int temp;
//	for (int i = 0; i < prices.size(); i++)
//	{
//		temp = 0;
//		for (int j = i; j < prices.size()-1; j++)
//		{	
//			if (prices[i] > prices[j])
//			{
//				temp = j - i;
//				break;
//			}
//			else
//				temp++;
//		}
//		answer.push_back(temp);
//	}
//	return answer;
//}
//
//
//int main()
//{
//	/*	
//		
//		6  9  5  7  4
//
//
//
//	*/
//	vector<int> price = { 498,501,470,489 };
//
//	for(int i = 0 ; i < solution(price).size(); i++)
//		cout << solution(price)[i] << endl;
//
//	//solution(progresses, speeds);
//	return 0;
//
//}