#include<stdio.h>
int main()
{
    int n,a[100],d,i;
    int min;
    while(scanf("%d",&n),n!=0)
    {
        min=100;
        for(i=0;i<n;i++)
        {
            scanf("%d",a[i]);
        }
        for(i=1;i<n;i++)
        {
            if(a[i]<min)
          {
            d=a[i];
            a[i]=min;
            min=d;
          }
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
