//#pragma once
//#ifndef __ARRAY_LIST_H__ //ifdef = if define -> 만약 정의가 됐었다면~ 이런 느낌으로 정의가 된 경우 재정의를 막기 위한 장치
//#define __ARRAY_LIST_H__ //ifndef는 not의 의미로 되지 않았다면~ 의 의미인데 ifdef의 경우의 번거로움을 줄여준다.
//						 //예를 들어 여러 c파일에 같은 헤더파일이 참조되어 있는 경우 여러번 참조할 수 있기때문이다.
//						 //ifdef의 경우, 정의가 되어있다면 ifdef와 else 사이 구간의 내용을 컴파일하고 
//						 //정의가 되어있지 않은 경우, else와 endif 사이 구간의 내용을 컴파일한다.
//						 //따라서 ifndef(반대의미)를 사용할 경우, 정의되지 않은 경우에는 endif 전까지 내용을 컴파일하고
//						 //정의된 경우, else이후를 컴파일하나 정의된 경우 컴파일의 필요가 없기때문에 생략가능하다.
//
//#include "point.h"
////필요 함수
////1. 초기화 - void ListInit(List* _list) : 리스트의 주소값을 받아 초기화를 진행한다.
////2. 데이터 추가 - void ListInsert(List* _list, LData data) : data를 받아 list에 저장한다.
////3. 데이터 참조 - int ListFirst(List* _list, LData* pdata) : list의 첫 데이터가 pdata에 저장된다.
////3-1. 데이터 참조 - int ListNext(List* _list, LData* pdata) : list의 첫 데이터 이후의 값들이 저장된다. 
////3)의 경우 참조 유무를 확인할 수 있으며, 반복호출이 가능하고 반복적인 재참조를 원할 경우, 항상 ListFirst가 선행되어야 한다.
////4. 데이터 삭제 - LData ListRemove(List* _list, LData* pdata) : 
////5. 데이터 총 정보
//
////일단 T/F 검사를 하기 위해 c++의 경우 Bool변수를 사용하면 되지만 여기는 c이기 때문에
//#define TRUE 1
//#define FALSE 0
//
////배열로 만드는 리스트이기 때문에 크기를 설정해주고
//#define LIST_LEN 100
////임시로 int자료형을 리스트의 데이터 형태로 설정한다(typedef를 굳이 사용한 이유는 추후에 다른 자료형을 다룰때 한 부분만 수정하는 편의
//typedef Point* LData; // 추가변경사항★
//
//typedef struct __ArrayList		//28~36 typedef의 쓰임을 잘 모르겠음
//{
//	LData arr[LIST_LEN];
//	int curPosition;
//	int numOfData;
//
//}ArrayList;
//
//typedef ArrayList List;
//
////초기화
//void ListInit(List* plist);
////저장
//void ListInsert(List* plist, LData data);
//
////조회
//int ListFirst(List* plist, LData* pdata);
//int ListNext(List* plist, LData* pdata);
//
////삭제
//LData ListRemove(List* plist);
////데이터수 조회
//int ListCount(List* plist);
//
//#endif // !__ARRAY_LIST_H__
//
