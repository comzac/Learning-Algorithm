//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void recurse(vector<int> numbers, int sum, int target, int index, int& count)
//{
//	if (index == numbers.size())
//	{
//		if (sum == target)
//			count++;
//		return;
//	}
//
//	recurse(numbers, sum + numbers[index], target, index + 1, count);
//	recurse(numbers, sum - numbers[index], target, index + 1, count);
//}
//
//
//int solution(vector<int> numbers, int target) {
//	int answer = 0;
//	int sum = 0;
//	int count = 0;
//
//	recurse(numbers, sum, target, 0, count);
//	return count;
//}
//
//int main()
//{
//	vector<int> numbers = { 1,1,1,1,2 };
//	int target = 4;
//	/*
//	1+1+1-1+2
//	1+1-1+1+2
//	1-1+1+1+2
//	-1+1+1+12
//
//	*/
//	/*
//	DFS·Î Çª´Â°Ô ¾î¶³±î½ÍÀ½
//
//
//	*/
//
//	cout << solution(numbers, target) << endl;
//
//
//	return 0;
//}