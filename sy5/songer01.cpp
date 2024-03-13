#include<iostream>
#include<string>
#include"songer00.h"

using namespace std;

int Songer::songer_num=0;

Songer::Songer()
{
    songer_num++;
    name="no name";
    fans_count=0;
}

Songer::Songer(string name_s,int fans_count_s)
{
    name=name_s;
    fans_count=fans_count_s;
    songer_num++;
}

Songer::Songer(const Songer &s)
{
    name=s.name;
    fans_count=s.fans_count;
    songer_num++;
}

Songer::~Songer()
{
    songer_num--;
    cout<<"using the destructor"<<endl;
}

Songer Songer::operator+(int add)
{
    Songer s;
    s.fans_count=fans_count+add;
    return s;//临时变量消失了怎么办
}

bool Songer::operator>(Songer &s)
{
    if(fans_count>s.fans_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(Songer &s1,Songer &s2)
{
    if(s1.fans_count==s2.fans_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Songer Songer::operator++()//返回Songer
{
    fans_count=fans_count+10;
    return *this;
}

Songer operator++(Songer &s,int s_i=0)//可以了，区分开就好使了！这里要返回Songer类型而不是引用
{
    Songer s_new;
    s_new=s;
    s_new.fans_count=s_new.fans_count+10;
    return s_new;
}

ostream & operator<<(ostream & os,Songer &s)
{
    os<<s.name<<" "<<s.fans_count<<endl;
    return os;
}

void Songer::setinform()
{
    cout<<"please input the information(eg.linda 390)"<<endl;
    cin>>name>>fans_count;

}

void Songer::shownum()
{
    cout<<"the num of the songer is "<<songer_num<<endl;
}

void Songer::showfans()
{
    cout<<"the fans_count is "<<fans_count<<endl;
}
void menu()
{
    cout<<"欢迎来到歌手类测试系统"<<endl;
    cout<<"1.输入歌手信息并展示"<<endl;
    cout<<"2.增加歌手粉丝数并展示"<<endl;
    cout<<"3.使歌手增加十个粉丝"<<endl;
    cout<<"4.比较两个歌手粉丝数是否相等"<<endl;
    cout<<"5.比较某歌手是否粉丝数大于其他歌手"<<endl;
    cout<<"6.显示当前歌手数"<<endl;
    cout<<"7.退出"<<endl;
}
