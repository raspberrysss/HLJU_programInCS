#include<stdio.h>
int main()
{
    int a,b,c,n;
    double e;
    while(scanf("%d",&n),n!=0)
    {
        a=0;
        b=0;
        c=0;
        while(n--)
        {
            scanf("%lf",&e);
            if(e>0)
            {
                a=a+1;
            }
            else
            {
                if(e==0)
                {
                    b=b+1;
                }
                else{
                    c=c+1;
                }
            }
        }
    printf("%d %d %d\n",c,b,a);
    }

    return 0;
}
