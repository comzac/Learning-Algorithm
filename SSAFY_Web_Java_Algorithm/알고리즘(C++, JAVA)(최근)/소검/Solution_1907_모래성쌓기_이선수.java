package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 0030~0150(1차시도) + ~ 0230 = 2H
// 7개 -> 2초, 262144kbytes => 256MB
// 빙산문제였나? 그거랑 비슷한거 같은데
// 차이가 있다면 범위? 1000까지라는것이다.
// 파도가 칠때마다 모래성의 주변 개수를 증가시켜줘야하는데,
// 파도가 한번 칠때마다 최대범위에서 최소 1,000,000(보다작음)의 연산이 이뤄져야한다. 
// 더불어 각 연산마다 팔방향을 검사하면 *8, 파도 열번만 쳐도 1억이다.

// 역시 클래스로만 해서 전부 순회를 하니 시간초과가 난다.
// add를 하는 과정에서부터 다음번에 무너지질지 안무너질지 알 수 있는데, 이걸 단순화시켜보자.


public class Solution_1907_모래성쌓기_이선수2 {
	
	static class pos{
		int y;
		int x;
		
		pos(int y, int x)
		{
			this.y = y;
			this.x = x;
		}
	}
	
	static int[][] dir = new int[][] {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; // i%2 ==0 가로이동 , 1이 세로이동
	static int N, M;
	static int[][] nadj;
	static int[][] map;
	static boolean[][] visit;
	static Queue<pos> que = new LinkedList<>();

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
			nadj = new int[N][M];
			visit = new boolean[N][M];
			
			for(int i = 0 ; i < N ; i++)
			{
				String s = br.readLine();
				for(int j = 0 ; j < M; j++)
				{
					char c = s.charAt(j);
					
					if(Character.isDigit(c))
					{
						map[i][j] = c - '0';
					}
					else
					{
						map[i][j] = -1;
					}
				}
			}
			adjoinCheck();
			System.out.println("#" + t + " " + destroy());
		}
		
	}
	
	static int destroy()
	{
		int cnt = 0;
		int size = 0;
		pos cur;
		int curY, curX;
		int ny, nx;
		while(!que.isEmpty())
		{
			size = que.size();
			
			while(size-->0)
			{
				cur = que.poll(); // 무너질 애들
				curY = cur.y;
				curX = cur.x;
				
				//디버깅
				/*
				 * map[curY][curX] = -1; for(int i = 0 ; i < N;i++)
				 * System.out.println(Arrays.toString(map[i])); System.out.println();
				 */
				
				for(int k = 0 ; k < 8 ; k ++)
				{
					ny = curY+dir[k][0];
					nx = curX+dir[k][1];
					
					if(ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == -1)
						continue;
					nadj[ny][nx]++;
					if(map[ny][nx] <= nadj[ny][nx]) // 맨 처음 부서질 애들
					{
						visit[ny][nx] = true;
						que.add(new pos(ny,nx));
					}
				}
			}
			cnt++;
		}
		
		
		return cnt;
	}
	
	static void adjoinCheck()
	{
		int ny, nx;
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0 ; j < M ; j++)
			{
				if(map[i][j] == -1 || map[i][j] == 9)
					continue;
				
				for(int k = 0 ; k < 8 ; k ++)
				{
					ny = i+dir[k][0];
					nx = j+dir[k][1];
					
					if(ny < 0 || nx < 0 || ny >= N || nx >= M )
						continue;
					
					if(map[ny][nx] == -1)
						nadj[i][j]++;
				}
				
				if(map[i][j] <= nadj[i][j]) // 맨 처음 부서질 애들
				{
					visit[i][j] = true;
					que.add(new pos(i,j));
				}
			}
		}		
	}	
}










