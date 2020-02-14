package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D3_1493_수의연산_이선수 {
	
	static int[][] map = new int[281][281];
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		int p;
		int q;
		
		int xadd;
		int xaddadd;
		
		xaddadd = 1;
		for(int i = 1; i <= 280; i++)
		{
			map[i][1] = map[i-1][1] + xaddadd; 
			if(i != 1)
				xaddadd++;
		}
		
		xaddadd = 2;
		for(int i = 1; i <= 280; i++)
		{
			xadd = xaddadd;
			for(int j = 2; j <= 280; j++)
			{
				map[i][j] = map[i][j-1] + xadd;
				xadd++;
			}
			xaddadd++;
		}
		
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			p = Integer.parseInt(st.nextToken());
			q = Integer.parseInt(st.nextToken());
			
			int y1, x1;
			int y2, x2;
			int dy, dx;
			
			y1 = y2 = x1 = x2 = 0;
			for(int i = 1 ; i <= 280; i++)
			{
				for(int j = 1 ; j <= 280; j++)
				{
					if(map[i][j] == p )
					{
						y1 = i;
						x1 = j;
					}
					if(map[i][j] == q )
					{
						y2 = i;
						x2 = j;
					}
				}
			}
			
			
			dy = y1+y2;
			dx = x1+x2;
			
			System.out.println("#" + t + " " + map[dy][dx]);
		}
		
	}

}
