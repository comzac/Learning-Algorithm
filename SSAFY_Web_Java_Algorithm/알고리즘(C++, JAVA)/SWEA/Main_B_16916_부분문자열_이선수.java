package com.corona;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main_B_16916_부분문자열_이선수 {
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String T = br.readLine();
		String P = br.readLine();
		
		ArrayList<Integer> answer = kmp(T, P);
		
		System.out.println(answer.size());
		for (Integer integer : answer) {
			System.out.print(integer + " ");
		}
		
	}
	
	public static int[] getPi(String str) {
		
		int[] pi = new int[str.length()];
		int i = 0;
		for (int j = 1; j < str.length(); j++)
		{
			while (i > 0 && str.charAt(i) != str.charAt(j))
				i = pi[i - 1];
			if (str.charAt(i) == str.charAt(j))
				pi[j] = ++i;
		}
		return pi;
	}
	
	public static ArrayList<Integer> kmp(String t, String p)
	{
		ArrayList<Integer> answer = new ArrayList<Integer>();
		int[] pi = getPi(p);

		int i = 0;
		for (int j = 0; j < t.length(); j++)
		{
			while (i > 0 && t.charAt(j) != p.charAt(i))
				i = pi[i - 1];
			if (t.charAt(j) == p.charAt(i))
			{
				if (i == p.length() - 1) // 완벽일치하면,
				{
					answer.add(j - p.length() + 1 + 1);
					i = pi[i];
				}
				else
				{
					i++;
				}
			}

		}

		return answer;
	}
}
