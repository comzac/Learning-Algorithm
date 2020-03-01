//#include <stdio.h>
//#include "arrayList.h"
//
//
//
//int main()
//{
//	//선언
//	List list;
//	int data;
//	ListInit(&list);
//
//	//저장
//	ListInsert(&list, 10);
//	ListInsert(&list, 10);
//	ListInsert(&list, 20);
//	ListInsert(&list, 20);
//	ListInsert(&list, 30);
//
//	//데이터수
//	printf("현재 데이터 수 : %d \n", ListCount(&list));
//
//
//	//조회
//	if (ListFirst(&list, &data))
//	{
//		printf("%d \n", data);
//
//		while (ListNext(&list, &data))
//		{
//			printf("%d \n", data);
//		}
//
//		printf("\n\n");
//	}
//
//	//삭제
//
//	if (ListFirst(&list, &data))
//	{
//		if (data == 20)
//		{
//			ListRemove(&list);
//		}
//		while (ListNext(&list, &data))
//		{
//			if (data == 20)
//			{
//				ListRemove(&list);
//			}
//		}
//	}
//
//
//	//데이터수
//	printf("현재 데이터 수 : %d \n", ListCount(&list));
//
//
//	//삭제 후 재조회
//	if (ListFirst(&list, &data))
//	{
//		printf("%d \n", data);
//
//		while (ListNext(&list, &data))
//		{
//			printf("%d \n", data);
//		}
//
//		printf("\n\n");
//	}
//
//
//
//
//	return 0;
//}