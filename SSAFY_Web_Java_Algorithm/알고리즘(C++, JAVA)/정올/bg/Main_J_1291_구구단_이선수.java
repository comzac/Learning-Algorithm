//2 bg
package hw.bg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_J_1291_구구단_이선수 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());

		int s = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());

		if (s < 2 || s > 9 || e < 2 || e > 9)
		{
			do {
				System.out.println("INPUT ERROR!");
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
			}while(s < 2 || s > 9 || e < 2 || e > 9);
			
		}
		if (s <= e) {
			for (int i = 1; i < 10; i++) {
				for (int num = s; num <= e; num++) {
					System.out.printf("%d * %d = %2d   ", num, i, num * i);
				}
				System.out.println();
			}
		} else {
			for (int i = 1; i < 10; i++) {
				for (int num = s; num >= e; num--) {
					System.out.printf("%d * %d = %2d   ", num, i, num * i);
				}
				System.out.println();
			}
		}


		
		

	}

}
