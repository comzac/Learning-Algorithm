package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

//1600~
public class Solution_1247_최적경로_이선수2 {
	static class pos{
		int y;
		int x;
		public pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	static int N;
	static pos home;
	static pos company;
	static pos[] cunsumer;
	static int[][] dis;
	static int[] companyDis;
	static int[] homeDis;
	static boolean[] visit;
	static int[] nparr;
	static int min;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1 ; t <= T; t++)
		{
			//입력과정
			min = 999999999;
			N = Integer.parseInt(br.readLine());
			dis = new int[N][N];
			cunsumer = new pos[N];
			visit = new boolean[N];
			nparr = new int[N];
			st = new StringTokenizer(br.readLine());
			company = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			home = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

			for(int i = 0 ; i < N; i++)
			{
				cunsumer[i] = new pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			
			//거리관계배열 생성
			makeDisInfo();
			compareDis();
			System.out.printf("#%d %d\n", t, min);
		}
	}
	
	static void makeDisInfo()
	{
		for(int i = 0 ; i < N ; i ++)
		{
			for(int j = 0 ; j < N; j++)
			{
				dis[i][j] = Math.abs(cunsumer[i].y - cunsumer[j].y)+Math.abs(cunsumer[i].x - cunsumer[j].x);
			}
		}
		companyDis = new int[N];
		homeDis = new int[N];
		for(int j = 0 ; j < N; j++)
		{
			companyDis[j] = Math.abs(company.y - cunsumer[j].y)+Math.abs(company.x - cunsumer[j].x);
			homeDis[j] = Math.abs(home.y - cunsumer[j].y)+Math.abs(home.x - cunsumer[j].x);
		}
		
		for(int i = 0 ; i < N; i++)
			nparr[i] = i;
		
	}
	
	static void compareDis()
	{
		int disSum;

		do {
			disSum = 0;
			// 회사부터 첫 위치 거리
			disSum += companyDis[nparr[0]];
			
			// 고객사 간의 거리
			for(int i = 1 ; i < N; i++)
			{
				disSum += dis[nparr[i-1]][nparr[i]];
			}
			
			disSum += homeDis[nparr[N-1]];
			
			if(min > disSum)
				min = disSum;
	
		}while(nextPermution(nparr));
	}
	
	static boolean nextPermution(int[] arr)
	{
		int i = N-1;
		
		while(i > 0 && arr[i-1] >= arr[i]) 
			i--;
		if(i==0)
			return false;
		
		int j = N-1;
		int num = arr[i-1];
		
		while(arr[j] <= num) 
			j--;
		
		int temp = arr[j];
		arr[j] = num;
		arr[i-1] = temp;
		
		Arrays.sort(arr, i, N);
		
		return true;
	}
}










