package ct02hw_서울_7반_이선수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_4D_9659_다항식계산_이선수 {

	static int N;
	static long[] num;
	static int[] _t = new int[51];
	static int[] a = new int[51];
	static int[] b = new int[51];
	static int M;
	static long[] x;

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T;
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			num = new long[N + 1];
			for (int n = 2; n <= N; n++) {
				st = new StringTokenizer(br.readLine());
				_t[n] = Integer.parseInt(st.nextToken());
				a[n] = Integer.parseInt(st.nextToken());
				b[n] = Integer.parseInt(st.nextToken());
			}

			M = Integer.parseInt(br.readLine());
			x = new long[M];
			st = new StringTokenizer(br.readLine());
			for (int m = 0; m < M; m++) {
				x[m] = Integer.parseInt(st.nextToken());
			}
			System.out.print("#"+t+" ");
			for (int i = 0; i < M; i++) {
				
				num[0] = 1;
				num[1] = x[i];
				for(int j = 2; j <= N; j++)
				{
					if(_t[j] == 1)
					{
						num[j] = (num[a[j]] + num[b[j]]) % 998244353;
					}
					else if(_t[j] == 2)
					{
						num[j] = (a[j] * num[b[j]]) % 998244353;
					}
					else
					{
						num[j] = (num[a[j]] * num[b[j]]) % 998244353;
					}
				}
				System.out.print(num[N] + " ");
			}
			System.out.println();
		}
	}

}
