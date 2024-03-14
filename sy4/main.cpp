#include <iostream>
#include"stack00.h"

//中心对称，进栈和出栈一样，这个字符串就是
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
