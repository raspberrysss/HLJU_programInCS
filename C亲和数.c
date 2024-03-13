#include<stdio.h>
int main()
{
    int m,a,b,c;
    while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            c=0;
            scanf("%d%d",&a,&b);
            for(int i=1;i<=a;i++)
            {
                if(a%i==0)
                {
                    c=c+i;
                }
            }
            c=c-a;
            if(c==b)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}
