#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double p,s,w;
    scanf("%lf%lf%lf",&a,&b,&c);
    p=(a+b+c)/2;
    w=p*(p-a)*(p-b)*(p-c);
    s=sqrt(w);
    printf("%lf",s);

}
