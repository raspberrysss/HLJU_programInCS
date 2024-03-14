#include<iostream>
#include<string>
#include"studentmanagement.h"



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

Student::Student(const Student &d)
{
    id=d.id;
    name=d.name;
    sex=d.sex;
    age=d.age;
    politics=d.politics;
    next=d.next;
}

Student::~Student()
{

}

Student & Student::getstudent()
{
    return *this;
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
    //num=n;
    for(int i=0;i<n;i++)
    {
        Student *s=new Student;
        s->setinform();
        s->setnext(NULL);
        insert_link(s);
    }
    }

void Link:: insert_link(Student * S)//!�ư����ư��ˣ����Լ�����Ǹ������⣬Ϊʲô�أ�
{
    num++;
    Student * p_pre,*pre;
    pre=head;
    if(head==NULL)
    {
           head=S;
          //S->setnext(NULL);

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
    }
}

Link::~Link()
{
   //num--;
   Student *p,*q;
   p=head;
   while(p!=NULL)
   {
       q=p;
       p=p->getnext();
       delete q;
   }
}

void Link::output()
{

    Student * h=head;
    while(h!=NULL)
    {
        h->showinform();
        h=h->getnext();
    }
}

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

 Student * Link::gethead()
 {
     return head;
 }

 void Link::connect_link(Link &p)
 {
     num+=p.num;
    Student *q;
    Student *x=p.head;
    Student *h=NULL;
    Student d;
    for(int i=0;i<p.num;i++)
    {
        d=x->getstudent();
        Student *s=new Student(d);
        if(h==NULL)
        {
            h=s;
            h->setnext(NULL);
            q=h;
        }
        else
        {
            q->setnext(s);
            s->setnext(NULL);
            q=s;
        }
        x=x->getnext();//һ��һ������
        //insert_link(s);
    }
    q=head;
    while(q->getnext()!=NULL)
    {
        q=q->getnext();
    }
    q->setnext(p.gethead());
     /*Student * tail=new Student;����д����С����
     tail=head;
      while(tail->getnext()!=NULL)//βָ����ָ��β,��������bug��Ҫʹ��
       {
           tail=tail->getnext();
       }
      tail->setnext(p.gethead());*/
 }

 void Link::shownum()
{
    cout<<"ѧ������Ϊ��"<<num<<endl;
}

Link::Link(const Link &l)
{
    num=l.num;
    Student *q;
    Student *p=l.head;
    head=NULL;
    Student d;
    for(int i=0;i<l.num;i++)
    {
        d=p->getstudent();//thisָ��                                                                                 ���治����
        Student *s=new Student(d);
        if(head==NULL)
        {
            head=s;
            head->setnext(NULL);
            q=head;
        }
        else
        {
            q->setnext(s);
            s->setnext(NULL);
            q=s;
        }
        p=p->getnext();//һ��һ������,p���������һ������
        //insert_link(s);
    }
}

void menu()
{
    cout<<"��ӭ����ѧ����Ϣ¼��ϵͳ"<<endl;
    cout<<"��ѡ�����ֶԴ�����������в���"<<endl;
    cout<<"1.����ѧ����Ϣ"<<endl;
    cout<<"2.ɾ��ѧ����Ϣ"<<endl;
    cout<<"3.���Ʊ��"<<endl;
    cout<<"4.��������"<<endl;
    cout<<"5.�˳�"<<endl;
    //cout<<"3.����ǰѧ����Ϣ����һ�����ӣ��������ӣ�"<<endl;
    //cout<<"4."<<endl;

}
