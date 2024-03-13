#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        a=1;
        for(int i=1;i<n;i++)//有n-1项，所以i从1开始
        {
            a=(a+1)*2;//逆过来想这个算式
        }
        printf("%d\n",a);
    }
}
