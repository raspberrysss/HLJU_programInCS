#include<iostream>
#include"link00.h"

 using namespace std;

Node::Node()
{
    data=0;
    next=NULL;
}

void Node::setdata()
{
    cout<<"��������Ҫ��ӵ�����"<<endl;
    cin>>data;
}

void Node::setnext(Node*p)
{
    next=p;
}

int Node::getdata()
{
    return data;
}

Node * Node::getnext()//p->next
{
    return next;
}

void Node:: setdata_inter(int x)
{
    data=x;
}

void Node:: setdata_delete(int x)
{
    data=x;
}

Node::~Node()
{
    cout<<data<<"������"<<endl;
}



Link::Link()//����һ��������ͷָ��Ϊ��
{
    head=NULL;
    num=0;
}

void Link::creatlink(int n)//Ŀǰ�޷���������ֻ������β��,�������������Ҫβָ����,��Ҫ
{//βָ��������Ƿ�����һ�����ϵ�ָ���ҵ��ط���Ҫ��Ȼ��Ҫ��ͷ�ҵ�β
  //����β��
    Node * tail=new Node;//����һ��ָ�룬����һ���ڴ�ռ䣬��Ȼ���о���
    tail->setnext(NULL);
    int i;
    num=n;
    for(i=0;i<n;i++)
    {
         Node * p=new Node;
         p->setdata();
         p->setnext(NULL);//p->next=NULL
         //no[i].setdata();//�������Ա���ʣ���ָ��Ӧ�ø���Щ
         if(head==NULL)
         {
              head=p;
             //p->setnext(head);
              //no[i].setnext(head);
         }
         else
         {
             tail->setnext(p);//tail->next=p
            // no[i].setnext(p);
         }
         tail=p;
    }
    //delete tail;�������л������룿��delete�й���Ϊʲô
    //����ôdelete p��
}


Node *Link::gethead()
{
    return head;
}

void Link::output()
{
     Node *h=head;
      while(h!=NULL)
      {
          cout<<h->getdata()<<" ";
          h=h->getnext();

      }
}

void Link::insert_link(int x)
{
    Node * pre=new Node;//��������ǰ���ڵ�
    Node *tail=new Node;//βָ��
    tail=head;
    while(tail->getnext()!=NULL)//����д���ˣ����ˣ��Լ��Ĺ����ģ�Ҳ�ǰ����Լ����뷨д�ģ��������
    {
        tail=tail->getnext();
    }
    Node *p=new Node;
    p->setdata_inter(x);
    p->setnext(NULL);
    if(head==NULL)
    {
        head=p;
    }
    else if(p->getdata()<head->getdata())
    {
         p->setnext(head);
         head=p;
    }
    else if(p->getdata()>tail->getdata())
    {
        tail->setnext(p);
        tail=p;
    }
    else//���м�
    {
         pre=head;//��ͷ��ʼ��
         Node * p_pre=new Node;
         p_pre=head;
         while(pre->getdata()<p->getdata())
         {
             p_pre=pre;
             pre=pre->getnext();

         }
         p_pre->setnext(p);
         p->setnext(pre);

         /*Node * p_pre=new Node;
         p_pre->setnext(NULL);
         p_pre->setnext(pre);
         p_pre->setnext(p);
         p->setnext(pre);*///���������任next��ppreҲҪ����ѭ����һ��
    }


}

void Link::delete_link(int x)
{

    //Node *p=new Node;
    Node *pre=new Node;
    //Node *tail=new Node;
    Node *q=new Node;
    pre=NULL;
    q=NULL;
   /* while(tail->getnext()!=NULL)
    {
        tail=tail->getnext();
    }*/
   // p->setdata_delete(x);
    //p->setnext(NULL);
    if(head==NULL)
    {
        cout<<"����Ϊ�գ��޷�����ɾ������"<<endl;
    }
    else if(head->getdata()==x)
    {
        pre=head;//��һ��ָ���ͷָ������ݣ��ٰ�ͷָ�������ƣ����Ѵ���ԭͷָ�������ɾ��
        head=head->getnext();
        delete pre;
    }
    else
    {
        q=head;//��ͷ����
        while(q!=NULL&&q->getdata()!=x)//��û���겢��û�ҵ��������
        {
            pre=q;
            q=q->getnext();//��ǰһ���������ݣ�һ��������
        }
        if(q!=NULL)//�ҵ���
        {
               // pre->getnext()=q->getnext();//��������������,�������У��漰����ֵ��ֵ�����⣿
               pre->setnext(q->getnext());
                delete q;
        }
        else
        {
            cout<<"û�з�����Ҫɾ��������"<<endl;
        }
    }

}
Link::~Link()
{
    cout<<"����link��������"<<endl;
}



