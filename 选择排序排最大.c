#include<stdio.h>
int main()
{
    int a[100];//”–Œ Ã‚
    int n,j,i,t;
    int max;
    while(scanf("%d",&n)!=EOF)
    {
        max=n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[max])
            {
                max=j;
            }
            t=a[i];
            a[i]=a[max];
            a[max]=t;
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
    }
}
