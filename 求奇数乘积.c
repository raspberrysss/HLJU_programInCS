#include<stdio.h>

int main()
{
    int a,n,c;
    while(scanf("%d",&a)!=EOF)
    {
        c=1;
        while(a--)
        {
            scanf("%d",&n);
            if(n%2==1)
            {
                c=c*n;
            }
        }
        printf("%d",c);

    }
}
