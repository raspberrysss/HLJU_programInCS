#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student//�ú�������β��
{
    long id;
    struct student *next;
}s_node;
s_node* creat_after(int n)
{
    s_node *head=NULL,*p,*pr;//β��㲻һ��Ϊ�գ����������ȶ��壬����ֵ
    int i;
    for(i=0;i<n;i++)
    {
        p=(s_node*)malloc(sizeof(s_node));
        printf("input id\n");
        scanf("%ld",&p->id);//ֻ���ýṹ��ָ���ʱ������->
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
