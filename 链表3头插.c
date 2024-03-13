#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct you
{
    int data;
    struct you *next;
};
int main()
{
   struct you *head,*p,*t;
   head=NULL;
   int i,n;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       p=(struct you *)malloc(sizeof(struct you));
       scanf("%d",&p->data);
       p->next=NULL;
       if(head==NULL)
       {
           head=p;
       }
       else
       {
           p->next=head;
           head=p;
       }
   }
  // t=head;//为什么这次又对了？
   while(p!=NULL)//头插与尾插不同，输出的时候head已经变成了p，所以从p开始输出?,可以由head判断，但是不能把head赋给t
   {
       printf("%2d",p->data);
       p=p->next;//这里是重点，要对应！前面输出的是p就pnext，t就t
   }

}
