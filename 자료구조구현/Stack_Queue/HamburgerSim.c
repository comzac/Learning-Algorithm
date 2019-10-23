#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

#define ORDERTIME 15

#define CHEBUR 0
#define BULBUR 1
#define DUBBUR 2

#define CHEBURT 12
#define BULBURT 15
#define DUBBURT 24


int main()
{
	int makeProc = 0;
	int cheorder = 0, bulorder = 0, duborder = 0;
	int sec;

	Queue que;
	QueInit(&que);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++)
	{
		if (sec % (ORDERTIME) == 0)
		{
			switch (rand()%3)
			{

			case CHEBUR:
				Enqueue(&que, CHEBURT);
				cheorder++;

				break;
			case BULBUR:
				Enqueue(&que, BULBURT);
				bulorder++;
				break;
			case DUBBUR:
				Enqueue(&que, DUBBURT);
				duborder++;
				break;


			default:
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&que))
		{
			makeProc = DeQueue(&que);
		}

		makeProc--;

	}

	printf("%d \n", cheorder);
	printf("%d \n", bulorder);
	printf("%d \n", duborder);
	printf("%d \n", QUEUELEN);



	return 0;
}