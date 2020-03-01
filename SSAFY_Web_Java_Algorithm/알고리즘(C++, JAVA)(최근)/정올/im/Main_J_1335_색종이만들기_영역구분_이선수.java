//11 im
package hw.im;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_J_1335_색종이만들기_영역구분_이선수 {

	static int[][] map;
	static int white;
	static int blue;
	
	static void div(int ws, int we, int hs, int he)
	{
		int base = map[ws][hs];
		boolean flag = true;
		for(int i = ws ; i < we; i++)
		{
			for(int j = hs; j < he; j++)
			{
				if(base != map[i][j])
					flag = false;
			}
		}
		if(flag)
		{
			if(base == 0)
				white++;
			else
				blue++;
			return;
		}
		else
		{
			div(ws, (ws+we)/2, hs, (hs+he)/2); // 1
			div((ws+we)/2, we, hs, (hs+he)/2); // 2
			div(ws, (ws+we)/2, (hs+he)/2, he); // 4
			div((ws+we)/2, we, (hs+he)/2, he); // 3
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		// 분할정복으로 가야할 듯
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		
		StringTokenizer st;
		
		for(int i = 0 ; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < N; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}
		
		div(0,N,0,N);
		System.out.println(white);
		System.out.println(blue);
	}

}
