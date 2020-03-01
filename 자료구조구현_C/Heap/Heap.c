#include "Heap.h"

void HeapInit(heap * h, priorityFunction pc)
{
	h->comp = pc;
	h->numOfData = 0;
}

int HIsEmpty(heap * h)
{
	if (h->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}
int GetLChildIDX(int idx)
{
	return idx * 2;
}
int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// 두번째 - 첫번째 > 0 이면, 첫번째가 더 작으므로 우선순위가 더 높다. 때문에 위쪽에 위치한다.
int GetHiPrichildIdx(heap* h, int idx)
{
	if (h->numOfData < GetLChildIDX(idx))
		return 0;
	else if (h->numOfData == GetLChildIDX(idx))
		return GetLChildIDX(idx);
	else
	{
		if (h->comp(h->heapArr[GetLChildIDX(idx)], h->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}


void HeapInsert(heap * h, Data data)
{
	int idx;
	idx = h->numOfData + 1;

	while (idx != 1)
	{
		if(h->comp(data, h->heapArr[GetParentIDX(idx)]) <= 0)
			break;
		else
		{
			h->heapArr[idx] = h->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
	}
	h->heapArr[idx] = data;
	h->numOfData++;
}

Data HeapDelete(heap * h)
{
	Data rData = h->heapArr[1];
	Data lastData = h->heapArr[h->numOfData];
	
	int parentIdx, childIdx;
	parentIdx = 1;

	while (childIdx = GetHiPrichildIdx(h, parentIdx))
	{
		if (h->comp(lastData, h->heapArr[childIdx]) >= 0)
		{
			break;
		}

		h->heapArr[parentIdx] = h->heapArr[childIdx];
		parentIdx = childIdx;
	}
	
	h->heapArr[parentIdx] = lastData;
	h->numOfData--;

	return rData;
}
