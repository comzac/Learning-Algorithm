///* 20:12~
//
//	1. 셔틀은 09:00부터 총 n회 t분 간격으로 역에 도착하며, 하나의 셔틀에는 최대 m명의 승객이 탈 수 있다.
//	2. 셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발한다. 
//		예를 들어 09:00에 도착한 셔틀은 자리가 있다면 09:00에 줄을 선 크루도 탈 수 있다.
//
//		  
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int convertToNum(string time) {
//	int t = 0;
//
//	string h = time.substr(0, 2);
//	string m = time.substr(3);
//
//	int hour = stoi(h);
//	int min = stoi(m);
//
//	t = min + hour * 60;
//
//	return t;
//}
//string solution(int n, int t, int m, vector<string> timetable) {
//	string answer = "";
//
//	int cnt = 1;
//
//	vector<int> convertToInt;
//	for (auto t : timetable) {
//		convertToInt.push_back(convertToNum(t));
//	}
//
//	sort(convertToInt.begin(), convertToInt.end());
//	int result = 0;
//	int curTime = 60 * 9;
//	int restIdx = 0;
//	while (true) {
//		int rest = m;
//		if (cnt == n) {
//			if (convertToInt.size() - restIdx < m) {
//				result = curTime;
//				break;
//			}
//			for (int i = restIdx; i < convertToInt.size(); i++) {
//				if (curTime >= convertToInt[i]) // 현재시간보다 빠른 애들이라면
//				{
//					restIdx++; // 태운걸로 하고 인덱스 증가
//					rest--;
//					if (rest == 0) {
//						result = convertToInt[i] - 1;
//						break;
//					}
//				}
//				else {
//					result = curTime;
//					break;
//				}
//			}
//			break;
//		}
//		else {
//			for (int i = restIdx; i < convertToInt.size(); i++) {
//				if (curTime >= convertToInt[i]) // 현재시간보다 빠른 애들이라면
//				{
//					restIdx++; // 태운걸로 하고 인덱스 증가
//					rest--;
//					if (rest == 0) {
//						break;
//					}
//				}
//				else {
//					break;
//				}
//			}
//		}
//
//		curTime += t;
//		cnt++;
//	}
//	
//	int hour = result / 60;
//	int min = result % 60;
//
//	if (hour / 10 != 0) {
//		answer += to_string(hour);
//	}
//	else {
//		answer += "0"+ to_string(hour);
//	}
//	answer += ":";
//
//	if (min / 10 != 0) {
//		answer += to_string(min);
//	}
//	else {
//		answer += "0" + to_string(min);
//	}
//
//	return answer;
//}
//int main()
//{
//	int n = 1;
//	int t = 1;
//	int m = 5;
//
//	vector<string> timetable = { "08:00", "08:01","08:02","08:03" };
//	//vector<string> timetable = { "09:10", "09:09","08:00" };
//	//vector<string> timetable = { "09:00", "09:00","09:00","09:00"};
//	//vector<string> timetable = { "00:01",  "00:01",  "00:01",  "00:01",  "00:01"};
//	//vector<string> timetable = { "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59"};
//	
//	cout << solution(n, t, m, timetable);
//
//	return 0;
//}