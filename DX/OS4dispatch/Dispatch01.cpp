#include"Dispatch.h"
#include<iostream>

using namespace std;

PCB::PCB()
{
    name="no";
    time_sub=-1;
    time_fin=-1;
    time_sta=-1;
}

PCB::~PCB()
{

}

void menu()
{
    cout<<"��ӭ���������㷨ģ�����"<<endl;
    cout<<"1.�����ȷ����㷨"<<endl;
    cout<<"2.����ҵ�����㷨"<<endl;
    cout<<"3.ʱ��Ƭ��ת�㷨"<<endl;
    cout<<"4.���м��㷨"<<endl;
    cout<<"5.�˳�"<<endl;
    cout<<"����������ѡ��"<<endl;
}
