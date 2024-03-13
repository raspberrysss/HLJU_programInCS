#include<stdio.h>
int main()
{
    int m,a,b,c,i;
    double x;
    while(scanf("%d",&n),n!=0)
    {
         a=0;
         b=0;
         c=0;
        if(m!=0)

        {
            for(i=0;i<m;i++)
            {
                scanf("%lf",&x);
                if(x<0)
                {
                    a++;
                }
                else if(x==0)
                {
                    b++;
                }
                else
                {
                  c++;
                }
            }
             printf("%d %d %d\n",a,b,c);

        }
        else
            break;
    }
    return 0;
}
