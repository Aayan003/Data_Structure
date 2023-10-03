#include <stdio.h>
int fibo(int lim, int n_1, int n_2)
{
	if(lim == 1)
	{
		return n_2;
	}
	else if(lim == 0)
	{
		return 0;
	}
	else
	{
		fibo(lim -1, n_2, n_1 + n_2);
	}
}
int main()
{
	int lim;
	printf("How many numbers you want to get from fibbonachi serise\n");
	scanf("%d", &lim);
	for(int i = 0; i < lim; i++)
	{
		printf("%d, ", fibo(i, 0, 1));
	}
	return 0;
}
