/*2220~2335
	1. 길의 지나갈 수 있는 조건
	1) 같은 높이
	2) 경사로 설치
	2-1) 경사로 설치 조건
	2-1-1) 경사로는 낮은칸에만 설치하며, 경사로의 길이 L 만큼 바닥이 접해야한다
			=> 아마 바닥의 높이들이 같아야한다는 뜻같음
	2-1-2) 허용 높이 차 = 1

	지나갈 수 있는 길의 개수는?
	2 <= N <= 100
	1 <= L <= N
	높이 <= 10 자연수
	메모리 제한 512MB

	풀이 방법
	1. map배열에 담은 뒤 행, 열 기준으로 순회를 하자 100*100 충분할 듯 하다.
		2. 높이가 변경된 지점의 오르내림을 기록해볼까?(두개가 공존하면 안된다 식)
		  했지만 211112 인 경우 경사로를 뒤집어 놓으면 된다.
		3. 높거나 낮은 지점을 만났을 때, 경사로를 설치하는 방식으로 생각했으나, 최대의 길이에
		  최대에 가까운 경사로를 설치하는 경우, 바닥의 고른 높이를 확인하는데 N만큼의 연산이 반복되어
		  결과적으로 O(n^3) 정도다. 가능할 거 같지만 예상하지 못한 부분이 있을수도 있으니 다른 방법을 고려하자

	4. 순회를 하는 과정에서 내리막을 만난 경우, 오르막을 만난 경우를 나눠서 진행하자
	  또한 순회를 하며, 고른 길을 판단하기 위해 현재 위치의 높이를 기록하며 오르막을 만난 경우,
	  경사로를 확보할 길이 있는지 판단하고, 반대로 내리막을 만난 경우, 이후에 길이 고른지 판단해보는 방식으로
	  구현하자.
*/


#include <iostream>
#include <string>

using namespace std;

int N;
int L;
int cnt;
int map[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int same;
	bool isOk;
	int diff;
	// 가로 순회
	for (int i = 0; i < N; i++)
	{
		//curH = map[i][0]; // 현재 높이 측정 변수
		same = 1; // 높이가 몇번 같았는지 // 1에서 시작해야 다른 높이를 만났을 때 확인하기 유용
		isOk = true; // 길이 가능하다고 가정하고 시작 for이 끝나고도 true면 카운트
		for (int j = 0; j < N-1; j++) // 현재와 다음을 비교하기에 범위 조정
		{
			if (!isOk) // 이 길은 안될거란걸 확인
				break;
			diff = map[i][j + 1] - map[i][j]; // 높이 차
			if (abs(diff) > 1) // 높이 제한의 경우 2이상의 오르막 내리막
			{
				isOk = false;
				break;
			}
			else if (diff == 1) // 오르막
			{
				if (same >= L) // 공간이 확인되면 문제없고 same은 새로운 높이에 초기화
					same = 1;
				else
					isOk = false;
			}
			else if (diff == 0) // 평지
			{
				same++; // 다음 칸도 높이가 같구나
			}
			else if (diff == -1) // 내리막
			{
				if (j + L > N) // 앞에 공간이 없는 경우,
				{
					isOk = false;
					break;
				}

				for (int k = j + 1; k < j + L; k++)
				{
					if (map[i][k] != map[i][k + 1])
					{
						isOk = false;
						break;
					}
				}

				if (isOk) // 문제가 없었다면,
				{
					same = 0; // 높이 재초기화
					j += L-1; // 조사 위치 조정
				}
			}
		}
		if (isOk)
			cnt++;
	}


	// 세로 순회
	for (int j = 0; j < N; j++)
	{
		same = 1;
		isOk = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (!isOk) // 이 길은 안될거란걸 확인
				break;
			diff = map[i + 1][j] - map[i][j]; // 높이 차
			if (abs(diff) > 1) // 높이 제한의 경우 2이상의 오르막 내리막
			{
				isOk = false;
				break;
			}
			else if (diff == 1) // 오르막
			{
				if (same >= L) // 공간이 확인되면 문제없고 same은 새로운 높이에 초기화
					same = 1;
				else
					isOk = false;
			}
			else if (diff == 0) // 평지
			{
				same++; // 다음 칸도 높이가 같구나
			}
			else if (diff == -1) // 내리막
			{
				if (i + L > N) // 앞에 공간이 없는 경우,
				{
					isOk = false;
					break;
				}

				for (int k = i + 1; k < i + L; k++)
				{
					if (map[k][j] != map[k + 1][j])
					{
						isOk = false;
						break;
					}
				}

				if (isOk) // 문제가 없었다면,
				{
					same = 0; // 높이 재초기화
					i += L - 1; // 조사 위치 조정
				}
			}
		}
		if (isOk)
			cnt++;
	}


	cout << cnt;

	return 0;
}
