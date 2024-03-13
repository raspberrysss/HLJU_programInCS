#include<stdio.h>

struct stack
{
    int top;
    char a[1000000];
};
int main()
{
    struct stack s;
    int n,i;
    int x;
    s.top=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==1)
            {
               scanf("%s",&s.a[s.top]);
                s.top++;
            }
            else if(x==2)
            {
                if(s.top!=0)
                {
                    printf("%s\n",s.a[s.top-1]);
                    s.top--;
                }
            }
            else if(s.top==0&&x!=2)
            {
                printf("weishenmedajiadoumeilai");
            }
            else if(s.top!=0&&x!=2)
            {
                printf("biejuanlebiejuanle");
            }
        }
    }
}
