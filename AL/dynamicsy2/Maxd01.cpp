#include"Maxd00.h"
#include<iostream>

using namespace std;

Maxsegment_d::Maxsegment_d()
{
    length_d=0;
    for(int i=1;i<=100;i++)
    {
        array_d[i]=0;
    }
    for(int i=1;i<=101;i++)
    {
        dynamic[i]=0;
    }
    sta=0;
    ter=0;
}

Maxsegment_d::~Maxsegment_d()
{

}

void Maxsegment_d::set_array_d()
{
    cout<<"请输入长度"<<endl;
    cin>>length_d;
    cout<<"请输入各个元素"<<endl;
    for(int i=1;i<=length_d;i++)
    {
        cin>>array_d[i];
    }
    cout<<endl;
    for(int i=1;i<=length_d;i++)
    {
        cout<<array_d[i]<<" ";
    }
}

int Maxsegment_d::find_Maxsegement()
{
    int sum=0;
    int i=0;
    for(int j=1;j<=length_d;j++)
    {
        if(dynamic[j]>0)
        {
            dynamic[j]=dynamic[j-1]+array_d[j];
        }
        else
        {
            dynamic[j]=array_d[j];
            i=j;
        }
        if(sum<dynamic[j])
        {
            sum=dynamic[j];
            sta=i;
            ter=j;
        }
    }
    return sum;
}
