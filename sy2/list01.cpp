#include<iostream>
#include"list00.h"

using namespace std;

//指针可以用*，元素可以用&互相转换利用函数
Node::Node()
{
    data=0;
    next=NULL;
}

Node* Node::get_next()
{
    return next;
}

int Node::get_data()
{
    return data;
}

void Node::set_next(Node * next_n)
{
    next=next_n;
}

void Node::set_data()
{
    cin>>data;
}

void Node::set_data2(int data_n)
{
    data=data_n;
}

void Node::show_data()
{
    cout<<data<<" ";
}

List::List()
{
    head=&nh;//头指针指向头结点
    nh.set_next(NULL);//头结点的next为空
    length=1;//头结点
    /*head=new Node;
    //Node nh;*head=nh;//头指针指向头结点
    (*head).set_next(NULL);//头结点的next指向null
    length=1;//头结点*/
}

void List::creat_list_tail(int n)
{
        //Node no;
        length=length+n;
        Node * tail;//尾指针
        tail=&nh;//尾指针先指向头结点
        tail->set_next(NULL);
        int i;
        cout<<"请依次有序输入数值"<<endl;
        for(i=0;i<n;i++)
        {
            Node *p=new Node;//开辟空间，p指向这个新空间进行接下来的操作
            p->set_data();
            p->set_next(NULL);
            tail->set_next(p);//把p挂在尾指针上
            tail=p;//尾指针改变
           //!不new一个交给指针，直接生成一个可行吗？等有时间自己试下
           /* Node no;
            no.set_data();
            no.set_next(NULL);
            tail->set_next(&no);
            tail->show_data();
            tail=&no;*/
        }
}

void List::show_list()
{
    Node* h=nh.get_next();//从头结点的后一个开始展示
    while(h!=NULL)
    {
        (*h).show_data();//h->show_data();
        h=h->get_next();
    }
    //cout<<endl<<length;
    cout<<endl;
}

void List::insert_list(int node_d)//
{
    length++;
    Node * find_p;//寻找指针
    Node * pre;//前置指针，方便插入，是要插入的地方的前一个地方
    pre=&nh;//!pre指针指向头结点，统一查找方式，nh的地址也是head
    find_p=nh.get_next();//从头结点的下一个结点开始找
    Node *no=new Node;//给要插入的元素套壳子
    no->set_data2(node_d);
    no->set_next(NULL);
    /*if(pre->get_data()>node_d)
    {
        no->set_next(find_p);
        pre=no;
        find_p=no;
    }*/
    //!find_p!=NULL要放在前面，不然无法退出循环?&&判断了一个就会不判断后面的了
    //!当find_p==NULL时，find_p->get_data()会崩溃，导致无法退出循环，所以判断要放在前面
    while(find_p!=NULL&&find_p->get_data()<node_d)//指针指向地方的数值小于要插入的，并且没找完，就继续找
    {
        pre=find_p;
        find_p=find_p->get_next();
        //cout<<find_p<<endl;
        //!用null访问，很危险 cout<<find_p->get_data()<<endl;
    }
    //cout<<"1"<<endl;
    //跳出循环，两种可能，到末尾了，找到位置了
    //到末尾时是find_p是null，pre是链表最后一个结点

   /* if(find_p==NULL)
    {
        pre->set_next(no);
        no->set_next(NULL);
    }*/
    pre->set_next(no);
    no->set_next(find_p);
    /*!no->set_next(pre->get_next());
       pre->set_next(no)  若这样写的话顺序不能变，不然pre的指针域发生变化*/
    //pre->set_next(no);//把no挂在前置指针上
    //no->set_next(find_p);//后面的指针挂在no上*/
}

void List::reverse_l()
{
    //一个指针遍历链表结点，把每个结点头插到前个结点，最后一个结点再与头结点尾部相连
    Node * pre,*p;//p是遍历指针，pre记录前面的结点，方便头插
    p=head->get_next();//pre=nh.get_next();一样，指向头结点的指针就是head
    //pre=head;
    head->set_next(NULL);//断开头结点
    while(p!=NULL)//没到最后一个结点就不停止头插
    {
        pre=p;
        p=p->get_next();//往后移动一位
        pre->set_next(head->get_next());//下面两条语句是头插
        head->set_next(pre);
    }
    //第一遍是让逆置后的最后一位置空
    //!不断断开head指向后面的指针，让其连到新的结点上，直到逆置完成！
}

void List::add_list_decline(List &L1)//比较，小的往前面放
{
        Node * p1,*p2;//比较指针
        Node *r;
        r=NULL;
      // Node *pre;
      // pre=NULL;
        p1=head->get_next();
        p2=L1.head->get_next();//从首元结点开始比较
        head->set_next(NULL);//头结点的next置空，便于后续头插
        L1.head->set_next(NULL);
        while(p1!=NULL&&p2!=NULL)//两者都不为空时进行比较头插,第一遍最小的next先置空再插到头结点后面，然后后面小的不断往头和1之间头插，最后最大的头插进来，从头结点看递减
        {
            if(p1->get_data()<p2->get_data())
            {
                r=p1->get_next();
                p1->set_next(head->get_next());//最开始head->next为空
                head->set_next(p1);
                p1=r;
                /*pre=p1;
                p1=p1->get_next();//往后移动一位
                pre->set_next(head->get_next());//让逆置后的最后一位置空
                head->set_next(pre);*/

            }
            else
            {
                /*pre=p2;
                p2=p2->get_next();//往后移动一位
                pre->set_next(L1.head->get_next());//让逆置后的最后一位置空
                L1.head->set_next(pre);*/
                r=p2->get_next();
                p2->set_next(head->get_next());//头插
                head->set_next(p2);
                p2=r;
            }
        }
        //当有一个链表为空时，退出循环
        while(p1!=NULL)//将不为空的链表按照原本的顺序头插在此时尾结点的后面
        {
            /* pre=p1->get_next();
            p1->set_next(head->get_next());
            head->set_next(p1);
            p1=pre;*/
            r=p1->get_next();
            p1->set_next(head->get_next());
            head->set_next(p1);
            p1=r;
        }
        while(p2!=NULL)
        {
            /*pre=p2->get_next();
            p2->set_next(L1.head->get_next());
            L1.head->set_next(p2);
            p2=pre;*/
            r=p2->get_next();
            p2->set_next(L1.head->get_next());
            L1.head->set_next(p2);
            p2=r;
        }

}

void List::reverse_me()//!问！
{
    Node *p,*pre;
    pre=head->get_next();
    p=head->get_next()->get_next();//p=pre->get_next();
    pre->set_next(NULL);
    head->set_next(NULL);
    while(p!=NULL)
    {
        p->set_next(pre);
        head->set_next(p);
        p=p->get_next();//!不能先插入后移动，这样后面的位置就是错误的！！！
        pre=p;
    }
}

void List::add_me(List &L1)
{
    Node *find_p1,*find_p2;
    Node *t;//有一个指针来记录下一个位置，方便移动
    t=NULL;
    find_p1=head->get_next();
    find_p2=L1.head->get_next();
    head->set_next(NULL);
    L1.head->set_next(NULL);
    while(find_p1&&find_p2)
    {
        if(find_p1->get_data()<find_p2->get_data())//小的先头插
        {
            t=find_p1->get_next();
            find_p1->set_next(head->get_next());
            head->set_next(find_p1);//!不要忘记这条语句，头插头结点一定要连上，保证头结点在第一位
            find_p1=t;
        }
        else
        {
            t=find_p2->get_next();
            find_p2->set_next(L1.head->get_next());
            L1.head->set_next(find_p1);//!不要忘记这条语句，头插头结点一定要连上，保证头结点在第一位
            find_p2=t;
        }//同上
    }
    while(find_p1!=NULL)//退出循环，第一条链表还不为空，把它剩下的所有结点头插
    {
        //直接头插，和上面一样的四条语句
            t=find_p1->get_next();
            find_p1->set_next(head->get_next());
            head->set_next(find_p1);//!不要忘记这条语句，头插头结点一定要连上，保证头结点在第一位
            find_p1=t;
    }
    while(find_p2!=NULL)
    {
            t=find_p2->get_next();
            find_p2->set_next(L1.head->get_next());
            L1.head->set_next(find_p1);//!不要忘记这条语句，头插头结点一定要连上，保证头结点在第一位
            find_p2=t;
    }

}

void menu()
{
    cout<<"1.测试插入算法"<<endl;
    cout<<"2.测试逆置算法"<<endl;
    cout<<"3.测试合并链表"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;
}
