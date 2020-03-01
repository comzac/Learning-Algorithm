//#include <stdio.h>
//#include "arrayList.h"
//
//void ListInit(List * plist)
//{
//	plist->curPosition = -1;
//	plist->numOfData = 0;	
//}
//
//void ListInsert(List * plist, LData data)
//{
//	plist->arr[plist->numOfData] = data;
//	plist->numOfData++;
//
//}
//
//int ListFirst(List * plist, LData * pdata)
//{
//	if (plist->numOfData == 0)
//		return FALSE;
//
//	plist->curPosition = 0;
//	*pdata = plist->arr[plist->curPosition];
//	return TRUE;
//
//}
//
//int ListNext(List * plist, LData * pdata)
//{
//
//	if (plist->curPosition >= plist->numOfData - 1)
//		return FALSE;
//
//	plist->curPosition++;
//	*pdata = plist->arr[plist->curPosition];
//
//	return TRUE;
//
//}
//
//LData ListRemove(List * plist)
//{
//	int rPos = plist->curPosition;
//	int num = plist->numOfData;
//	int i;
//	LData rData = plist->arr[rPos];
//
//	for (i = rPos; i < num -1; i++)
//	{
//		plist->arr[i] = plist->arr[i + 1];
//	}
//
//	(plist->numOfData)--;
//	(plist->curPosition)--;
//
//	return rData;
//}
//
//int ListCount(List * plist)
//{
//
//	return plist->numOfData;
//}
