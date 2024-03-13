#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char a[1000];
    char c;
    while(scanf("%d",&n)!=EOF)
    {

         for(i=0;i<n;i++)
         {
            scanf(" %c",&a[i]);

         }
         for(i=0;i<n;i++)
         {
             if(a[i]>='a'&&a[i]<='y')
             {
                 a[i]=a[i]+1;
             }
            else if(a[i]=='z')
             {
                 a[i]='a';
             }

         }
         for(i=0;i<n;i++)
         {
             printf("%c",a[i]);
         }
         printf("\n");
    }
}
