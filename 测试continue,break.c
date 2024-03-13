#include<stdio.h>
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==0&&y==0)
            break;
        if(x>y)
        {
            printf("0\n");
        }
        if(y>x)
        {
            printf("9\n");
        }
    }
}
