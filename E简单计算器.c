#include<stdio.h>
int main()
{
    int a,b;
    char c;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        scanf(" %c",&c);//要用空格吃掉字符空格？不明白
        if(c=='+')
        {
            printf("%d\n",a+b);
        }
        else if(c=='-')
        {
            printf("%d\n",a-b);
        }
        else if(c=='*')
        {
            printf("%d\n",a*b);
        }
        else if(c=='/')
        {
            if(b==0)
            {
                printf("Divided by zero!\n");
            }
            else
            {
                printf("%d\n",a/b);
            }
        }
        else
            {
                printf("Invalid operator!\n");
            }
    }
}
