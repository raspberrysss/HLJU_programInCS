#include<stdio.h>
int main()
{
    int n;
    int i,j;
    int c,d,g;
    int e,f;
    int a[1000][1000];
    while(scanf("%d",&n)!=EOF)
    {
        f=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(a[i][j]==0)
                    {
                         c=0;
                         d=0;
                        for(g=0;g<n;g++)
                        {
                            c=c+a[g][j];
                            d=d+a[i][g];
                        }
                        e=c+d;
                        if(e>f)
                        {
                            f=e;
                        }
                    }
                }
            }
            printf("%d\n",f);

    }
}
