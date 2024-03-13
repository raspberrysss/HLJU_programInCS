#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];//要用char型定义
    int n,b,j,g;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();//吃回车，满足题目要求
        while(n--)
        {
            b=0;
            gets(a);
            for(j=0;j<=g;j++)
            {
                if(a[j]>='0'&&a[j]<='9')
                b++;

            }

            printf("%d\n",b);

        }
    }
}
