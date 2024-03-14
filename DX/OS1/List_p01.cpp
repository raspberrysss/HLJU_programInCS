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
    Node_PCB *j=new Node_PCB;//!����Ҫ��ָ�룬new���ص���һ����ַ
    j->set_s(s_l);
    j->set_size(s);
    j->set_b(b);
    j->set_next(NULL);
    //Node_PCB *tail=NULL;//β����Ҫһ��һֱָ��β��ָ��
    //Node_PCB *p=NULL;//����ָ��
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
    Node_PCB* findf=NULL;//����ָ��
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
        while(findf->get_next()!=NULL&&findf->get_s()!=s_f)//û��β����û�ҵ�
            {
                //cout<<"111"<<endl;

                findf=findf->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findf->get_s()==s_f)//�ҵ�
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
    Node_zone *e=NULL;//����ָ�룬���㰴��ʼ��ַ��������
    Node_zone *pp=NULL;//����ָ���ǰ��ָ�룬�������
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
        else if(pp==e)//pp==e e->get_n()==NULL̫���������⣬���翴��
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
    cout<<"�����ڴ������";
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



//����Ԫ����������
//new ��ʲôʱ��delete
void ready_to_exe_auto(Link_PCB &l1,Link_PCB &l2)//l1 ready l2 exe
{
    if(l2.is_empty_list()&&!l1.is_empty_list())
    {
        //cout<<"111"<<endl;
        //!��ready��ͷ���ժ�£��ҵ�exe��β�����
       // Node_PCB *j= new Node_PCB;//��ժ�����Ľڵ�
       // Node_PCB *pre;//����ָ��
        if(l1.get_len()==1)//ֻ��һ���ڵ�
        {
            //cout<<"111"<<endl;
            //j->set_s(l1.get_head()->get_s());
            //j->set_next(NULL);
            l2.create_link((l1.get_head())->get_s(),l1.get_head()->get_size(),l1.get_head()->get_b());//l2����
            //!����������գ���ȻheadΪnull�����ִ���
            //!д�����ˣ�����ţţţ������
            l1.set_link(NULL,NULL,0);//l1���



        }
        else if(l1.get_len()>1)//����ڵ㣬��ͷ��㵽ִ�ж���
        {
            l2.create_link(l1.get_head()->get_s(),l1.get_head()->get_size(),l1.get_head()->get_b());
            l1.set_head(l1.get_head()->get_next());
            /*l2.create_link(l1.get_tail()->get_s());
            pre=l1.get_head();
            while(pre->get_next()!=l1.get_tail())
            {
                pre->set_next(pre->get_next());
            }//��tail��ǰ��
            pre->set_next(NULL);*/

        }

    }
    else
    {
       if(l2.is_empty_list()&&l1.is_empty_list())
       {
           //!ɾ�껹��������
           //cout<<"ִ���������Ϊ��"<<endl;
           //�����κβ���
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
        cout<<s_b<<"�ѳɹ���������̬"<<endl;
        l2b.create_link(l1b.get_head()->get_s(),l1b.get_head()->get_size(),l1b.get_head()->get_b());
        l1b.set_link(NULL,NULL,0);
        return true;
    }
    else
    {
        if(!l2b.is_empty_list()&&!l1b.is_empty_list())
        {
            string s_b=l1b.get_head()->get_s();
            cout<<s_b<<"�ѳɹ���������̬"<<endl;
            l2b.create_link(l1b.get_head()->get_s(),l1b.get_head()->get_size(),l1b.get_head()->get_b());
            l1b.set_link(NULL,NULL,0);
            return true;
        }
        else
        {
            cout<<"ִ������Ϊ�գ��޷���������̬"<<endl;
            return false;
        }
        //���ж�Ϊ�գ�û��Ҫд
    }
}

bool wake(Link_PCB &l1w,Link_PCB &l2w)//1 block 2 ready
{
    //����ͷ���ھ���β

    if(l1w.is_empty_list())//����Ϊ��
    {
        cout<<"��������Ϊ�գ��޷�����"<<endl;
        return false;
    }
   /* else if(!l2w.is_empty_list())
    {
        cout<<"cpu�ѱ�ռ�ã��޷�����"<<endl;
        return false;
    }*/
    else if(!l1w.is_empty_list())
    {
        string s_w=l1w.get_head()->get_s();
        cout<<s_w<<"�ѳɹ�������"<<endl;
        l2w.create_link(l1w.get_head()->get_s(),l1w.get_head()->get_size(),l1w.get_head()->get_b());
        l1w.set_link(NULL,NULL,0);
        return true;
    }
    else
        return false;


}

bool time(Link_PCB &l1t,Link_PCB &l2t)//1 exe 2 ready
{
    if(l1t.is_empty_list())//exeΪ��
    {
        cout<<"ִ������Ϊ��"<<endl;
        return false;
    }
    else if(!l1t.is_empty_list())//ִ�в�Ϊ�գ������ղ��ն���
    {
        string s_t=l1t.get_head()->get_s();
        cout<<s_t<<"ʱ��Ƭ�ѵ�"<<endl;
        l2t.create_link(l1t.get_head()->get_s(),l1t.get_head()->get_size(),l1t.get_head()->get_b());
        l1t.set_link(NULL,NULL,0);
        return true;
    }
    else
        return false;

}

void show_three(Link_PCB l11,Link_PCB l22,Link_PCB l33)
{
    cout<<"����̬ ";
    l11.show_link();
    cout<<endl;
    cout<<"ִ��̬ ";
    l22.show_link();
    cout<<endl;
    cout<<"����̬ ";
    l33.show_link();
    cout<<endl;
}

bool is_repeat(Link_PCB l1r,Link_PCB l2r,Link_PCB l3r,string sr)
{
    int r1=l1r.find_from_link(sr);
    int r2=l2r.find_from_link(sr);
    int r3=l3r.find_from_link(sr);
    if(r1!=5&&r2!=5&&r3!=5)//��û�ҵ���������
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
        cout<<"�޿��з�����½��̣�����ʧ��"<<endl;
        return false;
    }
    else
    {
        be_node_pcb=e->get_bz();
        e->set_beginz(e->get_bz()+size_pcb);
        e->set_sizez(e->get_sz()-size_pcb);
        return true;
    }
    //!��Ƭ�����⣬98ֱ�ӷ�100����
    /*else//��Ƭ��2������
    {
        cout<<"ʣ�µĿռ�Ϊ2kb��Ƭ���޷�����"<<endl;
        return false;
    }*/
}

bool end_exe3(Link_PCB &le,Link_Zone &lz)
{
    if(le.get_head()==NULL)
    {
        return false;//ʧ��
    }
    else
    {
        string s_de=le.get_head()->get_s();
        cout<<s_de<<"�ѳɹ���ֹ"<<endl;
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
        if(lz.get_lenz()==1)//ֻ��һ���ڵ�
        {
            //cout<<"111"<<endl;
            //�Ͳ���
        }
        else if(lz.get_lenz()>1)
        {
            while(e)//����
            {
                c=e;
                if(c->get_pre()!=NULL)//��ǰ���������Ľڵ�
                {
                    //!c���Ը�ǰ��ͣ���������һ��Ҳ���ԣ���һ��
                    //!��Ҫ�õ���һ�Σ���Ϊ������pre�����µĽڵ㣬ͷ���ǲ������
                    if(c->get_pre()->get_bz()+c->get_pre()->get_sz()==c->get_bz())
                    {
                        //cout<<"112"<<endl;
                            c->get_pre()->set_sizez(c->get_pre()->get_sz()+c->get_sz());
                            c->get_pre()->set_nextz(c->get_n());//!���c��nextΪ�գ���ֱ���ÿ�
                            if(c->get_n()!=NULL)//!Ϊ�˸Ĵ�д�����ģ�ϸ����ͦ��
                            {
                                c->get_n()->set_prez(c->get_pre());
                            }
                            else{}//!���ڿյ�������ÿ��ǣ���Ӱ����������
                            //c->set_nextz(NULL);
                            //c->set_prez(NULL);
                            //delete c;

                    }

                }
                if(c->get_n()!=NULL)//�ͺ���ͣ��Ѻ���ı���������Ľڵ�
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
                            lz.set_headz(e);//!�ص㣡ͷָ��һ��Ҫ�ģ���Ȼ�ϲ����öϵĵ�
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
    cout<<"��ӭ�������̵���ģ����� �˳����ڴ��������״���Ӧ�㷨"<<endl;
    cout<<"1.��������"<<endl;
    cout<<"2.��ֹ����"<<endl;
    cout<<"3.����"<<endl;
    cout<<"4.����"<<endl;
    cout<<"5.ʱ��Ƭ��"<<endl;
    cout<<"6.��ʾ��������"<<endl;
    cout<<"7.��ʾ�����ڴ��������ʼ����С��"<<endl;
    cout<<"8.�������̵���ģ�����"<<endl;
    cout<<"����������ѡ��ÿ����һ�κϷ������������չʾ������,��������ֹ����ʱ��ʾ�����ڴ�"<<endl;
}


//д��Ĵ���
/*bool Link_PCB::end_link_exe2()//!����������
{
    if(head==NULL)
    {
        return false;//ʧ��
    }
    else
    {
        string s_de=head->get_s();
        cout<<s_de<<"�ѳɹ���ֹ"<<endl;
        head=NULL;
        tail=NULL;
        length=0;
        return true;
    }
}*/

/*bool Link_PCB::end_link_exe(string s_de)
{
    Node_PCB* findp=NULL;//����ָ��
    Node_PCB* pre=NULL;
    findp=head;
    pre=head;
    if(head==NULL)
    {
        return false;//ʧ��
    }
    else if(head->get_s()==s_de)
    {
        //cout<<"j11"<<endl;
        head=head->get_next();
        if(head==NULL)
        {
            //cout<<"��������Ϊ��"<<endl;
        }
        return true;
    }
    else
    {
        while(findp->get_next()!=NULL&&findp->get_s()!=s_de)//û��β����û�ҵ�
            {
                //cout<<"111"<<endl;
                pre=findp;
                findp=findp->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findp->get_s()==s_de)//�ҵ�
            {
                //cout<<"112"<<endl;
                pre->set_next(findp->get_next());
                findp->set_next(NULL);
                return true;
            }

            else
            {
                //cout<<"��������"<<endl;
                return false;
            }

    }

}
int Link_PCB::end_link(std::string s_d)//��ֹ�������
{
     Node_PCB* findp=NULL;//����ָ��
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
            //cout<<"��������Ϊ��"<<endl;
        }
        return 2;
    }
    else
    {
        while(findp->get_next()!=NULL&&findp->get_s()!=s_d)//û��β����û�ҵ�
            {
                //cout<<"111"<<endl;
                pre=findp;
                findp=findp->get_next();
                //findp->set_next(findp->get_next());
            }
            if(findp->get_s()==s_d)//�ҵ�
            {
                //cout<<"112"<<endl;
                pre->set_next(findp->get_next());
                findp->set_next(NULL);
                return 2;
            }

            else
            {
                //cout<<"��������"<<endl;
                return 3;
            }

    }

}
*/

/*
void Link_PCB::end_link(std::string s_d,int &f)//��ֹ�������
{
    //���������ҵ���ɾ��
    Node_PCB* findp=NULL;//����ָ��
    Node_PCB* pre=NULL;
    findp=head;
    pre=head;
    if(head==NULL)
    {
        cout<<"kkk"<<endl;
    }
    while(findp->get_next()!=NULL&&findp->get_s()!=s_d)//û��β����û�ҵ�
    {
        cout<<"111"<<endl;
        pre=findp;
        findp=findp->get_next();
        //findp->set_next(findp->get_next());
    }
    if(findp->get_s()==s_d)//�ҵ�
    {
        cout<<"112"<<endl;
        pre->set_next(findp->get_next());
        findp->set_next(NULL);
    }
    else
    {
        cout<<"��������"<<endl;
        f=1;
    }

}
*///���õ��ȷ�
/*bool Link_PCB::block()
{
    //��ִ�е�һ����������β
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
        cout<<"�����ڴ˽��̣�������ѡ��"<<endl;
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
                    //!�������c��ǰ��
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
