#include<iostream>
#include"list00.h"

using namespace std;

//ָ�������*��Ԫ�ؿ�����&����ת�����ú���
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
    head=&nh;//ͷָ��ָ��ͷ���
    nh.set_next(NULL);//ͷ����nextΪ��
    length=1;//ͷ���
    /*head=new Node;
    //Node nh;*head=nh;//ͷָ��ָ��ͷ���
    (*head).set_next(NULL);//ͷ����nextָ��null
    length=1;//ͷ���*/
}

void List::creat_list_tail(int n)
{
        //Node no;
        length=length+n;
        Node * tail;//βָ��
        tail=&nh;//βָ����ָ��ͷ���
        tail->set_next(NULL);
        int i;
        cout<<"����������������ֵ"<<endl;
        for(i=0;i<n;i++)
        {
            Node *p=new Node;//���ٿռ䣬pָ������¿ռ���н������Ĳ���
            p->set_data();
            p->set_next(NULL);
            tail->set_next(p);//��p����βָ����
            tail=p;//βָ��ı�
           //!��newһ������ָ�룬ֱ������һ�������𣿵���ʱ���Լ�����
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
    Node* h=nh.get_next();//��ͷ���ĺ�һ����ʼչʾ
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
    Node * find_p;//Ѱ��ָ��
    Node * pre;//ǰ��ָ�룬������룬��Ҫ����ĵط���ǰһ���ط�
    pre=&nh;//!preָ��ָ��ͷ��㣬ͳһ���ҷ�ʽ��nh�ĵ�ַҲ��head
    find_p=nh.get_next();//��ͷ������һ����㿪ʼ��
    Node *no=new Node;//��Ҫ�����Ԫ���׿���
    no->set_data2(node_d);
    no->set_next(NULL);
    /*if(pre->get_data()>node_d)
    {
        no->set_next(find_p);
        pre=no;
        find_p=no;
    }*/
    //!find_p!=NULLҪ����ǰ�棬��Ȼ�޷��˳�ѭ��?&&�ж���һ���ͻ᲻�жϺ������
    //!��find_p==NULLʱ��find_p->get_data()������������޷��˳�ѭ���������ж�Ҫ����ǰ��
    while(find_p!=NULL&&find_p->get_data()<node_d)//ָ��ָ��ط�����ֵС��Ҫ����ģ�����û���꣬�ͼ�����
    {
        pre=find_p;
        find_p=find_p->get_next();
        //cout<<find_p<<endl;
        //!��null���ʣ���Σ�� cout<<find_p->get_data()<<endl;
    }
    //cout<<"1"<<endl;
    //����ѭ�������ֿ��ܣ���ĩβ�ˣ��ҵ�λ����
    //��ĩβʱ��find_p��null��pre���������һ�����

   /* if(find_p==NULL)
    {
        pre->set_next(no);
        no->set_next(NULL);
    }*/
    pre->set_next(no);
    no->set_next(find_p);
    /*!no->set_next(pre->get_next());
       pre->set_next(no)  ������д�Ļ�˳���ܱ䣬��Ȼpre��ָ�������仯*/
    //pre->set_next(no);//��no����ǰ��ָ����
    //no->set_next(find_p);//�����ָ�����no��*/
}

void List::reverse_l()
{
    //һ��ָ����������㣬��ÿ�����ͷ�嵽ǰ����㣬���һ���������ͷ���β������
    Node * pre,*p;//p�Ǳ���ָ�룬pre��¼ǰ��Ľ�㣬����ͷ��
    p=head->get_next();//pre=nh.get_next();һ����ָ��ͷ����ָ�����head
    //pre=head;
    head->set_next(NULL);//�Ͽ�ͷ���
    while(p!=NULL)//û�����һ�����Ͳ�ֹͣͷ��
    {
        pre=p;
        p=p->get_next();//�����ƶ�һλ
        pre->set_next(head->get_next());//�������������ͷ��
        head->set_next(pre);
    }
    //��һ���������ú�����һλ�ÿ�
    //!���϶Ͽ�headָ������ָ�룬���������µĽ���ϣ�ֱ��������ɣ�
}

void List::add_list_decline(List &L1)//�Ƚϣ�С����ǰ���
{
        Node * p1,*p2;//�Ƚ�ָ��
        Node *r;
        r=NULL;
      // Node *pre;
      // pre=NULL;
        p1=head->get_next();
        p2=L1.head->get_next();//����Ԫ��㿪ʼ�Ƚ�
        head->set_next(NULL);//ͷ����next�ÿգ����ں���ͷ��
        L1.head->set_next(NULL);
        while(p1!=NULL&&p2!=NULL)//���߶���Ϊ��ʱ���бȽ�ͷ��,��һ����С��next���ÿ��ٲ嵽ͷ�����棬Ȼ�����С�Ĳ�����ͷ��1֮��ͷ�壬�������ͷ���������ͷ��㿴�ݼ�
        {
            if(p1->get_data()<p2->get_data())
            {
                r=p1->get_next();
                p1->set_next(head->get_next());//�ʼhead->nextΪ��
                head->set_next(p1);
                p1=r;
                /*pre=p1;
                p1=p1->get_next();//�����ƶ�һλ
                pre->set_next(head->get_next());//�����ú�����һλ�ÿ�
                head->set_next(pre);*/

            }
            else
            {
                /*pre=p2;
                p2=p2->get_next();//�����ƶ�һλ
                pre->set_next(L1.head->get_next());//�����ú�����һλ�ÿ�
                L1.head->set_next(pre);*/
                r=p2->get_next();
                p2->set_next(head->get_next());//ͷ��
                head->set_next(p2);
                p2=r;
            }
        }
        //����һ������Ϊ��ʱ���˳�ѭ��
        while(p1!=NULL)//����Ϊ�յ�������ԭ����˳��ͷ���ڴ�ʱβ���ĺ���
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

void List::reverse_me()//!�ʣ�
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
        p=p->get_next();//!�����Ȳ�����ƶ������������λ�þ��Ǵ���ģ�����
        pre=p;
    }
}

void List::add_me(List &L1)
{
    Node *find_p1,*find_p2;
    Node *t;//��һ��ָ������¼��һ��λ�ã������ƶ�
    t=NULL;
    find_p1=head->get_next();
    find_p2=L1.head->get_next();
    head->set_next(NULL);
    L1.head->set_next(NULL);
    while(find_p1&&find_p2)
    {
        if(find_p1->get_data()<find_p2->get_data())//С����ͷ��
        {
            t=find_p1->get_next();
            find_p1->set_next(head->get_next());
            head->set_next(find_p1);//!��Ҫ����������䣬ͷ��ͷ���һ��Ҫ���ϣ���֤ͷ����ڵ�һλ
            find_p1=t;
        }
        else
        {
            t=find_p2->get_next();
            find_p2->set_next(L1.head->get_next());
            L1.head->set_next(find_p1);//!��Ҫ����������䣬ͷ��ͷ���һ��Ҫ���ϣ���֤ͷ����ڵ�һλ
            find_p2=t;
        }//ͬ��
    }
    while(find_p1!=NULL)//�˳�ѭ������һ��������Ϊ�գ�����ʣ�µ����н��ͷ��
    {
        //ֱ��ͷ�壬������һ�����������
            t=find_p1->get_next();
            find_p1->set_next(head->get_next());
            head->set_next(find_p1);//!��Ҫ����������䣬ͷ��ͷ���һ��Ҫ���ϣ���֤ͷ����ڵ�һλ
            find_p1=t;
    }
    while(find_p2!=NULL)
    {
            t=find_p2->get_next();
            find_p2->set_next(L1.head->get_next());
            L1.head->set_next(find_p1);//!��Ҫ����������䣬ͷ��ͷ���һ��Ҫ���ϣ���֤ͷ����ڵ�һλ
            find_p2=t;
    }

}

void menu()
{
    cout<<"1.���Բ����㷨"<<endl;
    cout<<"2.���������㷨"<<endl;
    cout<<"3.���Ժϲ�����"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;
}
