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
    cout<<"请输入想要添加的数据"<<endl;
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
    cout<<data<<"被析构"<<endl;
}



Link::Link()//建立一个空链表，头指针为空
{
    head=NULL;
    num=0;
}

void Link::creatlink(int n)//目前无法做到排序，只能正常尾插,这样的情况还需要尾指针吗？,需要
{//尾指针的作用是方便下一个接上的指针找到地方，要不然还要从头找到尾
  //正常尾插
    Node * tail=new Node;//定义一个指针，开辟一段内存空间，不然会有警告
    tail->setnext(NULL);
    int i;
    num=n;
    for(i=0;i<n;i++)
    {
         Node * p=new Node;
         p->setdata();
         p->setnext(NULL);//p->next=NULL
         //no[i].setdata();//用数组成员访问，用指针应该更好些
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
    //delete tail;加上这行会有乱码？与delete有关吗，为什么
    //？怎么delete p呢
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
    Node * pre=new Node;//用它来找前驱节点
    Node *tail=new Node;//尾指针
    tail=head;
    while(tail->getnext()!=NULL)//终于写对了，哭了，自己改过来的，也是按照自己的想法写的，我真棒！
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
    else//在中间
    {
         pre=head;//从头开始找
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
         p->setnext(pre);*///不能生生变换next，ppre也要跟着循环走一遍
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
        cout<<"数据为空，无法进行删除操作"<<endl;
    }
    else if(head->getdata()==x)
    {
        pre=head;//找一个指针放头指针的数据，再把头指针往后移，最后把带有原头指针的数据删掉
        head=head->getnext();
        delete pre;
    }
    else
    {
        q=head;//从头开找
        while(q!=NULL&&q->getdata()!=x)//在没找完并且没找到的情况下
        {
            pre=q;
            q=q->getnext();//用前一个储存数据，一个接着找
        }
        if(q!=NULL)//找到了
        {
               // pre->getnext()=q->getnext();//把相邻两个连上,这样不行，涉及到左值右值的问题？
               pre->setnext(q->getnext());
                delete q;
        }
        else
        {
            cout<<"没有发现想要删除的数据"<<endl;
        }
    }

}
Link::~Link()
{
    cout<<"调用link析构函数"<<endl;
}



