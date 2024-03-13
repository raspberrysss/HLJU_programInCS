#include<stdio.h>
#include<stdlib.h>
#include<string.h>//直接在主函数尾插
struct you
{
    int data;
    struct you *next;
};
int main()
{
  struct you *head,*pr,*p,*h;//p是新建节点，pr是尾指针
  head=NULL;//头指针为空，可以这样定义
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      p=(struct you *)malloc(sizeof(struct you));
      scanf("%d",&p->data);
      p->next=NULL;//!节点要指向空，否则循环无法停止
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
   h=head;//不用h也可以，直接head也可以
  while(h!=NULL)
  {
      printf("%2d",h->data);
      h=h->next;
  }
}
