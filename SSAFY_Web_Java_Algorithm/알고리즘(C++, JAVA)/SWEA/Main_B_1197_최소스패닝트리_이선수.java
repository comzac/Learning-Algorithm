package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main_B_1197_최소스패닝트리_이선수 {
	
	static int V, E;
	static int[] parent;
	static int[][] node;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		parent = new int[V+1];
		node = new int[E][3];
		
		int a, b, l;
		for(int i = 0; i < E; i++)
		{
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			
			node[i][0] = a;
			node[i][1] = b;
			node[i][2] = l;
		}
		
		Arrays.sort(node, Comparator.comparingInt(o1 -> o1[2]));
		
		int sum = 0;
		
		make_set();
		for (int i = 0; i < E; i++) {
			int to = (int)node[i][0];
			int from = (int)node[i][1];
			
			if(unionSet(to, from))
			{
				sum += node[i][2];
			}
		}
		
		System.out.println(sum);
	}
	
	public static void make_set() {
		for(int i = 1 ; i <= V; i++)
			parent[i] = -1;
	}
	
	public static int getParent(int x) {
		if(parent[x] < 0)
			return x;
		
		return parent[x] = getParent(parent[x]);
	}
	
	public static boolean unionSet(int a, int b) {
		int rootA = getParent(a);
		int rootB = getParent(b);
		
		if(rootA == rootB)
			return false;
		
		if(parent[rootA] < parent[rootB]) {
			parent[rootA] += parent[rootB];
			parent[rootB] = rootA;
		}else {
			parent[rootB] += parent[rootA];
			parent[rootA] = rootB;
		}
		return true;
	}
}
