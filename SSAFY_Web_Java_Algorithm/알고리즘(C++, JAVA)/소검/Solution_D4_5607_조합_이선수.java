package ct01hw_서울_7반_이선수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D4_5607_조합_이선수 {
	static int N, R;
	static int modVal = 1234567891;
	static long ft[] = new long[1000001];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			
			long son = factorial();
			long par = (ft[R]*ft[N-R]) % modVal;
			long npar = Fermat(par, modVal - 2);
			System.out.println("#"+t+" " + (son*npar)%modVal);
		}
	}
	
	public static long factorial() {
		ft[1] = 1;
		for (int i = 2; i <= N; i++)
		{
			ft[i] = (ft[i - 1] * i) % modVal;
		}
		return ft[N];
	}
	public static long Fermat(long par, int a) {
		if (a == 0) return 1;
		long div = Fermat(par, a / 2);
		long mul = (div*div) % modVal;
		if (a % 2 == 0) 
			return mul;
		else 
			return (mul * par) % modVal;
	}
}
