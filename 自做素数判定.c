#include<stdio.h>
int main()
{
    int x,y,a,t,l;
    while(scanf("%d%d",&x,&y),x!=0,y!=0)
    {
        if(x>y)
        {
            a=x;
            x=y;
            y=a;
        }
        for(int i=x; i<=y; i++)
        {
            t=i*i+i+41;
            for(int j=2;j<=t/2;j++)
            {
                 if(t%j!=0)
                {
                    if(j==t/2);
                    l=1;
                }
                if(t%j==0)

                    l=0;
                    break;
                }
                if(l==0)
                {
                    printf("Sorry\n");
                    break;
                }
        }

        if(l==0)
        {
            printf("OK\n");
        }
    }
        return 0;
}






