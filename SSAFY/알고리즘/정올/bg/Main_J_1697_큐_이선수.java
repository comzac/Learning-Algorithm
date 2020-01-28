//6 bg
/* 주의할 점
 * stack과 다르게 별도의 라이브러리를 제공하기보다는
 * linkedlist를 활용한다.
 * method명이 다르다.
 */
package hw.bg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_J_1697_큐_이선수 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Queue<Integer> qu = new LinkedList<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int num = Integer.parseInt(br.readLine());
		StringTokenizer st;
		
		for(int i = 0 ; i < num; i++)
		{
			st = new StringTokenizer(br.readLine());
			String com = st.nextToken();
			if(com.equals("i"))
			{
				qu.add(Integer.parseInt(st.nextToken()));
			}
			else if(com.equals("c"))
			{
				System.out.println(qu.size());
			}
			else if(com.equals("o"))
			{
				if(qu.isEmpty())
				{
					System.out.println("empty");
				}
				else
				{
					int top = qu.peek();
					qu.remove();
					System.out.println(top);					
				}
			}
		}
	}

}
