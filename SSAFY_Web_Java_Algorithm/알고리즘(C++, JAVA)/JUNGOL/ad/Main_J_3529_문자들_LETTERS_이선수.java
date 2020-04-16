//13 ad
package hw.ad;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_J_3529_문자들_LETTERS_이선수 {

	static String[][] map;
	static boolean[][] v;
	static int r;
	static int c;
	static int max;
	static int[][] dir = new int[][] {{0,1},{0,-1},{1,0},{-1,0}};
	
	static void search(ArrayList<String> arr, int y, int x, int cnt)
	{
		ArrayList<String> newArr = new ArrayList<String>();
		newArr.addAll(arr);
		int Cnt = cnt;
		
		if(y < 0 | y >= r | x < 0 | x >= c)
			return;
		if(v[y][x])
			return;
		
		for(int i = 0 ; i < arr.size(); i++)
		{
			if(newArr.get(i).equals(map[y][x]))
			{	
				return;
			}
		}
		
		v[y][x] = true;	
		newArr.add(map[y][x]);
		Cnt++;
		if(max < Cnt)
			max = Cnt;
		
		for(int i = 0 ; i < 4; i ++)
		{
			int nextY = y+dir[i][0];
			int nextX = x+dir[i][1];
			if(nextY < 0 | nextY >= r | nextX < 0 | nextX >=c)
				continue;
			search(newArr, nextY, nextX, Cnt);
			v[nextY][nextX] = false;
		}


	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		map = new String[r][c];
		v = new boolean[r][c];
		ArrayList<String> arr = new ArrayList<String>();
		
		for(int i = 0 ; i < r; i++)
		{
			String s = br.readLine();
			for(int j = 0 ; j <c; j++)
			{
				map[i][j] = String.valueOf(s.charAt(j));
			}
		}
		
		search(arr, 0,0,0);
		System.out.println(max);

	}

}
