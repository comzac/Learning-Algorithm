package com.corona;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_2215_¹ú²ÜÃ¤Ãë_ÀÌ¼±¼ö {

	static int N, M, C;
	static int[][] map = new int[10][10];

	static boolean[][] visit = new boolean[10][10];
	static int maxCombi;
	//static ArrayList<Integer> maxAl = new ArrayList<Integer>();
	static int maxVal;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st; 
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t =1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			
			for(int i = 0 ; i < N ; i++)
			{
				st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < N; j++)
				{
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int i = 0 ; i < N*N; i++)
			{
				dfs(i, 1, 0);
			}

			System.out.printf("#%d %d\n", t, maxVal);
			maxVal = 0;
		}
	}
	

	static void dfs(int idx, int cnt, int sum)
	{
		int y;
		int x;
		y = idx/N;
		x = idx%N;
		
		if(x >= N - M + 1)
			return;
		ArrayList<Integer> al = new ArrayList<Integer>();
		
		for(int i = 0 ; i < M; i++)
		{
			al.add(map[y][x+i]);
		}
		maxCombi = 0;
		for(int i = 0 ; i < M; i++)
		{
			maxComb(al, i, al.get(i), 0);
		}
		int maxTemp = maxCombi;
		//maxAl.add(maxCombi);
		if(cnt == 2)
		{
			if(maxVal < sum + maxCombi)
				maxVal = sum+maxCombi;
			return;
		}
		
		for(int i = idx+M ; i < N*N; i++)
		{
			dfs(i, cnt+1, maxTemp + sum);
		}
		
	}
	
	static void maxComb(ArrayList<Integer> arr, int idx, int num, int sum)
	{
		if(num > C)
			return;
		int powVal = (int) Math.pow(arr.get(idx), 2);
		if(maxCombi < sum + powVal)
			maxCombi = sum + powVal;
		
		for(int i = idx+1 ; i < M; i++)
		{
			maxComb(arr, i, num + arr.get(i), sum + powVal);
		}
	}


}
