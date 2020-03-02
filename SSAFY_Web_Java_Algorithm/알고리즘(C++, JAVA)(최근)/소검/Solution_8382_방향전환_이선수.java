package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 2350~1220
// 가로이동, 세로이동 상태 넣어서 이동시키고
// visit도 3차원 배열로 가로세로로 받고

public class Solution_8382_방향전환_이선수 {
	
	static class pos{
		int y;
		int x;
		int vh; // 0이면 가로, 1이면 세로
		public pos(int y, int x, int vh) {
			super();
			this.y = y;
			this.x = x;
			this.vh = vh;
		}
		
	}
	
	static pos start;
	static pos end;
	static boolean[][][] visit = new boolean[202][202][2]; // 0이 가로이동 , 1이 세로이동
	static int[][] dir = new int[][] {{0,1},{1,0},{0,-1},{-1,0}}; // i%2 ==0 가로이동 , 1이 세로이동
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++)
		{
			st = new StringTokenizer(br.readLine());
			
			start = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
			end = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
			
			System.out.println("#" + t + " " + bfs(start));
			
			for(int i = 0 ; i < 202; i++)
			{
				for(int j = 0 ; j < 202; j++)
				{
					visit[i][j][0] = false;
					visit[i][j][1] = false;
				}
			}
		}
		
	}
	
	
	
	static int bfs(pos start)
	{
		int move = 0;
		
		Queue<pos> que = new LinkedList<pos>();
		que.add(start);
		que.add(new pos(start.y, start.x, 1));
		visit[start.y + 100][start.x+ 100][0] = true;
		visit[start.y+ 100][start.x+ 100][1] = true; // 장애물이나 다른 조건이 없으니 제자리로 돌아오는건 최소거리에서 필요없을듯
		
		int curY, curX, curVH;
		int ny, nx;
		pos cur;
		
		while(!que.isEmpty())
		{
			int size = que.size();
			
			while(size-- >0)
			{
				cur = que.poll();
				curY = cur.y;
				curX = cur.x;
				curVH = cur.vh;
				
				if(curY == end.y && curX == end.x)
					return move;
				for(int i = 0 ; i < 4; i++)
				{
					if(i%2 == curVH)
						continue;
					ny = curY + dir[i][0];
					nx = curX + dir[i][1];
					
					if(ny < -100 || nx < -100 || ny > 100 || nx > 100 || visit[ny+100][nx+100][i%2])
						continue;
					visit[ny+100][nx+100][i%2] = true;
					que.add(new pos(ny, nx, i%2));
				}
				
				
			}
			move++;
		}
		
		return move;	
	}
}










