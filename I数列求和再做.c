#include<stdio.h>
#include<math.h>
int main()
{
    int m;
    double sum;
    double n;
    while(scanf("%lf%d",&n,&m)!=EOF)
    {
        sum=0.0;
        for(int i=0;i<m;i++)
        {
            sum=sum+n;
            n=sqrt(n);
        }
        printf("%.2f\n",sum);
    }
}
