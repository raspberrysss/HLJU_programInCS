#include<iostream>
#include"people00.h"//这里要写文件名

using namespace std;

Date::Date()
{
    cout<<"调用date无参默认构造函数"<<endl;
    year=0;
    month=0;
    day=0;
}

Date::Date(const Date &d)
{
    cout<<"调用date复制函数"<<endl;
    year=d.year;
    month=d.month;
    day=d.day;
}

Date::Date(int year_d,int month_d,int day_d)
{
    cout<<"调用date有参构造函数"<<endl;
    year=year_d;
    month=month_d;
    day=day_d;
}

Date::~Date()
{
    cout<<"调用date析构函数"<<endl;
}

void Date:: getdate()
{
     cout<<"please enter the year month day (eg 2002 5 17)"<<endl;
     cin>>year;
     cin>>month;
     cin>>day;
}

void Date:: showdate()
{
    cout<<year<<"."<<month<<"."<<day<<endl;
}

People::People():birth()//!这里要调用无参默认函数！可以不写
//相当于people内嵌一个birth，初始化时也要给他初始化了
{
    cout<<"调用people无参默认函数"<<endl;
    num=0;
    id=0;
    name="no name";
    //内嵌类如何进行初始化,使用成员初始化列表吗？好像是的
}

People::People(const People &p):birth(p.birth)//!此时这里调用的是birth的复制构造函数！
{
    num=p.num;
    id=p.id;
    name=p.name;
    //birth=p.birth;在这里写也可以，但是不规范
}

People::~People()
{
   cout<<"调用people析构函数"<<endl;
}

/*People:: People(int num_p,string name_p,long long id_p,Date birth_p):birth(birth_p)//内嵌对象初始化可以调用有参构造吗，如何调用
 {
     cout<<"调用people有参构造函数"<<endl;
     num=num_p;
     name=name_p;
     id=id_p;



 }*///

People::People(int num_p,string name_p,long long id_p,int year_p,int month_p,int day_p):birth(year_p,month_p,day_p)
{
    num=num_p;
    name=name_p;
    id=id_p;
//    year=year_p;
  //  month=month_p;
    //day=day_p;

}
void People::getpeople()
{
    //此时这个函数从意义上相当于构造函数,但是我又自己创建了
   cout<<"please input the information of the people eg(2 2302241988 lisi)"<<endl;
   cin>>num;
   cin>>id;
   cin>>name;
   birth.getdate();
}

void People::showpeople()
{
    cout<<"showing the information "<<endl;
    cout<<num<<endl;
    cout<<id<<endl;
    cout<<name<<endl;
    birth.showdate();
}
