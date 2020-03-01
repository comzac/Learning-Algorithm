#include <stdio.h>
#include "CLinkedList.h"

int main()
{
	List list;
	int data;
	ListInit(&list);


	ListInsert(&list, 10);
	ListInsert(&list, 10);
	ListInsert(&list, 20);
	ListInsert(&list, 20);
	ListInsert(&list, 30);

	printf("%d \n\n", ListCount(&list));

	if (ListFirst(&list, &data))
	{
		printf("%d \n\n", data);

		while (ListNext(&list, &data))
		{
			printf("%d \n\n", data);
		}

	}

	printf("\n\n");

	if (ListFirst(&list, &data))
	{
		if (data == 20)
		{
			ListRemove(&list);
		}
		while (ListNext(&list, &data))
		{
			if (data == 20)
			{
				ListRemove(&list);
			}
		}

	}

	printf("%d \n\n", ListCount(&list));

	if (ListFirst(&list, &data))
	{
		printf("%d \n\n", data);

		while (ListNext(&list, &data))
		{
			printf("%d \n\n", data);
		}

	}






	return 0;
}