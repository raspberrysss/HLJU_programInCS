#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
       double a;
       int b,c,e;
       b=0;
       c=0;
       e=0;
        while(n--)
        {
            scanf("%lf",&a);
            if(a==0)
            {
                b++;
            }
            else
            {
                if(a>0)
                {
                    c++;
                }
                else
               {
                   e++;
                }
            }
        }
        printf("%d %d %d\n",e,b,c);
    }
}
