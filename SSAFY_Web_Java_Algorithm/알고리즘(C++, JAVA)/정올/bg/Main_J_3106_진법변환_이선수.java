//1 bg
package hw.bg;

/* ### 주의할 부분 ###
 * 36진법까지 고려했던 점
 * 최대 크기가 2^64 였던 점
 * string reverse 표현 방식
 * 초기화 제대로 안한 점 
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_J_3106_진법변환_이선수 {

	static final String[] numbering = new String[]  { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C",
			"D", "E", "F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int A, B;
		String N;
		long before;
		String after;

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		while (true) {
			st = new StringTokenizer(br.readLine());

			A = Integer.parseInt(st.nextToken());
			if (A == 0)
				break;
			N = st.nextToken();
			B = Integer.parseInt(st.nextToken());

			int len = N.length();
			long comp = 1;
			before = 0;
			// before의 A진법 -> 10진법화
			for (int i = len - 1; i >= 0; i--) {
				try {
					before += Integer.parseInt(String.valueOf(N.charAt(i))) * comp;

				} catch (Exception e) {
					// System.out.println(String.valueOf(N.charAt(i)));
					for (int j = 0; j < numbering.length; j++) {
						// System.out.println(numbering[j]);
						if (numbering[j].equals(String.valueOf(N.charAt(i)))) {
							before += j * comp;
							// System.out.println("j: " +j);
						}
					}
				}
				comp *= A;
			}

			// before -> B진법화 = after
			long quot = 0;
			long remain = 0;

			// System.out.println(before);

			after = "";
			while (true) {
				quot = before / B;
				remain = before % B;
				after += numbering[(int)remain];
				if (quot == 0)
					break;
				before = quot;
			}

			System.out.println(new StringBuffer(after).reverse().toString());

		}

	}

}
