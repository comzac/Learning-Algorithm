package hw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_D4_1210_Ladder1_이선수 {

	static int posX, posY, addX, addY;
	static int[][] map;
	static boolean[][] v;
	static final int N = 100;
	static final int[][] dir = new int[][] { { 1, 0 }, { -1, 0 }, { 0, -1 } };

	public static void main(String[] args) throws IOException {

		int T = 10;
		map = new int[100][100];
		v = new boolean[100][100];

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int i = 0; i < T; i++) {
			for (int[] row : map)
				Arrays.fill(row, 0);
			for (boolean[] row : v)
				Arrays.fill(row, false);

			br.readLine(); // 문제 번호 입력
			for (int j = 0; j < N; j++) // 행 인덱스
			{
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < N; k++) // 열 인덱스
				{
					map[j][k] = Integer.parseInt(st.nextToken());
				}
			}

			for (int j = 0; j < N; j++) {
				if (map[N - 1][j] == 2) {
					posX = j;
					break;
				}
			}

			posY = N - 1;

			while (posY != 0) {
				for (int j = 0; j < 3; j++) {
					addX = posX + dir[j][0];
					addY = posY + dir[j][1];

					if (addX >= N | addX < 0)
						continue;

					if (!v[addY][addX] & (map[addY][addX] == 1)) {
						v[addY][addX] = true;
						posY = addY;
						posX = addX;
						break;
					}
				}

			}

			System.out.printf("#%d %d\n", i + 1, posX);

		}

	}

}
