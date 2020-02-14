/*
 *  path 압축만 하는 경우에 하위 노드를 호출하지 않고 계속적으로 루트노트와 다른 집합과의 비교를
 *  진행한 뒤, rank 비교없이 이어붙히고 마지막에 가장 하위 노드를 호출한다면, find_set과정에서
 *  엄청난 stack호출이 발생한다.
 *  그렇기 때문에, rank 관리와 동시에 최적의 union을 시키며, 추후 발생하는 하위 노드 호출에 따라
 *  path compression을 진행해야 메모리 관리까지 할 수 있다.
 */
package com.ssafy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_J_1863_종교_이선수 {
	
	static int[] arr;
	static int N;
	static int M;
	
	static void make_set() {
		Arrays.fill(arr, -1);
	}
	
	static int find_set(int idx)
	{
		if(arr[idx] < 0)
		{
			return idx;
		}	
		return arr[idx] = find_set(arr[idx]);
	}
	
	static void union_set(int a, int b)
	{
		int rootA;
		int rootB;
		rootA = find_set(a);
		rootB = find_set(b);
		
		if(rootA != rootB)
		{
			if(arr[rootA] < arr[rootB])
			{
				arr[rootA] += arr[rootB];
				arr[rootB] = rootA;
				
			}
			else
			{
				arr[rootB] += arr[rootA];
				arr[rootA] = rootB;		
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N+1];
		make_set();
		int stud1;
		int stud2;
		for(int i = 0 ; i < M; i++)
		{
			st = new StringTokenizer(br.readLine());
			stud1 = Integer.parseInt(st.nextToken());
			stud2 = Integer.parseInt(st.nextToken());
			
			union_set(stud1, stud2);
			//find_set(stud1);
		}
		
		int cnt = 0;
		for(int i = 1; i <= N; i++)
		{
			if(arr[i] < 0)
				cnt++;
		}
		
		System.out.println(cnt);
		
	}
}
