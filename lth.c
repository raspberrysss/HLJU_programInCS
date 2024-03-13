#include <stdio.h>
#include <stdlib.h>
int mystrcmp(char *p1,char *p2);
int main ()
{
    int k;
    char a[20],b[20];
    char *p1,*p2;
    gets(a);
    gets(b);
    p1=a;
    p2=b;
    k=mystrcmp(p1,p2);
    printf("%d",k);
    return 0;
}
int mystrcmp (char *p1,char *p2)
{
    int i=0;
    int k;
    while(*(p1+i)!='\0'||*(p2+i)!='\0')
    {
        if(*(p1+i)==*(p2+i))
             k=0;
        else
           {
            k=*(p1+i)-*(p2+i);
            break;
           }
        i++;
    }
    return k;
}
