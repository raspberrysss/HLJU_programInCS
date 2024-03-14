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
    base=top=new Elem[MAXSIZE];//都指向新开的数组
    length=0;
    size_of_stack=MAXSIZE;
}

int Stack::push(Elem e)//将e入栈
{
    length++;
    if(top-base==size_of_stack)//!指针也可以运算吗？
    {
        cout<<"此栈已经满了，无法继续入栈"<<endl;
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
        cout<<"此栈已空，无法进行出栈操作"<<endl;
        return 0;
    }
    top--;
    return 1;
}

void Stack::get_top_elem(char &c)//取出栈顶元素放在c中
{
    if(top==base)
    {
        cout<<"此栈已空，无法取出栈顶"<<endl;
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
