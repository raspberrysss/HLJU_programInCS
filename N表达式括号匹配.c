#include<stdio.h>
#include<string.h>//自己做的，棒棒
struct stack
{
   char b[2000];
   int top;
};
int main()
{
    struct stack s;
    int n,i;
    s.top=0;
    char a[2000];
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='(')
        {
            s.top++;
            s.b[s.top]=a[i];
        }
        if(a[i]==')')
        {
            s.top--;
        }
    }
    if(s.top==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
