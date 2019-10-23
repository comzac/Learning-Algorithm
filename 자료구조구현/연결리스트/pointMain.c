//#include <stdint.h>
//#include <stdlib.h>
////#include "arrayList.h"
//#include "linkedList.h"
//#include "point.h"
//
//int main()
//{
//	List list;
//	Point* point;
//	Point compPoint;
//
//	ListInit(&list);
//
//	point = (Point*)malloc(sizeof(Point));
//	setPosition(point, 1, 2);
//	ListInsert(&list, point);
//
//	point = (Point*)malloc(sizeof(Point));
//	setPosition(point, 1, 9);
//	ListInsert(&list, point);
//
//	point = (Point*)malloc(sizeof(Point));
//	setPosition(point, 2, 3);
//	ListInsert(&list, point);
//
//
//	point = (Point*)malloc(sizeof(Point));
//	setPosition(point, 4, 1);
//	ListInsert(&list, point);
//
//	
//	printf("%d\n\n", ListCount(&list));
//
//	if (ListFirst(&list, &point))
//	{
//		showPosInfo(point);
//
//		while(ListNext(&list, &point))
//			showPosInfo(point);
//	}
//
//	compPoint.xpos = 1;
//	compPoint.ypos = 3;
//
//	if (ListFirst(&list, &point))
//	{
//		if (compPosition(point, &compPoint) == 1)
//		{
//			point = ListRemove(&list);
//			free(point);
//		}
//
//		while (ListNext(&list, &point))
//		{
//			if (compPosition(point, &compPoint) == 1)
//			{
//				point = ListRemove(&list);
//				free(point);
//			}
//		}
//	}
//
//	printf("\n\n\n");
//	printf("%d\n\n", ListCount(&list));
//
//
//	if (ListFirst(&list, &point))
//	{
//		showPosInfo(point);
//
//		while (ListNext(&list, &point))
//			showPosInfo(point);
//	}
//
//
//
//	
//	
//	return 0;
//
//}