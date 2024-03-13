#include<stdio.h>
double feipower(float x,int n)
{
    int sum=1;
    for(int i=1;i<=n;i++)//µÝ¹éÒªÓÃÁ¬³Ë
    {
        sum=x*sum;
    }
    return sum;
}
double power(float e,int f)
{
    if(f==0)
    {
        return 1;
    }
    else if(f>0)
    {
        return e*power(e,f-1);
    }
}
int main()
{
    int n;
    float x;
    double a,b;
    scanf("%f%d",&x,&n);
    a=feipower(x,n);
    printf("%lf ",a);
    b=power(x,n);
    printf("%lf ",b);


}
