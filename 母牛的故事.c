#include<stdio.h>
int main()
{
    int a[56];
    int n;
        a[0]=0;
        a[1]=1;
        a[2]=2;
        a[3]=3;
        while(scanf("%d",&n),n!=0)
        {
            for(int i=4;i<=55;i++)
            {
                a[i]=a[i-1]+a[i-3];
            }
            printf("%d\n",a[n]);

        }
    }

