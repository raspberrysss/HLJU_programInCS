#include <iostream>//思考析构函数如何析构，带内嵌类!析构People时直接析构People类的内嵌类Date
#include"people00.h"
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    cout<<"welcome to test system"<<endl;
    cout<<"les us test"<<endl;
    system("pause");
    system("cls");
    cout<<"first,test the 无参默认函数"<<endl;
    People peo1;
    Date d1,d2;
    peo1.showpeople();
    cout<<endl;
    d1.showdate();
    cout<<endl;
    d2.showdate();
    system("pause");
    system("cls");
    cout<<"second,test the Date People 有参构造函数"<<endl;
   // Date d1(1998,7,9);隐式调用不对吗？对！但是要连在一起，不能新出现
   Date d3(1998,7,9);
   d3.showdate();
   cout<<"******************************************"<<endl;
   People peo4(2,"lisi",23022420030678,1999,6,8);
   peo4.showpeople();
   system("pause");
   cout<<"third,test other function"<<endl;
   peo1.getpeople();
   peo1.showpeople();
   cout<<"******************************************"<<endl;
   People peo2(peo1);//这里调用的是p2的复制构造，相当于把 peo1赋给peo2.
   cout<<"******************************************"<<endl;
   peo2.showpeople();
   system("pause");
   cout<<"finally,test the 析构函数"<<endl;

}
