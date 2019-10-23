#include <stdio.h>

//이진탐색
int BSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) // 최악의 경우 범위가 1인 경우까지 좁혀질텐데 그때에도 없다면 first = mid+1; 과정으로  
	{					  // while문의 조건을 벗어나게 된다. 때문에 '<='를 사용해야한다.
		mid = (first + last) / 2;

		if (target == arr[mid])
		{
			return mid;
		}
		else
		{
			if (arr[mid] > target)
			{
				last = mid - 1;
			}
			else
				first = mid + 1;
			/*
				mid가 target과 같지 않은 경우 last = mid, first = mid로 했을 경우, 한 개의 데이터를 더 검사할뿐 ? 이 아니다.
				first와 last에 가감이 없는 경우 결코 while에서 벗어날 수 없게 된다(first가 last보다 커질 수 없다.)
			
			*/
		}


	}

	return -1;
	
}


int main()
{

	int arr[] = { 1,4,7,9,12,19,23,28,33,60 };
	int idx;
	idx = BSearch(arr, sizeof(arr) / sizeof(int), 8);

	printf("%d", idx);

	return 0;

}