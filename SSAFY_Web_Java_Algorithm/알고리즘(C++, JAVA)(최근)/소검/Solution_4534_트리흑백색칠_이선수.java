package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 주어진 그래프는 트리임이 보장된다. => 사이클이 없다. 인접이 끊긴 별도의 그래프가 존재하지 않는다.

public class Solution_4534_트리흑백색칠_이선수 {
	
	static int N;
	static ArrayList<Integer> graph[];
	static int[] parent;
	static boolean[] visit;
	static int[][] dp;

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			// 입력단계
			N = Integer.parseInt(br.readLine());
			visit = new boolean[N+1];
			parent = new int[N+1];
			dp = new int[N+1][2];
			
			graph = new ArrayList[N+1];
			for(int i = 1; i <= N;i++)
				graph[i] = new ArrayList<Integer>();
			
			int node1, node2;
			for(int i = 0 ; i < N-1; i++)
			{
				st = new StringTokenizer(br.readLine());
				node1 = Integer.parseInt(st.nextToken());
				node2 = Integer.parseInt(st.nextToken());
				graph[node1].add(node2);
				graph[node2].add(node1);
			}

			makeParent(1);
			
			int white = paint(1,0);
			int black = paint(1,1);
			
			System.out.printf("#%d %d\n", t, (white + black)%1000000007);
		}
		
	}
	
	static void makeParent(int startIdx)
	{
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(startIdx);
		visit[startIdx] = true;
		
		while(!que.isEmpty())
		{
			int cur = que.poll();
			
			for(int i = 0 ; i < graph[cur].size(); i++)
			{
				if(visit[graph[cur].get(i)])
					continue;
				que.add(graph[cur].get(i));
				visit[graph[cur].get(i)] = true;
				parent[graph[cur].get(i)] = cur;
			}
			
		}
		
	}
	static int paint(int idx, int color)
	{
		// 점화식 dp(w) = dp(b) + dp(w) , dp(b) =  dp(w), 
		// 자식 노드끼리 경우의 수를 곱해주고 더해준다.
		boolean hasNext = false;
		for(int i = 0 ; i < graph[idx].size(); i++)
		{
			if(graph[idx].get(i) == parent[idx]) // 이미 방문했으면 노노
				continue;
			hasNext=true;
		}
		if(!hasNext)
			return 1; //단말노드
		
		long white;
		long black;
		long sum = 1;
	
		int i;		
		if(dp[idx][color] != 0)
			return dp[idx][color]%1000000007;
		
		if(color == 0)
		{
			//흰색일 때,
			sum = 1;
			for(i = 0 ; i < graph[idx].size(); i++)
			{
				if(graph[idx].get(i) == parent[idx]) // 이미 방문했으면 노노
					continue;
				int nextNode = graph[idx].get(i);
				white = paint(nextNode, 0)%1000000007 + paint(nextNode, 1)%1000000007;
				sum*=white;
				sum%=1000000007;
			}
		}

		//흑색일 때,
		else
		{
			sum = 1;
			for(i = 0 ; i < graph[idx].size(); i++)
			{
				if(graph[idx].get(i) == parent[idx])
					continue;
				int nextNode = graph[idx].get(i);
				black = paint(nextNode, 0)%1000000007;
				sum*=black;
				sum%=1000000007;
			}

		}
		

		return dp[idx][color] = (int) sum;
	}
}










