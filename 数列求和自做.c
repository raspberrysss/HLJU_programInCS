#include<stdio.h>
#include<math.h>
int main()
{
    int m;
    double n;
    while(scanf("%lf%d",&n,&m)!=EOF)
    {   double h=0.0;
        for(int i=0;i<m;i++)
        {
           h=h+n;
           n=sqrt(n);
        }
        printf("%.2lf\n",h);
    }
}
