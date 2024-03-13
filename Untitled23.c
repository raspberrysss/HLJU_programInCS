#include<stdio.h>
int main()
{
    int a,b;
    int j;
    char i;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        j=0;
        for(i=a;i<=b;i++)
        {
            if(i=='2')
            {
                j++;
            }
        }
        printf("%d\n",j);

    }
}

