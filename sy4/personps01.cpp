#include"personps00.h"
#include<iostream>
#include<string>//string! not string.h

using namespace std;

Person::Person()
{
    name="no name";
    sex="no sex";
    age=0;
}

Person::Person(string name_p,string sex_p,int age_p)
{
    name=name_p;
    sex=sex_p;
    age=age_p;
}

Person::Person(Person &p)
{
    name=p.name;
    sex=p.sex;
    age=p.age;
}

void Person::setinform_p()
{
    cout<<"please input the information(eg Alice female 19)"<<endl;
    cin>>name>>sex>>age;
}

void Person::showinform_p()
{
    cout<<name<<" "<<sex<<" "<<age<<endl;
}

Person::~Person()
{
    cout<<"using the Person destructor function"<<endl;
}

Student::Student()//:Person()
{
    num=00000000;
    school="no school";
    major="no major";
}

Student::Student(string name_s,string sex_s,int age_s,long num_s,string school_s,string major_s):Person( name_s,sex_s,age_s)
{
    num=num_s;
    school=school_s;
    major=major_s;
}

Student::Student(Student &s):Person(s)
{
     num=s.num;
     school=s.school;
     major=s.major;
}

Student::~Student()
{
     cout<<"using the Student destructor function"<<endl;
}

void Student::setinform_s()
{
    //setinform_p();
    cout<<"please input the information(eg 20217898 hlju computer)"<<endl;
    cin>>num>>school>>major;
}

void Student::showinform_s()
{
    //showinform_p();
    cout<<num<<" "<<school<<" "<<major<<endl;
}

Graduate::Graduate()//:Student()
{
    research_direction="no direction";
}

Graduate::Graduate(string name_g,string sex_g,int age_g,long num_g,string school_g,string major_g,string research_direction_g):Student( name_g, sex_g,age_g, num_g, school_g, major_g)//:Person(name_g,sex_g,age_g)
{
    research_direction=research_direction_g;
}

Graduate::Graduate(Graduate&g):Student(g)//！困扰的算被解决了，但是还是很怪异，明明g是graguate类啊，这就是继承和派生吗
{
    research_direction=g.research_direction;
}

Graduate::~Graduate()
{
    cout<<"using the Graduate destructor function"<<endl;
}

void Graduate::setinform_g()
{
    cout<<"please input the information(eg computer game)"<<endl;
    cin>>research_direction;
}

void Graduate::showinform_g()
{
    cout<<research_direction<<endl;
}
