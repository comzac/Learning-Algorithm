//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//string rankStr[9] = { "Straight Flush", "Four of a Kind", "Full House","Flush","Straight","Three of a kind","Two pair","One pair", "High card" };
//
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	return a.second < b.second;
//}
//
//vector<pair<int, int>> suit;
//vector<pair<int, int>> _rank;
//int num[14];
//int shape[4]; // 0 : 하트 , 1: 다이아, 2 : 클로바 , 3 :스페이드
//
//string check();
//int shapeCheck();
//vector<int> numSameCheck();
//int maxContinuousNum();
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		string temp;
//		for (int i = 0; i < 5; i++)
//		{
//			cin >> temp;
//
//			switch (temp[0])
//			{
//			case 'S':
//				suit.push_back({ i,3 });
//				break;
//			case 'D':
//				suit.push_back({ i,1 });
//				break;
//			case 'H':
//				suit.push_back({ i,0 });
//				break;
//			case 'C':
//				suit.push_back({ i,2 });
//				break;
//			}
//
//			if (isdigit(temp[1]))
//			{
//				_rank.push_back({ i,temp[1] - '0' });
//			}
//			else
//			{
//				switch (temp[1])
//				{
//				case 'A':
//					_rank.push_back({ i,1 });
//					break;
//				case 'T':
//					_rank.push_back({ i,10 });
//					break;
//				case 'J':
//					_rank.push_back({ i,11 });
//					break;
//				case 'Q':
//					_rank.push_back({ i,12 });
//					break;
//				case 'K':
//					_rank.push_back({ i,13 });
//					break;
//				}
//				
//			}
//		}
//		cout << "#" << t << " " << check() << endl;
//		suit.clear();
//		_rank.clear();
//		for (int i = 0; i < 13; i++)
//			num[i] = 0;
//		for (int i = 0; i < 4; i++)
//			shape[i] = 0;
//	}
//}
//
//string check()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		num[_rank[i].second]++;
//		shape[suit[i].second]++;
//	}
//	vector<int> numCnt = numSameCheck();
//	
//	int maxNumCnt = 1;
//	int minNumCnt = 1;
//	if (numCnt.size() >= 1)
//	{
//		maxNumCnt = *max_element(numCnt.begin(), numCnt.end());
//	}
//	if (numCnt.size() > 1)
//	{
//		minNumCnt = *min_element(numCnt.begin(), numCnt.end());
//	}
//
//	int shapeCnt = shapeCheck();
//	int conNum = maxContinuousNum();
//
//	if (conNum == 5 && shapeCnt == 5)
//		return rankStr[0];
//	else if (maxNumCnt >= 4)
//		return rankStr[1];
//	else if (maxNumCnt == 3 && minNumCnt == 2)
//		return rankStr[2];
//	else if (shapeCnt == 5)
//		return rankStr[3];
//	else if (conNum == 5)
//		return rankStr[4];
//	else if (maxNumCnt == 3 && minNumCnt == 1)
//		return rankStr[5];
//	else if (maxNumCnt == 2 && minNumCnt == 2)
//		return rankStr[6];
//	else if (maxNumCnt == 2 && minNumCnt == 1)
//		return rankStr[7];
//	else
//		return rankStr[8];
//
//
//	return string();
//}
//
//int shapeCheck()
//{
//	int cnt = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		if (shape[i] > cnt)
//			cnt = shape[i];
//	}
//	return cnt;
//}
//
//vector<int> numSameCheck()
//{
//	vector<int> temp;
//	for (int i = 0; i < 13; i++)
//	{
//		if (num[i] > 1)
//			temp.push_back(num[i]);
//	}
//	return temp;
//}
//
//int maxContinuousNum()
//{
//	sort(_rank.begin(), _rank.end(), cmp);
//	if (_rank[0].second == 1)
//		_rank.push_back({ 5,14 });
//	int max = 0;
//	int len = 1;
//	for (int i = 1; i < _rank.size(); i++)
//	{
//		if (_rank[i].second - _rank[i - 1].second == 1)
//		{
//			len++;
//			if (max < len)
//				max = len;
//		}
//		else
//		{
//			len = 1;
//		}
//	}
//	return max;
//}
