#include<stdio.h>
#include<math.h>
int main()
{
    int m,i;
    double n,x;
    while(scanf("%lf%d",&n,&m)!=EOF)
    {
        x=n;
        for(i=1;i<m;i++)//循环次数要注意
        {
            n=sqrt(n);
            x+=n;
        }
        printf( "%.2lf",x);
    }
}
