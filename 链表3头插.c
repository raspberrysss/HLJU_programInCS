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
  // t=head;//Ϊʲô����ֶ��ˣ�
   while(p!=NULL)//ͷ����β�岻ͬ�������ʱ��head�Ѿ������p�����Դ�p��ʼ���?,������head�жϣ����ǲ��ܰ�head����t
   {
       printf("%2d",p->data);
       p=p->next;//�������ص㣬Ҫ��Ӧ��ǰ���������p��pnext��t��t
   }

}
