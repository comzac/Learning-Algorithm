//10 bg
package hw.bg;

import java.util.Scanner;

public class Main_J_2604_±×¸©_ÀÌ¼±¼ö {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		char start = '[';
		int h = 0;
		for(int i = 0 ; i < s.length(); i++)
		{
			if(start == s.charAt(i))
				h+=5;
			else
			{
				h+=10;
				start = s.charAt(i);
			}
		}
		
		System.out.println(h);
	}

}
