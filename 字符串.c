#include<stdio.h>
#include<string.h>

int main()
{
	int n,i,j,d,m;
	char a[100];
	while (scanf("%d",&n)!=EOF)
	{
		getchar();
        while(n--)
        {
            gets(a);
            m=strlen(a);
		for (j=0,i=0;i<m;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			j++;
		}
		printf("%d\n",j);
		}

	}return 0;
}
