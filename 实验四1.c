#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int rand10()
{
    return rand()%10+1;
}
//int rand20()
//{
  //  srand((unsigned)time(NULL));
    //return rand()%10+1;
//}

void tongji(int a)
{
    int b;
    double c;
    b=a*10;
    printf("你的总分为%d，你的正确率为%d%%",b,b);


}
int correct(int a,int b,int c)
{
    int n;
    n=a*b;
    if(n!=c)
    {
        return 0;
    }
    else if(n==c)
    {
        return 1;
    }

}
int correct2(int a,int b,char r,int c)
{
    int n;
    if(r=='+')
    {

    }
}
void panduanchushu(int a,int b)
{

}
char randchar()
{
    int a;
    a=rand()%4+1;
    if(a==1)
    {
        return '+';
    }
    if(a==2)
    {
        return '-';
    }
    if(a==3)
    {
        return '*';
    }
    if(a==4)
    {
        return '/';
    }
}

int main()
{
    srand((unsigned)time(NULL));//要放在这里，每次才会不一样
    int n;
    int a,b,c;
    int d;
    char r;
    printf("***************************************************************************************\n");
    printf("*  1.任务一：随机产生1-10之间正整数，出乘法问题，直到学生答对为止                     *\n");
    printf("*  2.任务二：在任务一的基础上，当学生答错时，最多给三次机会                           *\n");
    printf("*  3.任务三：在任务一的基础上，连做十道乘法题，不给机会重做，统计总分，正确率         *\n");
    printf("*  4.任务四：在任务三的基础上，随机产生十道四则运算题，不给机会重做，统计总分正确率   *\n");
    printf("*  5.任务五：在任务四的基础上，若回答正确率低于75%%，则再做十道，直到正确率高于75%%     *\n");//只有这样可以正确，为啥
    printf("*  6.退出                                                                             *\n");
    printf("***************************************************************************************\n");
    printf("please choose one number\n");
    scanf("%d",&n);
    if(n==1)
    {
        a=rand10();
        b=rand10();
        printf("%d*%d=?\n",a,b);
        do{
        scanf("%d",&c);//不要忘记取地址符号
        d=correct(a,b,c);
        if(d==1)
        {
            printf("you are right!\n");//如何回到菜单页面？不会
        }
        else if(d==0)
        {
            printf("wrong,please try again\n");
        }
    }while(d==0);

    }
    if(n==2)
    {
        int count=0;
        a=rand10();
        b=rand10();
      do{
        printf("%d*%d=?\n",a,b);
        scanf("%d",&c);
        d=correct(a,b,c);
        if(d==0)
        {
            count++;
            if(count<=2)
            printf("wrong,please try again,you only have %d chance\n",3-count);
            if(count==3)
            {
                 printf("sorry,game over");

            }
        }
        if(d==1)
        {
            printf("right!");
        }
      }while(d==0&&count<3);


    }
    if(n==3)
    {
        int e=0;
        int count=0;
         do{
        a=rand10();
        b=rand10();
        printf("%d*%d=?\n",a,b);
        scanf("%d",&c);
        d=correct(a,b,c);
        if(d==1)
        {
            e++;
        }
        count++;
        }while(count<=10);
        tongji(e);

    }
    if(n==4)
    {
        int f=0;
        int count=0;
         do{
        a=rand10();
        b=rand10();
       r=randchar();
        printf("%d%c%d=?\n",a,r,b);
        scanf("%d",&c);
        d=correct(a,b,c);
        if(d==1)
        {
            f++;
        }
        count++;
        }while(count<=10);
        tongji(f);
    }
    if(n==5)
    {

    }
    if(n==6)
    {
        return 0;
    }

}
