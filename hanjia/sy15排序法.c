#include<stdio.h>//�Ƚ�������������,���������ѣ�����
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
       printf("������ϵ����ָ��\n");
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
  printf("��������a\n");
  printf("��������Ҫ�����Ľڵ���\n");
  scanf("%d",&n);
  heada=creat(n);


}
