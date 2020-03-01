//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//class truck
//{
//public:
//
//	bool isRide = false;
//	int timeRate = 0;
//};
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) {
//	int time = 0;
//	int timeRate = 0;
//	int totalW = 0;
//	int i = 0;
//	int timeOfTruck = 0;
//	
//	queue<int> tque;
//	truck* _truck = new truck[truck_weights.size()];
//	
//	while (1)
//	{
//		time++;
//		if (i < truck_weights.size())
//		{
//			if (totalW + truck_weights[i] <= weight && tque.size() < bridge_length)
//			{
//				tque.push(truck_weights[i]);
//				_truck[i].timeRate = bridge_length;
//				_truck[i].isRide = true;
//				totalW += truck_weights[i];
//				i++;
//			}
//		}
//		if (tque.empty() && totalW == 0)
//			break;
//
//		for (int j = 0; j < truck_weights.size(); j++)
//		{
//			if (_truck[j].isRide)
//			{
//				_truck[j].timeRate--;
//				if (_truck[j].timeRate <= 0)
//				{
//					_truck[j].isRide = false;
//					totalW -= tque.front();
//					tque.pop();
//				}
//			}		
//		}
//	}
//
//	return time;
//}
//
//
//int main()
//{
//	int len = 100;
//	int wei = 100;
//	vector<int> truck = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
//
//	cout << solution(len, wei, truck) << endl;
//
//
//	return 0;
//
//}