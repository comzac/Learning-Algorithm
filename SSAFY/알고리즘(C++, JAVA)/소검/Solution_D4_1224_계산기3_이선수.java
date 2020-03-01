
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution_D4_1224_계산기3_이선수 {
	static Stack<Integer> temp = new Stack<>();
	static boolean isNumber(char c)
	{
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
			return false;
		return true;		
	}
	
	static boolean priority(int l, int r)
	{
		if(l == '(' || r == '(')
			return false;
		if(l < r)
			return false;
		else
			return true;
	}
	
	static int operPrio(char c)
	{
		switch(c)
		{
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		}
		return 0;
	}
	
	public static void main(String[] args) throws Exception, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int t = 1; t <= 10; t++)
		{
			int len = Integer.parseInt(br.readLine());
			String s = br.readLine();
			int idx = 0;
			Stack<Character> st = new Stack<>();
			Queue<Character> que = new LinkedList<>();
			
			while(idx < len)
			{
				char c = s.charAt(idx);
				if(isNumber(c)) // 숫자면
					que.add(c);
				else
				{
					if(c == '(') // 여는 괄호
						st.push(c);
					else if(c == ')') // 닫는 괄호
					{
						while(st.peek() != '(')
						{
							que.add(st.pop());
						}
						st.pop(); //  '(' 괄호제거
					}
					else // 연산자
					{
						if(st.empty())
							st.push(c);
						else
						{
							if(priority(operPrio(st.peek()), operPrio(c))) // top > 현재 문자
							{
								while(priority(operPrio(st.peek()), operPrio(c)))
								{
									que.add(st.pop());
								}
								
								st.push(c);
							}
							else // top < 현재문자 = top보다 먼저 연산될거니깐
							{
								st.push(c);
							}
						}
					}
					
				}
				
				idx++;
					
			}

			while(!que.isEmpty())
			{
				
				int tempResult;
				char c = que.poll();
				if(isNumber(c))
					temp.push(Integer.parseInt(String.valueOf(c)));
				else
				{
					int r = Integer.parseInt(String.valueOf(temp.pop()));
					int l = Integer.parseInt(String.valueOf(temp.pop()));
					switch(c)
					{
					
					case '+':
						tempResult = l+r;
						temp.push(tempResult);
						break;
					case '*':
						tempResult = l*r;
						temp.push(tempResult);			
						break;
					case '-':
						tempResult = l-r;
						temp.push(tempResult);			
						break;
					case '/':
						tempResult = l/r;
						temp.push(tempResult);			
						break;
					}
				}
			}
			System.out.printf("#%d %d\n", t, temp.pop());
		}

		
	}

}
