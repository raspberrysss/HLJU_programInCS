#include<stdio.h>
#include<string.h>
int main()
{
    char n[100];
    int i=0,j;
    gets(n);
    j=strlen(n)-1;
    while(i<=j&&n[i]==n[j])//用例子可以试出来
    {
        i++;
        j--;
    }
    if(i<=j)//如果是回文序列，最后i和j一定会换地方
    {
        printf("no\n");
    }
    else{printf("yes\n");}

}
