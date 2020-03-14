package hw.ad;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class 게리멘더링 {
	
	static int[] population = new int[11];
	static HashSet<Integer> adjoin = new HashSet<Integer>();
	static ArrayList<Integer>[] locals = new ArrayList[11];
	static int N;
	static int minVal = 9999999;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N; i++)
		{
			population[i] = Integer.parseInt(st.nextToken());
		}
		
		int nums;
		for(int i = 0; i < N; i++)
		{
			st = new StringTokenizer(br.readLine());
			nums = Integer.parseInt(st.nextToken());
			locals[i] = new ArrayList<>();
			for(int n = 0; n < nums; n++)
			{
				locals[i].add(Integer.parseInt(st.nextToken())-1);
			}
		}
		
		combination();
		
		if(minVal == 9999999)
			System.out.println(-1);
		else
			System.out.println(minVal);
	}
	
	static void combination()
	{
		for(int i = 1; i+1 < (1<<N); i++ ) 	// 조건식에 i+1이 들어간 이유는 전부다 1로 채워지는 경우를 방지하는 것이다.
		{									// 전부다 1이 된 경우에는 결국 하나의 구를 만들게 되기때문에 제외한다.
			calcu(i);
		}
	}
	
	static void calcu(int bitLine)
	{
		HashSet<Integer> local_1, local_2;
		local_1 = new HashSet<Integer>();
		local_2 = new HashSet<Integer>();
		int local_1_sum, local_2_sum;
		local_1_sum = local_2_sum = 0;
		
		int maskLine;
		for(int i = 0; i < N; i++)
		{
			maskLine = (1<<i); // 오른쪽 idx부터 왼쪽으로 1을 옮기며 해당 지점에 값이 있는지 확인
			if((bitLine & maskLine) != 0)
			{
				local_1.add(i); // 1인 해당 지역 추가
				local_1_sum += population[i];
			}
			else
			{
				local_2.add(i); // 0인 해당 지역 추가
				local_2_sum += population[i];
			}
		}
		
		
		// 0 구역 인접확인
		adjoin.clear();
		Iterator<Integer> it = local_1.iterator();
		int start = it.next().intValue();
		adjoin.add(start);
		dfs(start, local_1);
		
		Iterator<Integer> it_local = local_1.iterator();
		Iterator<Integer> it_adjoin = adjoin.iterator();

		if(local_1.size() != adjoin.size()) return; // 인접지역의 개수가 다른 경우 바로 return;
		
		while(it_local.hasNext() && it_adjoin.hasNext()) // 같다면 hashSet의 성질(동일값을 제외하고 정렬해주는)을 활용해 동일값비교
		{
			if(it_local.next() != it_adjoin.next()) return;
		}

		// 1 구역 인접확인
		adjoin.clear();
		it = local_2.iterator();
		start = it.next().intValue();
		adjoin.add(start);
		dfs(start, local_2);
		
		it_local = local_2.iterator();
		it_adjoin = adjoin.iterator();

		if(local_2.size() != adjoin.size()) return; // 인접지역의 개수가 다른 경우 바로 return;
		
		while(it_local.hasNext() && it_adjoin.hasNext()) // 같다면 hashSet의 성질(동일값을 제외하고 정렬해주는)을 활용해 동일값비교
		{
			if(it_local.next() != it_adjoin.next()) return;
		}
		
		minVal = Math.min(minVal, Math.abs(local_1_sum-local_2_sum));
	}
	
	static void dfs(int startLocal, HashSet<Integer> local)
	{
		for (int i : locals[startLocal]) // 오토 언박싱일듯? 		// -> startLocal에 인접하는 지역 중 아래와 같은 조건(인접)이 만족하면 그 지역을 기준으로 재 탐색
		{													// 이 찾고자하는 지역이, arrayList를 통해 인접한 지역으로 확인된 곳이므로
			if(!adjoin.contains(i) && local.contains(i)) 	// 인접확인지역에 '없고' && 검사하려는 local1 or 2 지역에 있다면,
			{
				adjoin.add(i);	
				dfs(i, local);
			}
		}
	}

}
















