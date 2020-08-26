/* 22:24~
	1. 뿌요뿌요형 문제
	2. 최대범위가 30*30이기때문에 구역당 우, 하, 우하측 검사를 진행한다고 했을 때, 연산량의 문제는 없을것으로 보인다. 

	풀이
	1. 우, 하, 우하측 검사를 하며 4개가 만족하는 경우, 다른 배열에 true처리를 해준다. (이미 true인 경우는 카운팅이 되지 않는다.)
	2. 파괴 후 재정렬을 진행하고 앞선 과정을 반복한다.
	3. 누적된 카운트를 답으로 결정한다.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[31][31];
bool check[30][30];
int M, N;

void reset() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;
}

void move() {
	for (int i = M-1; i >=0; i--) {
		for (int j = N-1; j >=0; j--){
			if (check[i][j]) {
				vector<char> temp;

				for (int k = i; k >= 0; k--) {
					if (!check[k][j]) {
						temp.push_back(map[k][j]);
					}
					else {
						check[k][j] = false;
					}
					map[k][j] = ' ';
				}

				for (int k = 0; k < temp.size(); k++) {
					map[i - k][j] = temp[k];
				}

			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	M = m;
	N = n;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].length(); j++) {
			map[i][j] = board[i][j];
		}
	}

	int total = 0;
	int cnt;
	while (true) {
		cnt = 0;

		// 2*2 찾기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == ' ') // 비어있는경우,
					continue;
				char curChar = map[i][j];
				if (map[i][j + 1] == curChar && map[i + 1][j] == curChar && map[i + 1][j + 1] == curChar) {
					
					for (int k = i; k < i + 2; k++) {
						for (int l = j; l < j + 2; l++) {
							if (check[k][l])
								continue;
							cnt++;
							check[k][l] = true;
						}
					}

				}

			}
		}
		if (cnt == 0)
			break;
		// 이동
		move();

		reset();

		total += cnt;

	}
	answer = total;
	return answer;
}
int main()
{
	int m = 4;
	int n = 5;
	vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

	cout << solution(m, n, board) << endl;
	return 0;
}