#include<stdio.h>
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)//有时间补题
    {
        j=0;
        for(i=1;i<n;i++)
        {
            if(i%2!=0&&i%5!=0&&i%11!=0&&i%13!=0)
            {
                j++;
            }
        }
        printf("%d\n",j);
    }
    return 0;
}
