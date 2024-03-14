#include<iostream>
#include"greedy00.h"
#include<algorithm>

using namespace std;

Knapsack_g::Knapsack_g()
{
    for(int i=0;i<100;i++)
    {
        weight[i]=0.0;
    }
    for(int i=0;i<100;i++)
    {
        value[i]=0.0;
    }
    for(int i=0;i<100;i++)
    {
        result[i]=0.0;
    }
    for(int i=0;i<100;i++)
    {
        perw_va[i]=0.0;
    }
    num=0;
    weight_can=30.0;
    max_value=0.0;
}

Knapsack_g::~Knapsack_g()
{

}

void Knapsack_g::set_information()
{
    cout<<"���������װ�뱳������Ʒ����"<<endl;
    cin>>num;
    cout<<"�����������Ʒ����������ֵ������5.5 1.8������һ����Ʒ������5.5kg���ܼ�ֵ1.8Ԫ"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>weight[i]>>value[i];
        perw_va[i]=value[i]/weight[i];
    }

}

void Knapsack_g::sort_withper()
{
    double t1,t2;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            t1=value[j]/weight[j];
            t2=value[j+1]/weight[j+1];
            if(t1<t2)
            {
                double tt1;
                tt1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=tt1;
                double tt2;
                tt2=value[j];
                value[j]=value[j+1];
                value[j+1]=tt2;
            }
        }
    }
}

void Knapsack_g::greedy()
{
    double weight_have=0.0;//��װ������
    //!��sort��̫�У���֪��compare��ô�趨
   // sort(perw_va,perw_va+num,greater<double>());//�Ӵ�С������Ҫ�ڳ��ܷ�Χ�ڣ�������
     //  sort(weight,weight+num,);
      // sort(value,value+num,);
    //!!��Ҫ�����ǰ��յ��۰�weight�����value�������򣬶����ǰѵ�����������
    //!�����⣬�����ѡ����ϵ������
    sort_withper();
    /*for(int i=0;i<num;i++)
    {
        cout<<weight[i]<<endl;
    }*/
    while(weight_can!=weight_have)
    {
        for(int i=0;i<num;i++)
        {
            if(weight_can-weight_have>=weight[i])//ʣ����������ڵ��ڵ�λ��ֵ��ߵ���������ȫ������
            {
                result[i]=1;//��result*weight[i]Ϊװ������
                max_value+=value[i];
                weight_have+=weight.[i];
            }//����װȫ��
            else //װ����
            {
               result[i]=(weight_can-weight_have)/weight[i];
               //max_value+=result[i]*weight[i]*perw_va[i];//��װ��������ÿ��λ������ֵ
               max_value+=result[i]*value[i];//ͬ��һ���ĵ�������һ��
               weight_have+=weight[i]*result[i];
            }
        }
    }
    cout<<"װ�뱳������Ʒ����ֵΪ"<<max_value<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<"����Ϊ"<<weight[i]<<"��ֵΪ"<<value[i]<<"����Ʒװ��"<<result[i]<<endl;
    }
    cout<<endl;

}

Activity_g::Activity_g()
{
    n=0;
    for(int i=0;i<100;i++)
    {
        s[i]=0;
    }
    for(int i=0;i<100;i++)
    {
        t[i]=0;
    }
    for(int i=0;i<100;i++)
    {
        choice[i]=0;
    }
}

Activity_g::~Activity_g()
{

}

void Activity_g::set_in()
{
    cout<<"������Ҫ���Ż�ĸ���"<<endl;
    cin>>n;
    cout<<"�����������Ŀ�ʼʱ��ͽ���ʱ��"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>t[i];
    }
}

void Activity_g::sort_witht()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {

            if(t[j]>t[j+1])
            {
                int t1;
                t1=s[j];
                s[j]=s[j+1];
                s[j+1]=t1;
                int t2;
                t2=t[j];
                t[j]=t[j+1];
                t[j+1]=t2;

            }
        }
    }
}

void Activity_g::greedy()
{
    //!ͬ�������⣬���ǰ�t���򣬶��ǰ���t�ѿ�ʼʱ��ͽ���ʱ���С����������ͻ�ţ����������ţ�
    //sort(t,t+n);//t��С��������
    sort_witht();
    choice[0]=1;//ѡ���һ���
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]>=t[j])
        {
            choice[i]=1;
            j=i;
        }
        else
        {
            choice[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        //cout<<choice[i]<<endl;
        //cout<<t[i]<<endl;
        //cout<<s[i]<<endl;

        if(choice[i]==1)
        {
            cout<<"�"<<i+1<<"��ѡ�� "<<"��ʼʱ��Ϊ"<<s[i]<<"����ʱ��Ϊ"<<t[i]<<endl;
        }
    }

}


void menu()
{
    cout<<"1.��̰���㷨�󱳰�����"<<endl;
    cout<<"2.��̰���㷨����������"<<endl;
    cout<<"3.�˳�"<<endl;
    cout<<"���������ֽ���ѡ��"<<endl;


}
