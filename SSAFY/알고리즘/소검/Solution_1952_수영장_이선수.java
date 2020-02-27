package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1952_수영장_이선수 {

	static int[] week = new int[12];
	static int[] price = new int[4];
	static int minVal;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st; 
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t =1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < 4; i++)
			{
				price[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < 12; i++)
			{
				week[i] = Integer.parseInt(st.nextToken());
			}
			minVal = price[3]; // 일년 이용권
			for(int i = 0 ; i < 3; i++)
			{
				dfs(i, 0, 0);
			}
			
			System.out.printf("#%d %d\n", t, minVal);
			
		}
	}

	static void dfs(int priceNum, int sum, int cnt)
	{
		if(cnt >= 12)
		{
			if(minVal > sum)
				minVal = sum;
			return;
		}
		
		for(int i = 0 ; i < 3; i++)
		{
			if(week[cnt]== 0)
			{
				dfs(i, sum, cnt+1);
			}
			else
			{
				switch(priceNum)
				{
				case 0:
					dfs(i, sum + week[cnt] * price[0], cnt+1);
					break;
				case 1:
					dfs(i, sum + price[1], cnt+1);
					break;
				case 2:
					dfs(i, sum + price[2], cnt+3);
					break;
				}
			}
		}
	}
	
	
	
}










