#include<stdio.h>
int main()
{
    int n,min,i,j,a[100],d,j;
    while(scanf("%d",&n),n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",a[i]);
        }
        min=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]<min)
            {
                j=i;

            }
            a[j]=a

        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d\n",a[i]);
        }

    }
}
