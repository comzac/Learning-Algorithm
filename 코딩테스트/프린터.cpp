//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//#include <map>
//
///* 
//2 1 4 2 3
//1 4 2 3 2
//4 2 3 2 1    4 
//3 2 1 2      4 3
//2 1 2        4 3 2
//1 2
//2 1          4 3 2 2
//1 
//             4 3 2 2 1
//*/
//using namespace std;
//
//
//
//queue<int> recurse(queue<int> temp, vector<int> priorities)
//{
//	queue<int> _temp = temp;
//	queue<int> _temp2;
//	queue<int> _temp3;
//
//	vector<int> v;
//
//	while (!_temp.empty())
//	{
//		v.push_back(_temp.front());
//		_temp.pop();
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = i + 1; j < v.size(); j++)
//		{
//			if (priorities[v[i]] < priorities[v[j]])
//			{
//				_temp2.push(v[i]);
//				v.erase(v.begin()+i);
//				i--;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i < v.size(); i++)
//
//	
//	if (_temp2.empty())
//		return _temp3;
//	else
//		_temp2 = recurse(_temp2, priorities);
//
//	while (!_temp2.empty())
//	{
//		_temp3.push(_temp2.front());
//		_temp2.pop();
//	}
//
//	return _temp3;
//}
//
//int solution(vector<int> priorities, int location) {
//	int answer = 0;
//
//	queue<int> queTemp;
//
//	for (int i = 0; i < priorities.size(); i++)
//	{
//		queTemp.push(i);
//	}
//
//	queTemp = recurse(queTemp, priorities);
//
//	cout << queTemp.front() << endl;
//
//	return answer;
//}
//
//
//int main()
//{
//	//틀리지 않았지만 굳이 큐를 쓴 의미가 있을까?
//	//스텍을 활용하면 직전에 무엇을 썼었는지를 활용할 수 있다.
//	//그 부분으로 응용하자!
//
//	vector<int> prio = { 2,1,3,2 };
//	int location = 3;
//
//	cout << solution(prio, location) << endl;
//
//
//	return 0;
//
//}