#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%3==0)
        {
            printf("qy_god\n");
        }
        else
        {
            printf("Ana!!!\n");
        }
    }
    return 0;
}
