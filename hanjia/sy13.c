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
union marital//联合体后一个赋值会影响前一个，最后的值都是最后一个
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
        printf("请输入第%d个员工的姓名 性别 年龄\n",i);
        scanf("%s %c%d",&per[i].name,&per[i].sex,&per[i].age);
        printf("请选择第%d个员工的婚姻状态对应的号(1-3)：\n",i);
        printf("1.未婚\n");
        printf("2.已婚\n");
        printf("3.离异\n");
        printf("请输入第%d个员工的婚姻状态对应的号(1-3):\n",i);
        scanf("%d",&choice);
        if(choice==1)
        {
           per[i].um.marryflag=1;
           per[i].marryflag2=1;
        }
        else if(choice==2)
        {
           per[i].marryflag2= 2;
           printf("请输入第%d个员工的结婚年 月 日 :\n",i);
           scanf("%d%d%d",&per[i].um.m.marryday.year,&per[i].um.m.marryday.month,&per[i].um.m.marryday.day);
           printf("请输入第%d个员工的配偶姓名：\n",i);
           scanf("%s",&per[i].um.m.partnername);
           printf("请输入第%d个员工的孩子数：\n",i);
           scanf("%d",&per[i].um.m.children);
           // printf("%-10d%10s %6c%6d%已婚%d/%d/%d%10s%6d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children);
        }
        else if(choice==3)
        {
            per[i].marryflag2=3;
            printf("请输入第%d个员工的离婚年 月 日：\n",i);
            scanf("%d%d%d",&per[i].um.d.divorceday.year,&per[i].um.d.divorceday.month,&per[i].um.d.divorceday.day);
            printf("请输入第%d个员工的孩子数：\n",i);
            scanf("%d",&per[i].um.d.children);

        }


    }
}
void output(int a,struct person per[])
{
    printf("员工编号  姓名\t性别\t年龄\t婚姻状态  结婚或离婚日期  配偶姓名  孩子数\n");
    int i;
    for(i=1;i<=a;i++)
    {
        if(per[i].marryflag2==1)
        {
            printf("%d\t%s\t %c\t%d\t未婚\t\n",per[i].id,per[i].name,per[i].sex,per[i].age);
        }
        else if(per[i].marryflag2==2)
        {
    printf("%d\t%s\t %c\t%d\t已婚\t   %d/%d/%d\t  %s\t    %d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.partnername,per[i].um.m.children);

        }
        else if(per[i].marryflag2==3)
        {
             printf("%d\t%s\t %c\t%d\t离婚\t   %d/%d/%d\t\t    %d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.d.divorceday.year,per[i].um.d.divorceday.month,per[i].um.d.divorceday.day,per[i].um.d.children);

        }
    }//终于对了，改的我快哭了

    //printf("%d\n",i);
   //i=2;//我是大傻蛋！输出不了是因为我写的%离婚,我又不是了，还是不行
    //printf("%d\t%s\t %c\t%d已婚%d/%d/%d/%d%s\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children,per[i].um.m.partnername);
    // printf("%-10d%10s %6c%6d%已婚%d/%d/%d%10s%6d\n",per[i].id,per[i].name,per[i].sex,per[i].age,per[i].um.m.marryday.year,per[i].um.m.marryday.month,per[i].um.m.marryday.day,per[i].um.m.children);原来为什么错呢？怎么也输不出来
}
int main()
{
    int a;
    struct person per[100];
    printf("请输入员工数：");
    scanf("%d",&a);
    input(a,per);
    output(a,per);
    return 0;
}
