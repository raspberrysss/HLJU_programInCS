#include<stdio.h>
#include<string.h>
int main()
{
    int n,l,b;
    char a[100];
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            gets(a);
            l=strlen(a);
            b=0;
            for(int i=0;i<l;i++)
            {
                if(a[i]>='0'&&a[i]<='9')
                    b++;
            }
            printf("%d\n",b);

        }
    }
    return 0;
}
