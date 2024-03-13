#include<stdio.h>
int main()
{
    int m,b,x;
    int i,k;
    char a;
    int a[100000],e[100000],ne[100000];
    int idx,
    int head;
    head=-1;
    idx=0;
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%c",&a);
        }
        if(a=='H')
        {
            scanf("%d",&b);
            e[idx]=b;
            ne[idx]=head;//用数组它的模拟下一个数
            head=idx;
            idx++;
        }
        if(a=='D')
        {
            scanf("%d",&k);

        }
        if(a=='I')
        {
            scanf("%d%d",&k,&x);
            e[idx]=x;
            e[idx]=e[k];

        }
    }
}
