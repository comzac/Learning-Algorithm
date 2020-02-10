package com.ssafy.graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

/*
 * 1. 연결된 집들의 모임을 단지로 지정
 * 2. 대각선은 제외
 * 3. 단지의 가구수를 오름차순으로 출력 
 * 
 * 	5 <= N <= 25
 * 
 * 풀이방식 
 * 1. 행열로 순회하며 검사를 한다. 모든 ij 지점을 확인하지만 방문이 된 경우나 0인 경우 패스한다.
 * 2. 해당 지점이 1인 경우, 방문처리를 하거나 0으로 바꾼 뒤, 사방탐색을 통해 범위를 벗어나거나 주변에 더이상 1이 없는 상태에 됐을때, 매개변수로 
 * 	 전달받으며 카운팅한 가구 수를 ArrayList에 담는다.
 * 3. 1,2 번 반복한다.
 */
public class Main_B_2667_단지번호붙이기_이선수_DFS {

	static int[][] map = new int[25][25];
	static boolean[][] visit = new boolean[25][25];
	static int N;
	static ArrayList<Integer> arr = new ArrayList<>();
	static int[][] dir = new int[][] {{0,1},{1,0},{0,-1},{-1,0}};
	static int cnt;
	
	public static void main(String[] args) throws Exception, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
	
		for(int i = 0 ; i < N; i++)
		{
			String s = br.readLine();
			for(int j = 0 ; j < N; j++)
			{
				map[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
			}
		}
		
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0 ; j < N; j++)
			{
				if(visit[i][j] || map[i][j] == 0)
					continue;
				cnt = 0;
				dfs(i,j);
				arr.add(cnt);
			}
		}
		
		Collections.sort(arr);
		System.out.println(arr.size());
		for(int i = 0 ; i < arr.size() ; i++)
			System.out.println(arr.get(i));
	}
	
	static void dfs(int y, int x)
	{
		visit[y][x] = true;
		cnt++;
		for(int i = 0 ; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			
			if(ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] || map[ny][nx] == 0)
				continue;
			dfs(ny, nx);
		}
	}
	
	
	

}
