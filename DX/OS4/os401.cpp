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
    cout<<"��ӭ���������㷨ģ�����"<<endl;
    cout<<"1.�����ȷ����㷨"<<endl;
    cout<<"2.����ҵ�����㷨"<<endl;
    cout<<"3.ʱ��Ƭ��ת�㷨"<<endl;
   // cout<<"4.���м��㷨"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"����������ѡ��"<<endl;
}

bool Sort(PCB p1,PCB p2)//���ύʱ����������
{
        return p1.get_sub()<p2.get_sub();
}

bool Sort2(PCB p1,PCB p2)//������ʱ����������
{
        return p1.get_ke()<p2.get_ke();
}

bool Sort3(PCB p1,PCB p2)//������ʱ�併��������
{
        return p1.get_ke()>p2.get_ke();
}

void FCFS()
{
                int count_pcb;
                cout<<"������������ȵĽ��̵ĸ���"<<endl;
                cin>>count_pcb;
                cout<<"������ÿ�����̵����ֺ��ύʱ�䣬����ʱ�䣨eg A 0 5����������ΪA�Ľ���0ʱ���ύ������ʱ��Ϊ5"<<endl;
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
                cout<<"�������� �ύʱ�� ����ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ƽ����Ȩ��ת "<<endl;
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
                cout<<"����תʱ��"<<sum_t<<" ƽ����תʱ��"<<sum_ta<<endl;
                cout<<"�ܴ�Ȩ��תʱ��"<<sum_w<<" ƽ����Ȩ��תʱ��"<<sum_wa<<endl;



}

void SJF()
{
                int count_pcb;
                cout<<"������������ȵĽ��̵ĸ���"<<endl;
                cin>>count_pcb;
                cout<<"������ÿ�����̵����ֺ��ύʱ�䣬����ʱ�䣨eg A 0 5����������ΪA�Ľ���0ʱ���ύ������ʱ��Ϊ5"<<endl;
                int sub,keep;
                string name;
                vector<PCB> pv;
                vector<PCB> pvs;//����
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
                int time_now=pv[0].get_sub();//��¼��ǰʱ��,��ǰʱ��Ϊ������ύʱ��
                sort(pv.begin(),pv.end(),Sort2);
                for(int i=0;i<count_pcb;i++)
                {
                    if(pv[i].get_sub()==time_now)//�ҵ���һ�����е�
                    {
                        pv[i].set_sta(time_now);
                        pv[i].ca_fin();
                        pv[i].ca_tt();
                        pv[i].ca_w();
                        time_now=pv[i].get_fin();//��һ�����̵Ľ���ʱ�������ڵĵ�ǰʱ��
                        pvs.push_back(pv[i]);
                        pv.erase(pv.begin()+i);//vector,ɾ��һ���ض�����ֵ
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
                       if((*it).get_sub()<=time_now)//ʣ�µ��ύʱ��С�ڵ�ǰʱ��Ķ�����ִ�У�ִ�к����time_now
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
                            //!����ɾ��ɾ�˻�ɾ��//it=pv.erase(it);
                           // it=itt+1;
                       }
                }




                //cout<<time_now<<endl;

                cout<<"�������� �ύʱ�� ����ʱ�� ��ʼʱ�� ����ʱ�� ��תʱ�� ƽ����Ȩ��ת "<<endl;
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
                cout<<"����תʱ��"<<sum_t<<" ƽ����תʱ��"<<sum_ta<<endl;
                cout<<"�ܴ�Ȩ��תʱ��"<<sum_w<<" ƽ����Ȩ��תʱ��"<<sum_wa<<endl;

                //cout<<time_now<<endl;


                /*for(int i=0;i<count_pcb;i++)
                {
                    cout<<pv[i].get_ke()<<endl;
                }*/

}

void Time_change()
{
                int count_pcb;
                cout<<"������������ȵĽ��̵ĸ���"<<endl;
                cin>>count_pcb;
                cout<<"������ÿ�����̵����ֺ��ύʱ�䣬����ʱ�䣨eg A 0 5����������ΪA�Ľ���0ʱ���ύ������ʱ��Ϊ5"<<endl;
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
                cout<<"��������ת��ʱ�䵥λ"<<endl;
                cin>>q;
                //���ύʱ�����򣬺�һ��һ����ȥʱ��Ƭ
                //����������ʱ��/q������ѭ������
                double count_while=(double)n/(double)q;
                int result=ceil(count_while);
                //cout<<result;
                cout<<"ִ������Ϊ";
                while(result--)//�����н���δ��ִ�����
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
