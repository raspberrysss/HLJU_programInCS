#include<stdio.h>
int main()
{
int x,y,a,n,t,i,j;
while(scanf("%d%d",&x,&y)!=EOF)
{
    if(x==0&&y==0)
    {
        continue;
    }
    if(x>y)
    {
        a=x;
        x=y;
        y=a;
    }
    t=0;
	for(i=x;i<=y;i++)
	{
		n=i*i+i+41;
		for(j=2;j<=n/2;j++)
		 {
		      if(n%j==0)
                t++;
		 }

	}
	if(t==1)
	printf("Sorry\n");
	else
	printf("OK\n");
}
return 0;
}
