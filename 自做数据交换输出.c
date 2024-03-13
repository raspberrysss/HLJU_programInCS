#include<stdio.h>
int main()
{
    int n,m,d;
    int min=100;
    int a[100];
    while(scanf("%d",&n),n!=0);
    {
        for(int i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<min)
        {
            min=a[i];
        }
        d=a[0];
        a[0]=a[i];
        a[i]=d;

    }
    for(int i=0;i<=n;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",a[i]);
    }
    }
}
