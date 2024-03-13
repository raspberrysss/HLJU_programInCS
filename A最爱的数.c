#include<stdio.h>
int main()
{
    int a,b,c;
    int i;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=0;
        for(i=a;i<=b;i++)
        {
            if(i%33==0)
            {
                c++;
            }
        }
        printf("%d\n",c);
    }
}
