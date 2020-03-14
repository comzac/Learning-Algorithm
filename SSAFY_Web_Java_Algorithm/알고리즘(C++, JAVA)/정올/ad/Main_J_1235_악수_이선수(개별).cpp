
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int dp[1001][1001];
vector<int> v;
#define MAX(a,b) (a>b?a:b)

/*
예외
1 4 1 2
=> 0 이 돼야하는데 1이 나옴

# 조건 : 팔이 교차하지 않게 모두가 악수하는 방법 중에 ( 조건 1 )
		같은 브랜드를 좋아하는 사람 끼리 악수하는 ( 조건 2 ) 수가 제일 많은 방법을 찾아라.

1701 유전자문제와 같은 방식이라고 생각했지만 위의 예외상황이 있었다.
악수를 하려면 항상 2명의 인원이 존재하는데 유전자문제와 같은 방식으로 검사할 때 141 에서 dp에 1이
저장되고 결과적으로 1412 에서 141(1) + 2(0) 으로 합이 1로 결정된다.
하지만, 141에서 1끼리 악수를하면 4는 1과 1 사이에서 악수를 해야하는데 혼자(홀수)이기때문에
악수를 할 수 없게 된다. (조건 1에 반하는 결과)
따라서 시작점과 끝점의 같은 숫자를 가질때, 사이의 인원수가 홀수인 경우는 제외해야한다.

그래서, 가장 바깥 for문의 i를 1씩 증가시키지 않고 2씩 증가시키는 방향을 생각해봤다. 하지만 이 변화는
끝지점만 변경되며, 두번째 for문에서 끝지점 이하로 조사하는 단계에서 홀수개를 제외시킬수 없다.

=> 2번 for문 내에서 조건에 부합할 때, 내부의 갯수가 홀수개인지 확인하고 홀수인 경우, continue한다.
=> continue로 인해 그 경우, dp값의 변경이 일어나지 않는데 어차피 내부가 홀수인 경우에는 교차가
무조건 발생하므로 초기값인 0이어도 문제가 없다.
*/
int shake(int N)
{
	// j 시작점 , i 끝점
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] == v[i])
			{
				if ((i - j + 1) % 2 != 0) // 내부 홀수인 경우, skip
					continue;
				dp[j][i] = dp[j + 1][i - 1] + 1;
			}

			for (int k = 1; k <= i - j; k++) // dp값 비교 ( xxxxxxyyyy의 경우, dp[x~x]+dp[y~y]
			{
				int divDp = dp[j][i - k] + dp[i - k + 1][i];
				dp[j][i] = MAX(dp[j][i], divDp);
			}
		}
	}
	return dp[0][N - 1];
}

int main()
{
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cout << shake(n);

	return 0;
}
