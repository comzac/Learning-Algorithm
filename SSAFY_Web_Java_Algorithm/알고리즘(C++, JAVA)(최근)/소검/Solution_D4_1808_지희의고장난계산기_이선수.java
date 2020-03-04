/* 1710~1800+2015~2100 = 50 + 45 = 1 35 
 */

package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_D4_1808_지희의고장난계산기_이선수 {

	static int[] number = new int[10];
	static int num;
	static int answer = 999999999;
	static ArrayList<Integer> measure = new ArrayList<Integer>();
	static int[] AbleMeasure;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1 ; t <= T; t++)
		{
			answer = 999999999;
			st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < 10; i++)
				number[i] = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(br.readLine());
			
			int len = check(num);
			if(len > 0) // 모든 숫자가 있을 때,
			{
				System.out.println("#" + t + " " + (len + 1));
			}
			else
			{
				// 약수만들기
				for(int i = 2; i <= num; i++)
				{
					if(num%i == 0)
						measure.add(i);
				}
				
				AbleMeasure = new int[measure.size()];
				
				for(int i = 0 ; i < measure.size(); i++)
				{
					int cnt = check(measure.get(i));
					if(cnt != 0)
					{
						AbleMeasure[i] = cnt;
					}
				}
				
				for(int i = measure.size()-1; i >= 0 ; i--)
				{
					if(AbleMeasure[i] == 0)
						continue;
					dfs(i, 1, AbleMeasure[i]);

				}
				
				if(answer == 999999999)
					System.out.println("#" + t + " " + -1);
				else
					System.out.println("#" + t + " " + (answer + 1));
				
				measure.clear();

			}
			
			
			
		}
	}
	
	static void dfs(int idx, int total, int cnt)
	{
		if(total > num)
			return;
		
		int val = total*measure.get(idx);
		
		if(val > num)
			return;
		if(val == num)
		{
			if(answer > cnt)
				answer =  cnt;
			return;
		}
		
		for(int i = idx; i>= 0 ; i--)
		{
			if(AbleMeasure[i] == 0)
				continue;
			dfs(i, val, cnt + 1 + AbleMeasure[i]);

		}
	}
	
	static int check(int share) {
		int num = share;
		int len = 0;
		while (num != 0) {
			int end = num % 10;
			if (number[end] == 0)
				return 0;
			num /= 10;
			len++;
		}

		return len;
	}
	
}

/*
 *  0 1 2
 *  80
 *  
1
0 1 1 0 0 1 0 0 0 0
60
 * 
 */