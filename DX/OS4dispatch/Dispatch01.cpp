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
    cout<<"欢迎来到调度算法模拟程序"<<endl;
    cout<<"1.先来先服务算法"<<endl;
    cout<<"2.短作业优先算法"<<endl;
    cout<<"3.时间片轮转算法"<<endl;
    cout<<"4.银行家算法"<<endl;
    cout<<"5.退出"<<endl;
    cout<<"请输入数字选择"<<endl;
}
