#include<stdio.h>
int main()
{
	int a[55] = { 1,2,3,4 };
	int i,n,j;
	for (j = 0;; j++)
	{
		while(scanf("%d", &n),n!=0)
{


		for (i = 4; i < 54; i++)
		{
			a[i] = a[i - 1] + a[i - 3];
		}
		printf("%d\n", a[n-1]);
}

	}
    return 0;
}
