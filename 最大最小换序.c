#include<stdio.h>
int main()
{
    int n,t,d,i;
    int min_xb,max_xb;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        min_xb=0;
        max_xb=0;
        for(i=1;i<n;i++)
        {
            if(a[i]<a[min_xb])
            {
                min_xb=i;
            }
            d=a[i];
            a[i]=a[min_xb];
            a[min_xb]=d;
        }
        for(i=1;i<n;i++)
        {
            if(a[i]>a[max_xb])
            {
                max_xb=i;
            }
            t=a[i];
            a[i]=a[max_xb];
            a[max_xb]=t;
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",a[i]);
        }
    }
}
