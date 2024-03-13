#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    long id;
    char name[10];
    char sex;
    int age;
    int c;
    struct student *next;
};
void menu()
{
    printf("\t1.输入学生信息并建立链表输出");
    printf("\t2.对信息进行插入排序并输出");
    printf("\t3.输入学号删除学生信息");
    printf("\t4.退出");
    printf("\n");
}
struct student * create(int n)
{
     struct student *head,*pr,*p;
     int i;
     head=NULL;
     printf("please input the information\n");
     for(i=0;i<n;i++)
     {
        p=(struct student *)malloc(sizeof(struct student));
        scanf("%ld%s %c%d%d",&p->id,&p->name,&p->sex,&p->age,&p->c);//
         p->next=NULL;
         if(head==NULL)
         {
             head=p;
             pr=p;
         }
         else
         {
             pr->next=p;
             pr=p;
         }

     }
     return head;


}
void output(struct student *h)
{
    struct student *a;
    a=h;
    printf("the result is:\n");
   while(a!=NULL)
   {
       printf("%4d%4s%4c%4d%4d",a->id,a->name,a->sex,a->age,a->c);
       printf("\n");
       a=a->next;
   }
}

struct student * charu(struct student *h1,struct student *p)
{
     struct student *pre,*hou;
     if(h1==NULL)
     {
         h1=p;
     }
     else if(p->id<h1->id)
     {
         p->next=h1;
         h1=p;
     }
     else
     {
         hou=h1;//指后面的指针也先指到前面
         while(hou!=NULL&&p->id>hou->id)//不清楚，清楚了
         {
             pre=hou;
             hou=hou->next;
         }
         p->next=hou;
         pre->next=p;
     }
     return h1;
}
struct student * shanchu(struct student *h2,long sh)
{
    struct student *qian ,*q;
    if(h2==NULL)
    {
        return h2;
    }
    else if(h2->id==sh)
    {
        qian=h2;
        h2=h2->next;
        free(qian);
    }
    else
    {
        q=h2;//先指向头指针，这里不止后指针，而是用来判断的
        while(q!=NULL&&q->id!=sh)
        {
           qian=q;
           q=q->next;
        }
        if(q!=NULL)
        {
            qian->next=q->next;
            free(q);
        }
        else
        {
            printf("not found\n");
        }
    }
    return h2;
}

int main()
{
    int n;
    int a;
    long sh;
    int flag=1;
    struct student s[100];
    struct student *h,*p,*h1,*h2;
    //h1=NULL;
    h=NULL;
    printf("how many student you want to insert\n");
    scanf("%d",&n);
    while(flag)
    {
         system("cls");
         menu();
         printf("please chose\n");
         scanf("%d",&a);
         switch(a)
         {
         case 1:
            h=create(n);
            output(h);
            break;
         case 2:
             p=(struct student *)malloc(sizeof(struct student));
             printf("please input the new one\n");
             scanf("%ld%s %c%d%d",&p->id,&p->name,&p->sex,&p->age,&p->c);
             p->next=NULL;
            // h1=h;
             //h=charu(h1,p);
             h=charu(h,p);
             output(h);
            break;
         case 3:
         printf("which one you want to delete,input the id\n");
         scanf("%ld",&sh);//
         //h2=h;
         h=shanchu(h,sh);//
         output(h);//
         break;
         case 4:
            flag=0;
            printf("thank you for using\n");
            break;
         default:
            printf("please chose the right number\n");
         }
         system("pause");
    }
}
