#include<stdio.h>
int main()
{
    int n,b,c,d;
    double a;
    while(scanf("%d",&n),n!=0)
    {   b=0;
        c=0;
        d=0;
        while(n--)
        {
            scanf("%lf",&a);
            if(a==0)
            {
                b++;
            }
            else if(a<0)
            {
                c++;
            }
            else if(a>0)
            {
                d++;
            }
        }
        printf("%d %d %d\n",c,b,d);
    }
}
