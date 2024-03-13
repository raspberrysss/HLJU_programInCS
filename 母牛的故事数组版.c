#include<stdio.h>
int main()
{
    int a[55];
    a[0]=0;
    int n;
    for(int i=1;i<55;i++)
    {
        if(i<5)
        {
            a[i]=i;
        }
        else
        {
            a[i]=a[i-1]+a[i-3];
        }

    }
    while(scanf("%d",n),n!=0)
    {
        if(n>0&&n<55)
        {
            printf("%d",a[n]);
        }
        else
        return 0;

    }
    return 0;

 }
