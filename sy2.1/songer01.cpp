#include<iostream>
#include"songer00.h"
#include<string>

using namespace std;

// num_songer=0;

int Songer::num_songer=0;

Songer::Songer()
{
    name="no name";
    fans_count=0;
    num_songer++;
}

Songer::Songer(string name_s,int fans_count_s)
{
    name=name_s;
    fans_count=fans_count_s;
    num_songer++;
}
Songer::Songer(const Songer &s)
{
    name=s.name;
    fans_count=s.fans_count;
    num_songer++;
}
Songer::~Songer()
{
    num_songer--;
    cout<<"������������"<<endl;
}

void Songer::setcount()
{
    cout<<"please input the count of the fans"<<endl;
    cin>>fans_count;
}

void Songer::showcount()
{
    cout<<"the count of the fans is "<<fans_count<<endl;
}

void Songer::showsonger()
{
    cout<<"the name is "<<name<<endl;
    cout<<"the fans_count is "<<fans_count<<endl;

}
void Songer::shownum()
{
    cout<<"the number of the songer is "<<num_songer<<endl;
}

/*bool PK(const Songer &s1,const Songer &s2)
{
    return s1.fans_count>s2.fans_count;
}*///δ����ƽ��,�������bool�������Ҿ��úܰ�����һ����
int PK(const Songer &s1,const Songer &s2)//��������ñ����Ļ���ô���ָ��ƺ����أ�
{
    if(s1.fans_count>s2.fans_count)
    {
        return 1;
    }
    else if(s1.fans_count>s2.fans_count)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

