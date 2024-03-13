#include<stdio.h>
int main()
{
    int n,a[100],min,d;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        min=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[min])
               {
                   min=i;
               }
        }
        d=a[min];
        a[min]=a[0];
        a[0]=d;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
