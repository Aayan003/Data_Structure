#include <stdio.h>

void han(int lim, char ch_1, char ch_2, char ch_3)
{
	if(lim == 0)
	{
		//printf("%d num disk has been moved from %c to %c\n", lim, ch_1, ch_3);
		return;
	}
	han(lim - 1, ch_1, ch_3, ch_2);
	printf("%d num disk has been from %c to %c\n", lim, ch_1, ch_3);
	han(lim - 1, ch_2, ch_1, ch_3);
}
int main()
{
	int lim;
	//char ch_1 = 'S', ch_2 = 'A', ch_3 = 'D';
	printf("Enter how many disks you want-\n");
	scanf("%d", &lim);
	han(lim, 'S', 'A', 'D');
	return 0;
}
