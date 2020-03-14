/*
 * 	1. 처음에 dfs접근은 맞았으나, 방문실패를 했을 때 다시 원상복구를 시켰었다. 그리고 나서 경로가 완성될 때 마다 건물들의 인접여부를 확인하여
 * 	  상단부터 하단까지 이어져있는 형태를 띄면 더이상 경로를 생성할 수 없다 라는 로직으로 작성했지만(주석처리) 시간초과가 여전했다.
 *  2. 이 문제에 핵심은 백트래킹을 할 때, 어차피 밟았던 경로가 안되는 길이었다면 다시 밝지 않도록 하는 즉 false처리로 원상복구를 할 필요가 없었던 것이다.
 */

package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class pos3{
	int y;
	int x;
	public pos3(int y, int x) {
		super();
		this.y = y;
		this.x = x;
	}
	
}

public class Main_B_3109_빵집_이선수 {

	static int R;
	static int C;
	static char[][] map;
	static boolean[][] visit;
	static int pipes;
	static boolean isOver;
	static ArrayList<pos3> posList = new ArrayList<>();
	static ArrayList<pos3> tempPos = new ArrayList<>();
	static boolean[][] buildCheck;
	static int[][] dir = new int[][] {{-1,0},{0,1},{1,0},{0,-1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());		
		map = new char[R][C];
		visit = new boolean[R][C];
		
		String temp;
		char c;

		for(int i = 0 ; i < R; i++)
		{
			temp = br.readLine();
			for(int j = 0 ; j < C; j++)
			{
				c = temp.charAt(j);
				map[i][j] = c;
				if(c == 'x')
				{
					posList.add(new pos3(i,j));
				}
			}
		}
		
		for(int i = 0 ; i < R; i++)
		{
			dfs(i, 0);
			isOver = false;
			/*if(Xcheck())
			{
				break;
			}*/
		}
	
		System.out.println(pipes);
	}
	
	static boolean Xcheck()
	{
		int buildingNum = posList.size();
		buildCheck = new boolean[R][C];
		
		for(int i = 0 ; i < buildingNum; i++)
		{
			int y, x;
			y = posList.get(i).y;
			x = posList.get(i).x;
			if(buildCheck[y][x])
				continue;
			if(bfs(posList.get(i)))
				return true; // 경로가 막혔다.
		}
		return false;
	}
	
	static boolean bfs(pos3 cur)
	{
		PriorityQueue<pos3> que = new PriorityQueue<>(new Comparator<pos3>() {
			@Override
			public int compare(pos3 o1, pos3 o2) {
				if(o1.y == o2.y)
				{
					return o1.x - o2.x;
				}
				else
				{
					return o1.y - o2.y;					
				}
			}
		});
		boolean zeroRow = false;
		boolean finalRow = false;
		que.add(new pos3(cur.y, cur.x));
		buildCheck[cur.y][cur.x] = true; 
		
		while(!que.isEmpty())
		{
			pos3 curPos = que.poll();
			
			if(curPos.y == 0)
			{
				zeroRow = true;				
			}
			else if(curPos.y == R-1)
			{
				finalRow = true;
			}
			
			if(zeroRow && finalRow)
				return true;
			
			for(int i = 0 ; i < 4; i++)
			{
				int ny = curPos.y + dir[i][0];
				int nx = curPos.x + dir[i][1];
				
				if(ny < 0 || nx < 0 || ny >= R || nx >= C || buildCheck[ny][nx] || map[ny][nx] != 'x')
					continue;

				que.add(new pos3(ny,nx));
				buildCheck[ny][nx] = true;
			}
		}
		
		return false;
	}
	
	static void dfs(int y, int x)
	{
		if(x == C-1)
		{
			pipes++;
			isOver = true;
			for(int i = 0 ; i < tempPos.size(); i++)
			{
				posList.add(tempPos.get(i));
			}
			return;
		}
		
		
		if(y-1 >= 0 && map[y-1][x+1] != 'x') // 우상향
		{
			map[y-1][x+1] = 'x';
			//tempPos.add(new pos3(y-1, x+1));
			dfs(y-1, x+1);
			if(isOver)
				return;
			//map[y-1][x+1] = '.';
			//tempPos.remove(tempPos.size()-1);
		}
		
		if(map[y][x+1] != 'x' ) // 우향
		{
			map[y][x+1] = 'x';
			//tempPos.add(new pos3(y, x+1));
			dfs(y, x+1);
			if(isOver)
				return;
			//map[y][x+1] = '.';
			//tempPos.remove(tempPos.size()-1);
		}
		
		if(y+1 < R && map[y+1][x+1] != 'x') // 우하향
		{
			map[y+1][x+1] = 'x';
			//tempPos.add(new pos3(y+1, x+1));
			dfs(y+1, x+1);
			if(isOver)
				return;
			//map[y+1][x+1] = '.';
			//tempPos.remove(tempPos.size()-1);
		}
		
	}
	
	

}
