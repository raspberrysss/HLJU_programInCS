#include<iostream>
#include"stack00.h"

using namespace std;

const int MAXSIZE=100;

Elem::Elem()
{
    e='0';
}

char Elem::get_e()
{
    return e;
}

void Elem::show_e()
{
    cout<<e<<" ";
}

void Elem::set_e()
{
    cin>>e;
}

Stack::Stack()
{
    base=top=new Elem[MAXSIZE];//��ָ���¿�������
    length=0;
    size_of_stack=MAXSIZE;
}

int Stack::push(Elem e)//��e��ջ
{
    length++;
    if(top-base==size_of_stack)//!ָ��Ҳ����������
    {
        cout<<"��ջ�Ѿ����ˣ��޷�������ջ"<<endl;
        return 0;
    }
    *top=e;
    top++;
    return 1;
}

int Stack::pop()
{
    length--;
    if(top==base)
    {
        cout<<"��ջ�ѿգ��޷����г�ջ����"<<endl;
        return 0;
    }
    top--;
    return 1;
}

void Stack::get_top_elem(char &c)//ȡ��ջ��Ԫ�ط���c��
{
    if(top==base)
    {
        cout<<"��ջ�ѿգ��޷�ȡ��ջ��"<<endl;
    }
    c=(top--)->get_e();

}

void Stack::show_stack()
{
    top=base;
    if(top-base!=size_of_stack)
    {
        top->show_e();
    }
}
