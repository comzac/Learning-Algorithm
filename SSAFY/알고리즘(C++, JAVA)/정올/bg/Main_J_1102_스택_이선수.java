//5 bg
package hw.bg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main_J_1102_스택_이선수 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Stack<Integer> sta = new Stack<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int num = Integer.parseInt(br.readLine());
		StringTokenizer st;
		
		for(int i = 0 ; i < num; i++)
		{
			st = new StringTokenizer(br.readLine());
			String com = st.nextToken();
			if(com.equals("i"))
			{
				sta.add(Integer.parseInt(st.nextToken()));
			}
			else if(com.equals("c"))
			{
				System.out.println(sta.size());
			}
			else if(com.equals("o"))
			{
				if(sta.empty())
				{
					System.out.println("empty");
				}
				else
				{
					int top = sta.pop();
					System.out.println(top);					
				}
			}
		}
		
	}

}
