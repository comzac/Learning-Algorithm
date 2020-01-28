//4 bg
package hw.bg;

import java.util.Scanner;

public class Main_J_1997_¶±¸Ô´ÂÈ£¶ûÀÌ_ÀÌ¼±¼ö {

	static int f;
	static int days;
	
	static String fibo(int days)
	{
		if(days == 1)
			return "a";
		else if(days == 2)
			return "b";
		
		return fibo(days-2)+fibo(days-1);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * a
		 * b
		 * a+b = a+b
		 * a+b+b = a+2b
		 * a+b+b+a+b = 2a+3b
		 * a+b+b+a+b+a+b+b = 3a+5b
		 * a+b+b+a+b+a+b+b+a+b+b+a+b = 5a+8b
		 */
		Scanner sc = new Scanner(System.in);
		days = sc.nextInt();
		f = sc.nextInt();
		String answer = fibo(days);
		int a = 0;
		int b = 0;
		for(int i = 0 ; i <answer.length();i++)
		{
			if(answer.charAt(i)=='a')
				a++;
			if(answer.charAt(i)=='b')
				b++;
		}
		
		for(int A = 1; A*a <= f ; A++)
		{
			for(int B = 1; B*b <= f; B++)
			{
				if(A*a+B*b == f)
				{
					System.out.println(A);
					System.out.println(B);
					return;
				}
			}
		}
		
	}

}
