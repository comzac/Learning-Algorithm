//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> weight) {
//	int answer = 0;
//	sort(weight.begin(), weight.end());
//
//	vector<int> arrsum;
//	int temp = 0;
//	for (int i = 0; i < weight.size(); i++)		 
//	{											 
//		temp += weight[i];						 
//		arrsum.push_back(temp);					 
//	}											 
//												 
//	if (arrsum[0] != 1)							 
//		return 1;								// sum을 별도로 만드는 과정에서 즉각적인 비교도 가능하다 코드의 불필요한 부분을 제거하려고 노력해보자
//												 
//	for (int i = 0; i < weight.size()-1; i++)    
//	{											 
//		if (weight[i + 1] > arrsum[i] + 1)		 
//		{										 
//			return arrsum[i] + 1;				 
//		}										 
//	}											 
//												 
//	return arrsum[arrsum.size() - 1] + 1;
//}
//
//int main()
//{
//	vector<int> weight = { 3,1,6,2,7,30,1 };
//	cout << solution(weight) << endl;
//
//	return 0;
//}
