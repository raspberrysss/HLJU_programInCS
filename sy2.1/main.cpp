#include <iostream>
#include"songer00.h"
#include<cstdlib>

using namespace std;

int main()
{
    cout<<"welcome to the test system"<<endl;
    system("pause");
    system("cls");
    cout<<"first,let us test the Ĭ���޲ι��캯�������ò���ʾ,������ʾ��̬��Ա����"<<endl;
    Songer singer1;
    singer1.showsonger();
    singer1.shownum();
    system("pause");
    system("cls");
    cout<<"second,let us test the ���ƹ��죬��̬��Ա"<<endl;
    Songer singer2(singer1);
    singer2.showsonger();
    singer2.shownum();
    system("pause");
    system("cls");
    cout<<"third, let us test �вι��캯�����ò���ʾ��and modify the fans_count ������ʾ��̬��Ա����"<<endl;
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
    cout<<"finally,test the ��������"<<endl;
   // singer1.shownum();���������ԣ�����֮������Ѿ�û���ˣ��޷�����
    system("pause");
    return 0;
}
