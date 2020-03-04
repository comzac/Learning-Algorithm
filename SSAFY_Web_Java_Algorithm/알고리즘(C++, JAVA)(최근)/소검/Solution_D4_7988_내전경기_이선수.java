package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* 처음에는 사이클이 생겼을 때, 홀수갯수면 안된다고 생각을 해보고
 * 그림을 이래저래 그려봤더니 짝수사이클 두개가 붙어있으면
 * 순회하기가 애매했다.
 * 그래서 생각을 더 해본 결과, 어차피 인접해있는 노드는 서로 다른 값이어야기 때문에
 * 그래프만 형성할 수 있으면 순회를 하며 자기와 다른 값을 입력을 해준 뒤,
 * 최종적으로 인접관계를 살폈을 때, 같은 값이 나오면 false, 다른값이 전부 나오면 true 방식으로 진행해보자
 * 
 *  1. 그렇다면 그래프를 어떻게 형상할것인지, 짝은 어떻게 보관할 것인지
 *  2. 그리고 문자로 받아들인 값들은 어떻게 숫자로 변환 할 것인지
 *  
 *  1번은.. 음.. 아무거나 써도 될 듯하다. 큐든 스텍이든 뭐든 클래스만들어서 넣어두고
 *  2번은 새로운 값을 받을 때마다 넘버링을 변화해주며 순서대로 arraylist에 담자
 *  그럼 아마 visit도 해결이 될 듯 하다.
 *  
 *  이미 받은 값인지 확인하는 거에서 set이나 map을 쓰면 빠를텐데, 200개니깐 그냥해보자
 *  최악이어도 1+2+3+...+200 = 200*201/2 얼마안된다.
 * 
*/
public class Solution_D4_7988_내전경기_이선수 {
	
	static class partner{
		int s1;
		int s2;
		public partner(int s1, int s2) {
			super();
			this.s1 = s1;
			this.s2 = s2;
		}
	}
	
	static ArrayList<Integer> graph[];
	static boolean[] visit;
	static int[] teamNum;
	static ArrayList<partner> partners = new ArrayList<>();
	static ArrayList<String> sameCheck= new ArrayList<String>();
	static int numbering;
	static int K;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		for(int t = 1 ; t <= T; t++)
		{
			// 입력단계
			numbering = 0;
			partners.clear();
			sameCheck.clear();
			K = Integer.parseInt(br.readLine());
			
			graph = new ArrayList[K*K+1];
			for(int k = 0 ; k < K*K+1; k++)
				graph[k] = new ArrayList<Integer>();
			
			visit = new boolean[K*K+1];
			teamNum = new int[K*K+1];
			
			String s1, s2;
			int n1, n2;
			n1 = n2 = 0;
			
			for(int i = 0 ; i < K; i++)
			{
				st = new StringTokenizer(br.readLine());
				s1 = st.nextToken();		
				if(!sameCheck.contains(s1))
				{
					sameCheck.add(s1);
					n1 = numbering;
					numbering++;
				}
				else
				{
					n1 = sameCheck.indexOf(s1);
				}
				s2 = st.nextToken();
				if(!sameCheck.contains(s2))
				{
					sameCheck.add(s2);
					n2 = numbering;
					numbering++;
				}
				else
				{
					n2 = sameCheck.indexOf(s2);
				}
				graph[n1].add(n2);
				graph[n2].add(n1);
				partners.add(new partner(n1, n2));
			}
			
			// 여까지 짝궁, 그래프 생성
			
			for(int i = 0 ; i < sameCheck.size(); i++)
			{
				if(visit[i])
					continue;
				adjoinCheck(i);				
			}
			
			
			boolean isSame = false;
			for(int i = 0 ; i < partners.size(); i++)
			{
				if(teamNum[partners.get(i).s1] != teamNum[partners.get(i).s2])
					continue;
				isSame = true;
				break;
			}
			
			if(isSame)
				System.out.println("#" + t + " " + "No");
			else
				System.out.println("#" + t + " " + "Yes");
		}
	}
	
	static void adjoinCheck(int first)
	{
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(first);
		visit[first] = true;
		teamNum[first] = 0;
		
		while(!que.isEmpty())
		{
			int size = que.size();
			int curTeamNum = teamNum[que.peek()];
			while(size-->0)
			{
				int cur = que.poll();
				
				for(int i = 0 ; i < graph[cur].size(); i++)
				{
					int next = graph[cur].get(i);
					if(visit[next])
						continue;
					visit[next] = true;
					teamNum[next] = (curTeamNum+1)%2;
					que.add(next);
				}
				
			}
		}
		
		
		
	}
	
}












