///*
//	1. 만약 더 섭취해야 할 음식이 없다면 -1을 반환하면 된다.
//
//	효율성 테스트 제한 사항
//	food_times 의 길이는 1 이상 200,000 이하이다.
//	food_times 의 원소는 1 이상 100,000,000 이하의 자연수이다.
//	k는 1 이상 2 x 10^13 이하의 자연수이다.
//
//	이 문제는 정확성테스트 웬만해서 다 통과한다. 효율성 테스트가 관건이다.
//
//	풀이
//	1. struct 형태도 음식량과 인덱스를 새로운 벡터에 담는다.
//	2. 오름차순 정렬을 한다.
//	3. 순서대로 최소값와 사이즈를 비교해서 시간을 1초씩이 아닌 한 사이클 단위로 감소시킨다.
//	4. 3번 조건이 해당되지 않았을 때, 남은 값들을 별도의 벡터에 담아 인덱스 순서로 정렬시킨다.
//	5. 이후, 남은 시간만큼 순회하면 답이 나온다.
//
//	따라서, 인덱스 순서대로 정렬해줄 함수가 필요하다.
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Food {
//	int food;
//	int idx;
//
//	bool operator<(const Food &o) {
//		return food < o.food;
//	}
//};
//
//bool cmp(const Food &a, const Food &b)
//{
//	return a.idx < b.idx;
//}
//
//int solution(vector<int> food_times, long long k) {
//	int answer = 0;
//
//	vector<Food> foodIdxV;
//
//	int foodSize = food_times.size();
//	
//	for (int i = 0; i < foodSize; i++)
//	{
//		foodIdxV.push_back({ food_times[i], i });
//	}
//
//	sort(foodIdxV.begin(), foodIdxV.end()); // 남은 음식량 기준 정렬
//
//	long long totalMinus = 0;
//	long long time = k;
//	int i = 0;
//
//	for (; i < foodIdxV.size(); i++)
//	{
//		if ((foodIdxV[i].food-totalMinus) * foodSize <= time)
//		{
//			time -= (foodIdxV[i].food - totalMinus) * foodSize;
//			foodSize--;
//			totalMinus += foodIdxV[i].food - totalMinus;
//
//			if (foodSize == 0)
//				return -1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	vector<Food> idxFoodV;
//	for (int j = i; j < foodIdxV.size(); j++)
//	{
//		idxFoodV.push_back({ foodIdxV[j].food, foodIdxV[j].idx });
//	}
//
//	sort(idxFoodV.begin(), idxFoodV.end(), cmp);
//
//	int restSize = idxFoodV.size();
//
//	return idxFoodV[time % restSize].idx+1;
//
//}
//int main()
//{
//	vector<int> foodList = { 4, 3, 5, 6, 2 };
//	int k = 7;
//
//	cout << solution(foodList, k);
//
//	return 0;
//}