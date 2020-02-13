package com.ssafy.queue;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 * 1. 새로운 막대기를 놓을 때, 완전히 포함되도록 놓고, 끝점은 겹치지 않게 놓는다.
 * 2. 레이저는 어떤 쇠막대기의 양끝점과도 겹치지 않음
 * 3. 레이저는 적어도 하나 존재 
 *
 * 레이저는 () < 연속으로 나왔을 때 자름
 * 쇠막대기는 ( 가 있을 때 시작되고 )로 끝난다.
 * 
 * 풀이방식
 * 1. ( 가 나오면 스택에 넣어준다
 * 2. ) 가 나오면 스택에서 가장 위에거를 빼준다
 * 2-1) 그리고 스택크기를 답에 더해준다
 * 3. 1,2,3 반복
 */
public class Solution_D4_5432_쇠막대기자르기_이선수 {
	
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1 ; t <= T ; t++)
		{
			String s = br.readLine();
			Stack<Character> st = new Stack<>();
			int Len = s.length();
			int sum = 0;
			int before = 0;
			for(int i = 0 ; i < Len; i++)
			{
				if(s.charAt(i) == '(')
				{
					st.push(s.charAt(i));
					before = 0;
				}
				else
				{
					if(before == 0)
					{
						st.pop();
						sum += st.size();	
					}
					else
					{
						sum+=1;
						st.pop();
					}	
					before = 1;
				}
			}
				
			System.out.printf("#%d %d\n", t, sum);
		}
	}
}


// (((()(()()))(())()))(()())







