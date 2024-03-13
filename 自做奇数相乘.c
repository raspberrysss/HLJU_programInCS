#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int c=1;
        int e;
        while(n--)
        {
            scanf("%d",&e);
            if(e%2==1)
            {
                c=c*e;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
