#include<stdio.h>
int f(int a)
{
    if(a<=0)
    {
        return 2*a;
    }
    if(a>0&&a<=117)
    {
        return 3*a+1;
    }
    if(a>117)
    {
        return a*a;
    }
}
int main()
{
    int a,b,c,d,e;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=f(a);
        d=f(b);
        e=c-d;
        printf("%d\n",e);
    }
}
