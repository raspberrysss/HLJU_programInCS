#include<iostream>
#include"List_P00.h"

using std::string;
using std::cout;
using std::endl;

Node_PCB::Node_PCB()
{
    s="0";
    size_p=0;
    b=0;
    next=NULL;
}

Node_PCB::Node_PCB(string s_n,Node_PCB *p,int sp,int bp)
{
    s=s_n;
    size_p=sp;
    b=bp;
    next=p;
}

Node_PCB::~Node_PCB()
{

}

void Node_PCB::set_s(string s_s)
{
    s=s_s;
}

void Node_PCB::set_next(Node_PCB* p_s)
{
    next=p_s;
}

void Node_PCB::set_size(int s)
{
    size_p=s;
}

int Node_PCB::get_size()
{
    return size_p;
}

void Node_PCB::set_b(int bp)
{
    b=bp;
}

int Node_PCB::get_b()
{
    return b;
}

Node_PCB* Node_PCB::get_next()
{
    return next;
}

string Node_PCB::get_s()
{
    return s;
}


Link_PCB::Link_PCB()
{
    head=NULL;
    tail=NULL;
    length=0;
}

Link_PCB::Link_PCB(Node_PCB *l,Node_PCB *t,int lc)
{
    head=l;
    tail=t;
    length=lc;
}

Link_PCB::~Link_PCB()
{

}

void Link_PCB::set_link(Node_PCB *ll,Node_PCB *tl,int lcl)
{
    head=ll;
    tail=tl;
    length=lcl;
}

void Link_PCB::set_head(Node_PCB *sh)
{
    head=sh;
}

void Link_PCB::create_link(std::string s_l,int s,int b)
{
    length++;
    Node_PCB *j=new Node_PCB;//!这里要用指针，new返回的是一个地址
    j->set_s(s_l);
    j->set_size(s);
    j->set_b(b);
    j->set_next(NULL);
    //Node_PCB *tail=NULL;//尾插需要一个一直指向尾的指针
    //Node_PCB *p=NULL;//遍历指针
    if(head==NULL)
    {
        head=j;
    }
    else
    {

        tail->set_next(j);
        /*p=head;
        while(p->get_next()!=NULL)//p!=null
        {
           p->set_next(p->get_next());
        }
        p->set_next(j);
        tail=j;*/
    }
    tail=j;
}

void Link_PCB::show_link()
{
    Node_PCB *show_p;
    show_p=head;
    if(show_p==NULL)
    {
        cout<<" ";
    }
    while(show_p)
    {
        cout<<show_p->get_s()<<"("<<show_p->get_b()<<","<<show_p->get_size()<<") ";
        show_p=show_p->get_next();
        //show_p->set_next(show_p->get_next());
    }

}

bool Link_PCB ::is_empty_list()
{
    if(head==NULL)
    {
        return true;
    }

    return false;
}

int Link_PCB::get_len()
{
    return length;
}

Node_PCB* Link_PCB::get_head()
{
    return head;
}

Node_PCB* Link_PCB::get_tail()
{
    return tail;
}

int Link_PCB::find_from_link(string s_f)
{
    Node_PCB* findf=NULL;//遍历指针
    findf=head;
    if(head==NULL)
    {
        return 4;
    }
    else if(head->get_s()==s_f)
    {

        return 5;
    }
    else
    {
        while(findf->get_next()!=NULL&&findf->get_s()!=s_f)//没到尾并且没找到
            {
                //cout<<"111"<<endl;

                findf=findf->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findf->get_s()==s_f)//找到
            {
                return 5;
            }

            else
            {
                return 6;
            }

    }

}

Node_zone::Node_zone()
{
    begin_z=0;
    size_z=0;
    next=NULL;
    pre=NULL;
}

Node_zone::Node_zone(int b,int s,Node_zone* n,Node_zone* p)
{
    begin_z=b;
    size_z=s;
    next=n;
    pre=p;
}

Node_zone::~Node_zone()
{

}

void Node_zone::set_beginz(int bz)
{
    begin_z=bz;
}

void Node_zone::set_sizez(int sz)
{
    size_z=sz;
}

void Node_zone::set_nextz(Node_zone* nz)
{
    next=nz;
}

void Node_zone::set_prez(Node_zone* pz)
{
    pre=pz;
}

int Node_zone::get_bz()
{
    return begin_z;
}

int Node_zone::get_sz()
{
    return size_z;
}

Node_zone* Node_zone::get_n()
{
    return next;
}

Node_zone* Node_zone::get_pre()
{
    return pre;
}

Link_Zone::Link_Zone()
{
    head_z=NULL;
    tail_z=NULL;
    length_z=0;
}

Link_Zone::Link_Zone(Node_zone *h,Node_zone *t,int l)
{
    head_z=h;
    tail_z=t;
    length_z=l;
}

Link_Zone::~Link_Zone()
{

}

void Link_Zone::create_link_zone(int b,int s)
{
    length_z++;
    Node_zone *p=new Node_zone;
    p->set_beginz(b);
    p->set_sizez(s);
    p->set_nextz(NULL);
    p->set_prez(NULL);
    Node_zone *e=NULL;//遍历指针，方便按开始地址递增排序
    Node_zone *pp=NULL;//遍历指针的前序指针，方便插入
    if(head_z==NULL)
    {
        //cout<<"111"<<endl;
        head_z=p;
        tail_z=p;
    }
    else
    {
        pp=head_z;
        e=head_z;
        while(e!=NULL&&e->get_bz()<p->get_bz())
        {

            pp=e;
            e=e->get_n();
        }
        if(e==NULL)
        {
            tail_z->set_nextz(p);
            p->set_prez(tail_z);
            tail_z=p;
        }
        else if(pp==e)//pp==e e->get_n()==NULL太宽泛，有问题，明早看看
        {
            pp->set_nextz(NULL);
            pp->set_prez(p);
            p->set_prez(NULL);
            p->set_nextz(pp);
           // cout<<head_z->get_bz()<<endl;
            head_z=p;
            tail_z=pp;
        }
        else
        {
            pp->set_nextz(p);
            p->set_prez(pp);
            p->set_nextz(e);
            e->set_prez(p);
        }

    }

}

void Link_Zone::show_link_zone()
{
    cout<<"空闲内存分区：";
    Node_zone *show_z;
    show_z=head_z;
    if(show_z==NULL)
    {
        cout<<" ";
    }
    while(show_z)
    {
        cout<<"("<<show_z->get_bz()<<","<<show_z->get_sz()<<")"<<" ";
        show_z=show_z->get_n();
        //show_p->set_next(show_p->get_next());
    }
    cout<<endl;

}

Node_zone* Link_Zone::get_headz()
{
    return head_z;
}

void Link_Zone::set_headz(Node_zone *z)
{
    head_z=z;
}

int Link_Zone::get_lenz()
{
    return length_z;
}



//用友元函数可行吗？
//new 的什么时候delete
void ready_to_exe_auto(Link_PCB &l1,Link_PCB &l2)//l1 ready l2 exe
{
    if(l2.is_empty_list()&&!l1.is_empty_list())
    {
        //cout<<"111"<<endl;
        //!把ready的头结点摘下，挂到exe的尾结点上
       // Node_PCB *j= new Node_PCB;//存摘下来的节点
       // Node_PCB *pre;//遍历指针
        if(l1.get_len()==1)//只有一个节点
        {
            //cout<<"111"<<endl;
            //j->set_s(l1.get_head()->get_s());
            //j->set_next(NULL);
            l2.create_link((l1.get_head())->get_s(),l1.get_head()->get_size(),l1.get_head()->get_b());//l2连上
            //!先连上再清空，不然head为null，出现错误
            //!写出来了！！！牛牛牛！！！
            l1.set_link(NULL,NULL,0);//l1清空



        }
        else if(l1.get_len()>1)//多个节点，把头结点到执行队列
        {
            l2.create_link(l1.get_head()->get_s(),l1.get_head()->get_size(),l1.get_head()->get_b());
            l1.set_head(l1.get_head()->get_next());
            /*l2.create_link(l1.get_tail()->get_s());
            pre=l1.get_head();
            while(pre->get_next()!=l1.get_tail())
            {
                pre->set_next(pre->get_next());
            }//找tail的前驱
            pre->set_next(NULL);*/

        }

    }
    else
    {
       if(l2.is_empty_list()&&l1.is_empty_list())
       {
           //!删完还会进这个吗？
           //cout<<"执行与就绪均为空"<<endl;
           //不做任何操作
       }
       else if(!l2.is_empty_list())
       {

       }
    }
}

bool block(Link_PCB &l1b,Link_PCB &l2b)//1 exe 2 block
{
    if(l2b.is_empty_list()&&!l1b.is_empty_list())
    {
        string s_b=l1b.get_head()->get_s();
        cout<<s_b<<"已成功进入阻塞态"<<endl;
        l2b.create_link(l1b.get_head()->get_s(),l1b.get_head()->get_size(),l1b.get_head()->get_b());
        l1b.set_link(NULL,NULL,0);
        return true;
    }
    else
    {
        if(!l2b.is_empty_list()&&!l1b.is_empty_list())
        {
            string s_b=l1b.get_head()->get_s();
            cout<<s_b<<"已成功进入阻塞态"<<endl;
            l2b.create_link(l1b.get_head()->get_s(),l1b.get_head()->get_size(),l1b.get_head()->get_b());
            l1b.set_link(NULL,NULL,0);
            return true;
        }
        else
        {
            cout<<"执行链表为空，无法进入阻塞态"<<endl;
            return false;
        }
        //还有都为空，没必要写
    }
}

bool wake(Link_PCB &l1w,Link_PCB &l2w)//1 block 2 ready
{
    //阻塞头放在就绪尾

    if(l1w.is_empty_list())//阻塞为空
    {
        cout<<"阻塞链表为空，无法唤醒"<<endl;
        return false;
    }
   /* else if(!l2w.is_empty_list())
    {
        cout<<"cpu已被占用，无法唤醒"<<endl;
        return false;
    }*/
    else if(!l1w.is_empty_list())
    {
        string s_w=l1w.get_head()->get_s();
        cout<<s_w<<"已成功被唤醒"<<endl;
        l2w.create_link(l1w.get_head()->get_s(),l1w.get_head()->get_size(),l1w.get_head()->get_b());
        l1w.set_link(NULL,NULL,0);
        return true;
    }
    else
        return false;


}

bool time(Link_PCB &l1t,Link_PCB &l2t)//1 exe 2 ready
{
    if(l1t.is_empty_list())//exe为空
    {
        cout<<"执行链表为空"<<endl;
        return false;
    }
    else if(!l1t.is_empty_list())//执行不为空，就绪空不空都行
    {
        string s_t=l1t.get_head()->get_s();
        cout<<s_t<<"时间片已到"<<endl;
        l2t.create_link(l1t.get_head()->get_s(),l1t.get_head()->get_size(),l1t.get_head()->get_b());
        l1t.set_link(NULL,NULL,0);
        return true;
    }
    else
        return false;

}

void show_three(Link_PCB l11,Link_PCB l22,Link_PCB l33)
{
    cout<<"就绪态 ";
    l11.show_link();
    cout<<endl;
    cout<<"执行态 ";
    l22.show_link();
    cout<<endl;
    cout<<"阻塞态 ";
    l33.show_link();
    cout<<endl;
}

bool is_repeat(Link_PCB l1r,Link_PCB l2r,Link_PCB l3r,string sr)
{
    int r1=l1r.find_from_link(sr);
    int r2=l2r.find_from_link(sr);
    int r3=l3r.find_from_link(sr);
    if(r1!=5&&r2!=5&&r3!=5)//都没找到，不重名
    {
        return false;
    }
    else
        {
            return true;
        }

}

bool is_spare(Link_Zone &lz,int size_pcb,int &be_node_pcb)
{
    Node_zone *e=NULL;
    e=lz.get_headz();
    while(e!=NULL&&e->get_sz()<size_pcb)
    {
        e=e->get_n();
    }
    if(e==NULL)
    {
        cout<<"无空闲分配给新进程，创建失败"<<endl;
        return false;
    }
    else
    {
        be_node_pcb=e->get_bz();
        e->set_beginz(e->get_bz()+size_pcb);
        e->set_sizez(e->get_sz()-size_pcb);
        return true;
    }
    //!碎片有问题，98直接分100即可
    /*else//碎片是2的问题
    {
        cout<<"剩下的空间为2kb碎片，无法分配"<<endl;
        return false;
    }*/
}

bool end_exe3(Link_PCB &le,Link_Zone &lz)
{
    if(le.get_head()==NULL)
    {
        return false;//失败
    }
    else
    {
        string s_de=le.get_head()->get_s();
        cout<<s_de<<"已成功中止"<<endl;
        lz.create_link_zone(le.get_head()->get_b(),le.get_head()->get_size());
        //lz.show_link_zone();
        le.set_link(NULL,NULL,0);
        return true;
    }
}

void merge_lz(Link_Zone &lz)
{
        Node_zone *e=NULL;
        Node_zone *c=NULL;
        e=lz.get_headz();
        //c=lz.get_headz();
        if(lz.get_lenz()==1)//只有一个节点
        {
            //cout<<"111"<<endl;
            //和不了
        }
        else if(lz.get_lenz()>1)
        {
            while(e)//遍历
            {
                c=e;
                if(c->get_pre()!=NULL)//把前面变成真正的节点
                {
                    //!c可以跟前面和，？不加这一段也可以，问一下
                    //!需要用到这一段，因为和完后把pre当成新的节点，头还是不不变的
                    if(c->get_pre()->get_bz()+c->get_pre()->get_sz()==c->get_bz())
                    {
                        //cout<<"112"<<endl;
                            c->get_pre()->set_sizez(c->get_pre()->get_sz()+c->get_sz());
                            c->get_pre()->set_nextz(c->get_n());//!如果c的next为空，则直接置空
                            if(c->get_n()!=NULL)//!为了改错写出来的，细看还挺妙
                            {
                                c->get_n()->set_prez(c->get_pre());
                            }
                            else{}//!等于空的情况不用考虑，不影响整个链表
                            //c->set_nextz(NULL);
                            //c->set_prez(NULL);
                            //delete c;

                    }

                }
                if(c->get_n()!=NULL)//和后面和，把后面的变成真真正的节点
                {
                    if(c->get_n()->get_bz()==c->get_bz()+c->get_sz())
                    {
                        //cout<<"113"<<endl;
                        c->get_n()->set_beginz(c->get_bz());
                        //cout<<"114"<<endl;
                        c->get_n()->set_sizez(c->get_sz()+c->get_n()->get_sz());
                        //cout<<"115"<<endl;
                        c->get_n()->set_prez(c->get_pre());
                        //cout<<"116"<<endl;
                        if(c->get_pre()!=NULL)
                        {
                            c->get_pre()->set_nextz(c->get_n());
                        }
                        else
                        {
                            e=c->get_n();
                            lz.set_headz(e);//!重点！头指针一定要改，不然断不开该断的点
                           // cout<<e->get_bz()<<" "<<e->get_sz()<<endl;
                            c->set_nextz(NULL);
                        }
                        //c->set_nextz(NULL);
                        //c->set_prez(NULL);
                        //delete c;
                       // cout<<"117"<<endl;
                    }
                }
                //cout<<"118"<<endl;
                e=e->get_n();

            }
        }
        /*if(lz.get_headz())
        {
            cout<<lz.get_headz()->get_bz()<<","<<lz.get_headz()->get_sz()<<endl;
        }*/


}

void menu()
{
    cout<<"欢迎来到进程调度模拟程序 此程序内存分配采用首次适应算法"<<endl;
    cout<<"1.创建进程"<<endl;
    cout<<"2.中止进程"<<endl;
    cout<<"3.阻塞"<<endl;
    cout<<"4.唤醒"<<endl;
    cout<<"5.时间片到"<<endl;
    cout<<"6.显示三个链表"<<endl;
    cout<<"7.显示空闲内存分区（开始，大小）"<<endl;
    cout<<"8.结束进程调度模拟程序"<<endl;
    cout<<"请输入数字选择，每做完一次合法操作将会进行展示各链表,创建及中止进程时显示空闲内存"<<endl;
}


//写错的代码
/*bool Link_PCB::end_link_exe2()//!不用输名字
{
    if(head==NULL)
    {
        return false;//失败
    }
    else
    {
        string s_de=head->get_s();
        cout<<s_de<<"已成功中止"<<endl;
        head=NULL;
        tail=NULL;
        length=0;
        return true;
    }
}*/

/*bool Link_PCB::end_link_exe(string s_de)
{
    Node_PCB* findp=NULL;//遍历指针
    Node_PCB* pre=NULL;
    findp=head;
    pre=head;
    if(head==NULL)
    {
        return false;//失败
    }
    else if(head->get_s()==s_de)
    {
        //cout<<"j11"<<endl;
        head=head->get_next();
        if(head==NULL)
        {
            //cout<<"整个链表为空"<<endl;
        }
        return true;
    }
    else
    {
        while(findp->get_next()!=NULL&&findp->get_s()!=s_de)//没到尾并且没找到
            {
                //cout<<"111"<<endl;
                pre=findp;
                findp=findp->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findp->get_s()==s_de)//找到
            {
                //cout<<"112"<<endl;
                pre->set_next(findp->get_next());
                findp->set_next(NULL);
                return true;
            }

            else
            {
                //cout<<"错误输入"<<endl;
                return false;
            }

    }

}
int Link_PCB::end_link(std::string s_d)//中止这个进程
{
     Node_PCB* findp=NULL;//遍历指针
    Node_PCB* pre=NULL;
    findp=head;
    pre=head;
    if(head==NULL)
    {
        return 1;
    }
    else if(head->get_s()==s_d)
    {
        //cout<<"j11"<<endl;
        head=head->get_next();
        if(head==NULL)
        {
            //cout<<"整个链表为空"<<endl;
        }
        return 2;
    }
    else
    {
        while(findp->get_next()!=NULL&&findp->get_s()!=s_d)//没到尾并且没找到
            {
                //cout<<"111"<<endl;
                pre=findp;
                findp=findp->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findp->get_s()==s_d)//找到
            {
                //cout<<"112"<<endl;
                pre->set_next(findp->get_next());
                findp->set_next(NULL);
                return 2;
            }

            else
            {
                //cout<<"错误输入"<<endl;
                return 3;
            }

    }

}
*/

/*
void Link_PCB::end_link(std::string s_d,int &f)//中止这个进程
{
    //遍历链表，找到后删除
    Node_PCB* findp=NULL;//遍历指针
    Node_PCB* pre=NULL;
    findp=head;
    pre=head;
    if(head==NULL)
    {
        cout<<"kkk"<<endl;
    }
    while(findp->get_next()!=NULL&&findp->get_s()!=s_d)//没到尾并且没找到
    {
        cout<<"111"<<endl;
        pre=findp;
        findp=findp->get_next();
        //findp->set_next(findp->get_next());
    }
    if(findp->get_s()==s_d)//找到
    {
        cout<<"112"<<endl;
        pre->set_next(findp->get_next());
        findp->set_next(NULL);
    }
    else
    {
        cout<<"错误输入"<<endl;
        f=1;
    }

}
*///引用的先放
/*bool Link_PCB::block()
{
    //把执行的一个放在阻塞尾
    if(head==NULL)
    {
        return false;
    }
    else
    {

    }
}*/
/*void end_three(Link_PCB &l1e,Link_PCB &l2e,Link_PCB &l3e,string se,int &fl )
{

    int f1=l1e.end_link(se);
    int f2=l2e.end_link(se);
    int f3=l3e.end_link(se);
    //cout<<"f1="<<f1<<" f2="<<f2<<" f3="<<f3<<endl;
    if(f1!=2&&f2!=2&&f3!=2)
    {
        //cout<<"999"<<endl;
        cout<<"不存在此进程，请重新选择"<<endl;
        fl=1;
    }

}*/
/*void delete_same(Link_Zone &lz)
{
    Node_zone *p1=NULL;
    Node_zone *p2=NULL;
    if(lz.get_headz()==NULL)
    {

    }
    else
    {
        p1=lz.get_headz();
        p2=lz.get_headz()->get_n();
        while(p2!=NULL)
        {
            if(p1->get_bz()==p2->get_bz())
            {

            }
            else
            {
                p1=p1->get_n();
                p1->set_beginz(p2->get_bz());
                p1->set_sizez(p2->get_sz());
            }
            p2=p2->get_n();
        }
    }
}
*/
 /*while(e&&e->get_n()&&e->get_bz()+e->get_sz()==e->get_n()->get_bz())
            {
                    //!和完后考虑c的前后
                    c=e;
                    c->set_beginz(e->get_bz());
                    c->set_sizez(e->get_sz()+e->get_n()->get_sz());
                    //cout<<"113"<<endl;
                    c->set_nextz(e->get_n()->get_n());
                    //cout<<"114"<<endl;
                    //if(c->get_pre())
                    if(e->get_n()||e->get_n()->get_n())
                    {

                    }
                    else
                    {
                        //cout<<"115"<<endl;
                        e->get_n()->get_n()->set_prez(c);
                    }
                    if

                    //cout<<"116"<<endl;
                     e=e->get_n();
            }
*/
        /*while(e)
        {
            cout<<"111"<<endl;
            if(e->get_n()!=NULL)
            {
                while(e->get_bz()+e->get_sz()==e->get_n()->get_bz())
                {
                    cout<<"112"<<endl;
                    c=e;
                    c->set_beginz(e->get_bz());

                    c->set_sizez(e->get_sz()+e->get_n()->get_sz());
                    cout<<"113"<<endl;
                    c->set_nextz(e->get_n()->get_n());
                    cout<<"114"<<endl;
                    if(e->get_n()->get_n()!=NULL)
                    {
                        e->get_n()->get_n()->set_prez(c);
                    }
                    else
                    {

                    }
                    e=e->get_n();

                }
            }



        }*/
        /*if(e)
                {
                    //cout<<e->get_bz()<<" "<<e->get_sz()<<endl;
                }*/

                //if(e!=NULL)
                //cout<<e->get_bz()<<endl;
                //c->set_nextz(NULL);
                //c->set_prez(NULL);
