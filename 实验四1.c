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
    printf("����ܷ�Ϊ%d�������ȷ��Ϊ%d%%",b,b);


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
    srand((unsigned)time(NULL));//Ҫ�������ÿ�βŻ᲻һ��
    int n;
    int a,b,c;
    int d;
    char r;
    printf("***************************************************************************************\n");
    printf("*  1.����һ���������1-10֮�������������˷����⣬ֱ��ѧ�����Ϊֹ                     *\n");
    printf("*  2.�������������һ�Ļ����ϣ���ѧ�����ʱ���������λ���                           *\n");
    printf("*  3.��������������һ�Ļ����ϣ�����ʮ���˷��⣬��������������ͳ���ܷ֣���ȷ��         *\n");
    printf("*  4.�����ģ����������Ļ����ϣ��������ʮ�����������⣬��������������ͳ���ܷ���ȷ��   *\n");
    printf("*  5.�����壺�������ĵĻ����ϣ����ش���ȷ�ʵ���75%%��������ʮ����ֱ����ȷ�ʸ���75%%     *\n");//ֻ������������ȷ��Ϊɶ
    printf("*  6.�˳�                                                                             *\n");
    printf("***************************************************************************************\n");
    printf("please choose one number\n");
    scanf("%d",&n);
    if(n==1)
    {
        a=rand10();
        b=rand10();
        printf("%d*%d=?\n",a,b);
        do{
        scanf("%d",&c);//��Ҫ����ȡ��ַ����
        d=correct(a,b,c);
        if(d==1)
        {
            printf("you are right!\n");//��λص��˵�ҳ�棿����
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
