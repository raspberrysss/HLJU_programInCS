#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    long c,d;//�ó����Ͷ��廹�ǲ��У�ֻ��ÿ�ζ�ȡ��1000���������д�ĳ����Ǵ��
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=pow(a,b);
        d=c%1000;
        printf("%ld",d);
    }

}
