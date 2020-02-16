/*
 * 1. 각 칸에 포함된 적의 수는 최대 하나
 * 2. 격자판의 N번행의 바로 아래(N+1번 행)의 모든 칸에는 성
 * 3. 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|
 * 
 */
package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class pos2{
	int y;
	int x;
	public pos2(int y, int x) {
		super();
		this.y = y;
		this.x = x;
	}
}
public class Main_B_17135_캐슬디펜스_이선수 {

	static int[][] map = new int[16][15]; // 궁수 위치를 위해 추가
	static int[][] baseMap = new int[16][15]; // 검사를 위해 넘겨줄 맵
	static boolean[][] killcheck = new boolean[16][15];
	static boolean[][] visit = new boolean[16][16]; // bfs 탐색 시, 연산량 줄이기
	static boolean[] spotCombi;
	static int N; // Y
	static int M; // X
	static int D; // 거리 (D이하)
	static int maxVal = 0;
	static int[][] dir = new int[][] {{0,-1},{0,1},{-1,0}};
	static int enemyNum;
	static int enemyCnt;
	static int killEnemy;
	static boolean isOver;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		for(int i = 0 ; i < N; i ++)
		{
			st = new StringTokenizer(br.readLine());
			int temp;
			for(int j = 0 ; j < M; j++)
			{
				temp = Integer.parseInt(st.nextToken());
				baseMap[i][j] = temp;
				if(temp == 1)
					enemyCnt++;
			}
		}
		if(enemyCnt != 0)
		{
			spotCombi = new boolean[M];
			for(int i = 0 ; i < M; i++)
			{
				spotCombi[i] = true;
				attackSpot(i, 1);
				spotCombi[i] = false;
			}
		}

		
		System.out.println(maxVal);
		
	}
	
	static void mapCopy()
	{
		for(int i = 0 ; i < N; i ++)
		{
			for(int j = 0 ; j < M; j++)
			{
				map[i][j] = baseMap[i][j];
			}
		}
	}
	
	static void attackSpot(int idx, int cnt)
	{
		if(idx == M || cnt == 3)
		{
			if(cnt == 3)
			{
				//System.out.println(Arrays.toString(spotCombi));
				ArrayList<pos2> posArr = new ArrayList<>();
				for(int i = 0 ; i < M;i ++)
				{
					if(spotCombi[i])
					{
						posArr.add(new pos2(N, i));
					}
				}
				killEnemy = 0;
				enemyNum = enemyCnt;
				mapCopy();
				bfs(posArr);
				isOver = false;
				if(killEnemy > maxVal)
					maxVal = killEnemy;
			}
			return;
		}
		
		for(int i = idx+1 ; i < M; i++)
		{
			if(spotCombi[i])
				continue;
			spotCombi[i] = true;
			attackSpot(i, cnt+1);
			spotCombi[i] = false;
		}
	}
	
	static void visitInit()
	{
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0; j <M; j++)
			{
				visit[i][j] = false;
			}
		}
	}
	
	static void enemyMove()
	{
		for(int i = N; i >= 1; i--)
		{
			for(int j = 0; j < M; j++)
			{
				if(i == N)
				{
					if(map[i-1][j] == 1)
					{
						map[i-1][j] = 0;
						enemyNum--;
					}
				}
				else
				{
					if(map[i-1][j] == 1)
					{
						map[i-1][j] = 0;
						map[i][j] = 1;
					}
				}
				if(enemyNum == 0)
				{
					isOver = true;
					return;
				}
			}
		}
	}
	
	static void bfs(ArrayList<pos2> p)
	{
		PriorityQueue<pos2> sameDistance = new PriorityQueue<>(new Comparator<pos2>() {
			@Override
			public int compare(pos2 o1, pos2 o2) {
				return o1.x - o2.x;
			}
		});
		
		Queue<pos2> que = new LinkedList<>();
		HashSet<pos2> kill = new HashSet<>();
		
		while(!isOver)
		{
			for(int i = 0 ; i < p.size(); i++) // 세명 각각 검사
			{
				que.add(new pos2(p.get(i).y, p.get(i).x));
				visit[p.get(i).y][p.get(i).x] = true;
				int distance = 0;
				while(!que.isEmpty())
				{
					int size = que.size();
					boolean isFind = false;
					while(size-->0)
					{
						pos2 cur = que.poll();
						
						if(map[cur.y][cur.x] == 1)
						{
							sameDistance.add(new pos2(cur.y,cur.x));
							isFind = true;
						}
						for(int j = 0 ; j < 3; j++)
						{
							int ny = cur.y + dir[j][0];
							int nx = cur.x + dir[j][1];
							if(ny < 0 || nx < 0 || nx >= M || ny == N || visit[ny][nx])
								continue;
							que.add(new pos2(ny, nx));
							visit[ny][nx] = true;
						}
					}
					if(isFind) // 찾은 경우
					{
						pos2 minimum = sameDistance.poll();
						kill.add(new pos2(minimum.y, minimum.x));
						break;
					}
					if(distance >= D) // 거리제한
						break;
					distance++;
				}
				
				// 전부 초기화
				que.clear();
				sameDistance.clear();
				visitInit();
			}
			
			Iterator<pos2> it = kill.iterator();

			while(it.hasNext())
			{
				pos2 cur = it.next();
				if(killcheck[cur.y][cur.x]) continue;
				map[cur.y][cur.x] = 0;
				killcheck[cur.y][cur.x] = true;
				killEnemy++; // 죽인 수
				enemyNum--; // 죽은 수 ( 혹은 범위를 벗어날 때 감소)
				if(enemyNum == 0)
				{
					isOver = true;
					break;
				}
			}

			killInit();
			kill.clear();
			enemyMove();
		}
	}
	
	static void killInit()
	{
		for(int i = 0 ; i < N; i++)
		{
			for(int j = 0; j <M; j++)
			{
				killcheck[i][j] = false;
			}
		}
	}
}
