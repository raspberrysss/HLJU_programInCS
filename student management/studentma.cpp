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
    //num=n;
    for(int i=0;i<n;i++)
    {
        Student *s=new Student;
        s->setinform();
        s->setnext(NULL);
        insert_link(s);
    }
    }

void Link:: insert_link(Student * S)//!破案了破案了，是自己想的那个有问题，为什么呢？
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
        x=x->getnext();//一个一个复制
        //insert_link(s);
    }
    q=head;
    while(q->getnext()!=NULL)
    {
        q=q->getnext();
    }
    q->setnext(p.gethead());
     /*Student * tail=new Student;这样写会有小问题
     tail=head;
      while(tail->getnext()!=NULL)//尾指针先指到尾,这样会有bug，要使用
       {
           tail=tail->getnext();
       }
      tail->setnext(p.gethead());*/
 }

 void Link::shownum()
{
    cout<<"学生总数为："<<num<<endl;
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
        d=p->getstudent();//this指针                                                                                 ，真不赖！
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
        p=p->getnext();//一个一个复制,p代表遍历了一遍链表
        //insert_link(s);
    }
}

void menu()
{
    cout<<"欢迎来到学生信息录入系统"<<endl;
    cout<<"请选择数字对创建的链表进行操作"<<endl;
    cout<<"1.插入学生信息"<<endl;
    cout<<"2.删除学生信息"<<endl;
    cout<<"3.复制表格"<<endl;
    cout<<"4.链表连接"<<endl;
    cout<<"5.退出"<<endl;
    //cout<<"3.将当前学生信息与另一组链接（链表连接）"<<endl;
    //cout<<"4."<<endl;

}
