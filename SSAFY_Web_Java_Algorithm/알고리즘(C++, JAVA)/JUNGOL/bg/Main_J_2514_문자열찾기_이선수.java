//3 bg
/* 주의할 점
 * substring의 endidx는 포함되지 않는다
 * for을 통해 점진적으로 string을 검사할 때 끝 지점을 고려하여 범위한정을 정한다.
 * 문자열 비교는!!!!!!!!!!!!!!!!! equals~
 */
package hw.bg;

import java.util.Scanner;

public class Main_J_2514_문자열찾기_이선수 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String koi = "KOI";
		int ko = 0;
		String ioi = "IOI";
		int io = 0;
		
		for(int i = 0 ; i < s.length()-2; i++)
		{
			if(s.charAt(i) == 'K')
			{
				if(s.substring(i,  i+3).equals(koi))
					ko++;
			}
			else if(s.charAt(i) == 'I')
			{
				if(s.substring(i,  i+3).equals(ioi))
					io++;
			}		
		}
		
		System.out.println(ko);
		System.out.println(io);
		
		
	}

}
