#include <stdio.h>

void hanoiTower(int n, char from, char by, char to)
{
	if (n == 1)
	{
		printf("%d번째 원반을 %c에서 %c로 옮기세요\n", n, from, to);
	}
	else
	{
		hanoiTower(n - 1, from, to, by);
		printf("%d번째 원반을 %c에서 %c로 옮기세요\n", n, from, to);
		hanoiTower(n - 1, by, from, to);
	}
}


int main()
{
	hanoiTower(4, 'A', 'B', 'C'	);

	return 0;
}