package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* 1650~1720
 * 수연이의 위치는 ‘S’, 여신의 공간은 ‘D’, 돌의 위치는 ‘X’, 악마는 ‘*’
 * 
 * 고슴도치 문제랑 똑같다.
 */
public class Solution_D5_7793_오나의여신님_이선수 {

	static class pos
	{
		int y;
		int x;
		public pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	
	static Queue<pos> sque = new LinkedList<>();
	static Queue<pos> dque = new LinkedList<>();
	static int N, M;
	static char map[][];
	static int dir[][] = new int[][] {{0,1},{0,-1},{1,0},{-1,0}};
	static pos dest;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T;
		T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T ; t++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			map = new char[N][M];
			dest = new pos(0, 0);
			for(int i = 0 ; i < N ; i++)
			{
				String temp = br.readLine();
				for(int j = 0 ; j < M; j++)
				{
					map[i][j] = temp.charAt(j);
					if(map[i][j] == 'S') 
					{						
						sque.add(new pos(i,j));
					}
					else if(map[i][j] == '*') 
					{
						dque.add(new pos(i,j));
					}
					else if(map[i][j] == 'D')
					{
						dest.y = i;
						dest.x = j;
					}
				}
			}
			
			
			int answer = 0;
			answer = move();
			if(answer == 0)
			{
				System.out.println("#" + t + " " + "GAME OVER");
			}
			else
			{
				System.out.println("#" + t + " " + answer);
			}
			
			dque.clear();
			sque.clear();
		}
	}
	
	static int move()
	{
		int curY, curX, ny, nx;
		int time = 0;
		while(!sque.isEmpty())
		{
			int dsize = dque.size();
			while(dsize-->0)
			{
				curY = dque.peek().y;
				curX = dque.peek().x;
				dque.poll();
				
				for(int i = 0 ; i < 4 ; i ++)
				{
					ny = curY + dir[i][0];
					nx = curX + dir[i][1];
					
					if(ny < 0 || nx <0 || ny >= N || nx >= M || map[ny][nx] == '*' || map[ny][nx] == 'X' || map[ny][nx] == 'D')
						continue;
					dque.add(new pos(ny,nx));
					map[ny][nx] = '*';
				}
			}
			
			int ssize = sque.size();
			while(ssize-->0)
			{
				curY = sque.peek().y;
				curX = sque.peek().x;
				sque.poll();
				
				if(curY == dest.y && curX == dest.x)
				{
					return time;
				}
				for(int i = 0 ; i < 4 ; i ++)
				{
					ny = curY + dir[i][0];
					nx = curX + dir[i][1];
					
					if(ny < 0 || nx <0 || ny >= N || nx >= M || map[ny][nx] == '*' || map[ny][nx] == 'S' || map[ny][nx] == 'X')
						continue;
					sque.add(new pos(ny,nx));
					map[ny][nx] = 'S';
				}
			}
			time++;
		}
		return 0;
	}
}
















