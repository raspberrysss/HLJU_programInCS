#include <iostream>
#include"stack00.h"

//���ĶԳƣ���ջ�ͳ�ջһ��������ַ�������
//
using namespace std;

int main(void)
{
    Stack s1;
    Elem e1;
    e1.set_e();
    s1.push(e1);
    s1.show_stack();
    char c;
    s1.get_top_elem(c);
    cout<<c<<endl;
    return 0;
}
