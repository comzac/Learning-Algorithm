package com.corona;

/*
 * 
만약 가능한 방법이 여러 가지일 경우, 햄스터 수가 가장 많은 것을 출력한다.

그래도 가능한 방법이 여러 가지일 경우, 사전순으로 가장 빠른 것을 출력한다.

만약 모든 기록을 만족하는 햄스터 배치가 없다면, -1을 출력하도록 한다.

범위상 때려박기 해보기 ㄱ

 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution_D4_8275_햄스터_이선수 {

	static class line {
		int from;
		int to;
		int num;

		public line(int from, int to, int num) {
			super();
			this.from = from;
			this.to = to;
			this.num = num;
		}

	}

	static int N;
	static int X;
	static int M;
	static ArrayList<int[]> al = new ArrayList<>();
	static ArrayList<Integer> nonInfoNum = new ArrayList<Integer>();
	static line[] lines = new line[11];
	static int[] room = new int[7];
	static boolean[] nonInfo = new boolean[7];

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());

			init();
			
			int from, to, num;
			for (int m = 0; m < M; m++) {
				st = new StringTokenizer(br.readLine());
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				num = Integer.parseInt(st.nextToken());

				lines[m] = new line(from, to, num);

				for (int i = from; i <= to; i++) {
					if (nonInfo[i])
						continue;
					nonInfo[i] = true;
				}

			}

			for (int i = 1; i <= N; i++) {
				if (!nonInfo[i])
					nonInfoNum.add(i);
			}

			combi(0, 0);

			if (al.size() == 0) {
				System.out.println("#" + t + " " + -1);
			} else {

				Collections.sort(al, new Comparator<int[]>() {

					@Override
					public int compare(int[] o1, int[] o2) {
						int sum1 = 0;
						int sum2 = 0;
						for (int i = 1; i <= N; i++) {
							sum1 += o1[i];
							sum2 += o2[i];
						}

						if (sum1 == sum2) {
							int idx = 1;
							while(idx != N+1)
							{
								if(o1[idx] == o2[idx])
									idx++;
								else
									return o1[idx]-o2[idx];
							}
							return o1[1]-o2[1];
						} else {
							return Integer.compare(sum2, sum1);
						}
					}
				});

				System.out.print("#" + t + " ");
				for (int s = 1; s <= N; s++)
					System.out.print(al.get(0)[s] + " ");
				System.out.println();

			}

			al.clear();
			nonInfoNum.clear();
		}
	}

	static void init()
	{
		for(int i = 0 ; i < 7; i++)
		{
			room[i] = 0;
			nonInfo[i] = false;
		}

	}
	static void combi(int nums, int roomNum) {

		if (roomNum == N) {
			room[roomNum] = nums;
			if (infoCheck()) {
				for (int i = 0; i < nonInfoNum.size(); i++)
					room[nonInfoNum.get(i)] = X;

				int[] copy = new int[N + 1];
				copy = Arrays.copyOf(room, N + 1);
				al.add(copy);
			}
			return;
		}

		room[roomNum] = nums;

		for (int i = X; i >= 0; i--) {
			combi(i, roomNum + 1);
		}
	}

	static boolean infoCheck() {
		int from, to, num;
		int sum;
		for (int i = 0; i < M; i++) {
			sum = 0;
			from = lines[i].from;
			to = lines[i].to;
			num = lines[i].num;

			for (int j = from; j <= to; j++) {
				sum += room[j];
			}

			if (sum != num)
				return false;
		}
		return true;
	}

}

