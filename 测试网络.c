#include <stdio.h>
#include<string.h>
void Strcmp(char *str1,char *str2)
{
    while((*str1!='\0')&&(*str1==*str2))
    {
        str1++;
        str2++;
    }
    int t;
    t=*str1-*str2;
    if(t==0)
        printf("same string\n");
    if(t>0)
        printf("str1 is bigger\n");
    if(t<0)
        printf("str2 is bigger\n");
}
int main()
{
    char str1[10],str2[10];
    start:
    gets(str1);
    gets(str2);
    Strcmp(str1,str2);
    goto start;
    return 0;

}
