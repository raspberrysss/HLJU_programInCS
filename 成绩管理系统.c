#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>//加上它就不报错了
//void input(int c,int e,long d[],int f[],int g[][])//如何实现二维数组做形参
//如果是自己输入课程数目，如何传到函数里
void pingjun(int r,int c)
{
    double sum,ave;
    int i;
    sum=0.0;
    for(i=0;i<c;i++)
    {
        sum=r[i][0];
    }
    ave=sum/c;
    printf("%.2lf",ave);

}
void menu()
{
   int b;
    system("cls");
           printf("请选择选项进行操作\n");
    printf("******************************************************\n");
    printf("* (1) 录入每个学生的学号与成绩                       *\n");
    printf("* (2) 求第一门课的平均分                             *\n");
    printf("* (3) 找出有两门以上课程不及格的学生                 *\n");
    printf("*     输出他们的学号，全部课程成绩，平均成绩         *\n");
    printf("* (4) 找出平均成绩90分以上或全部成绩在85分以上的学生 *\n");
    printf("* (5) 退出                                           *\n");
    printf("******************************************************\n");
    printf("请输入选项：");
}
int login()
{
    long x;
    char a[6];
    int count=0;
    char c;
    int i;
    printf("请输入账号与密码\n");
    printf("账号：");
    scanf("%ld",&x);
    printf("密码：");
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
        if(strcmp(a,"hljtlsx")==0)
        {
            return 1;
            break;
        }
        else if(count<3)
        {
            printf("密码错误,请再次输入\n");
        }
        else
            {
                printf("密码已经错误三次，无法登入");
                return 0;
            }

    }
}
int main()
{
    int a;
    int b;
    int c;
    long d[100];
    int f[100];
    int e;
    int i,j,k;
    int g[100][100];
    printf("欢迎来到成绩管理系统\n");
    a=login();
    if(a==1)
    {    printf("密码正确，欢迎进入成绩管理系统\n");
         system("pause");
         system("cls");
         menu();
         scanf("%d",&b);
    if(b==5)
    {
        printf("感谢使用\n");
        return 0;
    }
    else if(b==1)
    {
        printf("请输入学生个数\n");
        scanf("%d",&c);
        printf("请输入课程个数");
        scanf("%d",&e);
        printf("请输入学生号\n");
        for(i=0;i<c;i++)
        {
            scanf("%d",&d[i]);
        }
        printf("请输入课程号\n");
        for(i=0;i<e;i++)
        {
            scanf("%d",&f[i]);
        }
        printf("请依次输入成绩\n");
        {
            for(i=0;i<c;i++)
            {
                for(j=0;j<e;j++)
                {
                    scanf("%d",&g[i][j]);
                }
            }
        }
        menu();
        scanf("%d",&b);
    }
    else if(b==2)
    {
        pingjun(g,c);
    }
    else if(b==3)
    {

    }

    }
    else if(a==0)
    {
        printf("已强制退出\n");
        return 0;
    }

}
