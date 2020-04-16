package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*	2310~2340
 * 	비트마스킹으로 판단하면 될듯 + dfs
 */
public class Solution_7699_수지의수지맞는여행_이선수 {
	
	static class pos{
		int y;
		int x;
		int see;
		
		pos(int y, int x, int see)
		{
			this.y = y;
			this.x = x;
			this.see = see;
		}
	}
	static int N, M;
	static int[][] map;
	static boolean[][][] visit;
	static int[][] dir = new int[][] {{0,1},{0,-1},{1,0},{-1,0}};
	static int maxVal = 0;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			map = new int[N][M];
			visit = new boolean[N][M][26];
			String s;
			
			for(int i  = 0 ; i < N; i++)
			{
				s = br.readLine();
				for(int j = 0 ; j < M; j++)
				{
					map[i][j] = s.charAt(j) - 'A' + 1;
				}
			}
			
			maxVal = 0;
			dfs(0, 0, 1, 1<<map[0][0]);
			
			System.out.println("#" + t + " " + maxVal);
		}
		
	}
	static void dfs(int y, int x, int cnt, int bitMask)
	{
		if(cnt > maxVal)
			maxVal = cnt;
		
		int ny, nx;
		for(int i = 0 ; i < 4; i++)
		{
			ny = y + dir[i][0];
			nx = x + dir[i][1];
			
			if(ny < 0|| nx < 0|| ny >= N || nx >= M || (bitMask & 1<<map[ny][nx]) != 0)
				continue;
			
			dfs(ny, nx, cnt+1, bitMask | 1<<map[ny][nx]);
		}
	}
	
}










