package hw_algo0501_서울_7반_이선수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int[][] scores;
	static boolean isFlag = false;
	static int[][] vs = new int[][] {{0,1},{0,2},{0,3},{0,4},{0,5},{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int i = 0; i < 4; i++) {
			scores = new int[6][3];
			isFlag = false;

			int sum = 0;
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 3; k++) {
					scores[j][k] = Integer.parseInt(st.nextToken());
					sum += scores[j][k];
				}
			}

			if(sum != 30)
			{
				System.out.print("0 ");
			}
			else
			{
				dfs(0);

				if (isFlag)
					System.out.print("1 ");
				else
					System.out.print("0 ");
			}

		}

	}

	private static void dfs(int cnt) {

		if (cnt == 15) {
			isFlag = true;
			return;
		}
		
		int i = vs[cnt][0];
		int j = vs[cnt][1];

		// 이긴경우
		if (scores[i][0] > 0 && scores[j][2] > 0) {
			scores[i][0]--;
			scores[j][2]--;
			dfs(cnt + 1);
			if (isFlag)
				return;
			scores[i][0]++;
			scores[j][2]++;
		}

		// 비긴경우
		if (scores[i][1] > 0 && scores[j][1] > 0) {
			scores[i][1]--;
			scores[j][1]--;
			dfs(cnt + 1);
			if (isFlag)
				return;
			scores[i][1]++;
			scores[j][1]++;
		}

		// 진경우
		if (scores[i][2] > 0 && scores[j][0] > 0) {
			scores[i][2]--;
			scores[j][0]--;
			dfs(cnt + 1);
			if (isFlag)
				return;
			scores[i][2]++;
			scores[j][0]++;
		}

	}
}
