//7 bg
package hw.bg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_J_2817_로또_이선수 {

	static int[] num;
	static int[] answer = new int[6];
	
	static void p() {
		for(int i = 0 ; i < 6; i++)
			System.out.printf("%d ", answer[i]);
		System.out.println();
	}
	static void lotto(int idx, int cnt)
	{
		if(cnt == 6)
		{
			p();
			return;
		}

		for(int i = idx; i< num.length; i++)
		{
			answer[cnt] = num[i];
			lotto(i+1, cnt+1);
		}
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		num = new int[N];
		for(int i = 0;i <N;i++)
		{
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		lotto(0,0);
		
	}

}
