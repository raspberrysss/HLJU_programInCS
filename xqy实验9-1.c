#include<stdlib.h>
#include<stdio.h>
#include <string.h>
typedef struct date//û�н����
{
    int year,month,day;
} Date;
typedef struct student
{
    long num;
    char name[10];
    char sex;
    Date birth;
    int f1;
    int f2;
    int f3;
    float ave;
} Stu;
void Output(Stu s[],int n);
void pjf(Stu s[],int n);
void px(Stu s[],int n);
void max(Stu s[],int n);
int main()
{
    int n,i,j,m;
    Stu s[10];
    printf("������ѧ��������");
    scanf("%d",&n);
    system("cls");
    printf("������ÿ��ѧ����ѧ�ţ��������Ա𣬳����������Լ����Ƴɼ���\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&s[i].num);
        getchar();
        scanf("%s",s[i].name);
        getchar();
        scanf("%c",&s[i].sex);
        scanf("%d %d %d",&s[i].birth.year,&s[i].birth.month,&s[i].birth.day);
        scanf("%d %d %d",&s[i].f1,&s[i].f2,&s[i].f3);
    }
    do
    {
        system("cls");
        printf("1�����ѧ��������Ϣ�Լ����ſγɼ�\n2�����ÿ��ѧ�����ſγ̵�ƽ����\n3����ƽ��������\n4�����ÿ����߷���ѧ������Ϣ\n5���˳�\n");
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            Output(s,n);
            break;
        case 2:
            pjf(s,n);
            break;
        case 3:
            px(s,n);
            break;
        case 4:
            max(s,n);
            break;
        default :
            break;
        }
        system("pause");

    }
    while(m>0&&m<5);
    return 0;
}
void pjf(Stu s[],int n)
{
    int i,j;
    float sum=0;
    for(i=0; i<n; i++)
    {
        sum=s[i].f1+s[i].f2+s[i].f3;
        s[i].ave=sum/3;
    }
    for(i=0; i<n; i++)
    {
        printf("ѧ��%dѧ��%s��ƽ����Ϊ %.2f\n",s[i].num,s[i].name,s[i].ave);
    }
}
void px(Stu s[],int n)
{
    int i,j,temp;
    Stu z;
    float sum=0;
    for(i=0; i<n; i++)
    {
        sum=s[i].f1+s[i].f2+s[i].f3;
        s[i].ave=sum/3;
        sum=0;
    }
    for(i=0; i<9; i++)
    {
        temp=i;
        for(j=i+1; j<10; j++)
        {
            if(s[j].ave>s[temp].ave)
            {
                temp=j;
            }
        }
        z=s[i];
        s[i]=s[temp];
        s[temp]=z;
    }
    for(i=0; i<n; i++)
    {
        printf("ѧ��%dѧ��%s��ƽ����Ϊ %.2f\n",s[i].num,s[i].name,s[i].ave);
    }
}
void max(Stu s[],int n)
{
    int i,j,a;
    int  k,l,z;
    int t,y,u;
    a=0;
    z=0;
    u=0;
    for(i=0; i<n; i++)
    {
        if(s[i].f1>s[a].f1)
        {
            a=i;
        }
    }
         for(j=0;i<n;j++)
         {
         if(s[j].f1==s[a].f1)
    printf("��Ŀ1��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[j].num,s[j].name,s[j].sex,s[j].birth.year,s[j].birth.month,s[j].birth.day,s[j].f1,s[j].f2,s[j].f3);
         }
//    for(j=0;i<n;j++)
//         if(s[j].f1=s[a].f1)
//    printf("��Ŀ1��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[a].num,s[a].name,s[a].sex,s[a].birth.year,s[a].birth.month,s[a].birth.day,s[a].f1,s[a].f2,s[a].f3);
    for(k=0; k<n; k++)
    {
        if(s[k].f2>s[z].f2)
        {
            z=i;
        }
    }
         for(l=0;l<n;l++)
         if(s[l].f1==s[z].f1)
    printf("��Ŀ2��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[l].num,s[l].name,s[l].sex,s[l].birth.year,s[l].birth.month,s[l].birth.day,s[l].f1,s[l].f2,s[l].f3);

//     for(j=0;j<n;j++)
//         if(s[j].f2=s[a].f2)
//    printf("��Ŀ2��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[a].num,s[a].name,s[a].sex,s[a].birth.year,s[a].birth.month,s[a].birth.day,s[a].f1,s[a].f2,s[a].f3);
    for(t=0; t<n; t++)
    {
        if(s[t].f3>s[u].f3)
        {
            t=i;
        }
    }
        for(y=0;y<n;y++)
         if(s[y].f3==s[u].f3)
    printf("��Ŀ3��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[y].num,s[y].name,s[y].sex,s[y].birth.year,s[y].birth.month,s[y].birth.day,s[y].f1,s[y].f2,s[y].f3);

//     for(j=0;j<n;j++)
//         if(s[j].f3=s[a].f3)
//    printf("��Ŀ3��ѧ��%d  ѧ��%s  �Ա�%c  ��������%d %d %d ���Ƴɼ�%d %d %d\n",s[a].num,s[a].name,s[a].sex,s[a].birth.year,s[a].birth.month,s[a].birth.day,s[a].f1,s[a].f2,s[a].f3);
}
void Output(Stu s[],int n)
{
    int i,j;
    printf("-------------------------------------------------------------\n");
    printf("    ѧ��     ����    �Ա�   ����    ��Ŀ1 ��Ŀ2 ��Ŀ3\n");
    printf("-------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%8d",s[i].num);
        printf("%10s",s[i].name);
        printf("%6c",s[i].sex);
        printf("%6d%02d%02d",s[i].birth.year,s[i].birth.month,s[i].birth.day);
        for(j=0; j<1; j++)
            printf("%6d%6d%6d",s[i].f1,s[i].f2,s[i].f3);
        printf("\n");
    }
}

