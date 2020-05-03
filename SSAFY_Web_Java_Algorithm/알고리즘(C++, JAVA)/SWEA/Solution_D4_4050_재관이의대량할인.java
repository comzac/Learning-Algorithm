package hw_algo0429_서울_7반_이선수;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Solution {
	
	static Integer[] price;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t = 1; t <= T; t++)
		{
			int N = sc.nextInt();
			price = new Integer[N+1];
			price[0] = 100001;
			for(int i = 1 ; i <= N; i++)
			{
				price[i] = sc.nextInt();
			}
			
			Arrays.sort(price, Collections.reverseOrder());
			
			int sum = 0;
			
			for(int i = 1 ; i <= N; i++)
			{
				if(i % 3 == 0)
					continue;
				sum += price[i];
			}
			
			System.out.println("#" + t + " " + sum);
		}
		
		
	}
}
