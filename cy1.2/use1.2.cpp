#include <iostream>//˼�����������������������Ƕ��!����Peopleʱֱ������People�����Ƕ��Date
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
    cout<<"first,test the �޲�Ĭ�Ϻ���"<<endl;
    People peo1;
    Date d1,d2;
    peo1.showpeople();
    cout<<endl;
    d1.showdate();
    cout<<endl;
    d2.showdate();
    system("pause");
    system("cls");
    cout<<"second,test the Date People �вι��캯��"<<endl;
   // Date d1(1998,7,9);��ʽ���ò����𣿶ԣ�����Ҫ����һ�𣬲����³���
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
   People peo2(peo1);//������õ���p2�ĸ��ƹ��죬�൱�ڰ� peo1����peo2.
   cout<<"******************************************"<<endl;
   peo2.showpeople();
   system("pause");
   cout<<"finally,test the ��������"<<endl;

}
