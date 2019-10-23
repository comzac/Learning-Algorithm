//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct pred // greater
//{
//	bool operator()(int a, int b)
//	{
//		return a > b; // greater
//		//return a < b; // less
//	}
//};
//
//int main()
//{
//	priority_queue<int, vector<int>, pred> pq;
////	priority_queue<int, vector<int>, greater<int>> pq;
////	priority_queue<int, vector<int>, less<int>> pq;
//
//	pq.push(1);
//	pq.push(5);
//	pq.push(2);
//	pq.push(6);
//	pq.push(4);
//	pq.push(8);
//
//	while (!pq.empty())
//	{
//
//		cout << pq.top();
//		pq.pop();
//
//	}
//
//	cout << endl;
//
//	vector<int> v = { 9, 1,2,4,6,8,7 };
//	sort(v.begin(), v.end(), pred());
//	//sort(v.begin(), v.end(), greater<int>());
//	//sort(v.begin(), v.end(), less<int>());
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i];
//
//	return 0;
//}