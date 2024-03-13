#include<stdio.h>
int main()
{
    int a,b,c,d;
    double e;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        e=a*0.2+b*0.1+c*0.2+d*0.5;
        printf("%.1lf\n",e);
    }
    return 0;
}
