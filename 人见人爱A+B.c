#include<stdio.h>
int main()
{
    int n,a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
    while(scanf("%d",&n)!=EOF)
    {
            while(n--)
            {
                  scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
                   c1=a1+b1;
                   c2=a2+b2;
                   c3=a3+b3;
                   d3=c3%60;
                   d2=(c2+c3/60)%60;
                   d1=c1+(c2+c3/60)/60;
                   printf("%d %d %d\n",d1,d2,d3);
            }
    }
    return 0;
}
