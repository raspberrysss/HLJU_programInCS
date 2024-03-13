#include<stdio.h>
struct stack
{
    int a[100000];
    int top;
};

int main()//²»»á
{
    struct stack s;
    int n,i,j;
    s.top=0;
    int c[100000],d[100000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
        }
        j=0;
        for(i=0;i<n;i++)
        {
            s.a[s.top]=c[i];
            s.top++;
            while(s.top!=0&&s.a[s.top]==d[j])
            {
                s.top--;
                j++;
            }
        }
        if(s.top!=0)
        {
            printf("Yes\n");
        }
        else{printf("No\n");}
    }
}
