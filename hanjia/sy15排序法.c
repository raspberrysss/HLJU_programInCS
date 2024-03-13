#include<stdio.h>//先建立链表再排序,这个好像很难，哭了
#include<stdlib.h>
typedef struct jiedian
{
   int x;
   int z;
   struct jiedian * next;
}j;

j* creat(int n)
{
   int i;
   j* p;
   j*head,*pr;
   head=NULL;
   for(i=0;i<n;i++)
   {
       p=(j*)malloc(sizeof(j));
       printf("请输入系数与指数\n");
       scanf("%d%d",&p->x,&p->z);
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
int main()
{
  j *heada,*headb;
  int n;
  printf("建立链表a\n");
  printf("请输入想要建立的节点数\n");
  scanf("%d",&n);
  heada=creat(n);


}
