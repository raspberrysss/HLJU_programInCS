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
    return s;//��ʱ������ʧ����ô��
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

Songer Songer::operator++()//����Songer
{
    fans_count=fans_count+10;
    return *this;
}

Songer operator++(Songer &s,int s_i=0)//�����ˣ����ֿ��ͺ�ʹ�ˣ�����Ҫ����Songer���Ͷ���������
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
    cout<<"��ӭ�������������ϵͳ"<<endl;
    cout<<"1.���������Ϣ��չʾ"<<endl;
    cout<<"2.���Ӹ��ַ�˿����չʾ"<<endl;
    cout<<"3.ʹ��������ʮ����˿"<<endl;
    cout<<"4.�Ƚ��������ַ�˿���Ƿ����"<<endl;
    cout<<"5.�Ƚ�ĳ�����Ƿ��˿��������������"<<endl;
    cout<<"6.��ʾ��ǰ������"<<endl;
    cout<<"7.�˳�"<<endl;
}
