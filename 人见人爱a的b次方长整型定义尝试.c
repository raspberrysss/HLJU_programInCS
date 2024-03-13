#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    long c,d;//用长整型定义还是不行，只能每次都取余1000，这个现在写的程序是错的
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=pow(a,b);
        d=c%1000;
        printf("%ld",d);
    }

}
