package hw_algo0501_서울_7반_이선수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	static boolean[][] biVisit = new boolean[41][2];
	static boolean[][] trVisit = new boolean[41][3];
	static String bi, tr;
	static long maxVal;
	static long answer;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			bi = br.readLine();
			tr = br.readLine();
			reset();
			maxVal = (1 << bi.length()) - 1;
			for (int i = 0; i < bi.length(); i++) {
				biVisit[i][bi.charAt(i) - '0'] = true;

			}
			for (int i = 0; i < tr.length(); i++) {
				trVisit[i][tr.charAt(i) - '0'] = true;
			}

			String btemp = "";
			String ttemp = "";
			boolean isCorrect = false;
			for (int i = 0; i < bi.length(); i++) {
				for (int j = 0; j < 2; j++) {
					if (biVisit[i][j] == false) {
						biVisit[i][j] = true;
						btemp = bi.substring(0, i) + Integer.toString(j) + bi.substring(i + 1);
						
						for (int p = 0; p < tr.length(); p++) {
							for (int k = 0; k < 3; k++) {
								if (trVisit[p][k] == false) {
									ttemp = tr.substring(0, p) + Integer.toString(k) + tr.substring(p + 1);
									long sameNum = sameCheck(btemp, ttemp);
									if (sameNum != 0) {
										answer = sameNum;
										isCorrect = true;
										break;
									}
								}
							}
							if (isCorrect)
								break;
						}
						if (isCorrect)
							break;
					}
					if (isCorrect)
						break;
				}
				if (isCorrect)
					break;
				
			}

			System.out.println("#" + t+ " " + answer);
		}

	}

	static void reset() {
		for(int i = 0 ; i < 41; i++)
		{
			biVisit[i][0] = false;
			biVisit[i][1] = false;
			trVisit[i][0] = false;
			trVisit[i][1] = false;
			trVisit[i][2] = false;
		}
	}
	static long sameCheck(String b, String t) {

		long l1 = 0;
		long l2 = 0;

		for (int i = b.length() - 1; i >= 0; i--) {
			l1 += (long) (Math.pow(2, b.length() - i - 1) * (b.charAt(i) - '0'));
		}

		for (int i = t.length() - 1; i >= 0; i--) {
			l2 += (long) (Math.pow(3, t.length() - i - 1) * (t.charAt(i) - '0'));
			if (l2 > maxVal)
				return 0;
		}

		if (l1 == l2)
			return l1;
		return 0;
	}
}


