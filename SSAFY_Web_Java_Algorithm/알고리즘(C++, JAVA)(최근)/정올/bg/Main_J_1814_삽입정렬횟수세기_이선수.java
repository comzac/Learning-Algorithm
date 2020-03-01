//8 bg
package hw.bg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_J_1814_삽입정렬횟수세기_이선수 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		ArrayList<Integer> arrl = new ArrayList<Integer>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N; i++)
		{
			arrl.add(Integer.parseInt(st.nextToken()));
		}
		
		int cnt = 0;
		int len = arrl.size();
		int idx = 0;
		for(int i =0; i < len-1; i++)
		{
			if(arrl.get(i) <= arrl.get(i+1))
				continue;
			for(int j = i; j >=0; j--)
			{
				if(arrl.get(j) > arrl.get(i+1))
				{
					idx = j;
					cnt++;
				}
				else
					break;
			}
			int temp = arrl.get(i+1);
			arrl.remove(i+1);
			arrl.add(idx, temp);
		}
		System.out.println(cnt);
		
	}

}
