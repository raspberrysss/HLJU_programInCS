#include <iostream>
#include"songer00.h"
#include<cstdlib>

using namespace std;

int main()
{
    cout<<"welcome to the test system"<<endl;
    system("pause");
    system("cls");
    cout<<"first,let us test the 默认无参构造函数，调用并显示,并且显示静态成员增加"<<endl;
    Songer singer1;
    singer1.showsonger();
    singer1.shownum();
    system("pause");
    system("cls");
    cout<<"second,let us test the 复制构造，静态成员"<<endl;
    Songer singer2(singer1);
    singer2.showsonger();
    singer2.shownum();
    system("pause");
    system("cls");
    cout<<"third, let us test 有参构造函数调用并显示，and modify the fans_count 并且显示静态成员增加"<<endl;
    Songer singer3("Lily",230);
    singer3.showsonger();
    singer3.setcount();
    singer3.showsonger();
    singer1.shownum();
    singer2.shownum();
    singer3.shownum();
    system("pause");
    system("cls");
    cout<<"forth,let us test the PK function and show the static num"<<endl;
    Songer singer4("Mike",210);
    int result;
     result=PK(singer3,singer4);
    if(result==1)
    {
        cout<<" Lily win !"<<endl;
    }
    else if(result==2)
    {
       cout<<"Mike win !"<<endl;
    }
    else
    {
         cout<<"they are equal"<<endl;
    }
    /*bool result;
    result=PK(singer2,singer3);
    if(result)
    {
        cout<<" Lily win !"<<endl;
    }
    else
    {
        cout<<"Mike win !"<<endl;
    }*/
    singer4.shownum();
    system("pause");
    system("cls");
    cout<<"finally,test the 析构函数"<<endl;
   // singer1.shownum();这样不可以，析构之后对象已经没有了，无法调用
    system("pause");
    return 0;
}
