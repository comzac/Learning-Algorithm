//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
///* 
//운이 좋아서 거진 15분만에 푼 듯하다.
//문제가 변형되며 범위에 맞게 효율성을 고려해야 했다.
//works 배열의 모든값을 접근하며 최대값을 감소시켜주는 방식을 고려하자니
//n의 최대값 * works의 최대길이를 고려했을 때 효율성 문제가 있을거로 판단되었고
//algorithm의 sort의 경우에도 연산량의 문제점이 보였다.
//따라서, 효과적인 정렬과 최대값을 찾을 수 있는 방법이 무엇일까 생각하다가
//우선순위큐(max heap)이 떠올라 적용해봤고 좋은 성적으로 통과!
//
//*/
//using namespace std;
//
//long long solution(int n, vector<int> works) {
//	long long answer = 0;
//	priority_queue<int> que;
//	int num = n;
//	for (int i = 0; i < works.size(); i++)
//	{
//		que.push(works[i]);
//	}
//
//	int temp = 0;
//
//	while (num != 0)
//	{
//		temp = que.top();
//		que.pop();
//		if (temp == 0)
//			return 0;
//		que.push(temp - 1);
//		num--;
//	}
//
//	long long sum = 0;
//	while (!que.empty())
//	{
//		sum += que.top() * que.top();
//		que.pop();
//	}
//
//	answer = sum;
//	return answer;
//}
//
//
//int main()
//{
//	vector<int> works = { 5};
//	int n = 3;
//	cout << solution(n, works) << endl;
//
//	return 0;
//}
