#include<stdio.h>//要实现边排序边插入，之前实现过排好的链表再插入
#include<stdlib.h>//系数输入全是零，为什么？
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
       //p2=(j*)malloc(sizeof(j*));不需要用两个变量，一个地址包含两个变量，可以用一个地址访问
       scanf("%d%d",&p->x,&p->z);
       //p->next=NULL;//这里也要指向空，避免出错！
       if(p->x==0)
       {
           continue;
       }
       if(head==NULL)
       {
          head=p;//如果头指针为空，则新创建的节点为最开始的节点
          p->next=NULL;//新的头指针把next指针指空，避免发生错误
       }
       else if(p->z<head->z)//新加入的节点比头指针小
       {
           p->next=head;//把p挂在头指针之前，让p的next指向head
           head=p;//新的头指针变成p
       }
       else//包括在中间的情况，也包括p在最后的情况，将p插入
       {
           zhao=head;//用到寻找指针和前指针，先让它们都在前面，头指针的位置，然后进行寻找
           per=head;
           while(zhao!=NULL&&p->z>zhao->z)//在没找完并且没找到比p节点大的数值时
           {
               per=zhao;//先记录下来前指针，每比较一次记录一下
               zhao=zhao->next;//将寻找指针不断后移，来继续比较
           }//当从while循环中退出时，有两种可能
           /*下面的不分情况也可以吗？，per->next=p;p->next=zhao;*/
           per->next=p;//!不要忘记，无论怎样，前指针一定指向节点
           if(zhao==NULL)//一种可能是找到头也没找出来
           {
               p->next=NULL;//则p是尾指针，直接指向空
           }
           else//另一种可能是找到了比p的数值更大的数
           {
              p->next=zhao;//把p指向寻找指针
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
    j *pa,*pb,*pc;//结点指针
    lc=heada;
    pa=heada->next;
    pb=headb->next;
    pc=lc;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->z<pb->z)//寻找较小的指数，将指数较小的插入c
        {
            pc->next=pa;
            pa=pa->next;//插入哪个哪个指针节点向后移动一位
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
