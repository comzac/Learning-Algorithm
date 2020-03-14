package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class 냉장고 {
	
	static int [] dp;
	static int [][] temper;
	static int N;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		
		dp = new int[N];
		temper = new int [N][2];
		for(int i = 0 ; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			temper[i][0] = Integer.parseInt(st.nextToken());
			temper[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(temper, new Comparator<int[]> () {

			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[0] - o2[0];
			}
		});
		
		dp[0] = 1;
		int Low = temper[0][0];
		int High = temper[0][1];
		
		for(int i = 1; i < N; i++)
		{
			if(Low <= temper[i][0] && temper[i][1] <= High) // 포함될 때.
			{
				Low = temper[i][0];
				High = temper[i][1];
				dp[i] = dp[i-1];
			}
			else if(Low <= temper[i][0] && temper[i][0] <= High) // 낮은 부분이 걸릴 때,
			{
				Low = temper[i][0];
				//High = temper[i][1];
				dp[i] = dp[i-1];
			}
			else if(temper[i][1] >= Low && temper[i][1] <= High) // 높은 부분이 걸릴 때, 
			{
				//Low = temper[i][0];
				High = temper[i][1];
				dp[i] = dp[i-1];
			}
			else // 해당이 안될 때,
			{
				dp[i] = dp[i-1]+1;
				Low = temper[i][0];
				High = temper[i][1];	
			}
		}
		
		System.out.println(dp[N-1]);
		
	}
}












