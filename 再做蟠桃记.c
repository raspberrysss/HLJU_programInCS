#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        a=1;
        for(int i=1;i<n;i++)//��n-1�����i��1��ʼ
        {
            a=(a+1)*2;//������������ʽ
        }
        printf("%d\n",a);
    }
}
