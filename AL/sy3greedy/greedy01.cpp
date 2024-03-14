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
    cout<<"请输入打算装入背包的物品数量"<<endl;
    cin>>num;
    cout<<"请输入各个物品的重量及价值（例：5.5 1.8，代表一个物品总重量5.5kg，总价值1.8元"<<endl;
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
    double weight_have=0.0;//已装的重量
    //!用sort不太行，不知道compare怎么设定
   // sort(perw_va,perw_va+num,greater<double>());//从大到小排序，需要在承受范围内，放最贵的
     //  sort(weight,weight+num,);
      // sort(value,value+num,);
    //!!需要做的是按照单价把weight数组和value数组排序，而不是把单价数组排序
    //!有问题，排序和选择联系不起来
    sort_withper();
    /*for(int i=0;i<num;i++)
    {
        cout<<weight[i]<<endl;
    }*/
    while(weight_can!=weight_have)
    {
        for(int i=0;i<num;i++)
        {
            if(weight_can-weight_have>=weight[i])//剩余的重量大于等于单位价值最高的重量，可全部放入
            {
                result[i]=1;//用result*weight[i]为装入质量
                max_value+=value[i];
                weight_have+=weight.[i];
            }//可以装全部
            else //装部分
            {
               result[i]=(weight_can-weight_have)/weight[i];
               //max_value+=result[i]*weight[i]*perw_va[i];//！装入质量乘每单位质量价值
               max_value+=result[i]*value[i];//同上一样的道理，换算一下
               weight_have+=weight[i]*result[i];
            }
        }
    }
    cout<<"装入背包的物品最大价值为"<<max_value<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<"重量为"<<weight[i]<<"价值为"<<value[i]<<"的物品装入"<<result[i]<<endl;
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
    cout<<"请输入要安排活动的个数"<<endl;
    cin>>n;
    cout<<"请输入各个活动的开始时间和结束时间"<<endl;
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
    //!同样的问题，不是把t排序，而是按照t把开始时间和结束时间从小到大排排序和活动号（不用特意排）
    //sort(t,t+n);//t从小到大排序
    sort_witht();
    choice[0]=1;//选择第一个活动
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
            cout<<"活动"<<i+1<<"被选择 "<<"开始时间为"<<s[i]<<"结束时间为"<<t[i]<<endl;
        }
    }

}


void menu()
{
    cout<<"1.用贪心算法求背包问题"<<endl;
    cout<<"2.用贪心算法求活动安排问题"<<endl;
    cout<<"3.退出"<<endl;
    cout<<"请输入数字进行选择"<<endl;


}
