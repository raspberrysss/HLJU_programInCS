#include<stdio.h>
long fei(int n )
{
    long t=1;
    for(int j=1;j<=n;j++)
    {
        t=t*j;
    }
    return t;

}
long  di(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n>1)
    {
        return n*di(n-1);
    }
}
int main()
{
    int i;
    long a,b;
    i=0;
    while(i<=10)
    {
        a=fei(i);
        b=di(i);
        printf("%ld ",a);
        printf("%ld ",b);
        i++;
    }
}
