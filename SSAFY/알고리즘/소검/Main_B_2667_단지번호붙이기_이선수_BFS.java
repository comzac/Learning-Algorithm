package com.ssafy.graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main_B_2667_단지번호붙이기_이선수_BFS {
	static int[][] map = new int[25][25];
	static boolean[][] visit = new boolean[25][25];
	static int N;
	static ArrayList<Integer> arr = new ArrayList<>();
	static int[][] dir = new int[][] { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	static int cnt;

	public static void main(String[] args) throws Exception, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
			}
		}

		
		
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0 ; j < N; j++)
			{
				if(map[i][j] == 0 || visit[i][j])
					continue;
				cnt = 0;
				bfs(i, j);
				arr.add(cnt);
			}
		}
		
		Collections.sort(arr);
		System.out.println(arr.size());
		for(int i = 0 ; i < arr.size() ; i++)
			System.out.println(arr.get(i));
		
		

	}

	static void bfs(int sy, int sx)
	{
		Queue<Integer> qx = new LinkedList<>();
		Queue<Integer> qy = new LinkedList<>();

		visit[sy][sx] = true;
		qy.offer(sy);
		qx.offer(sx);
		
		while(!qy.isEmpty() && !qx.isEmpty())
		{
			int y = qy.poll();
			int x = qx.poll();
			cnt++;
			for(int i = 0 ; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				
				if(ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || map[ny][nx] == 0)
					continue;
				visit[ny][nx] = true;
				qy.offer(ny);
				qx.offer(nx);
			}
		}	
	}
}













