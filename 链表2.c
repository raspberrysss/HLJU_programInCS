#include<stdio.h>
#include<stdlib.h>
#include<string.h>//ֱ����������β��
struct you
{
    int data;
    struct you *next;
};
int main()
{
  struct you *head,*pr,*p,*h;//p���½��ڵ㣬pr��βָ��
  head=NULL;//ͷָ��Ϊ�գ�������������
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      p=(struct you *)malloc(sizeof(struct you));
      scanf("%d",&p->data);
      p->next=NULL;//!�ڵ�Ҫָ��գ�����ѭ���޷�ֹͣ
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
   h=head;//����hҲ���ԣ�ֱ��headҲ����
  while(h!=NULL)
  {
      printf("%2d",h->data);
      h=h->next;
  }
}
