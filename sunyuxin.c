#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i;
    scanf("%s",a);
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='z')
            a[i]='a';
       else if(a[i]>='a'&&a[i]<'z')
        a[i]=a[i]+1;
   }
printf("%s",a);
}
