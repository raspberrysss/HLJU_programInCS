#include <iostream>
#include"personps00.h"
#include<string>

using namespace std;

int main(void)
{

    Graduate g1("alice","female",17,20210876,"hlju","computer","computer game");
    g1.showinform_p();
    g1.showinform_s();
    g1.showinform_g();
    Graduate g2;
    g2.setinform_p();
    g2.setinform_s();
    g2.setinform_g();
    cout<<"the result"<<endl;
    g2.showinform_p();
    g2.showinform_s();
    g2.showinform_g();
    Person p1("lily","female",20);
    Student s1("lily","female",20,20210897,"hlju","education");
    Graduate g3("lily","female",20,20210897,"hlju","education","pre_school_education");
    Graduate g4(g3);//!复制构造要这样写
    g4.showinform_p();
    g4.showinform_s();
    g4.showinform_g();

    return 0;
}
