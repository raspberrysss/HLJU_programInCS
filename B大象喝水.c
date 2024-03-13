#include<stdio.h>
#define PI 3.14159
int main()
{
    int h,r,b;
    double a;
    while(scanf("%d%d",&h,&r)!=EOF)
    {
        a=PI*r*r*h;
        b=20000/a;
        if(20000-a!=0)
        {
            b++;
        }
        printf("%d\n",b);
    }
}
