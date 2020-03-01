//#include <stdio.h>
//
//
//int RBSearch(int arr[], int first, int last, int target) //재귀로 선언함에 따라 기준이 되어줄 first와 last를 각각 변수로 설정해줘야한다.
//{
//
//	int mid = (first + last) / 2;
//
//	if (first > last)
//		return -1;
//
//	if (arr[mid] == target)
//	{
//		return mid;
//	}
//	else if (arr[mid] > target)
//	{
//		RBSearch(arr, 0, mid - 1, target);
//	}
//	else
//		RBSearch(arr, mid+1, last, target);
//}
//
//
//
//int main()
//{
//	int arr[] = { 1,3,5,7,9,11,15,19,24 };
//	int idx = RBSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 14);
//	printf("%d", idx);
//
//	return 0;
//}