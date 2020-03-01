package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Solution_2814_최장경로_이선수 {
	static int N, M;
	static ArrayList<Integer> graph[];
	static int maxVal;
	static boolean[] visit;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++)
		{
			// 입력
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			visit = new boolean[N+1];
			graph = new ArrayList[N+1];
			for(int i = 1; i <= N; i++)
				graph[i] = new ArrayList<Integer>();
			
			int from, to;
			for(int m = 0; m < M; m++)
			{
				st = new StringTokenizer(br.readLine());
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				graph[from].add(to);
				graph[to].add(from);
			}

			
			// 경로 확인
			maxVal = 0;
			for(int i = 1; i <= N; i++)
			{
				visit[i] = true;
				routeCheck(i, 1);
				visit[i] = false;
			}
			
			System.out.printf("#%d %d\n", t, maxVal);
		}
	}
	
	static void routeCheck(int cur, int cnt)
	{
		if(visitCheck())
		{
			if(cnt > maxVal)
				maxVal = cnt;
			return;
		}
		
		if(cnt > maxVal)
			maxVal = cnt;
		
		for(int i = 0; i < graph[cur].size(); i++)
		{
			if(visit[graph[cur].get(i)])
				continue;
			visit[graph[cur].get(i)] = true;
			routeCheck(graph[cur].get(i), cnt+1);
			visit[graph[cur].get(i)] = false;
		}	
	}
	
	static boolean visitCheck()
	{
		for(int i = 1; i <= N; i++)
		{
			if(!visit[i])
				return false;
		}
		return true;
	}
}










