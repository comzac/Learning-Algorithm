/*
 * 모든 방의 숫자가 다르다.
 * 숫자가 다 다르기 때문에 한 방에서 이동할 수 있는 방이 두가지인 경우는 없다.
 * 현재 위치에서 사방으로 이동이 가능하지만 현재 방보다 1의 값이 큰 경우만 가능하다
 * 어떤 방에 있어야 가장 많은 개수의 방을 이동할 수 있는지?
 * 1000*1000
 * 
 */
package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class pos{
	int y;
	int x;
	public pos(int y, int x) {
		super();
		this.y = y;
		this.x = x;
	}
	
}

public class Solution_D4_1861_정사각형방_이선수 {
	static int T;
	static int N;
	static int sx, sy;
	static boolean isOk;
	static int[][] map;
	static int[][] dp;
	static int[][] dir = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) 
		{
			ArrayList<pos> arr = new ArrayList<>();
			
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			dp = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());

				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}


			for (int i = 0; i < N; i++) 
			{
				for (int j = 0; j < N; j++) 
				{
					sy = i;
					sx = j;
					DP_dfs(i, j);
				}
			}
			int max = 0;
			
			// 최대값
			for (int i = 0; i < N; i++) 
			{
				for (int j = 0; j < N; j++) 
				{
					max = Math.max(max, dp[i][j]);
				}
			}
			
			// 동일값 위치
			for (int i = 0; i < N; i++) 
			{
				for (int j = 0; j < N; j++) 
				{
					if(dp[i][j] == max)
					{
						arr.add(new pos(i,j));
					}
				}
			}
			

			
			Collections.sort(arr, new Comparator<pos>() {

				@Override
				public int compare(pos o1, pos o2) {
					
					return map[o1.y][o1.x] - map[o2.y][o2.x];
				}
			});
			
			System.out.printf("#%d %d %d\n", t, map[arr.get(0).y][arr.get(0).x], dp[arr.get(0).y][arr.get(0).x]);
			
		}
	}


	static void DP_dfs(int y, int x) {
		if (dp[y][x] == 0) {
			
			dp[sy][sx]++;
						
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if(ny < 0 || nx < 0 || ny >= N || nx >= N)
					continue;
				
				if (map[ny][nx] == map[y][x] + 1) {
					DP_dfs(ny, nx);
					break;
				}
			}
		} 
		else {
			dp[sy][sx] = dp[y][x] +dp[sy][sx];
			return;
		}
	}

}
