//#include <string>
//#include <vector>
///*
//굉장히 비효율적으로 푼거 같기도하고
//접근방식은 맞았으나 풀이법이 복잡했던 거 같다
//*/
//
//using namespace std;
//int N;
//vector<int> recursive(vector<int> v)
//{
//	N--;
//	if (N == 0)
//	{
//		return v;
//	}
//	vector<int> temp;
//	for (int i = 0; i < v.size(); i++)
//		temp.push_back(v[i]);
//
//	temp.push_back(0);
//
//	for (int i = v.size() - 1; i >= 0; i--)
//		temp.push_back(!v[i]);
//
//	return recursive(temp);
//
//}
//
//vector<int> solution(int n) {
//	vector<int> answer;
//	vector<int> first = { 0 };
//	N = n;
//	if (N == 1)
//	{
//		return first;
//	}
//	else
//	{
//		answer = recursive(first);
//	}
//
//	return answer;
//}