#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d",&a,&b),a!=0&&b!=0)
    {
        c=a;

        for(int i=1;i<b;i++)
        {
           c=(c*a)%1000;
        }
        printf("%d\n",c);
    }
    return 0;
}
