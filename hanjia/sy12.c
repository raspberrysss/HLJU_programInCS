#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int M;
    int n;
    int e[10];
    int l=0;
    int i;
    int k;
    srand((unsigned)time(NULL));
    M=rand()%15+1;
    if(M!=3&&M!=6&&M!=7&&M!=8&&M!=9&&M!=12)
    {
        printf("M初始状态十进制表示：%d\n",M);
    }
    n=M;
    while(n/2)
    {
        e[l++]=n%2;//?
        n=n/2;
    }
    e[l++]=n%2;
    printf("M初始状态二进制表示：");//1,2,4,5有问题
    for(i=l-1;i>=0;i--)
    {
        printf("%d",e[i]);
    }
    k=rand()%3+1;
    printf("\n");
    printf("k=%d",k);
    if(k==1)
    {
       if(M==2||M==4||M==11||M==14)
       {
           printf("农夫与白菜不在同岸\n");
       }
       else{printf("no\n");}
    }


}
