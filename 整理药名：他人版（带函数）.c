#include<stdio.h>
void c(char *s)
{
    if(s[0]>='a'&&s[0]<='z')
    {
        s[0]=s[0]-32;
    }
    for(int i=1;s[i]!=0;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
    }
}
int main()
{
    int n;
    char a[100];
    scanf("%d\n",&n);
    while(n--)
    {
        gets(a);
        c(a);
        puts(a);
    }
}
