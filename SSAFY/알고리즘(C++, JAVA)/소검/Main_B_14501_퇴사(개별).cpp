/*
	1. N+1일에 퇴사
	2. 최대한 많은 상담, 하루에 하나씩 서로 다른 사람의 상담
	3. 걸리는 기간과 금액
	4. 햄버거와 유사하지만 idx 이동이 다르다

	풀이방식
	dfs로 일자에 접근하여 금액을 총합하여 최대값을 비교한다.
	이때, 해당 일자의 소요기간 만큼의 idx 변동이 필요하다.

*/
#include <iostream>
#include <string>
using namespace std;

int N;
int term[16]; // 일자라 헷갈릴 거 같으니 +1
int price[16];
#define MAX(A,B)(A>B?A:B)
int maxVal;

void dfs(int date, int sum)
{
	if (date + term[date] - 1 > N)
		return;

	maxVal = MAX(maxVal, sum + price[date]);

	for (int i = date + term[date]; i <= N; i++)
	{
		dfs(i, sum + price[date]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> term[i];
		cin >> price[i];
	}

	for(int i = 1; i <= N; i++) // 시작 날짜부터 체크 ( 0~7 )
		dfs(i, 0);

	cout << maxVal;

	return 0;
}
