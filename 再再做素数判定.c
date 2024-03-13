#include<stdio.h>
int main()
{
    int n,m,t,i,j,r;
    r=0;
    while(scanf("%d%d",&n,&m),n!=0,m!=0)
    {
        for(i=n; i<=m; i++)
        {
            t=i*i+i+41;
            for(j=2; j<=i; j++)
            {
                if(j==i)
                {
                    r=1;
                }
                if(t%j==0)
                {
                    r=0;
                    break;
                }
                if(r==0)
                {
                    printf("Sorry");
                    break;
                }
            }
        }
        if(r==1)
        {
            printf("OK");
        }

    }
}
