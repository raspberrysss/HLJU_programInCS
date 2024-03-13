#include<stdio.h>
int main()
{
    int i,n,m,t,r;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        if(n>=-39&&n<m&&m<=50)
        {
            for(i=n; i<=m; i++)
            {
                t=i*i+i+41;
                for(int j=2; j<=t/2; j++)
                {
                    if(t%j!=0)
                        if(j==t/2)
                            r=1;
                    if(t%j==0)
                    {
                        r=0;
                        break;
                    }
                }
                if(r==0)
                {
                    printf("Sorry\n");
                    break;
                }
            }
            if(r==1)
                printf("OK\n");
        }
    }
}
