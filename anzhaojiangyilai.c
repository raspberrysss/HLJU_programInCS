#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>//�������Ͳ�������
int b;
void pingjun(int r[][3])
{
    double sum,ave;
    int i;
    sum=0.0;
    for(i=0;i<5;i++)
    {
        sum=sum+r[0][i];
    }

    ave=sum/5;
    printf("%.2lf",ave);

}
void input(long d[5],int g[][3])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        scanf("%d",&d[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
}
void menu()
{
   int b;
    system("cls");
           printf("��ѡ��ѡ����в���\n");
    printf("******************************************************\n");
    printf("* (1) ¼��ÿ��ѧ����ѧ����ɼ�                       *\n");
    printf("* (2) ���һ�ſε�ƽ����                             *\n");
    printf("* (3) �ҳ����������Ͽγ̲������ѧ��                 *\n");
    printf("*     ������ǵ�ѧ�ţ�ȫ���γ̳ɼ���ƽ���ɼ�         *\n");
    printf("* (4) �ҳ�ƽ���ɼ�90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ�� *\n");
    printf("* (5) �˳�                                           *\n");
    printf("******************************************************\n");
    printf("������ѡ�");
}
int login()
{
    long x;
    char a[6];
    int count=0;
    char c;
    int i;
    printf("�������˺�������\n");
    printf("�˺ţ�");
    scanf("%ld",&x);
    printf("���룺");
    i=0;
    while(count<3)
    {
        for(i=0;;i++)
        {
            c=getch();
            a[i]=c;
            switch(c)
            {
                case '\b':
                a[--i]='\0';
                i--;
                printf("\b \b");
                break;

           case '\r':

                a[i]='\0';
                putchar('\n');
                break;
            default:

                putchar('*');
                break;
            }

            if(a[i]=='\0')
            {
                break;
            }

        }
        count++;
        if(strcmp(a,"hljdxsx")==0)
        {
            return 1;
            break;
        }
        else if(count<3)
        {
            printf("�������,���ٴ�����\n");
        }
        else
            {
                printf("�����Ѿ��������Σ��޷�����");
                return 0;
            }

    }
}
int main()
{
    int a;
    int c;
    long d[100];
    int f[3];
    int e;
    int i,j,k;
    int g[5][3];
    printf("��ӭ�����ɼ�����ϵͳ\n");
    a=login();
    if(a==1)
    {
         printf("������ȷ����ӭ����ɼ�����ϵͳ\n");
         system("pause");
         system("cls");
         menu();
         scanf("%d",&b);
    if(b==5)
    {
        printf("��лʹ��\n");
        return 0;
    }
    else if(b==1)
    {
        input(d,g);
        menu();
        scanf("%d",&b);
    }
    else if(b==2)
    {
        printf("hello");
        pingjun(g);
        menu();
        scanf("%d",&b);
    }
    else if(b==3)
    {

    }

    }
    else if(a==0)
    {
        printf("��ǿ���˳�\n");
        return 0;
    }

}
