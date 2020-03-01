//12 im
package hw.im;

import java.util.Scanner;

public class Main_J_1027_좋은수열_이선수 {

	static int len;
	static String[] num = new String[] {"1","2","3"};
	static int cnt;
	static boolean check;
	static void backt(String s)
	{
		boolean flag = false;
		for(int i = 0 ; i < 3; i++)
		{
			flag = false;
			String temp = s+num[i];
			int cycle = temp.length()/2;
			while(cycle!=0)
			{
				String sub1 = temp.substring(temp.length()-cycle*2,temp.length()-cycle );
				String sub2 = temp.substring(temp.length()-cycle, temp.length());
				if(sub1.equals(sub2))
				{
					flag = true;
					break;
				}
				cycle--;
			}
			
			if(flag)
				continue;
			else
			{
				cnt++;
				if(cnt == len)
				{
					System.out.println(temp);
					check = true;
					return;
				}
				backt(temp);
				if(check)
					break;
				cnt--;
			}
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		len = sc.nextInt();
		backt("");
	}

}
