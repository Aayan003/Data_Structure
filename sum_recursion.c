#include <stdio.h>
long long int sum(long long int val, int lim)
{
	if(lim == 0 || lim == 1)
	{
		return val;
	}
	else
	{
		return sum(lim + lim - 1 + val, lim - 2);
	}
}
int main()
{
	int lim;
	printf("How many numbers you want to sum from serise of N: ");
	scanf("%d", &lim);
	printf("%lld\n", sum(0, lim));
	return 0;
}
