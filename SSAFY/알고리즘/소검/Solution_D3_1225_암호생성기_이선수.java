package com.ssafy.queue;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_D3_1225_암호생성기_이선수 {

	static final int limit = 8;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int t = 1; t <= 10; t++)
		{
			
			br.readLine();
			Queue<Integer> que = new LinkedList<Integer>();
			st = new StringTokenizer(br.readLine());
			for(int i = 0 ;i < limit; i++)
			{
				que.offer(Integer.parseInt(st.nextToken()));
			}		
			
			int minus = 0;
			while(true)	
			{	
				minus++;
				int first = que.poll();
				if(first - minus <= 0)
				{
					que.offer(0);
					break;
				}
				else
					que.offer(first-minus);
				
				if(minus == 5)
					minus = 0;
			}
			
			System.out.printf("#%d ", t);
			while(!que.isEmpty())
			{
				System.out.print(que.poll() + " ");
			}
			System.out.println();
		}
	}

}
