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
         b=b>>1;//�߼�����Ҫ����������ֱ��b>>

    }
}
int judge(int M,int i)//�м��ö��ţ�
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
    printf("M��ʼ״̬ʮ���Ʊ�ʾ��%d\n",M);
    printf("M��ʼ״̬�����Ʊ�ʾ��");
    binary( M);
    printf("\n");

while(flag==1)//Ҳ������do while ��ʱǰ���flagҪ��ֵ
{
    k=rand()%3+1;
    printf("k=%d\n",k);
    if(k==1)
    {
       a=judge(M,1);
       if(a==1)
       {
           printf("ũ����ײ���ͬ��\n");
           M=move(M,1);
           printf("ũ�򽫰ײ��Ƶ��԰���״̬��");
           binary(M);
           printf("\n");
           printf("��Ҫ������\n");


       }
       else
       {
           printf("ũ����ײ˲���ͬ��\n");
            printf("��Ҫ������\n");


       }
    }
    if(k==2)
    {
       a=judge(M,2);
       if(a==1)
       {
           printf("ũ��������ͬ��\n");
           M=move(M,2);
           printf("ũ�����Ƶ��԰���״̬:");
           binary(M);
           printf("\n");
           printf("��Ҫ������\n");

       }
       else
       {
           printf("ũ��������ͬ��\n");
            printf("��Ҫ������\n");

       }
    }
    if(k==3)
    {
       a=judge(M,3);
       if(a==1)
       {
           printf("ũ��������ͬ��\n");
           M=move(M,3);
           printf("ũ�����Ƶ��԰���״̬:");
           binary(M);
           printf("\n");
           printf("��Ҫ������\n");

       }
       else
       {
           printf("ũ�����ǲ���ͬ��\n");
            printf("��Ҫ������\n");

       }
    }
    scanf(" %c",&choose);//������ȡַ����,!!!����scanf�������ⲻִ�л���ͻȻ��������ѭ����%cǰҪ�ӿո�
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




