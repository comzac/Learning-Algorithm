/*
	1. 수의 개수 2<= <=11
	2. 수들		1<= <=100
	3. 덧셈 개수, 뺄셈 개수, 곱셈 개수, 나눗셈 개수
	출력 = 최댓값, 최솟값 // int로 가능 (중간과정에서도 10억 이하라 int 가능)
*/
/*
	1. 숫자 배열 완성하고
	2. 연산자 별 변수에 값 넣고
	3. 재귀로 연산자 카운트 줄여가며 N에 도달했을 때 값 벡터에 저장
	4. 함수 실행 후, vector의 최대값 최소값 출력
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[11];
vector<int> v;

void calcu(int cnt, int total, int s, int mi, int mu, int di)
{
	if (cnt == n)
	{
		v.push_back(total);
		return;
	}

	int cur = num[cnt];

	if(s != 0)
		calcu(cnt + 1, total + cur , s-1, mi, mu, di);
	if (mi != 0)
		calcu(cnt + 1, total - cur, s, mi-1, mu, di);
	if (mu != 0)
		calcu(cnt + 1, total * cur, s, mi, mu-1, di);
	if (di != 0)
		calcu(cnt + 1, total / cur, s, mi, mu, di-1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum;
	int minus;
	int multi;
	int divide;

	int total = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	cin >> sum;
	cin >> minus;
	cin >> multi;
	cin >> divide;

	calcu(1, num[0], sum, minus, multi, divide);

	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *min_element(v.begin(), v.end()) << endl;

}
