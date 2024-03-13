#include<stdio.h>
int main()
{
    int a[40];
    int n,i;
    while(scanf("%d",&n)!=EOF)//怎么用循环做呢？
    {
        a[1]=0;
        a[2]=1;
        for(i=3;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        for(i=1;i<=n;i++)
        {
            if(i==1)
            {
                printf("%d",a[i]);
            }
            else
            {
                printf(" %d",a[i]);
            }
        }

    }
}
