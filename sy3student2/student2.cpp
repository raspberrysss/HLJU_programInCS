#include<iostream>
#include"student2.h"

using namespace std;

//int Link::num=0;

Student::Student()
{
    id=00000000;
    name="no name";
    sex="no sex";
    age=0;
    politics="no";
    next=NULL;
}

Student::Student(long id_s,string name_s,string sex_s,int age_s,string politics_s,Student * next_s)
{
    id=id_s;
    name=name_s;
    sex=sex_s;
    age=age_s;
    politics=politics_s;
    next=next_s;
}

Student::~Student()
{

}

void Student::setinform()
{
    cout<<"������ѧ����Ϣ��eg.20210987 ���� Ů 18 Ⱥ�ڣ�"<<endl;
    cin>>id;
    cin.get();//�����������Ҳ�У�Ϊ��ô��
    cin>>name;
    cin.get();
    cin>>sex;
    cin>>age;
    cin.get();
    cin>>politics;
}

void Student::setnext(Student *next_s)
{
    next=next_s;
}

Student * Student::getnext()
{
    return next;
}

long Student::getid()
{
    return id;
}

void Student::showinform()
{
    //cout<<"ѧ����Ϣ������ʾ"<<endl;
    cout<<id<<" "<<name<<" "<<sex<<" "<<" "<<age<<" "<<politics<<endl;
}

Link::Link()
{
    head=NULL;
    num=0;
}

Link::Link(int n)
{
    //Student *p_pre,*pre;
    //p_pre=pre=NULL;
    num=n;
    int i;
    for(i=0;i<n;i++)
    {
        Student *s=new Student;
        s->setinform();
        s->setnext(NULL);
        insert_link(s);
       /* if(head==NULL)
        {
            head=s;
            s->setnext(NULL);
        }
        else if(s->getid()<head->getid())
        {
            s->setnext(head);
            head=s;
        }
        else
        {
            pre=head;
            while(pre!=NULL&&pre->getid()<s->getid())
        {
               p_pre=pre;
               pre=pre->getnext();
        }
        s->setnext(p_pre->getnext());
        p_pre->setnext(s);
        }
       // insert_link(s);
    }*/
}
}

/*Link::Link(int n)
{
    num=n;
    int i=0;
    for(i=0;i<n;i++)
    {
        Student *s=new Student;
        s->setinform();
        s->setnext(NULL);
        if(head==NULL)
        {

        }
    }

    head=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        Student *s=new Student;
        s->setinform();
        s->setnext(NULL);
        insert_link(s);
    }
    *
    /�������У����ǲ�֪��Ϊʲô�����뺯��ֻ�����Ѵ��ڵ����������!�ʣ�����
}

Link(n)
{
    for(i=0;i<n;i++)
    {

    }
}
}*/

Link::~Link()
{
   num--;
   Student *p,*q;
   p=head;
   while(p!=NULL)
   {
       q=p;
       p=p->getnext();
       delete q;
   }
}

void Link::creatlink(int n)
{
    Student * tail=new Student;
    tail->setnext(NULL);
    int i;
    for(i=0;i<n;i++)
    {
        Student *p=new Student;
        num++;
        p->setinform();
        p->setnext(NULL);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            tail->setnext(p);//tail->next=p;
        }
        tail=p;
    }
}
//β�巨,�Ȳ���

void Link::output()
{

    Student * h=head;
    while(h!=NULL)
    {
        h->showinform();
        h=h->getnext();
    }
}

void Link:: insert_link(Student * S)//!�ư����ư��ˣ����Լ�����Ǹ������⣬Ϊʲô�أ�
{
   Student * p_pre,*pre;
    pre=head;
    if(head==NULL)
    {
           head=S;
          // S->setnext(NULL);

    }
    else if(S->getid()<head->getid())
       {
           S->setnext(head);
           head=S;
       }
    else
    {
        while(pre!=NULL&&pre->getid()<S->getid())
        {
               p_pre=pre;
               pre=pre->getnext();
        }
        S->setnext(p_pre->getnext());
        p_pre->setnext(S);
         //p_pre->setnext(S);
         //S->setnext(pre);
    }
   /* Student *p,*q;//����д�Ͷԣ����Բ��룬����βָ�����õĲ�����
    p=q=head;
    while(p!=NULL&&S->getid()<p->getid())
    {
        q=p;
        p=p->getnext();
    }
    if(p==head)
    {
        S->setnext(head);
        head=S;
    }
    else
    {
        q->setnext(S);
        S->setnext(p);
    }
*//*
       num++;
       Student * tail;//=new Student;
       Student * pre;//=new Student;
       Student *p_pre;//=new Student;
       tail=head;
       pre=head;
       p_pre=head;
       while(tail!=NULL&&tail->getnext()!=NULL)//βָ����ָ��β
       {
           tail=tail->getnext();
       }
       if(head==NULL)
       {
           head=S;
           S->setnext(NULL);
       }
       else if(S->getid()<head->getid())
       {
           S->setnext(head);
           head=S;
       }
       else if(S->getid()>tail->getid())
       {
           tail->setnext(S);
           tail=S;
       }
       else
       {
           while(pre->getid()<S->getid())
           {
               p_pre=pre;
               pre=pre->getnext();
           }
           p_pre->setnext(S);
           S->setnext(pre);
       }*/
}

/*void Link::insert_link(Student &s)
{
    num++;
    s.setinform();
    Student *q=new Student(s);//ʹ��Student��Ĭ�ϸ��ƹ���
    Student *p_pre,*tail,*pre;
    tail=p_pre=pre=NULL;
    while(tail->getnext()!=NULL)
    {
        tail=tail->getnext();
    }
    if(head==NULL)
    {
        head=q;
    }
    else if(q->getid()<head->getid())
    {
        q->setnext(head);
        head=q;
    }
    else if(q->getid()>tail->getid())
    {
        tail->setnext(q);
        tail=q;
    }
    else
    {
       while(pre->getid()<q->getid())
           {
               p_pre=pre;
               pre=pre->getnext();
           }
           p_pre->setnext(q);
           q->setnext(pre);
    }

}*/

 void  Link::delete_link(long id_l)
 {
    num--;
    Student *pre;
    Student *q;
    pre=NULL;
    q=NULL;
    if(head==NULL)
    {
        cout<<"����Ϊ�գ��޷�����ɾ������"<<endl;
    }
    else if(head->getid()==id_l)
    {
        pre=head;//��һ��ָ���ͷָ������ݣ��ٰ�ͷָ�������ƣ����Ѵ���ԭͷָ�������ɾ��
        head=head->getnext();
        delete pre;
    }
    else
    {
        q=head;//��ͷ����
        while(q!=NULL&&q->getid()!=id_l)//��û���겢��û�ҵ��������
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

 /*Link::Link(Link &l)
 {
     num=l.num;
     int i;
     Student *p,*q;
     Student t;
     p=l.head;
     head=NULL;
     for(i=0;i<num;i++)
     {
          Student *s=new Student(t);


     }

 }
 */

 Student * Link::gethead()
 {
     return head;
 }

 void Link::connect_link(Link &p)
 {
     Student * tail=new Student;
     tail=head;
      while(tail->getnext()!=NULL)//βָ����ָ��β,��������bug��Ҫʹ��
       {
           tail=tail->getnext();
       }
      tail->setnext(p.gethead());
 }

void Link::shownum()
{
    cout<<"ѧ������Ϊ��"<<num<<endl;
}

void menu()
{
    cout<<"��ӭ����ѧ����Ϣ¼��ϵͳ"<<endl;
    cout<<"1.����ѧ����Ϣ����������õ�����"<<endl;
    cout<<"2.����ѧ����Ϣ"<<endl;
    cout<<"3.ɾ��ѧ����Ϣ"<<endl;
    cout<<"4.����ǰѧ����Ϣ����һ�����ӣ��������ӣ�"<<endl;
    cout<<"5."<<endl;

}


