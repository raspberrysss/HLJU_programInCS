#include<stdio.h>//Ҫʵ�ֱ�����߲��룬֮ǰʵ�ֹ��źõ������ٲ���
#include<stdlib.h>//ϵ������ȫ���㣬Ϊʲô��
typedef struct jiedian
{
   float x;
   int z;
   struct jiedian *next;
}j;
j* creat( )
{
    j *head,*per,*zhao,*p;
    head=NULL;
    int i,n;
    printf("how many the node do you want to build\n");
    scanf("%d",&n);
    printf("please input the x and z\n");
    for(i=0;i<n;i++)
    {
       p=(j*)malloc(sizeof(j*));
       //p2=(j*)malloc(sizeof(j*));����Ҫ������������һ����ַ��������������������һ����ַ����
       scanf("%d%d",&p->x,&p->z);
       //p->next=NULL;//����ҲҪָ��գ��������
       if(p->x==0)
       {
           continue;
       }
       if(head==NULL)
       {
          head=p;//���ͷָ��Ϊ�գ����´����Ľڵ�Ϊ�ʼ�Ľڵ�
          p->next=NULL;//�µ�ͷָ���nextָ��ָ�գ����ⷢ������
       }
       else if(p->z<head->z)//�¼���Ľڵ��ͷָ��С
       {
           p->next=head;//��p����ͷָ��֮ǰ����p��nextָ��head
           head=p;//�µ�ͷָ����p
       }
       else//�������м�������Ҳ����p�������������p����
       {
           zhao=head;//�õ�Ѱ��ָ���ǰָ�룬�������Ƕ���ǰ�棬ͷָ���λ�ã�Ȼ�����Ѱ��
           per=head;
           while(zhao!=NULL&&p->z>zhao->z)//��û���겢��û�ҵ���p�ڵ�����ֵʱ
           {
               per=zhao;//�ȼ�¼����ǰָ�룬ÿ�Ƚ�һ�μ�¼һ��
               zhao=zhao->next;//��Ѱ��ָ�벻�Ϻ��ƣ��������Ƚ�
           }//����whileѭ�����˳�ʱ�������ֿ���
           /*����Ĳ������Ҳ�����𣿣�per->next=p;p->next=zhao;*/
           per->next=p;//!��Ҫ���ǣ�����������ǰָ��һ��ָ��ڵ�
           if(zhao==NULL)//һ�ֿ������ҵ�ͷҲû�ҳ���
           {
               p->next=NULL;//��p��βָ�룬ֱ��ָ���
           }
           else//��һ�ֿ������ҵ��˱�p����ֵ�������
           {
              p->next=zhao;//��pָ��Ѱ��ָ��
           }
       }
    }
    return head;
}
void output(j*head)
{
    j* p;
    p=head;
    while(p!=NULL)
    {
        printf("%3d%3d",p->x,p->z);
        p=p->next;
    }
}
j* add(j* heada,j* headb)
{
    int temp;
    j *lc;
    j *pa,*pb,*pc;//���ָ��
    lc=heada;
    pa=heada->next;
    pb=headb->next;
    pc=lc;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->z<pb->z)//Ѱ�ҽ�С��ָ������ָ����С�Ĳ���c
        {
            pc->next=pa;
            pa=pa->next;//�����ĸ��ĸ�ָ��ڵ�����ƶ�һλ
            pc=pc->next;
        }
        else if(pa->z==pb->z)
        {
            temp=pa->x+pb->x;
            if(temp!=0)
            {
                pa->x=temp;
                pc->next=pa;
                pa=pa->next;
                pb=pb->next;
                pc=pc->next;
            }
            else
            {
                pa=pa->next;
                pb=pb->next;
            }
        }
        else
        {
            pc->next=pb;
            pb=pb->next;
            pc=pc->next;
        }
    }
    return lc;
}
int main()
{
    j*p;
    j *heada;
    j *headb;
    j *headc;
    printf("please creat a\n");
    heada=creat();
    printf("please output the a\n");
    output(heada);
    printf("\n");
    printf("please creat b\n");
    headb=creat();
    printf("please output the b\n");
    output(headb);
    printf("\n");
    printf("afer adding,this is a\n");
    headc=add(heada,headb);
    output(headc);

}
