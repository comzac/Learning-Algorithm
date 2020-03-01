	1. 1초 128MB 빡빡하다
	2. 1 <= N <= 50 , 0 <= K <= 26

	풀이:
	기본 antic -> 이 다섯글자를 모르면 모든 단어를 모른다
	=> K < 5 => 0개
	=> K == 5 => 다섯개가 아닌 문자가 중간에 있으면 => 0개
	=> K > 5 => 중간 문자들을 조사해야한다.
	=> 알파벳이 총 26개 그 중 antic 다섯개 제외하면 21개
	조합의 경우가 가장 많은 경우는 K가 16일 때, 약 21개중 10개를 고를 때,
	순서가 상관없기 때문에 21*20*19...*11 = 14,079,294,028,800 그냥 초과
	map을 활용해서 최대값을 갖는 알파벳들을 순서대로 처리해도 될듯?
	그런데 길이를 보면 15가 최대니 21*20*19*18*17*16*15 => 586,051,200 이다.
	이때, 조합을 생성하기에 앞서 map을 통해 값이 큰 문자는 고정하는 방식으로 가지치기를 하면
	가능성이 있지 않을까? 일단 밥먹고 하자
  ===...>>> 한참 걸렸다..ㅎㅎ 완탐굳
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
char frontEnd[5] = { 'a','n','t','i','c' }; // 기본적으로 들어 갈 애들
int answer;
int maxVal;

bool isLearned[26];
vector<string> words;

void input();
void dfs(int wp, int learnCnt);
int main()
{
	input();
	if (K < 0)
	{
		cout << 0;
		return 0;
	}
	else if (K == 21)
	{
		cout << N;
		return 0;
	}

	dfs(0, 0);
	cout << maxVal;
	

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	string temp;
	for (int i = 0; i < N; i++) // 단어 갯수
	{
		cin >> temp;
		words.push_back(temp);
	}

	K -= 5; // 기본단어 제외

	for (int i = 0; i < 5; i++)
	{
		isLearned[frontEnd[i] - 'a'] = true;
	}
}

void dfs(int wp, int learnCnt)
{
	if (learnCnt == K)
	{
		answer = 0;
		string temp;
		int len;
		int cnt;
		bool isFailed;
		for (int i = 0; i < words.size() ; i++)
		{
			
			temp = words[i];
			len = words[i].size();
			isFailed = false;
			for (int j = 0; j < len; j++)
			{
				if (!isLearned[temp[j] - 'a'])
				{
					isFailed = true;
					break;
				}
			}
			if (!isFailed)
				answer++;
		}
		if (maxVal < answer)
			maxVal = answer;

		return;
	}


	for (int i = wp; i < 26; i++)
	{
		if (isLearned[i])
			continue;

		isLearned[i] = true;
		dfs(i, learnCnt + 1);
		isLearned[i] = false;
	}

}


