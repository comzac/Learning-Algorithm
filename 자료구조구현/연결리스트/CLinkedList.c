#include "CLinkedList.h"

void ListInit(List * _list)
{
	_list->numOfData = 0;
	_list->tail = NULL;
	_list->cur = NULL;
	_list->before = NULL;

	//왜? 원형에서는 cur과 before에 null초기화를 해줄까?

}

void ListInsert(List * _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;


	if (_list->tail == NULL)
	{
		_list->tail = newNode;
		newNode->next = _list->tail;
	}
	else//                    tail
	{	// [ 1 ] -- [ 3 ] -- [ 4 ]

		newNode->next = _list->tail->next;
		_list->tail->next = newNode;
		_list->tail = newNode;


	}
}


void ListInsertFront(List * _list, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (_list->tail == NULL)
	{
		_list->tail = newNode;
		newNode->next = _list->tail;
	}
	else
	{
		newNode->next = _list->tail->next;
		_list->tail->next = newNode;
	}
}

int ListFirst(List * _list, LData * data)
{
	if (_list->tail == NULL)
		return FALSE;
	
	// *data = _list->tail->next->data; 이렇게 작성했을때, next와의 연계가 어렵다. 때문에,
	_list->before = _list->tail;
	_list->cur = _list->tail->next;
	*data = _list->cur->data;

	return TRUE;

}

int ListNext(List * _list, LData * data)
{
	//if (_list->cur->next == NULL) // ?
	if (_list->tail == NULL) // 아마 이렇게 설정하는 이유가 삭제에서 조회하는 과정에서 남은 노드가 없는 경우를 색출하기 위해서 인듯하다? 물론 위의 방식도 틀리지 않은듯하다!
		return FALSE;

	_list->before = _list->cur;
	_list->cur = _list->cur->next;
	*data = _list->cur->data;
	return TRUE;
}

LData ListRemove(List * _list)
{
	Node* rPos = _list->cur;
	LData rData = rPos->data;

	if (rPos == _list->tail)
	{
		if (_list->tail == _list->tail->next)
			_list->tail = NULL;
		else
			_list->tail = _list->before;


	}

	_list->before->next = _list->cur->next;
	// _list->cur->next = NULL; 또 cur을 하나의 노드라고 생각함. 이것을 노드를 가리키고 있는 개념! 때문에 삭제와 함께 cur은 뒤로 한칸 이동해야한다. 따라서,
	_list->cur = _list->before;

	free(rPos);
	_list->numOfData--;
	return rData;
}

int ListCount(List * _list)
{
	return _list->numOfData;
}
