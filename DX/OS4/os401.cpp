#include<iostream>
#include"os400.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;

PCB::PCB()
{
    name="no";
    //id=-1;
    time_sub=-1;
    time_fin=-1;
    time_sta=-1;
    time_ke=-1;
    time_tt=-1;
    w=-1;
    //next=NULL;
}

PCB::~PCB()
{

}

void PCB::show()
{

    cout<<name<<"\t "<<time_sub<<"\t  "<<time_ke<<"\t    "<<time_sta<<"\t    "<<time_fin<<"\t     "<<time_tt<<"\t       "<<fixed<<setprecision(2)<<w<<endl;
}

/*
PCB_link::PCB_link()
{
    head=NULL;
    length=0;
}

PCB_link::~PCB_link()
{

}
*/
void menu()
{
    cout<<"欢迎来到调度算法模拟程序"<<endl;
    cout<<"1.先来先服务算法"<<endl;
    cout<<"2.短作业优先算法"<<endl;
    cout<<"3.时间片轮转算法"<<endl;
   // cout<<"4.银行家算法"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入数字选择"<<endl;
}

bool Sort(PCB p1,PCB p2)//按提交时间升序排序
{
        return p1.get_sub()<p2.get_sub();
}

bool Sort2(PCB p1,PCB p2)//按运行时间升序排序
{
        return p1.get_ke()<p2.get_ke();
}

bool Sort3(PCB p1,PCB p2)//按运行时间降序序排序
{
        return p1.get_ke()>p2.get_ke();
}

void FCFS()
{
                int count_pcb;
                cout<<"请输入您想调度的进程的个数"<<endl;
                cin>>count_pcb;
                cout<<"请输入每个进程的名字和提交时间，运行时间（eg A 0 5）代表名字为A的进程0时刻提交，运行时间为5"<<endl;
                int sub,keep;
                string name;
                vector<PCB> pv;
                for(int i=0;i<count_pcb;i++)
                {
                    cin>>name>>sub>>keep;
                    PCB p1;
                    p1.set_name(name);
                    p1.set_k(keep);
                    p1.set_sub(sub);
                    pv.push_back(p1);

                }
                sort(pv.begin(),pv.end(),Sort);

                for(int i=0;i<count_pcb;i++)
                {
                    //cout<<pv[i].get_sub()<<endl;
                    if(i==0)
                    {
                        cout<<pv[i].get_sub()<<endl;
                       pv[i].set_sta(pv[i].get_sub());

                    }
                    else
                    {
                        pv[i].set_sta(pv[i-1].get_fin());
                    }
                    cout<<pv[i].get_ke()<<endl;

                    pv[i].ca_fin();
                    pv[i].ca_tt();
                    pv[i].ca_w();
                }
                cout<<"进程名字 提交时间 运行时间 开始时间 结束时间 周转时间 平均带权周转 "<<endl;
                for(int i=0;i<count_pcb;i++)
                {
                    pv[i].show();
                }
                int sum_t=0;
                double sum_w=0;
                for(int i=0;i<count_pcb;i++)
                {
                    sum_t=sum_t+pv[i].get_tt();
                    sum_w=sum_w+pv[i].get_w();
                }
                double sum_ta=(double)sum_t/(double)count_pcb;
                double sum_wa=sum_w/count_pcb;
                cout<<"总周转时间"<<sum_t<<" 平均周转时间"<<sum_ta<<endl;
                cout<<"总带权周转时间"<<sum_w<<" 平均带权周转时间"<<sum_wa<<endl;



}

void SJF()
{
                int count_pcb;
                cout<<"请输入您想调度的进程的个数"<<endl;
                cin>>count_pcb;
                cout<<"请输入每个进程的名字和提交时间，运行时间（eg A 0 5）代表名字为A的进程0时刻提交，运行时间为5"<<endl;
                int sub,keep;
                string name;
                vector<PCB> pv;
                vector<PCB> pvs;//最后的
                for(int i=0;i<count_pcb;i++)
                {
                    cin>>name>>sub>>keep;
                    PCB p1;
                    p1.set_name(name);
                    p1.set_k(keep);
                    p1.set_sub(sub);
                    pv.push_back(p1);
                }
                sort(pv.begin(),pv.end(),Sort);
                int time_now=pv[0].get_sub();//记录当前时间,当前时间为最早的提交时间
                sort(pv.begin(),pv.end(),Sort2);
                for(int i=0;i<count_pcb;i++)
                {
                    if(pv[i].get_sub()==time_now)//找到第一个运行的
                    {
                        pv[i].set_sta(time_now);
                        pv[i].ca_fin();
                        pv[i].ca_tt();
                        pv[i].ca_w();
                        time_now=pv[i].get_fin();//第一个进程的结束时间是现在的当前时间
                        pvs.push_back(pv[i]);
                        pv.erase(pv.begin()+i);//vector,删除一个特定的数值
                        break;

                    }
                }

//                for(vector<PCB>::iterator it=pv.begin();it!=pv.end();it++)
//                {
//                    (*it).show();
//                }
//cout<<pvs.capacity()<<endl;

            for(vector<PCB>::iterator it=pv.begin();it!=pv.end();it++)
                {
                        //cout<<"time_now="<<time_now<<endl;
                       //cout<<(*it).get_name()<<endl;
                       if((*it).get_sub()<=time_now)//剩下的提交时间小于当前时间的都可以执行，执行后更改time_now
                       {
                           // cout<<"time_now="<<time_now<<endl;
                            //cout<<(*it).get_ke()<<endl;
                            (*it).set_sta(time_now);
                            //cout<<(*it).get_name()<<(*it).get_sta()<<endl;
                            (*it).ca_fin();
                            (*it).ca_tt();
                            (*it).ca_w();
                            time_now=(*it).get_fin();
                            pvs.push_back(*it);
                            //cout<<"11111111111111"<<endl;
                           // vector<PCB>::iterator itt=it;
                            //!不能删，删了会删丢//it=pv.erase(it);
                           // it=itt+1;
                       }
                }




                //cout<<time_now<<endl;

                cout<<"进程名字 提交时间 运行时间 开始时间 结束时间 周转时间 平均带权周转 "<<endl;
                for(int i=0;i<count_pcb;i++)
                {
                   pvs[i].show();
                }
                int sum_t=0;
                double sum_w=0;
                for(int i=0;i<count_pcb;i++)
                {
                    sum_t=sum_t+pvs[i].get_tt();
                    sum_w=sum_w+pvs[i].get_w();
                }
                double sum_ta=(double)sum_t/(double)count_pcb;
                double sum_wa=sum_w/count_pcb;
                cout<<"总周转时间"<<sum_t<<" 平均周转时间"<<sum_ta<<endl;
                cout<<"总带权周转时间"<<sum_w<<" 平均带权周转时间"<<sum_wa<<endl;

                //cout<<time_now<<endl;


                /*for(int i=0;i<count_pcb;i++)
                {
                    cout<<pv[i].get_ke()<<endl;
                }*/

}

void Time_change()
{
                int count_pcb;
                cout<<"请输入您想调度的进程的个数"<<endl;
                cin>>count_pcb;
                cout<<"请输入每个进程的名字和提交时间，运行时间（eg A 0 5）代表名字为A的进程0时刻提交，运行时间为5"<<endl;
                int sub,keep;
                string name;
                vector<PCB> pv;
                for(int i=0;i<count_pcb;i++)
                {
                    cin>>name>>sub>>keep;
                    PCB p1;
                    p1.set_name(name);
                    p1.set_k(keep);
                    p1.set_sub(sub);
                    pv.push_back(p1);
                }
                sort(pv.begin(),pv.end(),Sort3);
                int n=pv[0].get_ke();
                //cout<<n<<endl;
                sort(pv.begin(),pv.end(),Sort);
                int q=0;
                cout<<"请输入轮转的时间单位"<<endl;
                cin>>q;
                //按提交时间排序，后一个一个减去时间片
                //以最大的运行时间/q来决定循环次数
                double count_while=(double)n/(double)q;
                int result=ceil(count_while);
                //cout<<result;
                cout<<"执行序列为";
                while(result--)//当所有进程未被执行完成
                {
                    for(vector<PCB>::iterator it=pv.begin();it!=pv.end();it++)
                    {
                        //cout<<"ke"<<(*it).get_ke()<<endl;
                        if((*it).get_ke()>0)
                        {
                            (*it).dec_ke(q);
                            cout<<(*it).get_name();
                        }
                        else
                        {
                            //it=pv.erase(it);
                        }

                    }
                }
                cout<<endl;

}
