#include<stdio.h>
int main()
{
    int a[100];
    int n,m,d,i;
    while(scanf("%d%d",&n,&m),n!=0,m!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(m>a[i])
        {
            m=i;
        }
        d=a[i];
            a[i]=m;
             m=d;

        printf("%d",a[i]);
    }
}
