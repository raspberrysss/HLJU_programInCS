#include<iostream>
#include"link_cycle00.h"

using namespace std;

Node::Node()
{
    data=0;
    next=NULL;
}

void Node::set_data()
{
    cin>>data;
}

void Node::set_next(Node* p)
{
    next=p;
}

int Node::get_data()
{
    return data;
}

Node* Node::get_next()
{
    return next;
}

void Node::show_data()
{
    cout<<data<<" ";
}

Link_cycle::Link_cycle()
{
    tail=NULL;
    length=0;
}

void Link_cycle::creat_link_c(int n)//无头结点的尾插，再连到头结点
{
       //Node *text=new Node;
       //cout<<text->get_data()<<endl;
        length=n;
        Node *p_h;//建立一个头指针辅助创建链表
        p_h=NULL;
        cout<<"请依次输入您想建立的链表的元素"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            Node *p=new Node;
            p->set_data();
            p->set_next(NULL);
            if(p_h==NULL)
            {
                p_h=p;
                tail=p;
            }
            else
            {
                tail->set_next(p);
                tail=p;
            }
        }
        tail->set_next(p_h);//连到头结点
}

void Link_cycle::show_link()
{
    Node *p;
    p=tail->get_next();
    do
    {
        p->show_data();
        p=p->get_next();
    }while(p!=tail->get_next());//!用do while循环，才能输出所有结点的内容  对啦！
     cout<<endl;
        /*链表建立正常，但是输出总陷入循环
        Node *p;
        p=NULL;
        while(p!=tail->get_next())
        {
            p=tail->get_next();//因为每次循环都等于它了，所以出不来！
            p->show_data();
            p=p->get_next();
        }*/
}

void Link_cycle::delete_pre(int node_d)
{

    Node *find_p,*pre,*p_pre;
    find_p=tail;
    pre=tail;
    p_pre=tail;
    //若用户输入的数不存在，用i记录循环次数，和length进行对比，写完主要的再写
    while(find_p->get_data()!=node_d)//先找到结点,退出循环时find_p指向node_d所在的结点
    {
        p_pre=pre;
        pre=find_p;//记录前驱结点
        find_p=find_p->get_next();
    }
    //第一轮循环和不进入循环的情况，p_pre不会指在想让它指向的位置
    if(tail->get_data()==node_d)//tail即是要找的结点，不进入循环的情况
    {

        while(pre->get_next()!=tail)//找到tail的前前置和前置，p_pre,pre
        {
            p_pre=pre;
            pre=pre->get_next();
        }
    }
    else if(find_p==tail->get_next())//只进行了一次循环，要删掉的是tail
    {
        while(p_pre->get_next()!=tail)//找到tail前置,放到p_pre里，pre就是tail
        {
            p_pre=p_pre->get_next();
        }
        pre=tail;
    }
    p_pre->set_next(find_p);
    pre->set_next(NULL);
    if(pre==tail)
    {
        tail=p_pre;
    }
    delete pre;
}//自己写对啦，没到网上找资料！牛牛牛！

Node_c::Node_c()
{
    data='n';//''字符“”字符串?
    next=NULL;
}

void Node_c::set_data()
{
     //cin.getchar()=data;
    cin>>data;
}

void Node_c::set_next(Node_c *p)
{
    next=p;
}

char Node_c::get_data()
{
    return data;
}

Node_c *Node_c::get_next()
{
    return next;
}

void Node_c::show_data()
{
    cout<<data<<" ";
}

List_ch::List_ch()
{
    length=1;
    head=&nch;
    nch.set_next(NULL);
}

void List_ch::creat_tail()
{
    cout<<"请输入链表元素个数"<<endl;//!问！空格和回车不清晰
    int n;
    cin>>n;
    length=length+n;
    int i;
    Node_c *tail;
    tail=head;
    cout<<"请依次输入元素的值"<<endl;
    for(i=0;i<n;i++)
    {
        Node_c *p=new Node_c;
        p->set_data();
        p->set_next(NULL);
        tail->set_next(p);
        tail=p;
    }
}

void List_ch::show_tail()
{
   Node_c *h=head->get_next();
   while(h!=NULL)
   {
       h->show_data();
       h=h->get_next();
   }
   cout<<endl;
}

void List_ch::classify(List_ch &L1,List_ch &L2)
{
    Node_c *p,*t1,*t2;//遍历指针和它的前置指针，方便断开它,两个尾指针，尾插
    t1=L1.head;
    t2=L2.head;
    Node_c *pre;
    pre=head;//pre最开始指向头结点
    p=head->get_next();//从头结点的下一个开始遍历
    while(p!=NULL)
    {
            if(p->get_data()>='0'&&p->get_data()<='9')//若是数字字符
            {
               // head->set_next(p->get_next());//!这条语句有问题，若第一个特殊字符，第二遍时越过了第一个字符
                t1->set_next(p);
                t1=p;
                p=p->get_next();
            }
            else if((p->get_data()>='a'&&p->get_data()<='z')||(p->get_data()>='A'&&p->get_data()<='Z'))
            {
                //head->set_next(p->get_next());
                t2->set_next(p);
                t2=p;
                p=p->get_next();
            }
            else
            {
               //!问！如何用两个指针实现！head->set_next(p);//!加到这里也不对，这样只能得到一个其他字符
                pre=p;
                p=p->get_next();//这样写只有最后是其他字符时才有作用，不然会崩溃
            }
    }
    //最后改变当前尾指针，让其指向新的地方，断开之前的指向
    t1->set_next(L1.head);
    t2->set_next(L2.head);//变成循环链表
    pre->set_next(head);

}//又是完全自己的思路！棒！

void List_ch::classify2(List_ch &L1,List_ch &L2,List_ch &L3)
{
    Node_c *p,*t1,*t2,*t3;//遍历指针和它的前置指针，方便断开它,两个尾指针，尾插
    t1=L1.head;
    t2=L2.head;
    t3=L3.head;
   /* Node_c *pre;
    pre=head;//pre最开始指向头结点*/
    p=head->get_next();//从头结点的下一个开始遍历
    while(p!=NULL)
    {
            if(p->get_data()>='0'&&p->get_data()<='9')//若是数字字符
            {
               // head->set_next(p->get_next());//!这条语句有问题，若第一个特殊字符，第二遍时越过了第一个字符
                t1->set_next(p);
                t1=p;
                p=p->get_next();
            }
            else if((p->get_data()>='a'&&p->get_data()<='z')||(p->get_data()>='A'&&p->get_data()<='Z'))
            {
                //head->set_next(p->get_next());
                t2->set_next(p);
                t2=p;
                p=p->get_next();
            }
            else
            {
               t3->set_next(p);
               t3=p;
               p=p->get_next();
            }
    }
    //最后改变当前尾指针，让其指向新的地方，断开之前的指向
    t1->set_next(L1.head);
    t2->set_next(L2.head);//变成循环链表
    t3->set_next(L3.head);

}//又是完全自己的思路！棒！

void List_ch::show_classify_cycle()
{
    Node_c *h=head->get_next();
    while(h!=head)//有头结点就不用dowhile循环了
    {
        h->show_data();
        h=h->get_next();
    }
    cout<<endl;
}

D_node::D_node()
{
    data="no name";
    freq=0;
    prior=NULL;
    next=NULL;
}

string D_node::get_data()
{
    return data;
}

int D_node::get_freq()
{
    return freq;
}

D_node* D_node::get_prior()
{
    return prior;
}

D_node* D_node::get_next()
{
    return next;
}

void D_node::set_data()
{
    cin>>data;
}

void D_node::set_freq(int f)
{
    freq=f;
}

void D_node::add_freq()
{
    freq++;
}

void D_node::set_prior(D_node * p)
{
    prior=p;
}

void D_node::set_next(D_node *n)
{
    next=n;
}

void D_node::show_data_freq()
{
   cout<<"网页名称 "<<data<<" 访问次数 "<<freq<<endl;
}

List_d::List_d()
{
    head=&nd;
    head->set_next(NULL);
    head->set_prior(NULL);
}

void List_d::creat_tail()
{
    D_node *tail;//尾指针
    tail=head;//尾指针，指向头结点
    int n;
    cout<<"请输入新建链表的元素个数"<<endl;
    cin>>n;
    length=length+n;
    int i;
    cout<<"请依次输入链表网页名称"<<endl;
    for(i=0;i<n;i++)
    {
        D_node *p=new D_node;
        p->set_data();
        p->set_freq(0);
        p->set_next(NULL);
        p->set_prior(NULL);//!???封装好p指针指向的区域!是否没有必要，初始化的时候已经初始好了
        tail->set_next(p);
        p->set_prior(tail);
        tail=p;
    }
    tail->set_next(NULL);
}

void List_d::show_list_d()
{
        cout<<"您目前建立的链表如下"<<endl;
        D_node *p=head->get_next();//从头指针的下一个开始遍历
        while(p!=NULL)
        {
            p->show_data_freq();
            p=p->get_next();
        }
}

void List_d::locate(string d)
{
    cout<<"您访问了"<<d<<"网站一次"<<endl;
    D_node *find_p;//寻找指针，找到位置，使其freq增加1；
    find_p=head->get_next();//从头结点的后一个开始找
    while(find_p!=NULL&&find_p->get_data()!=d)
    {
        find_p=find_p->get_next();
    }
    if(find_p==NULL)
    {
        cout<<"当前网站不在链表中"<<endl;
        exit(0);
    }
    else
    {
        find_p->add_freq();
        //寻找和增加频度没有问题 cout<<find_p->get_data()<<" "<<find_p->get_freq()<<" "<<endl;
    }
    //!插入，找频率大于当前变换频率结点的结点，把当前结点插入找到的结点之后
    D_node *find_pre;
    find_pre=find_p->get_prior();//从增加频率的结点之前找，因为前面的全都是频率增加过的
    while(find_pre->get_prior()!=NULL&&find_pre->get_freq()<=find_p->get_freq())//!第一个条件是找到头结点还没有频率大的，即第一次插入，退出循环时find_pre是头结点
    {
       find_pre=find_pre->get_prior();//若没有，向前移动，直到找到
    }
    if(find_p->get_next()==NULL)
    {
        find_p->get_prior()->set_next(NULL);

    }//!若find_p是尾指针，把它断开的代码和正常的不一样
    else
    {
        find_p->get_prior()->set_next(find_p->get_next());
        find_p->get_next()->set_prior(find_p->get_prior());//把find_p前后连上
    }
    //!上面把find_p断开，接下来，把它连在find_pre与其后继后面
    find_p->set_prior(find_pre);
    find_p->set_next(find_pre->get_next());
    find_pre->get_next()->set_prior(find_p);//!这句一定要在下一句之前，不然找不到此节点的下一个结点了
    find_pre->set_next(find_p);
    /*
    //!把频率增加的结点插到最高频率之后
    D_node *find_pre;
    find_pre=find_p;
    while(find_pre->get_prior()!=NULL&&find_pre->get_prior()->get_freq()<=find_p->get_freq())
    {
        find_pre=find_pre->get_prior();
    }
    cout<<find_pre->get_freq();
    if(find_p->get_next()==NULL)
    {
        find_p->get_prior()->set_next(NULL);//前一个的next指针指空
        find_p->set_prior(NULL);//把find_p全部摘除
        find_p->set_next(NULL);
    }
    find_p->get_prior()->set_next(find_p->get_next());
    find_p->get_next()->set_prior(find_p->get_prior());//把find_p前后连上
    find_p->set_prior(find_pre);//把find_p放在头结点和头结点下一个结点之间
    find_p->set_next(find_pre->get_next());
    find_pre->get_next()->set_prior(find_p);//!这一步的顺序不能在前，不然找不到find_pre的后一结点！
    find_pre->set_next(find_p);
     */
}

void menu()
{
    cout<<"1.测试循环单链表删除直接前驱结点"<<endl;
    cout<<"2.测试分类链表"<<endl;
    cout<<"3.测试带频度链表"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}
