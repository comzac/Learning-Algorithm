package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class pos4{
	int y;
	int x;
	public pos4(int y, int x) {
		super();
		this.y = y;
		this.x = x;
	}
}
public class Main_B_7576_토마토_이선수 {

	static int N; // 세로 (2~1000)
	static int M; // 가로 (2~1000)
	static int[][] box = new int[1000][1000];
	static boolean[][] visit = new boolean[1000][1000];
	static Queue<pos4> que = new LinkedList<pos4>();
	static int[][] dir = new int[][] {{0,1},{0,-1},{1,0},{-1,0}};
	static int unTomato;
	static boolean isOver;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		int temp;
		
		for(int i = 0 ; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < M; j++)
			{
				temp = Integer.parseInt(st.nextToken());
				box[i][j] = temp;
				if(temp == 1) // 익은 토마토면
				{
					que.add(new pos4(i,j));
					visit[i][j] = true;
				}
				else if(temp == 0)
				{
					unTomato++;
				}
			}
		}
		
		if(unTomato == 0)
			System.out.println(0);
		else
		{
			int days = bfs();
			System.out.println(days);			
		}
	}
	
	static int bfs()
	{
		int days = 0;
		while(!que.isEmpty())
		{
			int size = que.size();
			
			while(size-->0)
			{
				pos4 curpos = que.poll();
				
				for(int i = 0 ; i < 4; i++)
				{
					int ny = curpos.y + dir[i][0];
					int nx = curpos.x + dir[i][1];
					
					if(ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || box[ny][nx] == -1)
						continue;
					
					visit[ny][nx] = true;
					if(box[ny][nx] == 0) // 안익은 -> 익혀주고, 안익은토마토 개수 줄여주고
					{
						que.add(new pos4(ny,nx));
						box[ny][nx] = 1;
						unTomato--;
						if(unTomato == 0)
						{
							isOver = true;
							break;
						}
					}
					else // 익은
					{
						que.add(new pos4(ny,nx));
					}
				}
			}
			days++;
			if(isOver)
				break;
		}
		if(!isOver)
		{
			return -1;
		}
		else
		{
			return days;
		}
	}
	

}

















