#include<stdio.h>//原来这个也有问题，我还参考这个做哈哈哈哈哈
#include<stdlib.h>//建立链表的时候没建好，输不出来
#include<string.h>
typedef struct student
{
    int data;
    struct student *next;
}stu;
int main()
{
    stu *head,*pre,*p,*zhao;
    int n,i;
    head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p=(stu *)malloc(sizeof(stu*));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            head->next=NULL;
            //p->next=NULL;//可有可无，通过for循环也可以指向null
        }
        else if(p->data<head->data)//在头节点前插入
        {
            p->next=head;//将p挂在head前面
            head=p;//p变成新的head
        }
        else
        {
            zhao=head;//将找位置的指针先放在最前面，一个一个找
            while(p->data>zhao->data&&zhao!=NULL)
            {
                pre=zhao;//把前面的位置也要找到，记录下来
                zhao=zhao->next;//往后走
            }
            pre->next=p;
            p->next=zhao;
         while(head!=NULL)
         {
             printf("%3d",p->data);
             p=p->next;
         }



        }
    }
}
