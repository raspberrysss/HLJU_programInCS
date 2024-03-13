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
    cout<<"请输入学生信息（eg.20210987 张三 女 18 群众）"<<endl;
    cin>>id;
    cin.get();//不用这个好像也行，为社么？
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
    //cout<<"学生信息如下所示"<<endl;
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
    /这样不行，但是不知道为什么，插入函数只能在已存在的数据里插入!问！！！
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
//尾插法,先不用

void Link::output()
{

    Student * h=head;
    while(h!=NULL)
    {
        h->showinform();
        h=h->getnext();
    }
}

void Link:: insert_link(Student * S)//!破案了破案了，是自己想的那个有问题，为什么呢？
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
   /* Student *p,*q;//这样写就对，可以插入，是我尾指针引用的不对吗？
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
       while(tail!=NULL&&tail->getnext()!=NULL)//尾指针先指到尾
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
    Student *q=new Student(s);//使用Student的默认复制构造
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
        cout<<"数据为空，无法进行删除操作"<<endl;
    }
    else if(head->getid()==id_l)
    {
        pre=head;//找一个指针放头指针的数据，再把头指针往后移，最后把带有原头指针的数据删掉
        head=head->getnext();
        delete pre;
    }
    else
    {
        q=head;//从头开找
        while(q!=NULL&&q->getid()!=id_l)//在没找完并且没找到的情况下
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
      while(tail->getnext()!=NULL)//尾指针先指到尾,这样会有bug，要使用
       {
           tail=tail->getnext();
       }
      tail->setnext(p.gethead());
 }

void Link::shownum()
{
    cout<<"学生总数为："<<num<<endl;
}

void menu()
{
    cout<<"欢迎来到学生信息录入系统"<<endl;
    cout<<"1.输入学生信息创建已排序好的链表"<<endl;
    cout<<"2.插入学生信息"<<endl;
    cout<<"3.删除学生信息"<<endl;
    cout<<"4.将当前学生信息与另一组链接（链表连接）"<<endl;
    cout<<"5."<<endl;

}


