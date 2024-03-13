#include<stdio.h>
int main()
{
    int x,y,f;
    int a,b;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        a=0;
        b=0;
        if(x>y)
        {
            f=x;
            x=y;
            y=f;
        }
        for(int i=x;i<=y;i++)//小于等于！要看好！看明白！
    {
            if(i%2==0)
            {
                a=a+i*i;

            }
            else if(i%2==1)
            {
                b=b+i*i*i;
            }
        }
        printf("%d %d\n",a,b);

    }
}
