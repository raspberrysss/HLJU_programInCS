#include<iostream>
#include"sequence00.h"//先放下动态的试着写一写，我一定能写出来，还有一周时间，不急不急

using namespace std;

Sequence_elem::Sequence_elem()
{
    a=0;
}

Sequence_elem::~Sequence_elem()
{

}

int Sequence_elem::get_elem()
{
    return a;
    //cout<<a<<" ";
}

void Sequence_elem::set_elem()
{
    cin>>a;
}

Sequence::Sequence()
{
    length=0;
    size_s=0;
    se_q=new Sequence_elem[length];
}

Sequence::Sequence(int len_s)
{
    length=len_s;
    size_s=0;
    se_q=new Sequence_elem[length];
}

Sequence::~Sequence()
{
    size_s=0;
    length=0;
    delete []se_q;
}

int Sequence::get_len()
{
    return length;
}
void Sequence::add(Sequence_elem e)//考虑动态数组
{
    se_q[size_s]=e;
    size_s++;
}

void Sequence::insert_se(Sequence_elem e)
{
    int in;//记录下标
    int i;
    for(i=0;i<=size_s;i++)
    {
        if(e.get_elem()<se_q[i].get_elem())
        {
            in=i;
            break;
        }
    }
    int j;
    for(j=size_s;j>=in;j--)
    {
        se_q[j+1].get_elem()=se_q[j].get_elem();
    }
    se_q[in].get_elem()=e.get_elem();
    get_len()++;


}
