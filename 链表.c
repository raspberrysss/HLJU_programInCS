#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student//用函数进行尾插
{
    long id;
    struct student *next;
}s_node;
s_node* creat_after(int n)
{
    s_node *head=NULL,*p,*pr;//尾结点不一定为空，所以这里先定义，不赋值
    int i;
    for(i=0;i<n;i++)
    {
        p=(s_node*)malloc(sizeof(s_node));
        printf("input id\n");
        scanf("%ld",&p->id);//只有用结构体指针的时候会出现->
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
void printlink(s_node *h)
{
    s_node *p;
    p=h;
    while(p!=NULL)
    {
        printf("%3ld",p->id);
        p=p->next;
    }
}

int main()
{
   s_node *h;
   int n;
   scanf("%d",&n);
   h=creat_after(n);
   printlink(h);
   return 0;
}
