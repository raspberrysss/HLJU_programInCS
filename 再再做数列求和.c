#include<stdio.h>
#include<math.h>
int main()
{
    int m;
    double n,sum,x;
    while(scanf("%lf%d",&n,&m)!=EOF)
    {
        sum=0;
        while(m--)
        {
            x=sqrt(n);
            sum=sum+x;
        }
        printf("%.2lf",sum);
    }
}
