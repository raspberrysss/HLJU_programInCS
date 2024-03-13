#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Rand1()
{
    int U;
    srand((unsigned)time(NULL));
    U=rand()%15+1;
    return U;
}
void binary(int M)
{
    int n;
    int b=8;
    while(b!=0)
    {
        n=M&b;
        if(n!=0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
         b=b>>1;//逻辑右移要这样，不能直接b>>

    }
}
int judge(int M,int i)//中间用逗号！
{
    int x;
    int y;
    x=M;
    y=M;
    x=x<<(4-i);
    x=x&8;
    y=M&8;
    if(x^y==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int move(int M,int u)
{
    int c=1;
    c=c<<u-1;
    c=c|8;
    M=M^c;
    return M;
}
int main()
{
    char choose;
    int M;
    int n;
    int i;
    int k;
    int a;
    int flag=1;
    M=Rand1();
    while(M==3||M==6||M==7||M==8||M==9||M==12)
    {
        M=Rand1();
    }
    printf("M初始状态十进制表示：%d\n",M);
    printf("M初始状态二进制表示：");
    binary( M);
    printf("\n");

while(flag==1)//也可以用do while 此时前面的flag要无值
{
    k=rand()%3+1;
    printf("k=%d\n",k);
    if(k==1)
    {
       a=judge(M,1);
       if(a==1)
       {
           printf("农夫与白菜在同岸\n");
           M=move(M,1);
           printf("农夫将白菜移到对岸后状态：");
           binary(M);
           printf("\n");
           printf("还要继续吗？\n");


       }
       else
       {
           printf("农夫与白菜不在同岸\n");
            printf("还要继续吗？\n");


       }
    }
    if(k==2)
    {
       a=judge(M,2);
       if(a==1)
       {
           printf("农夫与羊在同岸\n");
           M=move(M,2);
           printf("农夫将羊移到对岸后状态:");
           binary(M);
           printf("\n");
           printf("还要继续吗？\n");

       }
       else
       {
           printf("农夫与羊不在同岸\n");
            printf("还要继续吗？\n");

       }
    }
    if(k==3)
    {
       a=judge(M,3);
       if(a==1)
       {
           printf("农夫与狼在同岸\n");
           M=move(M,3);
           printf("农夫将狼移到对岸后状态:");
           binary(M);
           printf("\n");
           printf("还要继续吗？\n");

       }
       else
       {
           printf("农夫与狼不在同岸\n");
            printf("还要继续吗？\n");

       }
    }
    scanf(" %c",&choose);//别忘了取址符！,!!!遇到scanf出现问题不执行或者突然出现两次循环，%c前要加空格
    if(choose=='y')
    {
        flag=1;
    }
    else if(choose=='n')
    {
        flag=0;
    }
}
return 0;

   }




