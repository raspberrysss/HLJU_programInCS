#include<iostream>
#include"people00.h"//����Ҫд�ļ���

using namespace std;

Date::Date()
{
    cout<<"����date�޲�Ĭ�Ϲ��캯��"<<endl;
    year=0;
    month=0;
    day=0;
}

Date::Date(const Date &d)
{
    cout<<"����date���ƺ���"<<endl;
    year=d.year;
    month=d.month;
    day=d.day;
}

Date::Date(int year_d,int month_d,int day_d)
{
    cout<<"����date�вι��캯��"<<endl;
    year=year_d;
    month=month_d;
    day=day_d;
}

Date::~Date()
{
    cout<<"����date��������"<<endl;
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

People::People():birth()//!����Ҫ�����޲�Ĭ�Ϻ��������Բ�д
//�൱��people��Ƕһ��birth����ʼ��ʱҲҪ������ʼ����
{
    cout<<"����people�޲�Ĭ�Ϻ���"<<endl;
    num=0;
    id=0;
    name="no name";
    //��Ƕ����ν��г�ʼ��,ʹ�ó�Ա��ʼ���б��𣿺����ǵ�
}

People::People(const People &p):birth(p.birth)//!��ʱ������õ���birth�ĸ��ƹ��캯����
{
    num=p.num;
    id=p.id;
    name=p.name;
    //birth=p.birth;������дҲ���ԣ����ǲ��淶
}

People::~People()
{
   cout<<"����people��������"<<endl;
}

/*People:: People(int num_p,string name_p,long long id_p,Date birth_p):birth(birth_p)//��Ƕ�����ʼ�����Ե����вι�������ε���
 {
     cout<<"����people�вι��캯��"<<endl;
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
    //��ʱ����������������൱�ڹ��캯��,���������Լ�������
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
