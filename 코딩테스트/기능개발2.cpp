//#include <string>
//#include <vector>
//#include <iostream>
//#include <stack>
//
//
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//	vector<int> answer;
//	vector<int> prio;
//	stack<int> priStack;
//	float x;
//	for (int i = 0; i < progresses.size(); i++)
//	{
//		x = float(100 - progresses[i]) / speeds[i];
//		prio.push_back(x > (int)x ? x + 1 : x);
//	}
//
//	int temp = 0;
//	int count = 0;
//	for (int i = 1; i < prio.size(); i++)
//	{
//		count++;
//		if (prio[temp] < prio[i])
//		{
//			answer.push_back(count);
//			count = 0;
//			temp = i;
//		}
//	}
//
//	answer.push_back(++count);
//	return answer;
//}
//
//
//int main()
//{
//	/*	progresses	 speeds	    return
//		[93, 30, 55] [1, 30, 5] [2, 1]
//
//		입출력 예 설명
//		첫 번째 기능은 93 % 완료되어 있고 하루에 1 % 씩 작업이 가능하므로 7일간 작업 후 배포가 가능합니다.
//		두 번째 기능은 30 % 가 완료되어 있고 하루에 30 % 씩 작업이 가능하므로 3일간 작업 후 배포가 가능합니다.하지만 이전 첫 번째 기능이 아직 완성된 상태가 아니기 때문에 첫 번째 기능이 배포되는 7일째 배포됩니다.
//		세 번째 기능은 55 % 가 완료되어 있고 하루에 5 % 씩 작업이 가능하므로 9일간 작업 후 배포가 가능합니다.
//
//		따라서 7일째에 2개의 기능, 9일째에 1개의 기능이 배포됩니다.
//	*/
//
//	//	vector<int> progresses = { 93,30,55,40,80,10,60 };
//		//vector<int> speeds = { 1,30,5,40,2,60,4 };
//	vector<int> progresses = { 15, 1, 14, 9, 29, 25, 17, 24, 4, 27, 7, 19, 29, 14, 23, 4, 21, 3, 8, 14 };
//	vector<int> speeds = { 9, 11, 21, 16, 11, 21, 7, 5, 6, 30, 11, 24, 26, 18, 20, 18, 15, 30, 7, 18 };
//
//	for(int i = 0 ; i < solution(progresses, speeds).size() ;++i)
//		cout << solution(progresses, speeds)[i] << endl;
//
//	//solution(progresses, speeds);
//	return 0;
//
//}