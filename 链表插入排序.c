#include<stdio.h>//ԭ�����Ҳ�����⣬�һ��ο����������������
#include<stdlib.h>//���������ʱ��û���ã��䲻����
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
            //p->next=NULL;//���п��ޣ�ͨ��forѭ��Ҳ����ָ��null
        }
        else if(p->data<head->data)//��ͷ�ڵ�ǰ����
        {
            p->next=head;//��p����headǰ��
            head=p;//p����µ�head
        }
        else
        {
            zhao=head;//����λ�õ�ָ���ȷ�����ǰ�棬һ��һ����
            while(p->data>zhao->data&&zhao!=NULL)
            {
                pre=zhao;//��ǰ���λ��ҲҪ�ҵ�����¼����
                zhao=zhao->next;//������
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
