#include<stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
struct married
{
    struct date marryday;
    char partnername[10];
    int children;
};
struct divorce
{
    struct date divorceday;
    int children;
};
union marital//�������һ����ֵ��Ӱ��ǰһ��������ֵ�������һ��
{
    int marryflag;
    struct married m;
    struct divorce d;

};
struct person
{
    int id;
    char name[10];
    char sex;
    int age;
    union marital um;
    int marryflag2;
};
void input(int a,struct person per[])
{
    int i;
    int choice;
    for(i=1;i<=a;i++)
    {
        per[i].id=i;
        printf("�������%d��Ա�������� �Ա� ����\n",i);
        scanf("%s %c%d",&per[i].name,&per[i].sex,&per[i].age);
        printf("��ѡ���%d��Ա���Ļ���״̬��Ӧ�ĺ�(1-3)��\n",i);
        printf("1.δ��\n");
        printf("2.�ѻ�\n");
        printf("3.����\n");
        printf("�������%d��Ա���Ļ���״̬��Ӧ�ĺ�(1-3):\n",i);
        scanf("%d",&choice);
        if(choice==1)
        {
           per[i].um.marryflag=1;
           per[i].marryflag2=1;
        }
        else if(choice==2)
        {
           per[i].marryflag2= 2;
           printf("�������%d��Ա���Ľ���� �� �� :\n",i);
           scanf("%d%d%d",&per[i].um.m.marryday.year,&per[i].um.m.marryday.month,&per[i].um.m.marryday.day);
           printf("�������%d��Ա������ż������\n",i);
           scanf("%s",&per[i].um.m.partnername);
           printf("�������%d��Ա���ĺ�������\n",i);
           scanf("%d",&per[i].um.m.children);
           // printf("%-10d%10s %6c%6d%�ѻ�%d/%d/%d%10s%6d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children);
        }
        else if(choice==3)
        {
            per[i].marryflag2=3;
            printf("�������%d��Ա��������� �� �գ�\n",i);
            scanf("%d%d%d",&per[i].um.d.divorceday.year,&per[i].um.d.divorceday.month,&per[i].um.d.divorceday.day);
            printf("�������%d��Ա���ĺ�������\n",i);
            scanf("%d",&per[i].um.d.children);

        }


    }
}
void output(int a,struct person per[])
{
    printf("Ա�����  ����\t�Ա�\t����\t����״̬  �����������  ��ż����  ������\n");
    int i;
    for(i=1;i<=a;i++)
    {
        if(per[i].marryflag2==1)
        {
            printf("%d\t%s\t %c\t%d\tδ��\t\n",per[i].id,per[i].name,per[i].sex,per[i].age);
        }
        else if(per[i].marryflag2==2)
        {
    printf("%d\t%s\t %c\t%d\t�ѻ�\t   %d/%d/%d\t  %s\t    %d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.partnername,per[i].um.m.children);

        }
        else if(per[i].marryflag2==3)
        {
             printf("%d\t%s\t %c\t%d\t���\t   %d/%d/%d\t\t    %d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.d.divorceday.year,per[i].um.d.divorceday.month,per[i].um.d.divorceday.day,per[i].um.d.children);

        }
    }//���ڶ��ˣ��ĵ��ҿ����

    //printf("%d\n",i);
   //i=2;//���Ǵ�ɵ���������������Ϊ��д��%���,���ֲ����ˣ����ǲ���
    //printf("%d\t%s\t %c\t%d�ѻ�%d/%d/%d/%d%s\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children,per[i].um.m.partnername);
    // printf("%-10d%10s %6c%6d%�ѻ�%d/%d/%d%10s%6d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children);ԭ��Ϊʲô���أ���ôҲ�䲻����
}
int main()
{
    int a;
    struct person per[100];
    printf("������Ա������");
    scanf("%d",&a);
    input(a,per);
    output(a,per);
    return 0;
}
